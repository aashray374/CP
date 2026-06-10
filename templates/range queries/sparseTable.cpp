#include <bits/stdc++.h>
using namespace std;

class SparseTree{
    vector<vector<int>> tree;

    int fun(int a,int b){
        return min(a,b);
    }

    void build(vector<int> &v){
        tree.push_back(v);
        int curr = 2;
        while(curr<=(int)v.size()){
            vector<int> temp;
            for(int i = 0;i<=(int)v.size()-curr;i++){
                temp.push_back(fun(tree.back()[i],tree.back()[i+(curr)/2]));
            }
            tree.push_back(temp);
            curr*=2;
        }
    }

    public:
        SparseTree(vector<int> &v){
            build(v);
        }

        int query(int l,int r){
            int len = r-l+1;
            len = pow(2,(int)log2(len));

            return fun(tree[log2(len)][l],tree[log2(len)][r-len+1]);
        }
};
