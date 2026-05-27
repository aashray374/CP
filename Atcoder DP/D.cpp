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


// int solve(vector<vector<int>> &v,vector<vector<int>> &dp,int ind,int W){
//     if(ind < 0) return 0;

//     if(dp[ind][W] != -1)    return dp[ind][W];

//     int ans = INT_MIN;
//     if(W>=v[ind][0]){
//         ans = max({ans,solve(v,dp,ind-1,W),solve(v,dp,ind-1,W-v[ind][0])+v[ind][1]});
//     }else{
//         ans = max(ans,solve(v,dp,ind-1,W));
//     }

//     return dp[ind][W] = ans;
// }


void testcase() {
    int n,w;
    cin>>n>>w;

    vector<vector<int>> v(n+1,vector<int>(2,0));
    vector<int> dp(w+1,0);
    for(int i = 1;i<=n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    
    // vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    // for(int i = 1;i<=n;i++){
    //     for(int j = 0;j<=w;j++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j>=v[i][0]){
    //             dp[i][j] = max(dp[i-1][j-v[i][0]]+v[i][1],dp[i][j]);
    //         }
    //     }
    // }

    // cout<<dp[n][w];

    for(int i = 1;i<=n;i++){
        for(int j = w;j>=0;j--){
            if(j>=v[i][0]){
                dp[j] = max(dp[j-v[i][0]]+v[i][1],dp[j]);
            }
        }
    }

    cout<<dp[w]<<endl;
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