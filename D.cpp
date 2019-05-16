
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define intl long long

intl s1 = -3e10, s2 = 3e10;
intl mod = 1e9+7;

//find_by_order(int) and order_of_key(int)
typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ors;

ors os;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    intl v;
    intl ans = 1, f = 1;
    intl l = s1, r = s2;
    //os.insert(l);
    //os.insert(r);
    //cout << os.order_of_key(13) << endl;
    while(n--)
    {
        cin >> s >> v;
        if( s[1] == 'D' )
        {
            os.insert(v);
        }
        else
        {
            if( v == l || v == r )
            {
               int d = os.order_of_key(v);
               if( d == 0 )
               {
                   l = s1;
               }
               else
               {
                   l = *os.find_by_order(d-1);
               }
               if( d == os.size()-1 )
                {
                    r = s2;
                }
                else
                {
                    r = *os.find_by_order(d+1);
                }
               os.erase(v);
            }

            else if( v > l && v < r )
            {
                int d = os.order_of_key(v);
                if( d == 0 )
                {
                    l = s1;
                }
                else
                    l = *os.find_by_order(d-1);
                if( d == os.size()-1 )
                {
                    r = s2;
                }
                else
                    r = *os.find_by_order(d+1);
                ans = (ans*2)%mod;

            }
            else
            {
                ans = 0;
            }

        }

    }


    cout << ans << endl;

    return 0;
}
