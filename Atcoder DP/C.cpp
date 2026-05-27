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


// void solve(vector<vector<int>> &v,vector<vector<int>> &dp,int ind){
//     if(ind == v.size()) return;

//     dp[ind][0] = v[ind][0]+max(dp[ind-1][1],dp[ind-1][2]);
//     dp[ind][2] = v[ind][2]+max(dp[ind-1][1],dp[ind-1][0]);
//     dp[ind][1] = v[ind][1]+max(dp[ind-1][0],dp[ind-1][2]);

//     solve(v,dp,ind+1);
// }

void testcase() {
    int n;cin>>n;
    vector<int> v(3,0);
    vector<int> dp(3,0);

    for(int i = 1;i<=n;i++){
        cin>>v[0]>>v[1]>>v[2];
        vector<int> next(3,0);
        next[0] = v[0]+max(dp[1],dp[2]);
        next[1] = v[1]+max(dp[0],dp[2]);
        next[2] = v[2]+max(dp[1],dp[0]);

        dp[0] = next[0];
        dp[1] = next[1];
        dp[2] = next[2];
    }

    cout<<max({dp[0],dp[1],dp[2]})<<endl;
    
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