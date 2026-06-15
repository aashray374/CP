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

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});

    vector<int> dist(n+1,LLONG_MAX);
    dist[1] = 0;

    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();
        
        if(curr.first> dist[curr.second])   continue;

        
        for(pair<int,int> &x : graph[curr.second]){
            if(dist[x.first]>curr.first+x.second){
                pq.push({curr.first+x.second,x.first});
                dist[x.first] = curr.first+x.second;
            }
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<dist[i]<<" ";
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