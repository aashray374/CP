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

void getDepth(vector<vector<int>> &tree,vector<int> &depth,int prev,int curr,int parent,vector<int> &p){
    p[curr] = parent;
    for(int &x : tree[curr]){
        if(x != parent){
            depth[x] = prev+1;
            getDepth(tree,depth,depth[x],x,curr,p);
        }
    }
}

void testcase() {
    
    int n,q;cin>>n>>q;

    vector<vector<int>> ancs,tree(n);
    vector<int> parent(n,-1),depth(n,0);

    for(int i = 1;i<n;i++){
        // int t;cin>>t;t--;
        // parent[i] = t;
        int u,v;cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    getDepth(tree,depth,0,0,-1,parent);
    int curr = 2;
    vector<int> prev = parent;
    ancs.push_back(parent);
    while(curr<n){
        vector<int> temp(n,-1);
        for(int i = 0;i<n;i++){
            if(prev[i] != -1){
                temp[i] = prev[prev[i]];
            }
        }
        ancs.push_back(temp);
        prev = temp;
        curr<<=1;
    }

    while(q--){
        int u,v;cin>>u>>v;
        u--;
        v--;
        int x = u,y = v;
        if(depth[u]<depth[v]){
            swap(v,u);
        }

        int k = depth[u]-depth[v];
        for(int i = 0;i<ancs.size() && k!= 0 && u != -1;i++){
            if(((1<<i)&k)){
                u = ancs[i][u];
                k-=(1<<i);
            }
        }

        if(u == v){
            cout<<abs(depth[x]-depth[y])<<endl;
            continue;
        }
        
        for(int i = ancs.size()-1;i>=0;i--){
            if(ancs[i][u] != ancs[i][v]){
                u = ancs[i][u];
                v = ancs[i][v];
            }
        }
        // cout<<x<<" "<<y<<" "<<u<<endl;
        cout<<depth[x]-depth[parent[u]]+depth[y]-depth[parent[u]]<<endl;
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