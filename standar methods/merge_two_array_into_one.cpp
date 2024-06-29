#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,j,n) for(int i=j;i<n;i++)


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>sol;
    vector<int>a(n),b(m);
    rep(i,0,n)
       cin>>a[i];
    rep(i,0,m)
       cin>>b[i];
    
    int i=0,j=0;
    // cout<<a[0]<<" "<<b[0]<<endl;
    while(i<n && j<m)
    {
        // cout<<a[i]<<" "<<b[j]<<endl;
        // cout<<"sol : "<<endl;
            // for(int x:sol)
            //     cout<<x<<" ";
            //     cout<<endl;     

            if(a[i]==b[j])
            {
        // cout<<"same"<<" "<<b[j]<<endl;
                if(sol.size()!=0 && sol.back()==a[i])
                   {
                    i++;
                    j++;
                   }
                else
                   {
                    sol.push_back(a[i]);
                    i++;
                    j++;
                   }  
            }
            else if(a[i]>b[j])
               {
        // cout<<"diss"<<" "<<b[j]<<endl;
                sol.push_back(b[j]);
                    j++;
               }   
            else if(a[i]<b[j])
               {
        // cout<<"diff"<<" "<<b[j]<<endl;
                sol.push_back(a[i]);
                i++;
               }   
    }

    while(i<n)
        {
            sol.push_back(a[i]);
            i++;
        }
    while(j<m)
        {
            sol.push_back(b[j]);
            j++;
        }
    
    

    for(int x:sol)
        cout<<x<<" ";
        cout<<endl;     

}