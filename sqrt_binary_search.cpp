#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int lo=0,hi=n;
    int ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;

        if(mid*mid>=n)
           {
            ans=mid;
            hi=mid-1;
           }
        else
        {
            lo=mid+1;
        } 

        // cout<<mid<<endl;  
    }
    cout<<ans<<endl;
}