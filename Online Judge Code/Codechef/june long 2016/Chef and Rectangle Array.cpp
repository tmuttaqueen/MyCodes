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

intl ara[1000][1000], sum[1000][1000];
int rmq[1000][1000][11][11];

intl maxx( int a, int b, int c, int d )
{
    intl ans = a;
    ans = (b>ans)?b:ans;
    ans = (c>ans)?c:ans;
    ans = (d>ans)?d:ans;
    return ans;
}

int sss( int i, int j, int x, int y )
{
    if( i == x && j == y )
        return ara[i][j];
    else if( i == 0 )
        return sum[x][y] - sum[x][j-1];
    else if( j == 0)
        return sum[x][y] - sum[i-1][y];

    return sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1];
}


int main()
{
    //ios::sync_with_stdio(false);
    filein;
    double log2 = log(2);
    intl n, m, a;
    scanf("%lld %lld", &n, &m);
    int ln = log(n)/log2 + 1 , lm = log(m)/log2 + 1;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            scanf("%lld", &a);
            ara[i][j] = rmq[i][j][0][0] = a;
            if( i == 0 && j == 0 )
                sum[0][0] = a;
            else if( i == 0 ) sum[i][j] = sum[i][j-1] + a;
            else if( j == 0 ) sum[i][j] = sum[i-1][j] + a;
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] + a - sum[i-1][j-1];
        }
    }
    /*for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
            cout << sum[i][j] << " ";
        cout << endl;
    }*/

    for( int i = 1; (1<<i)<n; i++ )
    {
        for( int j = 1; (1<<j)<m; j++ )
        {
            int px = 1<<(i-1), py = 1<<(j-1);
            for( int x = 0; x+(1<<i)-1 < n; x++ )
            {
                for( int y = 0; y+(1<<j)-1 < m; y++ )
                {
                    c++;
                    rmq[x][y][i][j] = maxx(rmq[x][y][i-1][j-1],rmq[x+px][y][i-1][j-1], rmq[x+px][y+py][i-1][j-1],rmq[x][y+py][i-1][j-1] );
                }
            }
        }
    }

    what_is(c);

    int q;
    scanf("%d", &q);
    while(q--)
    {
        intl a, b, ans = 10000000000000000LL;
        scanf("%lld %lld", &a, &b);
        int k1 = log(a)/log2, k2 = log(b)/log2;
        //what_is(k1);
        //what_is(k2);
        int px = 1<<k1, py = 1<<k2;
        for( int i = a-1; i < n; i++ )
        {
            for( int j = b-1; j < m; j++ )
            {
                int s = i-a+1, e = j-b+1;
                intl mx = maxx( rmq[s][e][k1][k2], rmq[i-px+1][e][k1][k2], rmq[s][j-py+1][k1][k2], rmq[i-px+1][j-py+1][k1][k2] );
                //printf("%d %d %d %d ", s,e, i,j);
                 //cout << "mx " << mx << "     ";
                //cout << sss(s,e,i,j) << endl;
                what_is(mx);
                ans = min(ans, a*b*mx - sss(s,e,i,j));
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}



