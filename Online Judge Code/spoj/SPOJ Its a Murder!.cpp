#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

vector<pii> vec(100005);
vector<long long> tree(4*100005);
//vector<long long> ans(100005);

bool comp( pii a, pii b )
{
    if( a.xx == b.xx ) return a.yy > b.yy;
    return a.xx < b.xx;
}

bool cmmp( pii a, pii b  )
{
    return a.xx < b.xx;
}

void update( int cn, int s, int e, int x, int val )
{
    //what_is(x);
    if( s > x || e < x ) return;
    if( s == e )
    {
        tree[cn] = val;
        //debug;
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, val );
    update( cn*2 + 1, m+1, e, x, val );
    tree[cn] = tree[cn*2] + tree[cn*2 + 1];
    return;
}

long long query( int cn, int s, int e, int x, int y)
{
    if( s > y || x > e ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)/2;
    long long l1 = query( cn*2, s, m, x, y );
    long long l2 = query( cn*2+1, m+1, e, x, y );
    return l1+l2;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        for( int i = 0; i < 4*100005; i++ ) tree[i] = 0;
        int n, a;
        intl ans = 0;
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> vec[i].xx;
            vec[i].yy = i;
        }

        sort( vec.begin(), vec.begin() + n + 1, comp );

        for( int i = 1; i <= n; i++ )
        {
            //what_is(vec[i].yy);
            ans += query( 1, 1, n, 1, vec[i].yy );
            update( 1, 1, n, vec[i].yy, vec[i].xx );
            //auto m = lower_bound( vec.begin(), vec.begin() + n +1, vec[i], cmmp );
            //what_is(ans);
        }
        cout << ans <<  endl;
    }

    return 0;
}


