#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define SZ(x) ((int)(x).size())
#define endl "\n"
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
ll mod = 1e9 + 7;
//const double pi = acos(-1.0);
/*
ll kmp(string x)
{
    ll n= x.length();
    //cout<<x<<endl;
    vector<ll> lcp(x.length(), 0);
    for(ll i=1;i<n;i++)
    {
        ll j=lcp[i-1];
        while(j>0 && x[j]!=x[i])
            j=lcp[j-1];
        if(x[i]==x[j])
            j++;
        lcp[i]=j;
    }
    return lcp[n-1];
}

int N = 1000002;
int ar[100002];
void sieve()
{
    for(int i=1;i<=N;i++)
        ar[i] = 1;
    ar[0] = 0;
    for(int i=2;i*i<=N;i++)
    {
        if(ar[i] && i*i<=N)
        {
            for(int j = i*i; j<=N;j+=i)
                ar[j] = 0;
        }
    }
}

ll modex(ll a,ll b){
    if(b<=0){
        return 1;
    }
    if(b%2==0)
    {
        ll x = modex(a, b/2);
        return ((x*x)%mod);
    }
    else
        return ((a%mod * modex(a, b-1))%mod);
}

ll c[1010][1010];

ll combina(ll i, ll j){
        for (int i=0;i<=1005;i++)
        for (int j=0;j<=i;j++)
        {
            if (j==i||j==0)
                c[i][j]=1;
            else
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=mod;
        }
        return c[i][j];
}
void find_fac(int x){
    vector<ll> di;
    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i==0){
            di.push_back(i);
            while(x%i==0)
                x/=i;
        }
    }
    if(x > 1)
        di.push_back(x);
}
*/

struct segtree{
    ll sz = 1;
    vector<ll> ar;
    ll nop = -1;
    void init(ll n){
        while(sz<=n){
            sz*=2;
        }
        ar.resize(2*sz);
    }

    void build(vector<ll> &a, int x, int lx, int rx){
        if(rx-lx==1)
        {
            if(lx<a.size())
                ar[x] = (a[lx]*a[lx]);
            return;
        }
        ll m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        ar[x] = ar[2*x+1] + ar[2*x+2];
    }

    void apply_operation(ll &a, ll b){
        if(b==nop){
            return;
        }
        a = b;
    }

    void lazy_propagate(ll x, ll lx, ll rx){
        if(rx-lx==1)
            return;
        apply_operation(ar[2*x+1], ar[x]);
        apply_operation(ar[2*x+2], ar[x]);
        ar[x] = nop;
    }

    void update(ll l, ll r, ll v, ll x, ll lx, ll rx){
        lazy_propagate(x, lx, rx);
        if(lx>=r || rx<=l)
            return;
        if(lx>=l && rx<=r){
            ar[x] = v;
            return;
        }
        ll m = (lx+rx)/2;
        update(l, r, v, 2*x+1, lx, m);
        update(l, r, v, 2*x+2, m, rx);
    }

    void update(ll l, ll r, ll v){
        update(l, r, v, 0, 0, sz);
    }

    ll get(ll i, ll x, ll lx, ll rx){
        lazy_propagate(x, lx, rx);
        if(rx-lx==1)
            return ar[x];
        ll m = (lx+rx)/2;
        ll s = 0;
        if(i<m)
            s = get(i, 2*x+1, lx, m);
        else
            s = get(i, 2*x+2, m, rx);
        return s;
    }

    ll get(ll i){
        return get(i, 0, 0, sz);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n, m;
        cin>>n>>m;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
            cin>>a[i];
        segtree st;
        st.init(n);
        while(m--){
            ll x;
            cin>>x;
            if(x==1){
                ll l, r, v;
                cin>>l>>r>>v;
                st.update(l, r, v);
            }
            else{
                ll i;
                cin>>i;
                cout<<st.get(i)<<endl;
            }
        }
    }
    return 0;
}
