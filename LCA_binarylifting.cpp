#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define SZ(x) ((int)(x).size())
#define endl "\n"
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll mod = 1000000007;
const double pi = acos(-1.0);

int n, m, ti = 0;
vvi gr, lc;
vector<int> in, ou;
vector<int> dp, le;

int dfs(int x, int p, int h){
    in[x] = ti++;
    lc[x][0] = p;
    le[x] = h;
    for(int i=1;i<=m;i++){
        lc[x][i] = lc[lc[x][i-1]][i-1];
    }
    int s = 1;
    for(auto i:gr[x]){
        if(i!=p){
            s += dfs(i, x, h+1);
        }
    }
    dp[x] = s;
    ou[x] = ti++;
    return s;
}

bool isancestor(int x, int y)
{
    if(in[x]<=in[y] && ou[x]>=ou[y])
        return 1;
    return 0;
}

int lca(int x, int y){
    if(isancestor(x, y))
        return x;
    if(isancestor(y, x))
        return y;
    for(int i=m;i>=0;i--){
        if(!isancestor(lc[x][i], y))
            x = lc[x][i];
    }
    return lc[x][0];
}

int mid(int x, int di){
    for(int i=m;i>=0;i--){
        if((1<<i)&di)
            x = lc[x][i];
    }
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(15);
    cin>>n;
    gr.resize(n), ou.resize(n), in.resize(n), dp.resize(n), le.resize(n);
    m = ceil(log2(n));
    lc.resize(n, vector<int> (m+1));
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        x--, y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    int to = dfs(0, 0, 0);
    int q;
    cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        x--;y--;
        if(x==y)
        {
            cout<<n<<endl;
            continue;
        }
        int r = lca(x, y);
        int d1 = le[x]-le[r], d2 = le[y]-le[r];
        //cout<<d1<<" "<<d2<<endl;
        if((d1+d2)%2==0)
        {
            int re = (d1+d2)/2, an;
            if(d1==d2){
                int x1=mid(y, re-1);
                int x2 = mid(x, re-1);
                an = n - dp[x1] - dp[x2];
            }
            else if(d1<d2){
                int mi = mid(y, re);
                int x1 = mid(y, re-1);
                //cout<<mi<<" "<<x1<<endl;
                an = dp[mi]-dp[x1];
            }
            else{
                int mi = mid(x, re);
                int x2 = mid(x, re-1);
                an = dp[mi] - dp[x2];
            }
            cout<<an<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
