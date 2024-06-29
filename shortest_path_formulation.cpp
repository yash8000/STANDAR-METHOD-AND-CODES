#include <bits/stdc++.h>
using namespace std;
using ii=pair<int,int>;
using state=pair<int,int>;
#define rep(i,j,n) for(int i=j;i<n;i++)
#define MP make_pair
#define F first
#define S second

vector<vector<pair<int,ii>>>g;
int n,m,k;
int dis[1001][1001];
int vis[1001][1001];
int cost[100005];

void dijkstra(state st)
{
    rep(i,0,n)
       rep(j,0,m)
       {
        
          dis[i][j]=1e9;
          vis[i][j]=0;
       }


    priority_queue<pair<int,state>>pq;
    dis[st.F][st.S]=0;
    pq.push({0,st});

    while(!pq.empty())
    {
        auto val=pq.top();
        pq.pop();

        int cur_dist=-val.F;
        state cur_state=val.S;

        // if(vis[cur_state.F][cur_state.S])continue;
        // vis[cur_state.F][cur_state.S]=1;

        for (auto v:g[cur_state.F])
        {
            if(cur_state.S>=v.S.F)   // cur_state.S--> kitna petroal hai is atate pe mere pass
            {                        //  v.S.F--> neigjbour ke pass jane ke lioye kitna chaiye

                //relax dijkstra  if we have suficient petrol to ggo there
                if(!vis[v.F][cur_state.S-v.S.F] && dis[v.F][cur_state.S-v.S.F]>cur_dist+(0))//will go to v.F
                                                            // fuel wi be reduce bt v.S.F amount
                {
                    dis[v.F][cur_state.S-v.S.F]=cur_dist+(0);
                    pq.push(MP(-dis[v.F][cur_state.S-v.S.F],MP(v.F,cur_state.S-v.S.F)));
                }
            }

            //refill

            // relqx dijkstra
            if(cur_state.S<k)  // to ensure we dont fill beyond capacity
            if(!vis[cur_state.F][cur_state.S+1]  && dis[cur_state.F][cur_state.S+1]>cur_dist+cost[cur_state.F])
            {
                dis[cur_state.F][cur_state.S+1]=cur_dist+cost[cur_state.F];
                pq.push(MP(-dis[cur_state.F][cur_state.S+1],MP(cur_state.F,cur_state.S+1)));  
            }

            
        }
    }
}


void solve()
{
    cin>>n>>m>>k;
    g.resize(n+1);

    for(int i=1;i<=n;i++)
       cin>>cost[i];
    int st_node=1,en_node=n;
    for(int i=0;i<m;i++)
    {
        int p,d;
        int a,b;   //a->b
        cin>>a>>b;
        cin>>p>>d;  // petrol cost , dist 
        g[a].push_back(MP(b,MP(p,d)));        
        g[b].push_back(MP(a,MP(p,d)));        
        
    }
    
    state st={st_node,0};

    dijkstra(st);

    cout<<dis[en_node][0]<<endl;





    

}

int main()
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

}