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

// int solve(string &s,string &t,vector<vector<int>> &dp,int i,int j){
//     if(i == s.length() || j == t.length())  return 0;

//     if(dp[i+1][j+1] != -1)  return dp[i+1][j+1];

//     int ans = max(solve(s,t,dp,i+1,j),solve(s,t,dp,i,j+1));
//     if(s[i] == t[j]){
//         ans = max(ans,solve(s,t,dp,i+1,j+1)+1);
//     }

//     return dp[i+1][j+1] = ans;
// }

void testcase() {
    string s,t;
    cin>>s>>t;

    int n = s.length(),m = t.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    string ans = "";
    ans.reserve(dp[n][m]);
    int curr = dp[n][m]-1;

    int i = n,j = m;

    while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    reverse(ans.begin(),ans.end());
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