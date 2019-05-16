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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;
const int mxx = 1000000;
vector<int>prime;
bool fl[1000002];
int ara[100005];
int tt[1000005];
int dp[170][100005];
int th[100005];
pii xy[100005], pq[100005];
vector<int>divv[1000005];
int ans[100005];
int sum[170][100005];

struct querr
{
    int l, r, x, y, ind;
};

querr quer[100005];

void sieve()
{
    for( int i = 2; i <= mxx; i+=2 )
    {
        if( tt[i] == 0 )
            continue;
        int d = i, c = 0;
        while(d%2 == 0)
        {
            d /= 2;
            c++;
        }
        dp[0][ tt[i] ] = c;
    }
    int ind = 1;
    for( int i = 3; i <= mxx; i+=2 )
    {
        if( fl[i] == 0 )
        {
            for( int j = i; j <= mxx; j += i )
            {
                if( j != i ) fl[j] = 1;
                if( tt[j] == 0 ) continue;
                int d = j, c = 0;
                while( d%i == 0 )
                {
                    d/=i;
                    c++;
                }
                if( i < 1000 )
                    dp[ind][ tt[j] ] = c;
                else
                {
                    divv[i].pb( tt[j] );
                }

            }
            if( i < 1000 )
                ind++;
        }

    }
    prime.pb(2);
    for( int i = 3; i <= mxx; i+=2 )
    {
        if( fl[i] == 0 )
        {
            prime.pb(i);
        }

    }

}

const int mx = 100002;
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

bool compx( querr &a, querr &b )
{
    return a.x < b.x;
}
bool compy( querr &a, querr &b )
{
    return a.y > b.y;
}

int summ( int x, int y, int l, int r )
{
    return sum[y][r] - sum[x-1][l-1] + sum[x-1][r] + sum[y][l-1];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        tt[ara[i]] = i;
    }
    sieve();

    for( int i = 1; i <= 168; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
             sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + dp[i-1][j];
        }
    }

    for( int i = 1; i < 10; i++ )
    {
        for( int j = 1; j <= n; j++ )
            cout << sum[i][j] << " ";
        cout << endl;
    }

    int q;
    cin >> q;
    for( int i = 0; i < q; i++ )
    {
        cin >> pq[i].xx >> pq[i].yy >> xy[i].xx >> xy[i].yy;
        int a = lower_bound( prime.begin(), prime.end(), xy[i].xx ) - prime.begin();
        xy[i].xx = prime[a];
        a = lower_bound( prime.begin(), prime.end(), xy[i].yy ) - prime.begin();
        if( a == prime.size() ) a--;
        if( prime[a] > xy[i].yy ) a--;
        xy[i].yy = prime[a];
        quer[i].l = pq[i].xx;
        quer[i].r = pq[i].yy;
        quer[i].x = xy[i].xx;
        quer[i].y = xy[i].yy;
        cout << "q " << quer[i].l << " " << quer[i].r << " " << quer[i].x << " " << quer[i].y << endl;
        quer[i].ind = i;
    }
    cout << "1st\n";
    sort( quer, quer+q, compx );
    for( int i = 0; i < q; i++ )
    {
        if( quer[i].x < 1000 && quer[i].y < 1000 )
        {
            int a = lower_bound( prime.begin(), prime.end(), quer[i].x ) - prime.begin();
            int b = lower_bound( prime.begin(), prime.end(), quer[i].y ) - prime.begin();
            cout << a+1 << " " << b+1 << " " << quer[i].l << " " << quer[i].r << endl;
            int d = summ( a+1, b+1, quer[i].l, quer[i].r );
            ans[ quer[i].ind ] += d;
            what_is(d);
            quer[i].x = quer[i].y = -1;
        }
        else if( quer[i].x < 1000 )
        {
            cout << "y is high ";
            int a = lower_bound( prime.begin(), prime.end(), quer[i].x ) - prime.begin();
            int b = 167;
            cout << a+1 << " " << b+1 << " " << quer[i].l << " " << quer[i].r << endl;
            int d = summ( a+1, b+1, quer[i].l, quer[i].r );
            ans[ quer[i].ind ] += d;
            cout << "1# d is " << d << "\n";
            quer[i].x = 1009;
        }
    }
    cout << "2nd\n";
    sort( quer, quer+q, compx );
    for( int i = 0; i < q; i++ )
    {
        if( quer[i].x == -1 ) continue;
        int d = (query( quer[i].r ) - query( quer[i].l-1) );
        cout << "2# d is " << d << "\n";
        ans[ quer[i].ind ] -= d;
        if( i < q-1 && quer[i+1].x == quer[i].x ) continue;
        for( int x: divv[ quer[i].x ] )
        {
            what_is(x);
            update( x, 1 );
        }
    }

    cout << "3rd\n";

    memset( bit, 0, sizeof bit );

    sort( quer, quer+q, compy );
    for( int i = 0; i < q; i++ )
    {
        if( quer[i].y < 1000 )
        {
            //debug;
            break;
        }
        else
        {
            int d = (query( quer[i].r ) - query( quer[i].l-1) );
            cout << "3# d is " << d << "\n";
            ans[ quer[i].ind ] -= d;
            if( i < q-1 && quer[i+1].y == quer[i].y ) continue;
            for( int x: divv[ quer[i].y ] )
            {
                what_is(x);
                update( x, 1 );
            }
        }
    }

    for( int i = 0; i < q; i++ )
    {
        cout << ans[i] << "\n";
    }



    return 0;
}



