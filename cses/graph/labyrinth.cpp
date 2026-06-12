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

vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
vector<char> ops = {'L','R','U','D'}; 
bool inGraph(int i,int j,vector<string> &graph){
    return i>=0 && j>=0 && i<graph.size() && j<graph[0].length();
}


void testcase() {
    int n,m;cin>>n>>m;

    int di = -1,dj = -1;
    vector<string> graph(n);
    vector<vector<int>> vis(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for(int i = 0;i<n;i++){
        cin>>graph[i];
        for(int j = 0;j<m && (q.empty() || di == -1);j++){
            char ch = graph[i][j];
            if(ch == 'A'){
                q.push({i,j});
                vis[i][j] = 0;
            }else if(ch == 'B'){
                di = i;
                dj = j;
            }
        }
    }

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        for(vector<int> &d : dir){
            int ni = curr.first+d[0],nj = curr.second+d[1];
            if(inGraph(ni,nj,graph) && vis[ni][nj] == -1 && graph[ni][nj] != '#'){
                vis[ni][nj] = vis[curr.first][curr.second]+1;
                q.push({ni,nj});
            }
        }
    }
    if(vis[di][dj] == -1){
        no;
        return;
    }
    string ans = "";
    while(vis[di][dj] != 0){
        for(int i = 0;i<4;i++){
            int ni = di+dir[i][0],nj = dj+dir[i][1];

            if(inGraph(ni,nj,graph) && vis[ni][nj]+1 == vis[di][dj]){
                di = ni;dj = nj;
                ans.push_back(ops[i]);
                break;
            }
        }
    }

    reverse(ans.begin(),ans.end());
    yes;
    cout<<ans.length()<<endl<<ans<<endl;
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