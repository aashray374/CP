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


vector<int> bellman_ford(int n,vector<vector<int>> &edges,int st){
    vector<int> res(n,INT_MAX);

    res[st] = 0;
    for(int i = 0;i<n-1;i++){
        for(vector<int> &e : edges){
            if(res[e[0]] != INT_MAX && res[e[1]] > res[e[0]]+e[2]){
                res[e[1]] = res[e[0]]+e[2];
            }
        }
    }

    for(vector<int> &e : edges){
        if(res[e[0]] != INT_MAX && res[e[1]] > res[e[0]]+e[2]){
            for(int i = 0;i<n;i++){
                res[i] = -1;
            }
            return res;
        }
    }

    return res;
}

void testcase() {
    int n,m;cin>>n>>m;
    
    vector<vector<int>> edges;

    for(int i = 0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<int> ans = bellman_ford(n,edges,0);

    for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    while(t--){
        testcase();
    }

}