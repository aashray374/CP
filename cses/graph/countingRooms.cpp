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


void precompute(){

}

vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

bool inGraph(int i,int j,vector<string> &graph){
    return i>=0 && j>=0 && i<graph.size() && j<graph[0].length();
}

void dfs(vector<string> &graph,int i,int j,vector<vector<int>> &vis){
    vis[i][j] = 1;

    for(vector<int> &d : dir){
        int ni = d[0]+i,nj = d[1]+j;

        if(inGraph(ni,nj,graph) && !vis[ni][nj] && graph[ni][nj] == '.'){
            dfs(graph,ni,nj,vis);
        }
    }
}

void testcase() {
    int n,m;cin>>n>>m;

    vector<string> graph(n);
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        cin>>graph[i];
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(graph[i][j] == '.' && !vis[i][j]){
                dfs(graph,i,j,vis);
                ans++;
            }
        }
    }

    cout<<ans<<endl;
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