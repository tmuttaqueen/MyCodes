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
#define piii        pair<pii, int>

const int mx = 100005;
int sq;
int ara[mx];
int num[mx];
piii query[50005];
int ans[50005];
int val;

bool comp( piii a, piii b )
{
    if( a.xx.xx/sq == b.xx.xx/sq )
        return a.xx.yy < b.xx.yy;
    return a.xx.xx < b.xx.xx;

}

void xmoveleft( int a )
{
    if( ara[num[a]] > 0 )
        val--;
    ara[num[a]]++;
    val++;
}

void xmoveright( int a )
{
    if( ara[ num[a] ] > 1 )
        val++;
    ara[ num[a] ]--;
    val--;
}

void ymoveleft( int a )
{
    if( ara[ num[a] ] > 1 )
        val++;
    ara[ num[a] ]--;
    val--;
}

void ymoveright( int a )
{
    if( ara[num[a]] > 0 )
        val--;
    ara[num[a]]++;
    val++;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q, a, b, c, cx = 0, cy = 0;
        val = 1;
        memset( ara, 0, sizeof(ara) );
        scanf("%d %d", &n, &q);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &a);
            num[i] = a;
            //ara[a]++;
        }
        ara[ num[0] ]++;
        sq = sqrt(n) + 0.5;
        for( int i = 0; i < q; i++ )
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            query[i].xx.xx = a;
            query[i].xx.yy = b;
            query[i].yy = i;
        }

        sort( query, query + q, comp );

        for( int i = 0; i < q; i++ )
        {
            int l = query[i].xx.xx, r = query[i].xx.yy;
            while( l > cx )
                xmoveright( cx++ );
            while( l < cx )
                xmoveleft( --cx );
            while( r > cy )
                ymoveright( ++cy );
            while( r < cy )
                ymoveleft( cy-- );
            ans[ query[i].yy ] = val;
        }
        printf("Case %d:\n", caseno++);
        for( int i = 0; i < q; i++ )
            printf("%d\n", ans[i]);
    }

    return 0;
}



