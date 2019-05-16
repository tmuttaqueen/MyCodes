#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

const int mx = 300002;
intl bit1[mx], bit2[mx], n;

void update1( int x, intl val ) //add val to index x
{
    while( x <= n )
    {
        bit1[x] += val;
        x += (x&(-x));
    }
}

intl query1( int x ) //sum from 1 to x (inclusive)
{
    intl sum = 0;
    while( x > 0 )
    {
        sum += bit1[x];
        x -= (x&(-x));
    }
    return sum;
}

void update2( int x, intl val ) //add val to index x
{
    while( x <= n )
    {
        bit2[x] += val;
        x += (x&(-x));
    }
}

intl query2( int x ) //sum from 1 to x (inclusive)
{
    intl sum = 0;
    while( x > 0 )
    {
        sum += bit2[x];
        x -= (x&(-x));
    }
    return sum;
}

intl t[MAXN], b[MAXN];
pii Time[MAXN], bt[MAXN];
int pos[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> t[i] >> b[i];
        bt[i] = mp( b[i], i);
        Time[i] = mp( t[i], i );
    }
    sort( bt+1, bt+n+1 );
    sort( Time+1, Time+n+1 );
    reverse( Time+1, Time+n+1 );

    for( int i = 1; i <= n; i++ )
    {
        //cout << Time[i].xx << " " << bt[i].xx << endl;
        pos[ Time[i].yy ] = i;
        update2( i, Time[i].xx );
        update1( i, 1 );
    }
    intl ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        intl curb = bt[i].xx, curt = t[ bt[i].yy ];
        //cout << curb << " " << curt << " " << pos[ bt[i].yy ] << endl;
        update2( pos[ bt[i].yy ], -curt );
        update1( pos[ bt[i].yy ], -1 );
        int l = 1, r = n, sol = 0;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( query1(m) <= k-1 )
            {
                l = m+1;
                sol = m;
            }
            else
                r = m - 1;
        }
        curt += query2(sol);
        ans = max( ans, curt*curb );
    }
    cout << ans << endl;


    return 0;
}

/*
4 1
4 7
15 1
3 6
6 8
*/
