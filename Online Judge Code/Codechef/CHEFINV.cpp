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
    touple( int x = 0, int y = 0, int z = 0 )
    {
        xx = x;
        yy = y;
        zz = z;
    }
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
        {
            if( yy == a.yy )
            {
                return zz < a.zz;
            }
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;



//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int ara[222222];
int qry[222222];
map<int,int>mm;
vector<tii>vec[222222];
vector<int>ind[222222];
pii tt[222222];

///1D BIT O(logn)
const int mx = 200002;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q, d = 1;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        tt[i] = mp( ara[i], i );

    }
    sort( tt+1, tt+n+1 );
    for( int i = 1; i <= n; i++ )
    {
        if( mm[ tt[i].xx ] == 0 )
        {
            mm[ tt[i].xx ] = d++;
        }
    }
    for( int i =1; i <= n ; i++ )
    {
        ara[i] = mm[ ara[i] ];
        ind[ ara[i] ].pb(i);
    }

    for( int i = 0; i < q; i++ )
    {
        int x, y;
        cin >> x >> y;
        vec[ ara[x] ].pb( tii(x,y, i) );
        vec[ ara[y] ].pb( tii(y,x, i) );
    }
    intl ans = 0;
    for( int i = 1; i < d; i++ )
    {
        for( tii p: vec[i] )
        {
            if( p.xx < p.yy )
            {
                qry[ p.zz ] -= ( query( p.yy ) - query( p.xx ) );
            }
            else if( p.xx > p.yy )
            {
                qry[ p.zz ] += ( query( p.xx-1) - query( p.yy ) );
            }
        }
        for( int x: ind[i]  )
        {
            update(x,1);
        }
    }
    /*for( int i= 0; i < q; i++  )
    {
        what_is(qry[i]);
    }*/
    memset( bit, 0, sizeof bit );
    for( int i = d-1; i > 0; i-- )
    {
        //cout << "temp " <<  temp[i].xx << " " << temp[i].yy << endl;
        for( tii p: vec[i] )
        {
            //cout << p.xx << " " << p.yy << " " << p.zz << endl;
            if( p.xx < p.yy )
            {
                qry[ p.zz ] += ( query( p.yy ) - query( p.xx ) );
            }
            else if( p.xx > p.yy )
            {
                qry[ p.zz ] -= ( query( p.xx-1) - query( p.yy ) );
            }
        }
        for( int x: ind[i]  )
        {
            update(x,1);
        }
    }
    /*for( int i= 0; i < q; i++  )
    {
        what_is(qry[i]);
    }*/
    memset( bit, 0, sizeof bit );
    for( int i = 1; i < d; i++ )
    {
        for( int x: ind[i]  )
        {
            ans += ( query(n) - query(x) );
        }
        for( int x: ind[i]  )
        {
            update(x,1);
        }
    }
    //what_is(ans);

    for( int i = 0; i < q; i++)
    {
        cout << ans + qry[i] << endl;
    }


    return 0;
}
