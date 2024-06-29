#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define vi vector<long long>
#define vc vector<char>
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

vector<vector<int>>g;
int n,m;

vector<int>vis;

vector<int>topo;

void dfs(int node)
{
    vis[node]=1;
    for(auto v:g[node])
       {
        if(!vis[v])
           {
            dfs(v);
           }
       }
    topo.pb(node);   
}

void solve()
{
    int k=0,ans=0;
    // int n=0,m=0;
    int x=0,y=0;
    int a=0,b=0;
    int c=0,d=0;

    cin>>n>>m;
    vector<int>v;
    g.resize(n+1);
    vis.assign(n+1,0);
    

    rep(i,0,n)
    { 
        int x,y;   
        cin>>x>>y;

        g[x].pb(y);   
        
    }

    for(int i=1;i<=n;i++)
       {
        if(!vis[i])
           {
            dfs(i);
           }
       }

    reverse(all(topo));

    for(auto v:topo)
       cout<<v<<" ";
       cout<<endl;   

}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

