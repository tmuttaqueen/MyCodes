#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

intl offset[100];

inline int level( intl n )
{
    int c = -1;
    while(n)
    {
        n >>= 1;
        c++;
    }
    return c;
}

inline intl vertex( intl ind, intl l )
{
    intl x =  ((offset[l] + ind)%(1LL<<l) + (1LL<<l))%(1LL<<l);
    return x + (1LL<<l);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        intl x, k;
        cin >> t;
        if( t == 1 )
        {
            cin >> x >> k;
            intl l = level(x);
            offset[l] -= k;
        }
        else if( t == 2 )
        {
            intl d = 1;
            cin >> x >> k;
            intl l = level(x);
            k %= (1LL<<l);
            for( intl i = l; i <= 61; i++ )
            {
                offset[i] -= d*k;
                d <<= 1;
            }
        }
        else
        {
            cin >> x;
            intl l = level(x);
            intl ind = x - (1LL<<l) - offset[l];
            for( intl i = l; i >= 0; i-- )
            {
                cout << vertex(ind, i) << ' ';
                ind >>= 1;
            }
            cout << "\n";
        }
    }
    return 0;
}
