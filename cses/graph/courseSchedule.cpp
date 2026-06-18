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
    int ct = 0;
    vector<vector<int>> graph(n+1),rev(n+1);
    vector<int> indegree(n+1,0);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        rev[v].push_back(u);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
            ct++;
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int &x : graph[curr]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
                ct++;
                ans.push_back(x);
            }
        }
    }

    if(ct == n){
        for(int i = 0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }else{
        impo;

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