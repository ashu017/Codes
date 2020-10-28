
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

struct node
{
    node *ch[26];
    int in, cn, le;
    node(){
        for(int i=0;i<26;i++)
            ch[i]=NULL;
    }
    node(int x, int y){
        for(int i=0;i<26;i++)
            ch[i]=NULL;
        in = x;
        le = y;
        cn = 1;
    }
};

node* root = new node();
string s;

void insert(int in){
    node* cur = root;
    for(int i=in;i<s.length();i++){
        if(!cur->ch[s[i]-'a']){
            node* te = new node(in, i-in+1);
            cur->ch[s[i]-'a'] = te;
            cur = te;
        }
        else{
            node* te = cur->ch[s[i]-'a'];
            te->cn++;
            cur = te;
        }
    }
}

map<int, vector<int> > mp;

void dfs(node *t)
{
    if(t->cn==1){
        mp[t->le].push_back(t->in);
    }
    for(int i=0;i<26;i++)
    {
        if(t->ch[i]!=NULL)
        {
            dfs(t->ch[i]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++){
        insert(i);
    }
    dfs(root);
    for(auto it=mp.begin();it!=mp.end();it++){
        sort(it->second.begin(), it->second.end());
    }
    int q;
    cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        if(x>mp[y].size()){
            cout<<-1<<endl;
            continue;
        }
        cout<<mp[y][x-1]+1<<endl;
    }
    return 0;
}
