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
    
    int n,q;cin>>n>>q;

    vector<vector<int>> ancs;
    vector<int> parent(n,-1);

    for(int i = 1;i<n;i++){
        int t;cin>>t;t--;
        parent[i] = t;
    }

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
        int x,k;cin>>x>>k;

        x--;
        for(int i = 0;i<ancs.size() && k!= 0 && x != -1;i++){
            if(((1<<i)&k)){
                x = ancs[i][x];
                k-=(1<<i);
            }
        }

        if(k || x == -1){
            cout<<-1<<endl;
        }else{
            cout<<x+1<<endl;
        }
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