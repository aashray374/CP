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


void testcase() {
    int n,m,q;cin>>n>>m>>q;


    vector<vector<int>> dist(n+1,vector<int>(n+1,LLONG_MAX));
    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        dist[u][v] = min(w,dist[u][v]);
        dist[v][u] = min(dist[v][u],w);
    }

    for(int i = 0;i<=n;i++){
        dist[i][i] = 0;
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j)  continue;

                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }


    while(q--){
        int u,v;cin>>u>>v;

        cout<<(dist[u][v] == LLONG_MAX? -1: dist[u][v])<<endl;
    }
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