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

string s[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int r, c;
    cin >> r >> c;
    for( int i = 0; i < r; i++ )
        cin >> s[i];
    int f = 1;
    for( int i = 0; i < r; i++ )
    {
        for( int j = 0; j < r; j++ )
        {
            int d = 0;
            for( int k = 0; k < c; k++ )
            {
                if( s[i][k] == s[j][k] && s[i][k] == '#' )
                    d++;
            }
            //cout << i << " " << j << " " << d << endl;
            if( d > 0 && s[i] != s[j] )
            {
                f = 0;
            }
        }
    }
    if(f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
