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

void solve(int curr,vector<vector<int>> &tree,vector<int> &ans){
    ans[curr] = 1;

    for(int &x : tree[curr]){
        solve(x,tree,ans);
        ans[curr]+=ans[x];
    }
}

void testcase() {
    int n;cin>>n;
    vector<vector<int>> tree(n);
    vector<int> ans(n,0);

    for(int i = 1;i<n;i++){
        int t;cin>>t;
        tree[--t].push_back(i);
    }
    solve(0,tree,ans);

    for(int i = 0;i<n;i++){
        cout<<ans[i]-1<<" ";
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