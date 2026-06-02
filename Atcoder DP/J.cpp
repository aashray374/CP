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

int n;

double solve(int o1,int o2,int o3,vector<vector<vector<double>>> &dp){
    if(o1<0 || o2<0 || o3<0)    return 0.0;


    if(o1 == 0 && o2 == 0 && o3 == 0)   return 0;


    if(dp[o1][o2][o3] != -1.0)  return dp[o1][o2][o3];

    double ans = 1.0*n/(o1+o2+o3);
    ans+=(solve(o1-1,o2,o3,dp))*o1/(o1+o2+o3);
    ans+=(solve(o1+1,o2-1,o3,dp))*o2/(o1+o2+o3);
    ans+=(solve(o1,o2+1,o3-1,dp))*o3/(o1+o2+o3);

    return dp[o1][o2][o3] = ans;
}

void testcase() {
    cin>>n;

    int o1 = 0,o2 = 0,o3 = 0;

    int t;
    for(int i = 0;i<n;i++){
        cin>>t;
        if(t == 1)  o1++;
        if(t == 2)  o2++;
        if(t == 3)  o3++;
    }
    
    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(o2+o3+1,vector<double>(o3+1,-1.0)));

    cout<<setprecision(10)<<solve(o1,o2,o3,dp)<<endl;
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