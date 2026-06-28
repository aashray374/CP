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


int solve(int curr,vector<int> &ans,vector<vector<int>> &tree,bool f){

    if(f){
        for(int i = 0;i<ans.size();i++){
            ans[i] = 0;
        }
    }

    vector<int> vis(ans.size(),0);
    queue<int> q;
    q.push(curr);
    vis[curr] = 1;
    int maxi = curr;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int &x : tree[curr]){
            if(vis[x] == 0){
                ans[x] = ans[curr]+1;
                if(ans[x]>ans[maxi]){
                    maxi = x;
                }
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    return maxi;
}

void testcase() {
    int n;cin>>n;
    vector<vector<int>> tree(n);
    vector<int> ans1(n,0),ans2(n,0);
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }

    int endpoint = solve(0,ans1,tree,false);
    int anotherEndpoint = solve(endpoint,ans2,tree,false);
    solve(anotherEndpoint,ans1,tree,true);
    for(int i = 0;i<n;i++){
        cout<<max(ans1[i],ans2[i])<<" ";
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