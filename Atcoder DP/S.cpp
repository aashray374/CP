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

int solve(string &s,int )

void testcase() {
    string s;int d;

    cin>>s>>d;


    vector<vector<vector<int>>> dp(s.length(),vector<vector<int>>(d,vector<int>(2,-1)));

    // prefix summed base case for 0 digits taken
    // vector<vector<int>> dp(2,vector<int>(d,1));

    // for(int i = 0;i<s.length();i++){
    //     vector<vector<int>> curr(2,vector<int>(d,0));
    //     int ub = s[i]-'0';
    //     for(int mod = 0;mod<d;mod++){
            
    //         // tight 
    //         for(int digit = 0;digit<ub;digit++){
    //             int l = mod,r = (mod+digit)%d;
    //             int sum = 0;
    //             if(r>=l){
    //                 if(l!=0){
    //                     sum = dp[r][0]-dp[l-1][0];
    //                 }else{
    //                     sum = dp[r][0];
    //                 }
    //             }
    //         }


    //         //loose
    //     }
    // }
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