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


void floydWarshall(vector<vector<int>> &dist){
    
    for(int k = 0;k<dist.size();k++){
        for(int i = 0;i<dist.size();i++){
            for(int j = 0;j<dist.size();j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

void testcase() {
    int n,m;cin>>n>>m;
    
    vector<vector<int>> graph(n,vector<int>(n,INT_MAX));

    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u][v] = min(graph[u][v],w);
    }

    floydWarshall(graph);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    while(t--){
        testcase();
    }

}