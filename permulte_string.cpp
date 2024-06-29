#include <bits/stdc++.h>
using namespace std;

    string s;
void permute(string &a,int l,int r)
{
   if(l==r)
     {
        cout<<a<<"  ";
        cout<<s<<endl;
        return ;
     }
   for(int i=l;i<=r;i++)
      {
        swap(a[l],a[i]);
        permute(a,l+1,r);
        swap(a[l],a[i]);

      }  
}

int main()
{
    cin>>s;
    
    permute(s,0,s.length()-1);
}