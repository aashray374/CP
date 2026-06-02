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


bool solve(int k,vector<int> &v,vector<int> &dp){
    if(k<v[0])  return false;

    if(dp[k] != -1) return (dp[k] == 1);
    bool ans = false;
    for(int i = 0;i<v.size();i++){
        if(k>=v[i]){
            ans|=!solve(k-v[i],v,dp);
            if(ans) break;
        }else{
            break;
        }
    }

    dp[k] = (ans?1:0);
    return ans;
}

void testcase() {
    int n,k;cin>>n>>k;
    queue<int> q;
    vector<int>  dp(k+1,0),v(n,0);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    for(int i = 0;i<=k;i++){
        for(int &x : v){
            if(x+i<=k){
                dp[i+x] |=(1-dp[i]);
            }
        }
    }

    if(dp[k]){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
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