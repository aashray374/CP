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


vector<vector<int>> mul(vector<vector<int>> &a,vector<vector<int>> &b){
    int n = a.size();

    vector<vector<int>> res(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int ans = 0;
            for(int k = 0;k<n;k++){
                ans = (ans+(a[i][k]*b[k][j])%M)%M;
            }
            res[i][j] = ans;
        }
    }

    return res;
}


vector<vector<int>> bin(vector<vector<int>> &graph,int b){
    int n = graph.size();
    vector<vector<int>> res(n,vector<int>(n,0));

    for(int i = 0;i<n;i++)  res[i][i] = 1;

    while(b){
        if(b&1ll){
            res = mul(res,graph);
        }
        graph = mul(graph,graph);
        b>>=1ll;
    }

    return res;
}

void testcase() {
    int n,k;cin>>n>>k;
    vector<vector<int>> graph(n,vector<int>(n,0));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    vector<vector<int>> res = bin(graph,k);

    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ans = (ans+res[i][j])%M;
        }
    }

    cout<<ans<<endl;
    
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