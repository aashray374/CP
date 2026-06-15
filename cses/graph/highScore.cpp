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
    int n,m;cin>>n>>m;

    vector<vector<int>> edges;
    unordered_set<int> mp;
    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({u,v,-w});
        if(v == n){
            mp.insert(u);
        }
    }
    // cout<<mp.size()<<endl;

    vector<int> dist(n+1,LLONG_MAX),rev(n+1,LLONG_MAX);
    dist[1] = 0;
    rev[n] = 0;
    for(int i = 0;i<n-1;i++){
        for(vector<int> &e : edges){
            if(dist[e[0]] != LLONG_MAX && dist[e[1]]>dist[e[0]]+e[2]){
                dist[e[1]] = dist[e[0]]+e[2];
            }
            if(rev[e[1]] != LLONG_MAX && rev[e[0]]>rev[e[1]]+e[2]){
                rev[e[0]] = rev[e[1]]+e[2];
            }
        }
    }
    
    int ans = dist[n];
    
    for(vector<int> &e : edges){
        if(dist[e[0]] != LLONG_MAX && dist[e[1]]>dist[e[0]]+e[2]){
            dist[e[1]]=dist[e[0]]+e[2];
            if(rev[e[1]] != LLONG_MAX){
                cout<<-1<<endl;
                return;
            }
        }
    }
    
    // for(int i = 1;i<=n;i++){
    //     cout<<dist[i]<<" "<<rev[i]<<endl;;
    // }
    // cout<<endl;
    // if(dist[n]<ans){
    //     cout<<-1<<endl;
    // }else{
        // }
    cout<<(-ans)<<endl;
    
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