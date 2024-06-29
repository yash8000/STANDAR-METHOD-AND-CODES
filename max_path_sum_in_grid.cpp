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

int a[1001][1001];
int dp[1001][1001];
vector<int>sol;

int path(int i,int j)
{
    if(i<0 || j<0)
      return -1e9;
    if(i==0 && j==0)
      return a[i][j];

    if(dp[i][j]!=-1)                 // upadte : move to a vis[n][n] so dp[x][y] if has ans value -1 if ingrid , does not collide
       return dp[i][j];

    
    int ans=-1e9;
    if(i!=0)    
     ans=max(ans,a[i][j]+path(i-1,j));
    //  ans=a[i][j]+path(i-1,j);    
    if(j!=0)    
     ans=max(ans,a[i][j]+path(i,j-1));

    return dp[i][j]=ans; 



}

void solve()
{
    int k=0,ans=0;
    int n=0,m=0;
    int x=0,y=0;
    // int a=0,b=0;
    int c=0,d=0;

    cin>>n>>m;
    // g.resize(n+1);
    // vis.assign(n+1,0);

    // set<int>st;

    // string s;
    // cin>>s;

    rep(i,0,m)
    { 
        rep(j,0,m)
        {
            cin>>a[i][j];
            dp[i][j]=-1;
        }
        
    }

    ans=path(n-1,m-1);
    cout<<ans<<endl;



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