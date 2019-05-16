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

intl sum[4444], len;
vector<intl>v;

intl solve( intl s )
{
    intl c = 0, i1 = -1, i2 = -2;
    for( int i = 1; i <= len; i++ )
    {
        int l = i, h = len;
        i1 = -1;
        i2 = -2;
        while( l <= h )
        {
            int m = (l+h)/2;
            intl d = sum[m] - sum[i-1];
            if( d == s )
            {
                i1 = m;
                h = m - 1;
            }
            else if( d > s )
            {
                h = m - 1;
            }
            else
                l = m + 1;
        }

        l = i; h = len;
        while( l <= h )
        {
            int m = (l+h)/2;
            intl d = sum[m] - sum[i-1];
            if( d == s )
            {
                i2 = m;
                l = m + 1;
            }
            else if( d > s )
            {
                h = m - 1;
            }
            else
                l = m + 1;
        }
        c += i2-i1+1;
    }

    return c;
}

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int z = 0;
    //filein;
    intl a, c = 0;
    cin >> a;
    cin >> s;
    len = s.length();
    for( int i = 0; i < s.length(); i++ )
    {
        sum[i+1] = s[i] - '0';
        if( s[i] == '0' ) z++;
    }
    for( int i = 1; i <= len; i++ )
    {
        sum[i] = sum[i] + sum[i-1];
    }
    for( intl i = 1; i*i <= a; i++ )
    {
        if( a%i == 0 )
        {
            v.pb(i);
            if( a/i != i )
                v.pb(a/i);
        }
    }

    intl ans = 0;
    if( a == 0 )
    {
        ans = len*(len+1)/2;
        intl t = ans;
        ans = ans*ans;
        z = solve(0);
        //what_is(z);
        ans -= (t-z)*(t-z);
    }
    if( len == 1 && s[0] - '0' == a && a != 0 )
        ans++;
    for( int x: v )
    {
        int y = a/x;
        intl p = solve(x), q = solve(y);
        //cout << x << " " << p << "    " << y << " " << q << endl;
        ans += p*q;
    }
    cout << ans << endl;
    return 0;
}




