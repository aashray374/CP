#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    int defaultValue;
    vector<int> seg,v;

    int fun(int a,int b){
        return min(a,b);
    }

    void build(int lo,int hi,int ind){
        if(lo == hi){
            seg[ind] = v[lo];
            return;
        }

        int mid = lo+(hi-lo)/2;

        build(lo,mid,2*ind+1);
        build(mid+1,hi,2*ind+2);

        seg[ind] = fun(seg[2*ind+1],seg[2*ind+2]);
    }

    public:
        SegmentTree(vector<int> &v){
            int n = v.size();
            this->v = v;

            seg.resize(4*n+10,defaultValue);

            build(0,n-1,0);
        }

        int query(int lo,int hi,int ind,int l,int r){
            if(lo>r || hi<l){
                return defaultValue;
            }

            if(lo>=l && hi<=r){
                return seg[ind];
            }

            int mid = lo+(hi-lo)/2;

            int left = query(lo,mid,2*ind+1,l,r);
            int right = query(mid+1,hi,2*ind+2,l,r);

            return fun(left,right);
        }

        void pointUpdate(int lo,int hi,int ind,int i,int val){
            if(lo == hi){
                if(lo == i){
                    seg[ind] = val;
                    v[i] = val;
                }
                return;
            }

            if(i<lo || i>hi){
                return;
            }

            int mid = lo+(hi-lo)/2;

            pointUpdate(lo,mid,2*ind+1,i,val);
            pointUpdate(mid+1,hi,2*ind+2,i,val);
        }
};