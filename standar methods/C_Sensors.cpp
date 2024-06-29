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

int n=0,m=0;
vector<string>a;
int vis[1001][1001];
bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m && a[x][y]!='.')
      return true;
      return false;
}

int dx[]={1,-1,0,0,1,-1,-1,1};
int dy[]={1,-1,1,-1,0,0,1,-1};

vector<pair<int,int>> neighbours(int x,int y)
{
    vector<pair<int,int>>v;
    for(int k=0;k<8;k++)
    {
      int xx=x+dx[k];
      int yy=y+dy[k];
      if(valid(xx,yy) && a[xx][yy]!='.')
        v.pb({xx,yy});
    }
    return v;

}


void bfs(int x,int y)
{
  queue<pair<int,int>>q;
//   vis[x][y]=1;
  q.push({x,y});

  while(!q.empty())
  {
    auto cur=q.front();q.pop();

    // if(vis[cur.first][cur.second]==1)continue;
    //    vis[cur.first][cur.second]=1;

    for(auto v:neighbours(cur.first,cur.second))
    {
        if(!vis[v.first][v.second] && a[v.first][v.second]!='.')
        {
            vis[v.first][v.second]=1;
            q.push({v.first,v.second});
        }
    }
  }
}

void solve()
{
    int k=0,ans=0;
    int x=0,y=0;
    // int a=0,b=0;
    int c=0,d=0;

    cin>>n>>m;

    rep(i,0,n)
    { 
        string x;   
        cin>>x;   
        a.push_back(x); 
    }

    rep(i,0,n)
        {
            rep(j,0,m)
               {
                if(a[i][j]=='#' && !vis[i][j])
                  {
                    bfs(i,j);
                    ans++;
                    // cout<<ans<<" ";
                  }
                //   else
                    // cout<<". ";

               }
               cout<<endl;
        }
               cout<<endl;

    // rep(i,0,n)
    //     {
    //         rep(j,0,m)
    //            {
    //             cout<<vis[i][j]<<" ";

    //            }
    //            cout<<endl;
    //     }
    cout<<ans<<endl;    

}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}

// set<int>prime;
//     vector <bool>v(1e6+1,true);
//     v[0]=v[1]=false;

//     for(int i=2;i<1e6+1;i++)
//     {
//         if(v[i])
//         {
//             for(int j=2*i;j<=1e6+1;j=j+i)
//                {
//                 v[j]=false;
//                }
//         }
//     }

//     rep(i,0,1e6+2)
//     {
//         if(v[i])
//         {
//             prime.insert(i*i);
//             // cout<<i*i<<" ";
//         }
//     }

//     if(prime.find(n)!=prime.end())
//       cout<<"YES"<<endl;
//     else
//       cout<<"NO"<<endl;  


// void sieve(int n)
// {
//     vector<int>prime;
//     vector <bool>v(1e6+1,true);
//     v[0]=v[1]=false;

//     for(int i=2;i<1e6+1;i++)
//     {
//         if(v[i])
//         {
//             for(int j=2*i;j<=1e6+1;j=j+i)
//                {
//                 v[j]=false;
//                }
//         }
//     }

//     rep(i,0,1e6+2)
//     {
//         if(v[i])
//         {
//             prime.push_back(i);
//         }
//     }

// }

//  SIEVE
// vector<int>v(100000,1);
    
//     v[0]=v[1]=0;

//     for(int i=2;i<=v.size();i++)
//     {
//         for(int j=i*i;j<=v.size();j+=i)
//         {
//             v[j]=0;
//         }
//     }



// power 
// int power(int a , int n, int m)
// {
//     int res=1;
//    while(n)
//    {
//     if(n%2==0)
//     {
//         res=res*a;
//         n--;
//     }
//     else
//     {
//         a=*a*a;
//         n=n/2;
//     }
//    }

//    return res;
// }