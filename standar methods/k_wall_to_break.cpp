#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define vi vector<long long>
#define vc vector<char>
using state=pair<long long,long long>;

int n,m,k;
char a[100][100];
int vis[100][100];
int dis[100][100];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
vector<vector<state>>par;
vector<state>path;
set<state>stt;

state st,en;

bool valid(int x,int y)
{
   if(x<n && y<m && x>=0 && y>=0  )
     return true;
   return false;  
}

vector<state> neighbours(int x,int y)
{
    vector<pair<int,int>>v;

    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(valid(xx,yy))
           v.pb({xx,yy});
    }
    return v;
}



void solve()
{

    cin>>n>>m;
    par.resize(n,vector<state>(m,{-1,-1}));

    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>a[i][j];
            // cout<<a[i][j]<<" ";
            if(a[i][j]=='S')
              {
                st.first=i;
                st.second=j;
                // par[i][j]=-1;
              }
            if(a[i][j]=='F')
            {
                en.first=i;
                en.second=j;

            }  
                vis[i][j]=0;
                dis[i][j]=100;
        }
    }
    cout<<st.first<<" "<<st.second<<endl;
    cout<<en.first<<" "<<en.second<<endl;

    rep(i,0,n)
    {
        rep(j,0,m)
           {
            cout<<dis[i][j]<<" ";
           }
           cout<<endl;

    }
    deque<pair<int,int>>dq;
    dq.push_front(st);
    dis[st.first][st.second]=0;
    vis[st.first][st.second]=1;
    par[st.first][st.second]={-1,-1};



    while(!dq.empty())
    {
        auto cur=dq.front();
        dq.pop_front();
        
        // if(vis[cur.first][cur.second]==1)continue;
        //    vis[cur.first][cur.second]==1;

        for(auto x: neighbours(cur.first,cur.second))
        {
            if(!vis[x.first][x.second])
            {
                vis[x.first][x.second]=1;
                par[x.first][x.second]=cur;

                if( a[x.first][x.second]!='#')
                    {
                        dis[x.first][x.second]=dis[cur.first][cur.second];
                        dq.push_front({x.first,x.second});
                        par[x.first][x.second]=cur;
                    }
                else if( a[x.first][x.second]=='#')
                    {
                        dis[x.first][x.second]=dis[cur.first][cur.second]+1;
                        dq.push_back({x.first,x.second});
                    }
            }
        }
    }
     
    //path
    state cur=en;
    while(cur!=make_pair(-1LL,-1LL))
     {
      path.pb(cur);
      cur=par[cur.first][cur.second];
      cout<<" h " <<cur.first<<" "<<cur.second<<endl;

     } 

    reverse(path.begin(),path.end());

    for(auto v:path)
    {

      stt.insert({v.first,v.second});
       cout<<v.first<<" "<<v.second<<endl;
    }



    cout<<endl;
    rep(i,0,n)
    {
        rep(j,0,m)
           {
            cout<<dis[i][j]<<" ";
           }
           cout<<endl;

    }
    cout<<endl;

    rep(i,0,n)
    {
        rep(j,0,m)
           {
            if(stt.find({i,j})!=stt.end())
            {
                if(a[i][j]=='.' )
                   cout<<"O ";
                else if(a[i][j]=='#' )
                   cout<<"X ";
                else
                cout<<a[i][j]<<" ";

            }
                else
                cout<<a[i][j]<<" ";
           }
           cout<<endl;

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