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

//    Masked pop-count
//    https://atcoder.jp/contests/abc356/tasks/abc356_d

int masked_pop_count(int n,int m)
{
     int ans = 0;
    n++;
    for(int i = 0; i < 63; i++)
    {
        if(m & (1LL<<i))
        {

        int full = n / (1LL << (i + 1));
        int rem = n % (1LL << (i + 1));
        int extra = max(rem - (1LL << i), 0LL);
        ans = (ans+full * (1LL << i) + extra)%998244353;
        }
    }
    return ans;
}
void solve_masked_popcount()
{
    int n,m;
    cin >> n>>m;
    // rep(i, 0, n)
    // {
    //     cout << i + 1 << " : " << count_1_bits_till(i + 1) << endl;
    //     // cout<<i<<" : "<<(1ULL<<i)<<endl;
    // }

    cout<<masked_pop_count(n,m);



}


int count_1_bits_till(int x)
{
    int ans = 0;
    x++;
    for(int i = 0; i < 63; i++)
    {
        int full = x / (1LL << (i + 1));
        int rem = x % (1LL << (i + 1));
        int extra = max(rem - (1LL << i), 0LL);
        ans += full * (1LL << i) + extra;
    }
    return ans;
}

int find_kth_one(int k)
{
    int lo=0,hi=k,ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(count_1_bits_till(mid)>=k)
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
}

int find_kth_one_pos_in_number(int x,int k)   // given binary number find the post of kth one in it
{
    int c=0;
    
    string s="";
    while(x)
    {
        if(x%2)
          s+='1';
        else
          s+='0';
        x=x/2;  
    }
    reverse(all(s));
    cout<<s<<endl;
    for(int i=0;i<s.length();i++)
       {
        // cout<<s[i];
        if(s[i]=='1')
          c++;
        if(c==k)
        {
            cout<<endl;
           return i;  

        }
       }
       return x;

}

int count_all_bits_till_given_number(int x)
{
    int num=1;
    int len=1;
    int ans=0;
    

    while(num<=x)
    {
           int sametill=(2*num)-1;
           if(sametill<=x)
           {

             ans+=len*(sametill-num+1);
             num=sametill+1;
             len++;
           }
           else
           {
            ans+=(len)*(x-num+1);
            break;
           }
        //    sametill=sametill<<1;
    }
    return ans+1;
}
void solve()
{
    int n,m;
    cin >> n; // we have to find when the n_th one comes
    // rep(i, 0, n)
    // {
    //     cout << i + 1 << " : " << count_1_bits_till(i + 1) << endl;
    //     // cout<<i<<" : "<<(1ULL<<i)<<endl;
    // }
    int num=find_kth_one(n);   //number which has the nth one


    cout<<num<<endl;  
    int index=n-count_1_bits_till(num-1);   //index of the kth one in the number which has kth one
    cout<<index<<endl;
    //                                                          index ->      1 23 45 67     8    ans=>8
    //now we ned to find sum of all bits ocurring befor the needed one eg-->  0 01 10 11 __ [1]00
    //                                                                           1 2  34     5   [the fith one]
    
    int pos=find_kth_one_pos_in_number(num,index);
    cout<<"pos of "<<index<<" th 1 in  "<<num<<" : "<<pos<<endl;
    int all_bits_before=count_all_bits_till_given_number(num-1)+1;
    cout<<all_bits_before<<endl;

    //ans
    cout<<all_bits_before+index<<endl;                                                                          

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
