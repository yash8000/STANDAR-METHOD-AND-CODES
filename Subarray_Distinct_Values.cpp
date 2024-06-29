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

    int n, k;
    vector<int> a;
    map<int, int> mp;
int func()
{
  int l=0,r=0,ans=0,sz=0;
  
  for(int r=0;r<n;r++)
     {
        mp[a[r]]++;
        if(mp[a[r]]==1)
          sz++;

        while(sz>k)
             {
                mp[a[l]]--;
                if(mp[a[l]]==0)
                  sz--;
                l++;
             } 
        ans=ans+r-l+1;      
     }
     cout<<ans<<endl;
}

void solve()
{
    cin >> n >> k;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a.pb(x);
    }

    int tail = 0, head = -1;
    int ans = 0, dist = 0;

    while (tail < n)
    {
        while(head + 1 < n && (dist < k || mp[a[head + 1]] != 0))
        {
            head++;
            mp[a[head]]++;
            if (mp[a[head]] == 1)
                dist++;
        }

        ans += head - tail + 1;

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            mp[a[tail]]--;
            if (mp[a[tail]] == 0)
                dist--;
            tail++;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


