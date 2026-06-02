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
    int n;cin>>n;

    vector<double> v(n),curr(n+1,0.0);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    curr[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = i;j>0;j--){
            curr[j] = (curr[j]*(1-v[i-1]))+(curr[j-1]*v[i-1]);
        }
        curr[0] = curr[0]*(1-v[i-1]);

        // prev = curr;
    }
    double ans = 0.0;
    for(int i = (n+1)/2;i<=n;i++){
        ans+=curr[i];
    }

    cout<<setprecision(10)<<ans<<endl;    
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