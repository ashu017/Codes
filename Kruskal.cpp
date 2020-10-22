#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl "\n"

vector<ll> pa, sz;

ll find(int a){
	if(a==pa[a])
		return a;
	return pa[a] = find(pa[a]);
}

void merge(int a, int b){
	if(sz[a]<sz[b]){
		swap(a, b);
	}
	pa[b] = a;
	sz[a] += sz[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	cout.precision(12);
	ll n, m;
	cin>>n>>m;
	pa.resize(n), sz.resize(n);
	for(ll i=0;i<n;i++){
		sz[i]=1;
		pa[i]=i;
	}
	vector<pair<ll, pll> > ed(m);
	for(int i=0;i<m;i++){
		ll x, y, z;
		cin>>x>>y>>z;
		x--, y--;
		ed[i] = {z, {x, y}};
	}
	sort(ed.begin(), ed.end());
	ll an = 0;
	for(ll i=0;i<m;i++){
		ll a = find(ed[i].second.first), b = find(ed[i].second.second);
		if(a!=b){
			merge(a, b);
			an += ed[i].first;
		}
	}
	cout<<an;
}


