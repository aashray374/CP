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
    
    
    
    set<vector<int>> s;
    vector<pair<int,int>> dp(n+1,{LLONG_MAX,LLONG_MAX});

    dp[1] = {0,0};
    s.insert({0,0,1});

    while(!s.empty()){
        int curr = (*s.begin())[2];
        s.erase(s.begin());

        for(pair<int,int> &e : graph[curr]){
            vector<int> t = {dp[e.first].first,dp[e.first].second,e.first};
            bool flag = false;

            if(dp[e.first].first>e.second+dp[curr].first){
                flag = true;
                dp[e.first].first = e.second+dp[curr].first;
            }

            if(dp[e.first].second > min(dp[curr].first+e.second/2,dp[curr].second+e.second)){
                flag = true;
                dp[e.first].second = min(dp[curr].first+e.second/2,dp[curr].second+e.second);
            }

            if(flag){
                s.erase(t);
                s.insert({dp[e.first].first,dp[e.first].second,e.first});
            }
        }
    }

    cout<<dp[n].second<<endl;
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