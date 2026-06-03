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


// int solve(int l,int j,vector<int> &v,vector<vector<int>> &dp){
//     if(l == j){
//         return 0;
//     }
    
//     if(dp[l][j] != -1)    return dp[l][j];

//     int ans = -1;
//     for(int i = l;i<j;i++){
//         if(ans == -1){
//             ans = solve(l,i,v,dp)+solve(i+1,j,v,dp);
//         }
//         ans = min(ans,solve(l,i,v,dp)+solve(i+1,j,v,dp));
//     }

//     return dp[l][j] = ans+v[j]-v[l-1];
// }

void testcase() {
    int n;cin>>n;

    vector<int> v(n+1,0);

    for(int i = 1;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int len = 2;len<=n;len++){
        for(int l = 1;l<=n;l++){
            int j = l+len-1;
            if(j>n) break;
            int cost = v[j]-v[l-1];

            int ans = 0;
            for(int k = l;k<j;k++){
                if(ans == 0){
                    ans = dp[l][k]+dp[k+1][j];
                }else{
                    ans = min(ans,dp[l][k]+dp[k+1][j]);
                }
            }

            dp[l][j] = cost+ans;
        }
    }

    cout<<dp[1][n]<<endl;
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