struct DSU{
    vector<int> pa;
    vector<int> sz;
    DSU(int n){
        pa.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            pa[i] = i;
            sz[i] = 1;
        }
    }
    int root(int i){
        while(pa[i]!=i)
        {
            i = pa[i];
        }
        return i;
    }
    void merge(int a, int b){
        int root_a = root(a);
        int root_b = root(b);
        if(root_a!=root_b){
            if(sz[root_a]<sz[root_b]){
                pa[root_a] = root_b;
                sz[root_b] += sz[root_a];
                sz[root_a] = 0;
            }
            else{
                pa[root_b] = root_a;
                sz[root_a] += sz[root_b];
                sz[root_b] = 0;
            }
        }
    }
};
