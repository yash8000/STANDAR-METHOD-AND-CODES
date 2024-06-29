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
int mod=1e9+7;



void solve()
{
    int n,ans1=0,ans2=0;
    cin>>n;
    vector<int>a(n);
    rep(i,0,n)
       {
        cin>>a[i];
       }

    // rep(i,0,n)
    //    {
    //     rep(j,i,n)
    //        {
    //         ans1+=a[i]^a[j];
    //         ans2+=a[i]&a[j];
    //        }
    //    }
    // cout<<ans1<<endl;   
    // cout<<ans2<<endl;   

    int ans_xor=0,ans_and=0,zero=0,one=0;
    int ans_xor_subset=0,ans_and_subset=0;

    for(int i=0;i<63;i++)
       {
        zero=0,one=0;
           for(int j=0;j<n;j++)
              {
                if(a[j]&(1LL<<i))
                  one++;
                else
                  zero++;  
              }
              ans_xor+=one*zero*(1LL<<i);
              ans_and+=(one*(one-1)/2)*(1LL<<i);
       }
    cout<<ans_xor<<endl;   
    cout<<ans_and<<endl;   
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
