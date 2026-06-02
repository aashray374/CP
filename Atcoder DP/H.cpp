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


void testcase() {
    int n,m;cin>>n>>m;

    vector<string> v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    
    vector<int> curr(m+1,0),prev(m+1,0);
    curr[1] = 1;

    for(int i = 1;i<=n;i++){
        curr[0] = 0;
        for(int j = 1;j<=m;j++){
            if(i == 1 && j == 1)    continue;
            if(v[i-1][j-1] == '.'){
                curr[j] = (prev[j]+curr[j-1])%M;
            }
        }
        for(int i = 0;i<=m;i++){
            prev[i] = curr[i];
            curr[i] = 0;
        }
    }

    cout<<prev[m]<<endl;
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