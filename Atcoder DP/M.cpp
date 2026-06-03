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


void testcase() {
    int n,k;cin>>n>>k;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    if(k == 0){
        cout<<1<<endl;
        return;
    }

    vector<int> curr(k+1,0),prev(k+1,0);

    // o children 0 candies
    prev[0] = 1;

    // prefix sum for optimization
    for(int i = 1;i<=k;i++){
        prev[i]+=prev[i-1];
    }

    for(int children = 1;children<=n;children++){

        curr[0] = 1;
        for(int j = 1;j<=k;j++){
            int r = j,l = max(0ll,j-v[children-1]);
            int sum = prev[r]%M;
            if(l != 0){
                sum = (sum-prev[l-1]+M)%M;
            }

            curr[j] = (sum+curr[j-1])%M;
        }

        prev = curr;
    }


    cout<<(curr[k]-curr[k-1]+M)%M<<endl;
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