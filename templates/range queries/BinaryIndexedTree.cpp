#include <bits/stdc++.h>
using namespace std;

class BIT{
    vector<int> bit;
    int n;
    public:
        BIT(int n){
            bit.resize(n,0);
            this->n = n;
        }

        void update(int i,int x){
            for(;i<n;i+=(i&(-i))){
                bit[i]+=x;
            }
        }

        int sum(int i){
            int ans = 0;
            for(;i>0;i-=(i&(-i))){
                ans+=bit[i];
            }
            return ans;
        }
};