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


pair<int,int> solve(vector<vector<int>> &graph,int curr,int parent){
    if(graph[curr].size() == 1) return {1,1};

    pair<int,int> ans = {1,1};
    for(int &x : graph[curr]){
        if(x != parent){
            pair<int,int> p = solve(graph,x,curr);

            ans.first = ((ans.first)*(p.first+p.second)%M)%M;
            ans.second = (ans.second * p.first)%M;
        }
    }

    return ans;
}

void testcase() {
    int n;cin>>n;

    vector<vector<int>> graph(n+1);

    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    graph[1].push_back(0);
    graph[0].push_back(1);

    pair<int,int> ans = solve(graph,1,0);

    cout<<(ans.first+ans.second)%M<<endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    // cin>>t;
    // precompute();
    while(t--){
        testcase();
    }

}