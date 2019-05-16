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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

int ara[SZ];
intl x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )  cin >> ara[i];
    sort( ara, ara+n );
    intl a = 1, b = 1, c = 1;
    x = ara[0];
    for( int i = 1; i < n; i++ )
    {
        if( ara[i] == x )
            a++;
        else
            break;
    }
    if( a >= 3 )
    {
        cout << a*(a-1)*(a-2)/6 << endl;
        return 0;
    }

    x = ara[a];
    for( int i = a+1; i < n; i++ )
    {
        if( ara[i] == x )
            b++;
        else
            break;
    }
    if( a + b >= 3 )
    {
        if( a == 1 )
        {
            cout << b*(b-1)/2 << endl;
        }
        else
            cout << b << endl;
        return 0;
    }
    x = ara[a+b];
    for( int i = a+b+1; i < n; i++ )
    {
        if( ara[i] == x )
            c++;
        else
            break;
    }
    cout << c << endl;
    return 0;
}



