#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

vector<int>edge[M];
int x[M], y[M];
map<int, int>mm[M];

bool flag[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n;
    cin >> n;
    intl m;
    cin >> m;
    intl a, b, c;
    intl ans = 0;
    cin >> a >> b >> c;

    for( intl i = 0; i < m; i++ )
    {
        intl p, q;
        cin >> p >> q;
        edge[p].pb(q);
        edge[q].pb(p);
        x[i] = p;
        y[i] = q;
        mm[p][q] = 1;
        mm[q][p] = 1;
    }
    for( intl i = 0; i < n; i++ )
    {
        //ans += i*(i-1)/2*a*(n-i-1) + i*(n-i-1)*i*b + ( n*(n-1)/2 - i*(i+1)/2 )*c*i;
        //what_is(ans);
        ans += ( (i*(i-1)/2)*c*i + i*(n-i-1)*i*b + ( (n-i-1)*(n-i-2)/2)*a*i);
        //cout << i << " " << ans << endl;
        //what_is(ans);
    }
    //what_is(ans);
    intl bad = 0;
    for( intl i = 0; i < m; i++ )
    {
        if( x[i] > y[i] ) swap( x[i], y[i] );
        if( y[i] < n-1  )
            bad += ( x[i]*a*(n-y[i]-1) + y[i]*b*(n-y[i]-1) + ( n*(n-1)/2 - y[i]*(y[i]+1)/2 )*c );
        if( x[i] > 0  )
            bad += ( x[i]*b*(x[i]) + y[i]*c*x[i] + (x[i]*(x[i]-1)/2)*a );
        if( y[i] - x[i] > 1 )
            bad += ( x[i]*a*(y[i]-x[i]-1) + y[i]*c*(y[i]-x[i]-1) + ( y[i]*(y[i]-1)/2 - x[i]*(x[i]+1)/2 )*b );
        //what_is(bad);
    }
    //debug;

    for( intl i = 0; i < n; i++ )
    {
        sort( edge[i].begin(), edge[i].end() );
        intl s1 = 0, c1 = 0, s2 = 0, c2 = 0;
        for( intl v: edge[i] )
        {
            if( v > i )
            {
                s2 += v;
                c2++;
            }
            else if( v < i )
            {
                s1 += v;
                c1++;
            }
        }
        bad -= ( c1*c2*i*b + s1*a*c2 + s2*c*c1 );
        //what_is(bad);
        intl d1 = 0, d2 = 0;
        for( intl v: edge[i] )
        {
            if( v > i )
            {
                d2++;
                bad -= ( (c2-d2)*v*b );
                bad -= ( (d2-1)*v*c );
            }
            else if( v < i )
            {
                d1++;
                bad -= ( (c1-d1)*v*a );
                bad -= ( (d1-1)*v*b );
            }
        }
        bad -= ( (c1*(c1-1)/2*c) + (c2*(c2-1)/2)*a )*i;
        //what_is(bad);
    }
    //debug;


    for( intl i = 1; i < n-1; i++ )
    {
        if( edge[i].size()*edge[i].size() < n )
        {
            int l = edge[i].size();
            for( int j = 0; j < l; j++ )
            {
                for( int k = 0; k < l; k++ )
                {
                    intl u = edge[i][j], v = edge[i][k];
                    if( u < i && v > i && mm[u].find(v) != mm[u].end())
                    {
                        bad += ( u*a + i*b + v*c );
                    }
                }
            }
        }
        else
        {
            memset( flag, 0, sizeof flag );
            for( int j = 0; j < edge[i].size(); j++ )
            {
                flag[ edge[i][j] ] = 1;
            }
            for( int j = 0; j < m; j++ )
            {
                if( flag[x[j]] == 1 && flag[ y[j] ] == 1 && x[j] < i && i < y[j] )
                {
                    bad += ( x[j]*a + i*b + y[j]*c );
                }
            }
        }
        //what_is(bad);
    }

    //what_is(ans);
    //what_is(bad);
    cout << ans - bad << endl;
    return 0;
}
