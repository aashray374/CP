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


void precompute(){

}

void testcase() {
    int n,q;cin>>n>>q;

    vector<vector<int>> tree(n);
    vector<int> bit1(2*n+1,0),bit2(2*n+1,0),v(n,0),entry(n,0),exit(n,0);
    int total = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        total+=v[i];
    }
    
    for(int i = 0;i<n-1;i++){
        int u,w;cin>>u>>w;
        u--;
        w--;
        tree[u].push_back(w);
        tree[w].push_back(u);
    }

    function<void(int,int)> update1 = [&](int i,int x)->void{
        for(;i<=2*n;i+=(i&-i)){
            bit1[i]+=x;
        }
    };
    
    function<void(int,int)> update2 = [&](int i,int x)->void{
        for(;i<=2*n;i+=(i&-i)){
            bit2[i]+=x;
        }
    };
    int t = 1;
    function<void(int,int)> dfs = [&](int curr,int parent){
        entry[curr] = t++;
        update2(entry[curr],v[curr]);
        for(int &x : tree[curr]){
            if(x != parent){
                dfs(x,curr);
            }
        }
        exit[curr] = t++;
        update1(exit[curr],v[curr]);
    };

    function<int(int)> sum1 = [&](int i) -> int{
        int res = 0;
        for(;i>0;i-=(i&-i)){
            res+=bit1[i];
        }
        return res;
    };
    
    function<int(int)> sum2 = [&](int i) -> int{
        int res = 0;
        for(;i>0;i-=(i&-i)){
            res+=bit2[i];
        }
        return res;
    };

    dfs(0,-1);
    while(q--){
        int type;cin>>type;

        if(type == 1){
            int s,val;cin>>s>>val;
            s--;
            update1(exit[s],val-v[s]);
            update2(entry[s],val-v[s]);
            v[s] = val;
        }else{
            int s;cin>>s;
            s--;
            int a = total-sum2(entry[s]); //jinka entry time zyada hai
            int b = total-sum1(exit[s]-1); // jinka exit time kam hai
            int c = sum1(exit[s])-sum1(entry[s]-1)-v[s]; //subtree
            cout<<b-a+c<<endl;
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