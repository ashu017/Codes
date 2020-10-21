ll kmp(string x)
{
    ll n= x.length();
    cout<<x<<endl;
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
