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

///1D BIT O(logn)
const intl mx = 100005;
intl bit[mx+5];
intl ara[mx];
intl dp[mx][12];

void update( intl x, intl val ) //add val to index x
{
    //what_is(x);
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

intl query( intl x ) //sum from 1 to x (inclusive)
{
    //what_is(x);
    intl sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}




int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    cin >> n >> k;
    k++;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        dp[i][1] = 1;
    }
    //debug;
    for( int i = 2; i <= k; i++ )
    {
        memset(bit, 0, sizeof bit);
        for( int j = 1; j <= n; j++ )
        {
            if( j > 1 )
                update( ara[j-1], dp[j-1][i-1] );
            //debug;
            dp[j][i] = query( ara[j]-1 );

        }
    }
    intl sum = 0;
    for( int i = 1; i <= n; i++ )
    {
        sum += dp[i][k];
        //cout << dp[i][k] << " ";
    }
    cout << sum << endl;
    return 0;
}



