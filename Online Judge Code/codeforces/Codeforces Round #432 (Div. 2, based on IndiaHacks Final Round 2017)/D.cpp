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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int mx = 2222222;
intl ara[mx], sum[mx], d;
intl inf = 5000000000000001LL;
int p[mx];
intl ans;
intl n, x, y, a;

intl sieve()
{
    for( intl i = 2; i < 1000000; i++ )
    {
        if( p[i] == 0 )
        {
            intl c = 0, dl = 0;
            for( intl j = i; j <= 2000000; j+=i )
            {
                if( j > i )
                    p[j] = 1;
                intl t = ara[j] - ara[ max(0LL, max(j-d-1, j-i ))], ss = sum[j] - sum[ max(0LL, max(j-d-1, j -i) ) ], dd = ara[max(0LL, max(j-d-1,j-i) )] - ara[ max(0LL,j-i) ]  ;
                if(  ( t*j-ss ) > 1000000000LL && y > 10000000LL  )
                {
                    c = inf;
                    break;
                }
                else
                    c += ( t*j-ss )*y;
                c += (dd*x);
                dl += dd;
                if( c >= inf )
                {
                    c = inf;
                    break;
                }
            }
            if( dl == n )
            {
                c = (n-1)*x;
                if( ara[1] == n )
                {
                    c += y;
                }
            }
            //what_is(i);
            //what_is(c);
            ans= min(ans, c  );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    //ans = 9200000000000000000LL;
    cin >> n >> x >> y;
    ans = n*x;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        ara[a]++;
        sum[a]+=a;
    }
    for( int i = 1; i < mx; i++ )
    {
        ara[i] += ara[i-1];
        sum[i] += sum[i-1];
    }
    d = x/y;
    sieve();
    intl c = (n-1)*x;
    if( ara[1] == n )
    {
        c += y;
    }
    ans = min(ans, c);
    cout << ans << endl;

    return 0;
}
