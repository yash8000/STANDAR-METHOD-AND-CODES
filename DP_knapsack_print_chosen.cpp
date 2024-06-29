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

int n=0,tot=0;
vector<int>w,v;
vector<int>sol;
vector<int>sol_mul;
vector<vector<int>>dp;
vector<vector<int>>dp_mul;

// can take multiple of the same item----------------------------------------------------------
int knapsack_mul(int level,int wt)  // to find what max value can we get givrn the weight
{
    if(level==n)
      {
        return 0 ;
      }

    if(dp_mul[level][wt]!=-1)
      return dp_mul[level][wt];  
    // not choose
    // knapsack(level+1,wt);
    //     choose
    // knapsack(level+1,wt-w[level]);
    int ans=knapsack_mul(level+1,wt);
    
    if(w[level]<=wt)
        ans=max(ans,knapsack_mul(level,wt-w[level])+v[level]);
      

    return dp_mul[level][wt]=ans;

}


int knapsack(int level,int wt)  // to find what max value can we get givrn the weight
{
    if(level==n)
      {
        return 0 ;
      }

    if(dp[level][wt]!=-1)
      return dp[level][wt];  
    // not choose
    // knapsack(level+1,wt);
    //     choose
    // knapsack(level+1,wt-w[level]);
    int ans=knapsack(level+1,wt);
    
    if(w[level]<=wt)
        ans=max(ans,knapsack(level+1,wt-w[level])+v[level]);
      

    return dp[level][wt]=ans;

}

// can take multiple of the same item----------------------------------------------------------
void generate_mul(int level,int wt)
{
    if(level==n)
       {
        return;
       }

    int not_taken=knapsack_mul(level+1,wt);
    if(wt>=w[level]) 
    {
        int taken=knapsack_mul(level,wt-w[level])+v[level];
        
        
        if(taken>not_taken)
        {
            sol_mul.pb(level);
            generate_mul(level,wt-w[level]);
        }
        else
        {
            generate_mul(level+1,wt);

        }
    }  
        else
        {
            generate_mul(level+1,wt);

        }
        
}
void generate(int level,int wt)
{
    if(level==n)
       {
        return;
       }

    int not_taken=knapsack(level+1,wt);
    if(wt>=w[level]) 
    {
        int taken=knapsack(level+1,wt-w[level])+v[level];
        
        
        if(taken>not_taken)
        {
            sol.pb(level);
            generate(level+1,wt-w[level]);
        }
        else
        {
            generate(level+1,wt);

        }
    }  
        else
        {
            generate(level+1,wt);

        }
        
}

void solve() 
{
    int k=0,ans=0;
    int x=0,y=0;
    int a=0,b=0;
    int c=0,d=0;
    
    cin>>n>>tot;

    dp.assign(n+1,vector<int>(tot+1,-1));
    dp_mul.assign(n+1,vector<int>(tot+1,-1));

    rep(i,0,n)
    { 
        int x,y;   
        cin>>x>>y;   
        w.push_back(x); 
        v.push_back(y); 
    }

    cout<<knapsack(0,tot)<<endl;
    cout<<knapsack_mul(0,tot)<<endl;
    generate(0,tot);
    generate_mul(0,tot);
    
    cout<<"IF we can take one item only once : "<<endl;
    cout<<sol.size()<<endl;

    cout<<"values : "<<endl;
    for(auto i:sol)
        cout<<v[i]<<" ";
        cout<<endl;
    cout<<"weights : "<<endl;
    for(auto i:sol)
        cout<<w[i]<<" ";
        cout<<endl;
        cout<<endl;

    cout<<"IF we can take one item multiple times : "<<endl;
    cout<<sol_mul.size()<<endl;

    cout<<"values : "<<endl;
    for(auto i:sol_mul)
        cout<<v[i]<<" ";
        cout<<endl;
    cout<<"weights : "<<endl;
    for(auto i:sol_mul)
        cout<<w[i]<<" ";
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
