struct DSU{
    vector<ll> pa, sz;
    DSU(ll n){
        pa.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            pa[i]=i;
            sz[i]=1;
        }
    }

    ll root(ll a){
        if(a==pa[a])
            return a;
        return pa[a] = root(pa[a]);
    }

    void merge(ll x, ll y){
        ll a = root(x), b = root(y);
        if(a!=b){
            if(sz[a]<sz[b])
                swap(a, b);
            pa[b] = a;
            sz[a] += sz[b];
            ex[b] -= ex[a];
        }
    }
};
