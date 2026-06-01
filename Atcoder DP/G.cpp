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


int dfs(vector<vector<int>> &graph,int i,vector<int> &vis){
    if(vis[i] != 0){
        return vis[i];
    }

    if(graph[i].size() == 0){
        return 1;
    }

    for(int &x : graph[i]){
        vis[i] = max(vis[i],1+dfs(graph,x,vis));
    }

    return vis[i];
}


void testcase() {
    int n,m;cin>>n>>m;

    vector<vector<int>> graph(n+1);
    
    vector<int> vis(n+1,0),indegree(n+1,0);
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    // queue<int> q;

    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            ans = max(ans,dfs(graph,i,vis)-1);
        }
    }

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