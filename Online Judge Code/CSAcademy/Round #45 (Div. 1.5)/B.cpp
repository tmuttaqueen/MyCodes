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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[111111];
intl ind[111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, s = 0;
    cin >> n;
    int c = 0;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        if( !ara[i] )
        {
            i--;
            n--;
            c++;
            continue;
        }
        ind[i] = ++c;
        s += abs( ara[i] );
    }
    cout << s << endl;
    if( ara[n-1] < 0  )
        cout << ind[n-1] << " ";
    for( int i = n-2; i >= 0; i-- )
    {
        if( (ara[i] < 0 && ara[i+1] > 0) || (ara[i] > 0 && ara[i+1] < 0) )
        {
            cout << ind[i] << " ";
        }

    }
    cout << endl;
    return 0;
}
