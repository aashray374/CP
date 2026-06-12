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
    vector<int> vis(n+1,0);
    vector<int> sol;

    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1;i<=n;i++){
        if(vis[i] != 0) continue;

        sol.push_back(i);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int curr = q.front();q.pop();

            for(int &x : graph[curr]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }

    cout<<sol.size()-1<<endl;
    for(int i = 1;i<sol.size();i++){
        cout<<sol[0]<<" "<<sol[i]<<endl;
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