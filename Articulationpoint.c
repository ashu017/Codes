ll n, m;

vector<ll> vi, in, lo;
ll ti;

void dfs(ll x, ll p, vvl &gr, set<pair<ll, ll> > &st){
    vi[x]=1;
    in[x] = lo[x] = ti;
    ti++;
    for(auto i:gr[x]){
        if(i==p){
            continue;
        }
        if(vi[i]){
            lo[x] = min(lo[x], in[i]);
        }
        else{
            dfs(i, x, gr, st);
            if(in[x]<lo[i])
            {
                if(i>x)
                    st.insert({x+1, i+1});
                else
                    st.insert({i+1, x+1});
            }
            lo[x] = min(lo[x], lo[i]);
        }
    }
}
