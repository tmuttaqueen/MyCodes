#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, q;
    cin >> n >> q;
    intl ara[100];
    intl c = 1, pow;
    for( int i = 0; ; i++ )
    {
        ara[i] = c;
        if( c == n+1 )
        {
            pow = i;
            break;
        }
        c*=2;
    }
    intl nop = n/2;
    string s;
    //what_is(pow);

    for( int i = 0; i < q; i++ )
    {
        intl cur;
        cin >> cur;
        cin >> s;
        //cout << cur << " " <<  s << endl;
        for( int i = 0; i < s.length(); i++ )
        {
            intl p = -1, l = -1, r =-1, level, pos;
            for( int j = 0; j < pow; j++ )
            {
                intl dif = cur - ara[j];
                intl div = ara[j+1];
                if( dif%div == 0 )
                {
                    level = j;
                    pos = dif/div;
                    break;
                }
            }

            //cout << cur << " " << level << " " << pos << endl;

            if( level == 0 )
            {
                l = -1;
                r = -1;
                p = (pos%2==0)?cur+1:cur-1;
                if( n == 1 )
                    p = -1;
            }
            else
            {
                if( level == pow - 1 )
                {
                    p = -1;
                    l = cur/2;
                    r = 3*cur/2;
                }
                else
                {
                    l = ara[level-1] + pos*2*ara[level];
                    r = ara[level-1] + (pos*2+1)*ara[level];
                    p = ara[level+1] + pos/2*ara[level+2];
                }
            }
            //cout << l << " " << r <<  endl;
            if( s[i] == 'U' && p != -1 )
                cur = p;
            else if( s[i] == 'R' && r != -1 )
                cur = r;
            else if( s[i] == 'L' && l != -1 )
                cur = l;
            //cout << cur << " " << level << " " << pos << endl;
        }
        cout << cur << endl;

    }
    return 0;
}




