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

int val[105];
char str[105][105];
vector<pii>range;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        range.clear();
        int c, r = 0;
        cin >> c;
        for( int i = 0; i < c; i++ )
        {
            cin >> val[i];
            r = max(r, val[i]);
        }
        for( int i = 0; i < c; i++ )
        {
            int s = 0;
            for( int j  = i; j >= 0; j-- )
            {
                s += val[j];
                r = max( r, s - (i-j) );
            }
        }
        cout << "Case #" << caseno++ << ": ";

        if( val[0] < 1 || val[c-1] < 1 )
        {
            cout << "IMPOSSIBLE " << endl;
            continue;
        }
        int f = 1, cur = 0;
        for( int i = 0; i < c; i++ )
        {
            int v = val[i], s = 0;
            range.push_back( mp(cur, cur+v-1) );
            cur = cur+v;
        }

        for( int i = 0; i < c; i++ )
        {
            if( range[i].yy < range[i].xx && val[i] > 0 )
            {
                f = 0;
                break;
            }
        }
        for( int i = 0; i < c && f == 1; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( i == j || range[i].yy < range[i].xx || range[j].yy < range[j].xx ) continue;
                if( (range[i].xx >= range[j].xx && range[i].xx <= range[j].yy) || (range[i].yy >= range[j].xx && range[i].yy <= range[j].yy) )
                {
                    f = 0;
                    break;
                }
            }
        }
        if(f == 0)
        {
            cout << "IMPOSSIBLE " << endl;
            continue;
        }
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
                str[i][j] = '.';
            str[i][c] = '\0';
        }
        for( int i = 0; i < c; i++ )
        {
            int x = range[i].xx, y = range[i].yy, v = val[i];
            if( y - x + 1 != v )
            {
                f = 0;
                break;
            }
            if( x <= y )
            {
                int l = 1, r = y - i;
                for( int j = x; j < i; j++ )
                {
                    for( int k = 0; k < l; k++ )
                        str[k][j] = '\\';
                    l++;
                }
                for( int j = i+1; j <= y; j++ )
                {
                    for( int k = 0; k < r; k++ )
                        str[k][j] = '/';
                    r--;
                }
            }
        }

        for( int i = 0; i < r; i++ )
        {
            for( int j = 1; j < c; j++ )
            {
                if( str[i][j-1] == '\\' && str[i][j] == '/' )
                {
                    f = 0;
                    break;
                }
            }
        }
        if(f == 0)
        {
            cout << "IMPOSSIBLE " << endl;
            continue;
        }
        int d = 0;
        for( int i = r-1; i >= 0; i-- )
        {
            int x = 0;
            for( int j = 0; j < c; j++ )
            {
                if( str[i][j] == '.' ) x++;
            }
            if( x == c )
            {
                d++;
            }
            else
                break;
        }
        r -= (d-1);
        cout << r << " " << endl;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                cout << str[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
