#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;

// Based on the formula F(2*n) = F(n)*[2*F(n+1) - F(n)] and F(2*n+1) = F(n)*F(n) + F(n+1)*F(n+1)

//Derivation:
//    https://math.stackexchange.com/a/3270571

ll an[2] = {0};

void solve(ll n){
    if(n==0){
        an[0] = 0, an[1] = 1;
        return ;
    }
    solve(n/2);
    ll a = an[0]; // an[0] = F(n)
    ll b = an[1]; //an[1] = F(n+1)
    ll c = (2*b - a + mod)%mod;
    c = (c * a)%mod; // F(2*n)
    ll d = (a*a + b*b)%mod; // F(2*n + 1)
    if(n%2==0){
        an[0] = c;
        an[1] = d;
    }
    else{
        an[0] = d;
        an[1] = (c + d)%mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        an[0] = 0, an[1] = 0;
        solve(n);
        cout<<an[0]<<endl;
    }
    return 0;
}

