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

int bellman_ford(int n,vector<vector<int>> &edges,vector<int> &parent){
    vector<int> res(n,0);

    int ans = -1;
    for(int i = 0;i<n;i++){
        ans = -1;
        for(vector<int> &e : edges){
            if(res[e[1]] > res[e[0]]+e[2]){
                res[e[1]] = res[e[0]]+e[2];
                parent[e[1]] = e[0];
                ans = e[1];
            }
        }
    }

    return ans;
}

void testcase() {
    int n,m;cin>>n>>m;

    vector<vector<int>> edges;
    vector<int> parent(n+1,-1);

    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    
    int x = bellman_ford(n+1,edges,parent);

    if(x != -1){
        for(int i = 0;i<n;i++){
            x = parent[x];
        }

        int st = x;
        vector<int> ans;
        ans.push_back(x);
        x = parent[x];

        while(st != x){
            ans.push_back(x);
            x = parent[x];
        }
        ans.push_back(x);

        yes;
        for(int i = ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }else{
        no;
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