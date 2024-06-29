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

// class prioritize{
//     public : bool operator()(int &p1, int &p2)
//     {
//         return p1.S>p2.S;
//     }
// }; 

int n,m;
vector<int>g[100100];
int vis[100100];
int dis[100100];

void dijkstra(int sc)
{
  rep(i,0,100100)
     {
        vis[i]=0;
        dis[i]=1e18;
     }
  
  

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
    inedge.assign(n+1,0);
    

    rep(i,0,m)
    { 
        int x,y,z;   
        cin>>x>>y>>y;

        g[x].pb({y,z});
        g[y].pb({x,z});
    }

   

   
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

