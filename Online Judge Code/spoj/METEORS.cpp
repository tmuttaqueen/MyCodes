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
const int M = 300008;

int mx = 300002;
intl bit[300002];
void update( int x, intl val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

intl query( int x ) //sum from 1 to x (inclusive)
{
    intl sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

void rangeUpdate( int l, int r, intl val )
{
    update( l, val );
    update( r+1, -val );
}

vector<int>state[M], inq[M];
intl ql[M], qr[M], qv[M];
intl R[M], L[M];
intl target[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //filein;
    int n, m, a;
    cin >> n >> m;
    mx = m+2;
    for( int i = 1; i <= m; i++ )
    {
        cin >> a;
        state[a].pb(i);
    }
    for( int i = 1; i <= n; i++ ) cin >> target[i];
    int k;
    cin >> k;
    for( int i = 1; i <= k; i++ )
    {
        cin >> ql[i] >> qr[i] >> qv[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        R[i] = k+1;
        L[i] = 1;
    }
    while(1)
    {
        int c = 0;
        for( int i = 1; i <= n; i++ )
        {
            if( L[i] != R[i] )
            {
                int m = ( L[i] + R[i] )/2;
                inq[m].pb(i);
                c++;
            }
        }
        if(!c) break;
        memset( bit, 0 , sizeof bit );
        for( int i = 1; i <= k; i++ )
        {
            if( ql[i] <= qr[i] )
            {
                rangeUpdate( ql[i], qr[i], qv[i] );
            }
            else
            {
                rangeUpdate( 1, qr[i], qv[i] );
                update( ql[i], qv[i] );
            }
            for( int j = 0; j < inq[i].size(); j++ )
            {
                int st = inq[i][j];
                intl sum = 0, f = 1;
                for( int x = 0; x < state[st].size(); x++ )
                {
                    int y = state[st][x];
                    sum += query(y);
                    if( sum >= target[st] )
                    {
                        R[st] = i;
                        f = 0;
                        break;
                    }
                }
                if(f)
                {
                    L[st] = i+1;
                }

            }
            inq[i].clear();
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        if( R[i] <= k )
        {
            cout << R[i] << "\n";
        }
        else
            cout << "NIE\n";
    }
    return 0;
}
