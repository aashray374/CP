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

// int solve(int i,int j,vector<int> &v,vector<vector<int>> &dp){
//     int used = v.size()-(j-i+1);
//     int turn = used%2;
//     if(i == j){
//         if(turn == 0){
//             return v[i];
//         }else{
//             return (-1*v[i]);
//         }
//     }

//     if(dp[i][j] != INT_MIN) return dp[i][j];

//     int op1 = solve(i+1,j,v,dp),op2 = solve(i,j-1,v,dp),ans;

//     if(turn == 0){
//         int a1 = v[i]+op1,a2 = v[j]+op2;

//         if(a1>a2){
//             op1+=v[i];
//             ans = op1;
//         }else{
//             op2+=v[j];
//             ans = op2;
//         }
//     }else{
//         int a1 = op1-v[i],a2 = op2-v[j];

//         if(a1<a2){
//             op1-=v[i];
//             ans = op1;
//         }else{
//             op2-=v[j];
//             ans = op2;
//         }
//     }

//     return dp[i][j] = ans;
// }

// pair<int,int> solve(int i,int j,vector<int> &v,vector<vector<pair<int,int>>> &dp){
//     int used = v.size()-(j-i+1);
//     int turn = used%2;
//     if(i == j){
//         if(turn == 0){
//             return {v[i],0};
//         }else{
//             return {0,v[i]};
//         }
//     }

//     if(dp[i][j].first != -1) return dp[i][j];

//     pair<int,int> op1 = solve(i+1,j,v,dp),op2 = solve(i,j-1,v,dp),ans;

//     if(turn == 0){
//         int a1 = v[i]+op1.first-op1.second,a2 = v[j]+op2.first-op2.second;

//         if(a1>a2){
//             op1.first+=v[i];
//             ans = op1;
//         }else{
//             op2.first+=v[j];
//             ans = op2;
//         }
//     }else{
//         int a1 = op1.first-op1.second-v[i],a2 = op2.first-op2.second-v[j];

//         if(a1<a2){
//             op1.second+=v[i];
//             ans = op1;
//         }else{
//             op2.second+=v[j];
//             ans = op2;
//         }
//     }

//     return dp[i][j] = ans;
// }

void testcase() {
    int n;cin>>n;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    vector<int> dp(n);
    
    // base case length = 1
    for(int i = 0;i<n;i++){
        int turn = n%2;
        if(turn == 0){
            dp[i] = -1*v[i];
        }else{
            dp[i] = v[i];
        }
    }


    for(int len = 2;len<=n;len++){
        vector<int> curr(n,0);
        
        int used = n-len;
        int turn = used%2;
        for(int i = 0;i<n-len+1;i++){
            int j = i+len-1;
            if(turn == 0){
                int op1 = dp[i]+v[j],op2 = dp[i+1]+v[i];
                dp[i] = max(op1,op2);
            }else{
                int op1 = dp[i]-v[j],op2 = dp[i+1]-v[i];
                dp[i] = min(op1,op2);
            }
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