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

const int mx = 100005;
int ara[mx];
int tree[mx*4];

void init( int cn, int s, int e )
{
    if( s == e )
    {
        tree[cn] = ara[s];
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1,e );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    return;
}

int query( int cn, int s, int e, int x, int y )
{
    if( e < x || s > y ) return -1;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)/2;
    int t1 = query( cn*2, s, m, x, y );
    int t2 = query( cn*2 + 1, m+1, e, x, y );
    return max(t1, t2);
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q, c;
        scanf("%d %d %d", &n, &c, &q);
        int pre[n+1];
        ara[0] = 0;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &ara[i]);
        }

        int temp = 0;
        int pr = ara[1];
        pre[1] = temp;;
        for( int i = 2; i <= n; i++ )
        {
            while( i <= n && ara[i] == pr )
            {
                pre[i] = temp;
                i++;
            }
            pr = ara[i];
            temp = i-1;
            pre[i] = temp;
        }

        c = 1;
        int p = ara[n];
        ara[n] = c++;
        for( int i = n-1; i > 0; i-- )
        {
            while( i > 0 && ara[i] == p )
            {
                ara[i] = c++;
                i--;
            }
            c = 1;
            p = ara[i];
            ara[i] = c++;
        }
        init( 1, 1, n );
        cout << "Case " << caseno++ << ":\n";
        for( int i = 1; i <= q; i++ )
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if( x == y )
            {
                printf("1\n");
                continue;
            }
            int temp = y;
            y = pre[y];
            //cout << "x " << x << " y " << y << endl;
            if( y < x )
            {
                int ans = temp - x + 1;
                printf("%d\n", ans );
                continue;
            }
            int ans = query( 1, 1, n, x, y );
            //what_is(ans);
            ans = max( ans, temp - y );
            printf("%d\n", ans);
        }

    }

    return 0;
}



