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

pii check[5000000];

intl hf[2000];
intl base = 97, mod = 1e9+7, mod2 = 1e9+9, base2 = 79;
intl hf2[2000];
intl bad[2000];
intl bb[2000], bb2[2000];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    string str;
    cin >> str;
    intl n = 0, k, tt = 1, b = 0, tt2= 1;
    cin >> k;
    for( int i = 0; i < s.length(); i++ )
    {
        bb[i] = tt;
        bb2[i] = tt2;
        bad[i] = i < 0? 0: bad[i-1];
        n = (n*base + s[i] - 'a'+1)%mod;
        b = (b*base2 + s[i] - 'a' + 1)%mod2;
        hf[i] = n;
        hf2[i] = b;
        if( str[ s[i] - 'a' ] == '0' )
        {
            //what_is(i);
            bad[i]++;
        }
        tt = (tt*base)%mod;
        tt2 = (tt2*base2)%mod2;
        //cout << bad[i] << endl;
        //what_is(n);
    }
    //cout <<  str << endl;
    intl ans = 0, cnt = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        if(  bad[i] <= k )
        {
           check[cnt++] = mp( hf[i], hf2[i] );
        }
    }
    //what_is(ans);


    for( int i = 1; i < s.length(); i++ )
    {
        for( int j = i; j < s.length(); j++ )
        {
            intl hh = (hf[j] - ( hf[i-1]*bb[j-i+1] )%mod)%mod;
            intl hh2 = ( hf2[j] - ( hf2[i-1]*bb2[j-i+1] )%mod2  )%mod2;
            hh = (hh + mod)%mod;
            hh2 = ( hh2+mod2 )%mod2;
            if( bad[j] - bad[i-1] <= k )
            {
                //cout << i << " " << j << " " << hh << endl;
                check[cnt++] = mp( hh, hh2 );
            }
        }
    }

    sort( check, check + cnt );
    if( cnt != 0 )
        ans = 1;
    for( int i = 1; i < cnt; i++ )
    {
        if( check[i] != check[i-1] )
            ans++;
    }

    cout << ans << endl;


    return 0;
}




