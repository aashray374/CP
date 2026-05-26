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
// int solve(int ind,vector<int> &v,vector<int> &dp,int k){
//     if(ind == v.size()-1) return 0;

//     if(dp[ind] != -1)   return dp[ind];

//     int ans = INT_MAX;
//     for(int i = 1;i<=k;i++){
//         if(ind+i<v.size()){
//             ans = min(ans,abs(v[ind]-v[ind+i])+solve(ind+i,v,dp,k));
//         }else{
//             break;
//         }
//     }

//     return dp[ind] = ans;
// }

void testcase() {
    int n,k;cin>>n>>k;
    vector<int> v(n);

    for(int i = 0;i<n;i++)  cin>>v[i];

    // vector<int> dp(n,INT_MAX);
    // dp[n-1] = 0;
    // for(int i = n-2;i>=0;i--){
    //     for(int j = 1;j<=k;j++){
    //         if(i+j<n){
    //             dp[i] = min(dp[i],abs(v[i+j]-v[i])+dp[j+i]);
    //         }else{
    //             break;
    //         }
    //     }
    // }
    // cout<<dp[0]<<endl;


    vector<int> dp(k+1,INT_MAX);
    dp[1] = 0;
    for(int i = n-2;i>=0;i--){
        int t = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(i+j<n){
                t = min(t,abs(v[i+j]-v[i])+dp[j]);
            }else{
                break;
            }
        }

        dp[0] = t;
        for(int j = k;j>0;j--){
            dp[j] = dp[j-1];
        }
    }
    cout<<dp[0]<<endl;
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