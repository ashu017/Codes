
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
//#define endl "\n"
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1000000007;
const double pi = acos(-1.0);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    ll t;
    cin>>t;
    while(t--){
        vector<int> dp((1<<20), 0);
        string s;
        cin>>s;
        dp[0]=1;
        int x = 0;
        for(int i=0;i<s.length();i++){
            x ^= (1<<(s[i]-'a'));
            dp[x]++;
        }
        int n = s.length(), an = 0;
        x = 0;
        for(int i=0;i<n;i++){
            dp[x]--;
            an += dp[x];
            for(int j=0;j<20;j++){
                int y = (x^(1<<j));
                an += dp[y];
            }
            x ^= (1<<(s[i]-'a'));
        }
        cout<<an<<endl;
    }
    return 0;
}
