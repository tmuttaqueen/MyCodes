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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>vec[1000001];
int ara[300001];
pii ans[300001];
vector<int>v;
int flag[1111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        flag[ ara[i] ] = 1;
    }
    for( int i = 0; i < n; i++ )
    {
        //cin >> ara[i];
        int m = ara[i];

        for( int j=1; j*j <= m; j++ )
        {
            if( m%j==0 )
            {
                if( m/j != j )
                {
                    if( flag[j] )
                        vec[j].pb(i);
                    if( flag[m/j] )
                        vec[m/j].pb(i);
                }
                else
                {
                    if( flag[j] )
                        vec[j].pb(i);
                }
            }
        }
    }
    int mx = 0;

    for( int i = 0; i < n; i++ )
    {
        int mm = ara[i];
        int d = lower_bound( vec[mm].begin(), vec[mm].end(), i ) - vec[mm].begin();
        //what_is(d);
        int x = d, y = d;
        int l = 0, r = d-1;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( vec[mm][d] - vec[mm][m] == d - m )
            {
                x = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        l = d+1; r = vec[mm].size()-1;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( vec[mm][m] - vec[mm][d] == m-d )
            {
                y = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        ans[i] = mp( vec[mm][x],vec[mm][y]);
        //cout << i << " " << x << " " << y << endl;
        mx = max( mx, y-x );
    }
    for( int i = 0; i < n; i++ )
    {
        if( ans[i].yy - ans[i].xx == mx )
        {
            v.pb( ans[i].xx );
        }
    }
    sort( v.begin(), v.end() );
    int it = unique( v.begin(), v.end() ) - v.begin();
    v.resize(it);
    cout << v.size() << " " << mx << endl;
    for( int x: v )
    {
        cout << x+1 << ' ';
    }
    cout << endl;


    return 0;
}
