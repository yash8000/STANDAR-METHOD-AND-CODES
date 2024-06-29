#include <bits/stdc++.h>
using namespace std;


// #define int long long
#define rep(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define F first
#define S second
#define vi vector<long long>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"


using state=pair<int,int>;

  int n,m,colour=0,walls_broken;

vector<vector<char>>arr;
vector<vector<int>>vis,dis;
vector<vector<state>>par;
set<pair<int,int>>stt;
string path_seq;

vector<state>vv;


bool bip=true;
 bool valid(int x ,int y)
 {
   if(x>=0 && x<n && y>=0 && y<m )
     return true;
   
     return false;  
 }

 int dx[]={-1,1,0,0};
 int dy[]={0,0,-1,1};
// int dx[]={2,1,-2,-1,-2,-1,2,-1};
// int dy[]={1,-2,1,-2,-1,2,-1,2};
 vector<state> neighbours(state node)
 {
  vector<state>n;
  for(int k=0;k<4;k++)
  {
   int x=node.F+dx[k];
   int y=node.S+dy[k];
   if(valid(x,y))
     {
      n.pb({x,y});
     }
  }
  return n;

 }

void bfs(state st_node)
{
 // vis.clear();
 // dis.clear();
 vis.resize(n,vector<int>(m,0));
 dis.resize(n,vector<int>(m,100));
 par.resize(n,vector<state>(m,{-1,-1}));

 deque<state>q;

  for(auto st_node:vv)
  {
 dis[st_node.F][st_node.S]=0;
 vis[st_node.F][st_node.S]=1;
 par[st_node.F][st_node.S]={-1,-1};
      // cout<<v.F<<" "<<v.S<<endl;
      q.push_front(st_node);
  }
     
//  q.push(st_node);


 while(!q.empty())
 {
  state node=q.front();
//   cout<<node.F<<" "<<node.S<<" "<<dis[node.F][node.S]<<endl;
  q.pop_front();
  for(auto v:neighbours(node))
     {
      if(!vis[v.F][v.S])
      {
            vis[v.F][v.S]=1;
            par[v.F][v.S]=node;

                if(arr[v.F][v.S]!='#' )
                        {
                            q.push_front(v);
                            dis[v.F][v.S]=dis[node.F][node.S];
                            //   dis[v.F][v.S]=dis[node.F][node.S]+1;

                        }
            else if(arr[v.F][v.S]=='#')
                        {
                        dis[v.F][v.S]=dis[node.F][node.S]+1;
                        //    dis[v.F][v.S]=dis[node.F][node.S]+2;
                        q.push_back(v);
                        


                        }
            //  dis[v.F][v.S]=min(dis[node.F][node.S]+1,dis[v.F][v.S]);
      }
     }

 }
 // rep(i,1,n+1)
 // {
 //  cout<<i<<" "<<vis[i]<<" "<<dis[i] <<endl;
 // }

}


void solve()
{

  cin>>n>>m;
  // arr.clear();
  arr.resize(n);

  state st,en;
  rep(i,0,n)
  {
   arr[i].resize(m);
   rep(j,0,m)
   {
   cin>>arr[i][j];
   if(arr[i][j]=='S')
   {
      st={i,j};
      vv.pb(st);
      
   }
   if(arr[i][j]=='F')
      en={i,j};

   }
   
  }
  
  bfs(st);
//   for(auto st:vv)
//   {
//   }


  if(!vis[en.F][en.S])
     cout<<"cannot reach"<<endl;
  else
    {
     cout<<dis[en.F][en.S]<<endl;

     vector<state>path;
     state cur=en;

     while(cur!=make_pair(-1,-1))
     {
      path.pb(cur);
      cur=par[cur.F][cur.S];
      // cout<<cur.F<<" "<<cur.S<<endl;

     } 

     reverse(path.begin(),path.end());
     int prev_x=path[0].first;
     int prev_y=path[0].second;

     for(auto v:path)
     {
        if(v.F>prev_x)
        {
           cout<<"D ";
           path_seq+="D ";
        }
        if(v.F<prev_x)
        {
           cout<<"U ";
           path_seq+="U ";

        }
        if(v.S>prev_y)
        {
           cout<<"R ";
           path_seq+="R ";
            
        }
        if(v.S<prev_y)
        {
           cout<<"L ";
           path_seq+="L ";

        }

        prev_x=v.F;
        prev_y=v.S;
         cout<<v.F<<" "<<v.S<<endl;
         stt.insert({v.F,v.S});
     }
     cout<<endl;
    }







  rep(i,0,n)
     {
      rep(j,0,m)
          {
           if(dis[i][j]!=100)
           cout<<dis[i][j]<<"\t";
           else
           cout<<"--\t";


          }
          cout<<endl;
     }
          cout<<endl;
  rep(i,0,n)
     {
      rep(j,0,m)
          {
            if(stt.find({i,j})!=stt.end() && arr[i][j]=='.')
            cout<<"o ";
            else if(stt.find({i,j})!=stt.end() && arr[i][j]=='#')
            {
             cout<<"x ";
             walls_broken++;
            }
            else
            cout<<arr[i][j]<<" ";


          }
          cout<<endl;
     }
     cout<<endl;
     cout<<path_seq<<endl;
     cout<<"Broke "<<walls_broken<<" walls"<<endl;



   


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