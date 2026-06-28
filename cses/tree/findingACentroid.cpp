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

void getSubtreeSize(int curr,int parent,vector<vector<int>> &tree,vector<int> &ans){
    ans[curr] = 1;
    for(int &x : tree[curr]){
        if(x != parent){
            getSubtreeSize(x,curr,tree,ans);
            ans[curr]+=ans[x];
        }
    }
}

int solve(int curr,int parent,vector<vector<int>> &tree,vector<int> &size){
    int p = size[0]-size[curr];

    int maxi = p;
    for(int &x : tree[curr]){
        if(x != parent){
            maxi = max(maxi,size[x]);
        }
    }

    if(maxi<=tree.size()/2){
        return curr;
    }

    for(int &x : tree[curr]){
        if(x != parent){
            int res = solve(x,curr,tree,size);
            if(res != -1){
                return res;
            }
        }
    }
    return -1;
}

void testcase() {
    int n;cin>>n;
    vector<vector<int>> tree(n);
    vector<int> size(n,0);
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }

    getSubtreeSize(0,-1,tree,size);
    cout<<solve(0,-1,tree,size)+1<<endl;
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