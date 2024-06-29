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

struct data_dashboard
{
    int sum=0;
    int sqsum=0;
    int cnt=0;
    map<int,int>freq;
    multiset<int>low,high;
    multiset<pair<int,int>>freq_order;

     void balance()
    {
        while (low.size() < high.size())
        {
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while (low.size() > high.size() + 1)
        {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }

    void insert(int x)
    {
        sum+=x;
        cnt++;
        sqsum+=x*x;

        if(freq_order.find(make_pair(freq[x],x))!=freq_order.end())
          {
            freq_order.erase(freq_order.find(make_pair(freq[x],x)));
          }
            freq[x]++;
            freq_order.insert(make_pair(freq[x],x));

        if(low.empty())
        {
            low.insert(x);
        }
        else if(x<=*low.rbegin())
           {
        
            low.insert(x);
           }
        else
        {
            high.insert(x);

        } 
        balance();  
    }

    void remove(int x)
    {
        sum-=x;
        cnt--;
        sqsum-=x*x;

        if(freq_order.find({freq[x],x})!=freq_order.end())
          {
            freq_order.erase(freq_order.find({freq[x],x}));
          }
            freq[x]--;
            freq_order.insert({freq[x],x});



    if(low.find(x)!=low.end())
    {
        low.erase(low.find(x));
    }
    else if(high.find(x)!=high.end())
    {
        high.erase(high.find(x));
    }
    balance();  
    }

    double median()
    {
        return *low.rbegin();
    }
};


void solve()
{
    int k=0,ans=0;
    int n=0,m=0;
    int x=0,y=0;
    int a=0,b=0;
    int c=0,d=0;

    cin>>n>>k;
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

    data_dashboard db;

    rep(i,0,k)
    {
     db.insert(v[i]);
    }
    cout<<db.median()<<" ";

    rep(i,k,n)
    {
        db.insert(v[i]);
        db.remove(v[i-k]);
    cout<<db.median()<<" ";
    }

}
int32_t main()
{
    cout<<setprecision(25);
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