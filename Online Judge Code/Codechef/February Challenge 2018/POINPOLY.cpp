#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define x           first
#define y           second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

vector<pii>up, down, all, ans;
intl lim;
map<pii, int>mm;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

intl cross( pii &a, pii &b, pii &c )
{
    return ( a.x-b.x )*( b.y - c.y ) - ( a.y - b.y )*( b.x - c.x );
}

void divide()
{
    up.clear();
    down.clear();
    int a = 0, b = all.size()-1;
    up.pb( all[a] );
    down.pb( all[a] );
    for( int i = a+1; i < b; i++ )
    {
        intl v = cross( all[a], all[b], all[i] );

        if( v >= 0 )
            up.pb( all[i] );
        else
            down.pb( all[i] );
    }
    down.pb( all[b] );
    up.pb( all[b] );
}

intl dist( pii &a, pii &b )
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool isinside( intl x, intl y )
{
    if( x == all[0].x && y == all[0].y ) return 0;
    pii p = mp(x,y);
    int l = 1, r = all.size()-1, p1 = 0;
    while( l <= r )
    {
        int m = (l+r)/2;
        if( cross( all[0],all[m], p ) >= 0 )
        {
            p1 = m;
            l = m+1;
        }
        else
            r = m - 1;
    }
    l = 1;
    r = all.size()-1;
    int p2 = 0;
    while( l <= r )
    {
        int m = (l+r)/2;
        if( cross( all[0],all[m], p ) <= 0 )
        {
            p2 = m;
            r = m-1;
        }
        else
            l = m+1;
    }
    //cout << x << ' ' << y << " " << p1 << " " << p2 << endl;
    if( p1 == p2 )
    {
        if( p1 == 0 || p1 == 1 || p1 == all.size() - 1 )
            return 0;
        if( dist( all[p1], all[0] ) <= dist( p, all[0] ) || dist( all[p1], all[0] ) <= dist( p, all[p1] ) )
            return 0;
        return 1;
    }
    else if( cross( all[p1], all[p2], p ) == 0 )
        return 0;
    intl a = abs(cross( all[p1], all[p2], all[0] ));
    intl a1 = abs( cross( all[p1], all[p2], p ) ) + abs( cross( all[p1], all[0], p ) ) + abs( cross( all[p2], all[0], p ) );
    return a == a1;

}

void dfs( intl x, intl y )
{
    //cout << "- " << x << " " << y << endl;
    mm[ mp(x, y) ] = 1;
    if( isinside(x, y) == 0 || ans.size() >= lim ) return;
    intl xx, yy;
    for( int i = 0; i < 8; i++ )
    {
        xx = x + dx[i];
        yy = y + dy[i];
        if( mm[ mp(xx,yy) ] == 0 && isinside(xx,yy) && ans.size() < lim )
        {
            //cout << xx << ' ' << yy << endl;
            ans.pb( mp(xx,yy) );
            dfs(xx,yy);
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        all.clear();
        mm.clear();
        intl n, a , b;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> a >> b;
            all.pb( mp(a,b) );
        }
        lim = n/10;
        int f = 1;
        //cin >> lim;
        for( int i = 0; i < n && f; i++ )
        {
            intl x = all[i].x, y = all[i].y;
            for( int j = 0; j < 8; j++ )
            {
                intl xx = x+dx[j], yy = y + dy[j];
                if( isinside(xx, yy) )
                {
                    //cout << xx << " " << yy << endl;
                    ans.pb( mp(xx,yy) );
                    dfs( xx, yy );
                    f = 0;
                    break;
                }
            }
        }
        //debug;
        if( ans.size() < lim )
        {
            cout << -1 << endl;
        }
        else
        {
            for( int i = 0; i < lim; i++ )
            {
                cout << ans[i].x << " " << ans[i].y << endl;
            }
        }
        ans.clear();
    }
    return 0;
}
