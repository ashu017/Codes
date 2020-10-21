ll fa[1000001];
ll inv[1000001];

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
ll fact(){
    fa[0] = 1;
    for(int i=1;i<=1000000;i++){
        fa[i]=(fa[i-1]*i)%mod;
    }
}

ll invfact(){
    inv[0]=1;
    for(int i=1;i<=1000000;i++)
        inv[i]=(inv[i-1]*modex(i,mod-2))%mod;
}

ll ncr(ll n, ll r){
    ll ans=(fa[n]*inv[n-r])%mod;
    ans=(ans*inv[r])%mod;
    return ans;
}
