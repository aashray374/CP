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
    int n,m,k;cin>>n>>m>>k;

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
    }

    vector<priority_queue<int>> dist(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();

        if(dist[curr.second].size() == k && dist[curr.second].top()<curr.first){
            continue;
        }

        for(pair<int,int> &e : graph[curr.second]){
            if(dist[e.first].size()<k){
                pq.push({e.second+curr.first,e.first});
                dist[e.first].push(e.second+curr.first);
            }else{
                if(dist[e.first].top()>e.second+curr.first){
                    dist[e.first].pop();
                    pq.push({e.second+curr.first,e.first});
                    dist[e.first].push(e.second+curr.first);
                }
            }
        }
    }

    vector<int> ans;
    while(!dist[n].empty()){
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    for(int i = k-1;i>=0;i--){
        cout<<ans[i]<<" ";
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