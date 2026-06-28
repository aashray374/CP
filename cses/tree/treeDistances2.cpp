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

void precompute(int curr,int parent,vector<vector<int>> &tree,vector<int> &ans,vector<int> &size){

    size[curr] = 1;

    for(int &x : tree[curr]){
        if(x != parent){
            precompute(x,curr,tree,ans,size);
            size[curr]+=size[x];
            ans[curr]+=ans[x]+size[x];
        }
    }

}

void solve(int curr,int parent,vector<vector<int>> &tree,vector<int> &ans,vector<int> &size){
    if(parent != -1)
        ans[curr] = ans[parent]+ans.size()-2*size[curr];

    for(int &x : tree[curr]){
        if(x != parent){
            solve(x,curr,tree,ans,size);
        }
    }
}

void testcase() {
    int n;cin>>n;
    vector<vector<int>> tree(n);
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }

    vector<int> ans(n,0),size(n,0);
    precompute(0,-1,tree,ans,size);
    solve(0,-1,tree,ans,size);

    for(int i = 0;i<n;i++){
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