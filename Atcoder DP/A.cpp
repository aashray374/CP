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


// recurrsion + memo
// int solve(int ind,vector<int> &v,vector<int> &dp){
//     if(ind == v.size()-1) return 0;

//     if(dp[ind] != -1)   return dp[ind];

//     int ans = INT_MAX;
//     for(int i = 1;i<=2;i++){
//         if(ind+i<v.size()){
//             ans = min(ans,abs(v[ind]-v[ind+i])+solve(ind+i,v,dp));
//         }
//     }

//     return dp[ind] = ans;
// }

void testcase() {
    int n;cin>>n;
    vector<int> v(n);

    for(int i = 0;i<n;i++)  cin>>v[i];

    // vector<int> dp(n,0);
    // dp[n-2] = abs(v[n-2]-v[n-1]);
    // for(int i = n-3;i>=0;i--){
    //     dp[i] = min(dp[i+1]+abs(v[i+1]-v[i]),dp[i+2]+abs(v[i+2]-v[i]));
    // }
    // cout<<dp[0]<<endl;


    int next1 = abs(v[n-2]-v[n-1]);
    int next2 = 0;

    for(int i = n-3;i>=0;i--){
        int t = min(next1+abs(v[i+1]-v[i]),next2+abs(v[i+2]-v[i]));
        next2 = next1;
        next1 = t;
    }

    cout<<next1<<endl;
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