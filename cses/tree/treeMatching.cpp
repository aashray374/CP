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

pair<int,int> solve(int curr,int parent,vector<vector<int>> &tree){

    pair<int,int> ans = {0,0};  //include,not include
    int maxi = INT_MIN;
    bool f = false;
    for(int &x : tree[curr]){
        if(x != parent){
            f = true;
            pair<int,int> res = solve(x,curr,tree);
            ans.second+=max(res.second,res.first);
            maxi = max(maxi,res.second-max(res.second,res.first));
        }
    }

    if(f){
        ans.first = 1+maxi+ans.second;
    }

    return ans;
}

void testcase() {
    int n;cin>>n;
    vector<vector<int>> tree(n);

    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }
    pair<int,int> ans = solve(0,-1,tree);

    cout<<max(ans.first,ans.second)<<endl;
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