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


void testcase() {
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1,-1);
    
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int &x : graph[curr]){
            if(vis[x] == -1){
                vis[x] = 1+vis[curr];
                q.push(x);
            }
        }
    }

    if(vis[n] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int curr = n;
    vector<int> ans = {curr};
    while(vis[curr] != 0){
        for(int &x : graph[curr]){
            if(vis[x]+1 == vis[curr]){
                curr = x;
                ans.push_back(curr);
                break;
            }
        }
    }

    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i = 0;i<ans.size();i++){
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