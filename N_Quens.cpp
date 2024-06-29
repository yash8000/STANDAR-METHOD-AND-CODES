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
int n;
int queens[10];

bool check(int row,int col)
{
    //check if we can [palce the queen without getting attacked
    for(int pr=0;pr<row;pr++)
       {
        // for every row queens has data which columns has a queen
        int pc=queens[pr];     //(pr,pc) has a queen . check if it attacks at (row,col)
        if( col==pc || abs(col-pc)==abs(row-pr))   // attack hojaye
          return 0;
       }
       return 1;
}

int rec(int level)
{
    //given you have decided [0...level-1] in queens
    // ..explore all   soln 
    //and count them

    //base case
    if(level==n )
    {
      for(int i=0;i<n;i++)
         {
         for(int j=0;j<n;j++)
         {
            if(queens[i]==j)
              {

                cout<<"Q  ";
              }
              else
                cout<<". ";
         }
         cout<<endl;

         }
         cout<<endl;

        
      return 1;  // if till this valid
    }

    //recursive case
    int ans=0;
    for(int ch=0;ch<n;ch++)
        {
            //going through all columns
            if(check(level,ch))
            {
                //move-> place the queen here
                queens[level]=ch;
                // go to next level in recursion
                ans+=rec(level+1);
                // unplace
                queens[level]=-1;
            }
        }
    return ans;    


}

void solve()
{
    cin>>n;
    memset(queens,-1,sizeof(queens));

    cout<<rec(0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
