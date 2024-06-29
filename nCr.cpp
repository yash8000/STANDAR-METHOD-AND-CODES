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
    const int N=1e6;

    vector<int>fact(N),inv_fact(N);
    
    int mod=1e9+7;

    int binpow(int a,int b)
    {
        int res=1;
        while(b)
        {
            if(1LL&b)
               res=(res*a)%mod;
            a=(a*a)%mod;
             
             b=b>>1;
        }
        return res;

    }

    void factorials()
    {
        fact[0]=1;

        for(int i=1;i<=N;i++)
           {
            fact[i]=(i*fact[i-1])%mod;
           }

        inv_fact[N]=binpow(fact[N],mod-2);
        for(int i=N-1;i>=0;i--)
           {
            inv_fact[i]=(inv_fact[i+1]*(i+1))%mod;
           }   
    }

    int nCr(int n,int k)
    {
        if(k>n)
           return 0;
        return (fact[n]*(inv_fact[k]*inv_fact[n-k]%mod))%mod;   
    }
    void solve()
    {
        int n;
        cin>>n;
        factorials();

        for(int j=0;j<=n;j++)
        {
            
        for(int i=0;i<=j;i++)
        {
           cout<<nCr(j,i)<<" ";
           
        //    cout<<binpow(2LL,i)<<" ";
        }
        cout<<endl;
        }
        // cout<<fact[0]<<" "<<fact[1]<<endl;

        for(auto i:fact)
        if(i<10000)
           cout<<i<<" ";
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