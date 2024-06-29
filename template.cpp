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
        a=1;
        rep(i,0,n)
        { 
            // int x;   
            // cin>>x;   
            // v.push_back(x);
            cout<<a<<endl;
            a=a*5; 
        }

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