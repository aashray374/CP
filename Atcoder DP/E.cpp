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

const int N = 1e5+10;

void testcase() {
    int n,w;
    cin>>n>>w;

    vector<vector<int>> v(n+1,vector<int>(2,0));
    for(int i = 1;i<=n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    
    vector<int> dp(N,INT_MAX);

    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = N-1;j>=0;j--){
            if(j-v[i][1]>=0){
                dp[j] = min(dp[j],dp[j-v[i][1]]+v[i][0]);
            }
        }
    }

    for(int i = N-1;i>=0;i--){
        if(dp[i]<=w){
            cout<<i<<endl;
            return;
        }
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