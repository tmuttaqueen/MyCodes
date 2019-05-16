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

pii c[500005];
char str[500005];
int inf = 2000000000;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, d = 0;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int mnh = -inf, mnv =-inf, mxh = inf, mxv = inf;
    char c1='B', c2='B', c3='B', c4='B';
    pii nh(-inf,-inf), nv(-inf,-inf), xh(inf,inf), xv(inf,inf);
    char nnh = 'R', nnv='R', xxh='R', xxv='R';
    for( int i = 0; i < n; i++ )
    {
        cin >> str[i] >> c[i].xx >> c[i].yy;
        if( c[i].xx == x )
        {
            if( c[i].yy > y && c[i].yy < mxv )
            {
                mxv = min( mxv, c[i].yy );
                c4 = str[i];
            }
            else if( c[i].yy < y && c[i].yy > mnv )
            {
                mnv = max( mnv, c[i].yy );
                c2 = str[i];
            }
        }
        if( c[i].yy == y )
        {
            if( c[i].xx > x && c[i].xx < mxh )
            {
                mxh = min( mxh, c[i].xx );
                c3 = str[i];
            }
            else if( c[i].xx < x && c[i].xx > mnh )
            {
                mnh = max( mnh, c[i].xx );
                c1 = str[i];
            }
        }
        if( (y-c[i].yy) == -(x-c[i].xx) )
        {
            if( c[i].xx > x && c[i].xx < xh.xx )
            {
                xh = c[i];
                xxh = str[i];
            }
            else if( c[i].xx < x && c[i].xx > nh.xx )
            {
                nh = c[i];
                nnh = str[i];
            }
        }
        if( (y-c[i].yy) == (x-c[i].xx) )
        {
            if( c[i].xx > x && c[i].xx < xv.xx )
            {
                xv = c[i];
                xxv = str[i];
            }
            else if( c[i].xx < x && c[i].xx > nv.xx )
            {
                nv = c[i];
                nnv = str[i];
            }
        }

    }
    str[n] = '\0';
    int flag = 0;
    if( xxh == 'B' || xxh == 'Q' ) flag = 1;
    if( nnh == 'B' || nnh == 'Q' ) flag = 1;
    if( xxv == 'B' || xxv == 'Q' ) flag = 1;
    if( nnv == 'B' || nnv == 'Q' ) flag = 1;
    if( flag )
    {
        cout << "YES\n";
        return 0;
    }
    if( c1 == 'Q' || c1 == 'R' ) flag = 1;
    if( c2 == 'Q' || c2 == 'R' ) flag = 1;
    if( c3 == 'Q' || c3 == 'R' ) flag = 1;
    if( c4 == 'Q' || c4 == 'R' ) flag = 1;
    if( flag )
    {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}



