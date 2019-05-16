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

intl ara[100005], temp[100005];
intl mod = 1e9+7;

long long exponentiation( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    intl ans = 0;
    for( intl i = 60; i >= 0; i-- )
    {
        int c = 0;
        intl o = 1;
        intl num = o<<i;

        for( int i = 0; i < n; i++ )
        {
            if( ara[i]&num )
            {
                temp[c++] = ara[i];
            }
        }
        if( c >= k )
        {
            n = c;
            //cout << i << " " << num << endl;
            ans += num;
            for( int i = 0 ; i < c; i++ )
            {
                ara[i] = temp[i];
            }
        }
    }

    intl f1 = 1, f2 = 1;
    for( intl i = 1; i <= k; i++ )
    {
        f1 = (f1*i)%mod;
    }

    for( intl i = n; i > n-k; i-- )
    {
        f2 = (f2*i)%mod;
    }

    intl res = exponentiation( f1, mod-2, mod );
    res = (res*f2)%mod;

    cout << ans << "\n" << res << endl;



    return 0;
}




