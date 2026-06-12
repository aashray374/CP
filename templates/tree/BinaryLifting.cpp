#include <bits/stdc++.h>
using namespace std;

class BinaryLifting{
    vector<vector<int>> ancs;
    vector<int> depth;


    void fillParent(vector<vector<int>> &tree,int curr,int parent,vector<int> &v){
        v[curr] = parent;
        if(curr != 0){
            depth[curr] = depth[parent]+1;
        }
        for(int &x : tree[curr]){
            if(x != parent)
                fillParent(tree,x,curr,v);
        }
    }

    void fill(vector<vector<int>> &tree,int curr,int parent,vector<int> &v){
        int p = ancs.back()[curr];
        if(p != -1)
            v[curr] = ancs.back()[p];
        else
            v[curr] = -1;
        for(int &x : tree[curr]){
            if(x != parent)
                fill(tree,x,curr,v);
        }
    }

    void build(vector<vector<int>> &tree){
        int n = tree.size();
        vector<int> temp(n,-1);

        fillParent(tree,0,-1,temp);
        ancs.push_back(temp);

        int curr = 2;
        while(curr<=n){
            fill(tree,0,-1,temp);
            ancs.push_back(temp);
            curr*=2;
        }
    }

    public:
        BinaryLifting(vector<vector<int>> &tree){
            depth.resize(tree.size());
            build(tree);
        }

        int kthAncs(int n,int k){
            if(k == 0)  return n;

            for(int i = 0;i<ancs.size() && n != -1;i++){
                if(k&(1<<i)){
                    n = ancs[i][n];
                }
            }

            return n;
        }

        int lca(int u,int v){
            if(depth[u]<depth[v]){
                swap(u,v);
            }

            u = kthAncs(u,depth[u]-depth[v]);
            if(u == v)  return u;
            
            for(int i = ancs.size()-1;i>=0;i--){
                if(ancs[i][u] != ancs[i][v]){
                    u = ancs[i][u];
                    v = ancs[i][v];
                }
            }

            return ancs[0][u];
        }
};

int main(){
    int n;cin>>n;

    vector<vector<int>> tree(n);

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;tree[u].push_back(v);
        tree[v].push_back(u);
    }

    BinaryLifting* ancs = new BinaryLifting(tree);

    int q;cin>>q;

    while(q--){
        int u,v;cin>>u>>v;
        cout<<(ancs->lca(u,v))<<endl;
    }
}