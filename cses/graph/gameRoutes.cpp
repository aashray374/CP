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
#define impo cout<<"IMPOSSIBLE"<<endl;
#define log logl
const int M = 1e9+7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


void precompute(){

}

int dfs(vector<int> &ways,vector<vector<int>> &graph,int curr){
    if(ways[curr] != -1)    return ways[curr];

    int ans = 0;
    for(int &x : graph[curr]){
        ans = (ans+dfs(ways,graph,x))%M;
    }

    return ways[curr] = ans;
}

void testcase() {
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> ways(n+1,-1);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[v].push_back(u);
    }

    ways[1] = 1;
    cout<<dfs(ways,graph,n)<<endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    // cin>>t;
    precompute();
    while(t--){
        testcase();
    }

}