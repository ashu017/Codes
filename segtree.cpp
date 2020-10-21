struct item{
    int m, c;
};
struct segtree{
    int sz=1;
    vector<item> va;
    void init(int n){
        while(sz<=n){
            sz*=2;
        }
        va.resize(2*sz);
    }
    item merge(item a, item b){
        if(a.m<b.m)
            return a;
        if(a.m>b.m)
           return b;
        return {a.m, a.c + b.c};
    }
    void build(vector<int> &ar, int x, int lx, int rx){
        if(rx-lx==1)
        {
            if(lx<ar.size())
                va[x] = {ar[lx] , 1};
            else
                va[x] = {INT_MAX, 0};
            return;
        }
        int mi = (lx+rx)/2;
        build(ar, 2*x+1 , lx, mi);
        build(ar, 2*x+2 , mi, rx);
        va[x] = merge(va[2*x+1], va[2*x+2]);
    }
    void build(vector<int> &ar)
    {
        build(ar, 0, 0, sz);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            va[x] = {v, 1};
            return;
        }
        int m = (lx+rx)/2;
        if(i<m)
            set(i, v, 2*x+1, lx, m);
        else
            set(i, v, 2*x+2, m, rx);
        va[x] = merge(va[2*x+1], va[2*x+2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    item calc(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l)
            return {INT_MAX, 0};
        if(lx>=l && rx<=r)
            return va[x];
        int m = (lx + rx)/2;
        item s1 = calc(l, r, 2*x+1, lx, m);
        item s2 = calc(l, r, 2*x+2, m, rx);
        return (merge(s1, s2));
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, sz);
    }
};
