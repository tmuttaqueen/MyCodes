#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int flag[2000005];
vector<int>prime;
vector<int>num[200005];
intl pp[200005];

void sieve()
{
    for( intl i = 2; i <= 1000005; i++ )
    {
        //what_is(i);
        if( flag[i] == 0 )
        {
            prime.pb(i);
            //what_is(i);
            for( intl j = i*i; j <= 1000005; j+=i )
            {
                flag[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    sieve();
    //for( int i = 0; i < 26; i++ ) cout << prime[i] << endl;
    intl a, b;
    cin >> a >> b;
    for( intl i = 0; i <= b-a; i++ )
        pp[i] = a+i;
    for( int i = 0; i < prime.size(); i++ )
    {
        intl p = prime[i];
        intl d = a/p;
        if( a%p ) d++;
        for( intl x = d*p; x <= b; x += p )
        {
            intl c = 0, t = pp[x-a];
            while( t%p == 0 )
            {
                c++;
                t/=p;
            }
            pp[x-a] = t;
            if( c > 0 )
                num[x-a].pb(c+1);
        }
    }
    for( intl i = 0; i <= b-a; i++ )
    {
        if( pp[i] != 1 )
            num[i].pb(2);
    }
    //debug;
    intl ans = 0;
    for( intl i = 0; i <= b-a; i++ )
    {
        if( a == 1 && i == 0 )
        {
            continue;
        }
        while( 1 )
        {
            intl temp = 1, ind = -1, mx = -1;
            for( int j = 0; j < num[i].size(); j++ )
            {
                temp *= num[i][j];
                if( num[i][j] > mx )
                {
                    ind = j;
                    mx = num[i][j];
                }
            }
            if( ind >= 0 )
                num[i][ind]--;
            if( mx == 1 )
                break;
            ans += temp;
        }
    }
    cout << ans << endl;
    return 0;
}




