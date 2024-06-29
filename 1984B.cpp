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

int large[5] = {5, 6, 7, 8, 9};

void solve()
{
        int k=0,ans=0;
        // int n=0,m=0;
        int x=0,y=0;
        int a=0,b=0;
        int c=0,d=0;
        bool f = false;

        string s ;
        cin>>s;
        int n = s.size();
 
        string small = "01234";
        string large = "56789";

        if (s.find(small) != string::npos && s.find(large) != string::npos) 
        {
            cout<<"NO"<<endl;
            return;
        }
 
        int ss = 0;
        int bad_tot =35;
        rep(i,0,n-1)
        {
            ss += (s[i] - '0');
            if (s[i] == '0') 
            {
                f = true;
            }
        }
 
        if (s[n-1]=='9' ) 
        {
            cout<<"NO"<<endl;
            return;
        } 
        else if (ss==bad_tot) 
        {
            cout<<"NO"<<endl;
            return;
        } 
        else if (s[0] != '1') 
        {
            cout << "NO" << endl;
            return;
        } 
        else if (n % 10 == 0) 
        {
            cout << "NO" << endl;
            return;
        } 
        else if (f) 
        {
            cout << "NO" << endl;
            return;
        } 
        
            cout << "YES" << endl;
        
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
#include <bits/stdc++.h>
using namespace std;
 
 
