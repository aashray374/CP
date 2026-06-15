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


vector<int> findCycle(vector<vector<int>> &graph,vector<int> &vis,int src,vector<int> &parent,vector<int> &lv){
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int &x : graph[curr]){
            if(vis[x] == 0){
                q.push(x);
                vis[x] = 1;
                parent[x] = curr;
                lv[x] = lv[curr]+1;
            }else if(x != parent[curr]){
                int u = x;
                int v = curr;
                vector<int> ans1,ans2;
                while(u != v){
                    if(lv[u] >= lv[v]){
                        ans1.push_back(u);
                        u = parent[u];
                    }else{
                        ans2.push_back(v);
                        v = parent[v];
                    }
                }
                ans1.push_back(u);
                for(int i = ans2.size()-1;i>=0;i--){
                    ans1.push_back(ans2[i]);
                }
                ans1.push_back(ans1[0]);
                return ans1;
            }
        }
    }

    return {};
}

void testcase() {
    int n,m;cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1,0),lv(n+1,0),parent(n+1,0);
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vector<int>ans = findCycle(graph,vis,i,parent,lv);
            if(ans.size() != 0){
                cout<<ans.size()<<endl;
                for(int i = 0;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    impo;

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