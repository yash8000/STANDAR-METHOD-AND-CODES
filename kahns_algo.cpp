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

vector<int>inedge;

vector<int>topo;

void kahn()
{

  priority_queue<int>pq;

  for(int i=1;i<=n;i++)
     {
        if(inedge[i]==0)
          pq.push(-i);
     }

  while(!pq.empty())
        {
            int cur=-pq.top();
            pq.pop();

            topo.pb(cur);
            for(auto v:g[cur])
               {
                inedge[v]--;
                if(inedge[v]==0)
                  pq.push(-v);
               }

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
        int x,y;   
        cin>>x>>y;

        g[x].pb(y);
        inedge[y]++;

        
    }

    kahn();

    // reverse(all(topo));

    if(topo.size()!=n)
      {
        cout<<"IMPOSSILE"<<endl;
      }
      else

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

