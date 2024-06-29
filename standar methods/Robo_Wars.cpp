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


void solve()
{
    int k=0,ans=0;
    int n=0,m=0;
    int x=0,y=0;
    int a=0,b=0;
    int c=0,d=0;

    cin>>n;
    vector<int>v;

    // set<int>st;

    // string s;
    // cin>>s;

    rep(i,0,n)
    { 
        int x;   
        cin>>x;   
        v.push_back(x); 
    }

    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {

          st.push(v[i]);
             continue;
        }
        else
        {
            if(st.top()*v[i]>0 || (st.top()<0 && v[i]>0))
              {
                st.push(v[i]);
                continue;
              }
            else
              {
                while(!st.empty() )
                {
                    if(st.top()>abs(v[i]) || st.top()<0)
                    break;

                    // cout<<"pop "<<st.top()<<endl;
                    st.pop();
                }
              }  
          if(!st.empty() && st.top()>abs(v[i]))
             continue;
        //  cout<<"push "<<v[i]<<endl;
          st.push(v[i]);
        } 
        
    }
    cout<<st.size()<<endl;
    vector<int>vv;
    while(!st.empty())
    {
        int u=st.top();
        // cout<<u<<" ";
        vv.push_back(u);
        st.pop();
    }
    reverse(all(vv));
    for(auto x:vv)
    cout<<x<<" ";
    cout<<endl;
       

}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
