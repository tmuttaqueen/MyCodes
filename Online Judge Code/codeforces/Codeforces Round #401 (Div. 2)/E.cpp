#include <bits/stdc++.h>

using namespace std;

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

struct data
{
    intl in, out, h;
};
intl tree[4*200005];
map<intl,intl>mm;
intl ara[200005];
data dt[100005];
intl ans[100005];

bool comp( data a, data b )
{
    if( a.out == b.out )
        return a.in > b.in;
    return a.out > b.out;
}

void update( int cn, int s, int e, int x, intl v )
{
    if( e < x || s > x )
        return;
    if( s == x && e == x )
    {
        tree[cn] = max( tree[cn], v );
        return;
    }
    int mid = (s+e)/2;
    update( cn*2, s, mid, x, v );
    update( cn*2+1, mid+1, e, x, v );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    return;
}

intl query( int cn, int s, int e, int x, int y )
{
    if( s > y || e < x )
        return 0;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int mid = (s+e)/2;
    intl x1 = query( cn*2, s, mid, x, y );
    intl x2 = query( cn*2+1, mid+1, e, x, y );
    return max(x1, x2);
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    int c = 0;
    for( int i = 0; i < n; i++ )
    {
        cin >> dt[i].in >> dt[i].out >> dt[i].h;
        ara[c++] = dt[i].in;
        ara[c++] = dt[i].out;
    }
    for( int i = 0; i < n; i++ )
    {
        //cout << dt[i].in << " " << dt[i].out << " " << dt[i].h << endl;
    }
    sort( ara, ara + c );
    int lo = 1;
    for( int i = 0; i < c; i++ )
    {
        if( mm.count( ara[i] ) < 1 )
            mm[ ara[i] ] = lo++;
    }
    //what_is(lo);
    for( int i = 0; i < n; i++ )
    {
        dt[i].in = mm[ dt[i].in ];
        dt[i].out = mm[ dt[i].out ];
    }

    sort( dt, dt + n, comp );
    //cout << endl;
    for( int i = 0; i < n; i++ )
    {
        //cout << dt[i].in << " " << dt[i].out << " " << dt[i].h << endl;
    }
    //lo--;
    ans[0] = dt[0].h;
    update( 1, 1, lo, dt[0].in, ans[0] );
    for( int i = 1; i < n; i++ )
    {
        intl d = query( 1, 1, lo, 1, dt[i].out-1  );
        //what_is(d);
        ans[i] = dt[i].h + d;
        update( 1, 1, lo, dt[i].in, ans[i] );
    }
    intl sol = -1;
    for( int i = 0; i < n; i++ )
    {
        sol = max( sol, ans[i] );
    }

    cout << sol << endl;

    return 0;
}



