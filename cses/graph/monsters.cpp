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

vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
string mo = "UDLR";

bool inGrid(int i,int j,vector<string> &graph){
    return i>=0 && j>=0 && i<graph.size() && j<graph[0].length();
}

void testcase() {
    int n,m;cin>>n>>m;
    
    vector<string> graph(n);
    vector<vector<int>> vis1(n,vector<int>(m,INT_MAX)),vis2(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>> q1,q2;
    for(int i = 0;i<n;i++){
        cin>>graph[i];
        for(int j = 0;j<m;j++){
            if(graph[i][j] == 'M'){
                q1.push({i,j});
                vis1[i][j] = 0;
            }else if(graph[i][j] == 'A'){
                q2.push({i,j});
                vis2[i][j] = 0;
            }
        }
    }

    while(!q1.empty()){
        pair<int,int> curr = q1.front();
        q1.pop();

        for(vector<int> &d : dir){
            int ni = curr.first+d[0],nj = curr.second+d[1];

            if(inGrid(ni,nj,graph) && vis1[ni][nj]>vis1[curr.first][curr.second]+1 && graph[ni][nj] != '#'){
                q1.push({ni,nj});
                vis1[ni][nj] = vis1[curr.first][curr.second]+1;
            }
        }
    }

    while(!q2.empty()){
        pair<int,int> curr = q2.front();
        q2.pop();

        for(vector<int> &d : dir){
            int ni = curr.first+d[0],nj = curr.second+d[1];

            if(inGrid(ni,nj,graph) && vis2[ni][nj]>vis2[curr.first][curr.second]+1 && graph[ni][nj] != '#' && vis1[ni][nj]>vis2[curr.first][curr.second]+1){
                q2.push({ni,nj});
                vis2[ni][nj] = vis2[curr.first][curr.second]+1;
            }
        }  
    }

    queue<pair<int,int>> q;
    for(int i = 0;i<n;i++){
        if(vis2[i][0] != INT_MAX && q.empty()){
            q.push({i,0});
        }
        
        if(vis2[i][m-1] != INT_MAX && q.empty()){
            q.push({i,m-1});
            
        }
    }
    for(int i = 0;i<m;i++){
        if(vis2[0][i] != INT_MAX && q.empty()){
            q.push({0,i});
            
        }
        
        if(vis2[n-1][i] != INT_MAX && q.empty()){
            
            q.push({n-1,i});
        }
    }

    if(q.empty()){
        no;
        return;
    }
    string ans = "";
    yes;
    cout<<vis2[q.front().first][q.front().second]<<endl;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int ni = curr.first+dir[i][0],nj = curr.second+dir[i][1];

            if(inGrid(ni,nj,graph) && vis2[ni][nj]+1 == vis2[curr.first][curr.second]){
                // cout<<mo[i];
                ans.push_back(mo[i]);
                q.push({ni,nj});
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
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