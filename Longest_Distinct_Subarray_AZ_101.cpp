
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

    int N=5*1e6+1;
void solve(int uu)
{
    vector<int>mp(N,0);
    int n,d,sz=0;
    cin>>n>>d;
    int ans=n+1;
    vector<int>v;
    set<int>st,ss;
    // map<int,int>mp;
    rep(i,0,n)
    {
        int x;
        cin>>x;
        v.pb(x);
        mp[v[i]]=0;
        // st.insert(x);
    }

    // rep(i,0,n)
    //    cout<<mp[v[i]]<<" ";
    //    cout<<endl;

    // int size=st.size();
    rep(i,0,d)
    {
        mp[v[i]]++;
        if(mp[v[i]]==1)
          sz++;

    }
    // if(sz==size)
    ans=min(ans,sz);

    rep(i,d,n)
    {
        mp[v[i]]++;

        if(mp[v[i]]==1)
          sz++;


        mp[v[i-d]]--;

        if(mp[v[i-d]]==0)
          sz--;  
         
    // if(sz==size)/
        ans=min(ans,sz);  
    }
    cout<<ans<<endl;
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
        solve(t);
    }
    return 0;
}

