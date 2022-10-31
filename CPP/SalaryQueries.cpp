#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ordered_set s,t;
 
    int n,q;cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        s.insert(v[i]);
    }
    while(q--)
    {
        char x;
        cin>>x;
        if(x=='?')
        {
            int l,r;
            cin>>l>>r;
            
            cout<<s.order_of_key(r+1)-s.order_of_key(l)-(t.order_of_key(r+1)-t.order_of_key(l))<<endl;
 
        }
        else
        {
            int k,i;
            cin>>k>>i;
            k--;
            //cout<<v[k]<<endl;
            
            t.insert(v[k]);
    
            v[k]=i;
            s.insert(v[k]);
        }
        
    }
 
}
