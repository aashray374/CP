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

class DSU{
    vector<int> parent,size;
    int findParent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }

    public:
        int components,maxi = 1;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            components = n;
            maxi = 1;

            for(int i = 1;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        bool join(int a,int b){
            a = findParent(a);
            b = findParent(b);

            if(a == b)  return false;

            if(size[a]<size[b]){
                parent[a] = b;
                size[b]+=size[a];
            }else{
                parent[b] = a;
                size[a]+=size[b];
            }

            components--;
            maxi = max({maxi,size[a],size[b]});
            return true;
        }

};

void testcase() {
    int n,m;cin>>n>>m;

    DSU* d = new DSU(n);
    for(int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        d->join(u,v);
        cout<<(d->components)<<" "<<(d->maxi)<<endl;
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