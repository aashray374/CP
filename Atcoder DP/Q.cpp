#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define alice cout<<"Alice"<<endl;
#define bob cout<<"Bob"<<endl;
#define log logl
const int M = 1e9+7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

class SegmentTree{
    vector<int> seg,v;

    public:
        SegmentTree(vector<int> &v){
            int n = v.size();
            seg.resize(4*n+10,0);
        }

        void pointUpdate(vector<int> &v,int ind,int lo,int hi,int i,int val){
            if(i<lo || i>hi)    return;

            if(lo == hi){
                if(lo == i){
                    seg[ind] = val;
                }
                return;
            }

            int mid = lo+(hi-lo)/2;

            pointUpdate(v,2*ind+1,lo,mid,i,val);
            pointUpdate(v,2*ind+2,mid+1,hi,i,val);

            seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
        }


        int rangeQuery(vector<int> &v,int ind,int lo,int hi,int r){
            if(hi<=r){
                return seg[ind];
            }

            if(lo>r)    return 0;
            int mid = lo+(hi-lo)/2;
            return max(rangeQuery(v,2*ind+1,lo,mid,r),rangeQuery(v,2*ind+2,mid+1,hi,r));
        }
};

void testcase() {
    int n;cin>>n;
    vector<int> h(n),v(n),dp(n+1,0);

    for(int i = 0;i<n;i++){
        cin>>h[i];
    }
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    SegmentTree* seg = new SegmentTree(dp);

    int ans = 0;
    for(int i = 0;i<n;i++){
        int prev = seg->rangeQuery(dp,0,0,n,h[i]);
        // cout<<prev<<endl;
        seg->pointUpdate(dp,0,0,n,h[i],v[i]+prev);

        ans =max(ans,prev+v[i]);
    }

    cout<<ans<<endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    // cin>>t;
    // precompute();
    while(t--){
        testcase();
    }

}