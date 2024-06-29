#include <bits/stdc++.h>
using namespace std;

int source=1,target=3,helper;

void hanoi(int x,int source,int target,int helper)
{
    if(x==1)
    {
      cout<<source<<" "<<target<<endl;
    //   cout<<1<<" from "<<source<<" to "<<target<<endl;
      return ;
    }
 hanoi(x-1,source,helper,target);
//  cout<<x<<" from  "<<source<<" to "<<target<<endl;
 cout<<source<<" "<<target<<endl;
 hanoi(x-1,helper,target,source);
}

int main()
{
    int n;
    cin>>n;
    // cout<<"from : ";
    // cin>>source;

    // cout<<"to : ";
    // cin>>target;
    helper=6-source-target;
    cout<<(1LL<<n)-1<<endl;
    hanoi(n,source,target,helper);
}