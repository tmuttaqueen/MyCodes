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

const int mx = 4000005;
int lazy[mx], tree[mx];
int ara[mx];

void relax( int cn, int s, int e )
{
    tree[cn] += (e-s+1)*lazy[cn];
    lazy[cn] = 0;
    lazy[cn<<1] += lazy[cn];
    lazy[(cn<<1)+1] += lazy[cn];
}

int query( int cn, int s, int e, int x, int y )
{
    relax( cn, s, e );
    if( y < s || x > e ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int s1 = query( cn*2, s, (s+e)/2, x, y );
    int s2 = query( cn*2+1, (s+e)/2 + 1, e, x, y );
    return s1+s2;
}

void update( int cn, int s, int e, int x, int y, int val )
{
    relax( cn, s, e );
    if( y < s || x > e ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] += val;
        relax( cn, s, e );
        return;
    }
    update( cn*2, s, (s+e)/2, x, y, val );
    update( cn*2+1, (s+e)/2 + 1, e, x, y, val );
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int flag = 1;
    memset( ara, -1, sizeof ara );
    int n, k;
    cin >> n >> k;
    for( int i = 1; i <= k; i++ )
    {
        int val, pos;
        cin >> val >> pos;

        int d = query( 1, 1, n, pos, pos );
        update( 1, 1, n, 1, pos, 1 );
        pos -= d;
        if( ara[pos] == val ) continue;
        if( ara[pos] == -1 )
            ara[pos] = val;
        else
            flag = 0;
    }


    return 0;
}




