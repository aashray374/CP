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

pair<int,pair<int,int>> dfs(vector<pair<int,pair<int,int>>> &ways,vector<vector<pair<int,int>>> &graph,int curr,vector<int> &dist){
    if(ways[curr].first != -1)    return ways[curr];

    int ans = 0,mini = INT_MAX,maxi = INT_MIN;
    for(pair<int,int> &x : graph[curr]){
        if(dist[x.first]-x.second == dist[curr]){
            pair<int,pair<int,int>> res = dfs(ways,graph,x.first,dist);
            ans = (ans+res.first)%M;
            if(res.second.first != INT_MAX){
                mini = min(mini,res.second.first+1);
                maxi = max(maxi,res.second.second+1);
            }
        }
    }

    return ways[curr] = {ans,{mini,maxi}};
}

void testcase() {
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<pair<int,pair<int,int>>> ways(n+1,{-1,{INT_MAX,INT_MIN}});
    vector<int> dist(n+1,LLONG_MAX);
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[v].push_back({u,w});
    }

    ways[1] = {1,{0,0}};
    dist[n] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,n});
    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();

        if(dist[curr.second]<curr.first)    continue;

        for(pair<int,int> &p : graph[curr.second]){
            if(dist[p.first]>curr.first+p.second){
                dist[p.first] = curr.first+p.second;
                pq.push({dist[p.first],p.first});
            }
        }
    }

    auto ans = dfs(ways,graph,n,dist);

    cout<<dist[1]<<" "<<ans.first<<" "<<ans.second.first<<" "<<ans.second.second<<endl;

    // cout<<dfs(ways,graph,n,)<<endl;
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