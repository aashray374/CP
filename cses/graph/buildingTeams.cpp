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


bool dfs(int curr,vector<int> &vis,int c,vector<vector<int>> &graph){
    vis[curr] = c;

    for(int &x : graph[curr]){
        if(vis[x] != -1){
            if(vis[x] == c){
                return false;
            }
        }else{
            if(!dfs(x,vis,1-c,graph)){
                return false;
            }
        }
    }


    return true;
}

void testcase() {
    int n,m;cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1,-1);

    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1;i<=n;i++){
        if(vis[i] == -1){
            // cout<<i<<" ";
            if(!dfs(i,vis,0,graph)){
                impo;
                return;
            }
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<vis[i]+1<<" ";
    }
    cout<<endl;
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