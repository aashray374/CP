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

pair<int,int> solve(int i,int j,vector<int> &v,vector<vector<pair<int,int>>> &dp){
    int used = v.size()-(j-i+1);
    int turn = used%2;
    if(i == j){
        if(turn == 0){
            return {v[i],0};
        }else{
            return {0,v[i]};
        }
    }

    if(dp[i][j].first != -1) return dp[i][j];

    pair<int,int> op1 = solve(i+1,j,v,dp),op2 = solve(i,j-1,v,dp),ans;

    if(turn == 0){
        int a1 = v[i]+op1.first-op1.second,a2 = v[j]+op2.first-op2.second;

        if(a1>a2){
            op1.first+=v[i];
            ans = op1;
        }else{
            op2.first+=v[j];
            ans = op2;
        }
    }else{
        int a1 = op1.first-op1.second-v[i],a2 = op2.first-op2.second-v[j];

        if(a1<a2){
            op1.second+=v[i];
            ans = op1;
        }else{
            op2.second+=v[j];
            ans = op2;
        }
    }

    return dp[i][j] = ans;
}

void testcase() {
    int n;cin>>n;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));

    pair<int,int> ans = solve(0,n-1,v,dp);

    cout<<ans.first-ans.second<<endl;

    
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