#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define SZ(x) ((int)(x).size())
#define endl "\n"
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1000000007;
const int INF = 1e9;
const double pi = acos(-1.0);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    ll n;
    cin>>n;
    ll d[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(d[i][k]<INF && d[k][j]<INF)
                    d[i][j] = min(d[i][j], d[k][j] + d[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

