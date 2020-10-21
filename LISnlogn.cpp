void LISNLOGN(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    vector<ll> d(n+1, 1e9);
    d[0] = -1e9;
    for(ll i=0;i<n;i++){
        ll j = upper_bound(d.begin(), d.end(), a[i])-d.begin();
        if(d[j-1]<a[i] && a[i]<d[j])
            d[j] = a[i];
    }
    ll an = 0;
    for(ll i=0;i<=n;i++){
        if(d[i]<1e9)
            an = i;
    }
}
