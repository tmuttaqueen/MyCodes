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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int zval[1111111], cnt[1111111];

void calculateZ( string &s, int zval[] )
{
    int len = s.length();
    int left = 0, right = 0;
    zval[0] = 0;
    for( int k = 1; k < len; k++ )
    {
        if( k > right )
        {
            left = right = k;
            while( right < len && s[right-left] == s[right] )
            {
                right++;
            }
            zval[k] = right - left;
            right--;
        }
        else
        {
            if( k + zval[k-left] < right )
            {
                zval[k] = zval[k-left];
            }
            else
            {
                left = k;
                while( right < len && s[right-left] == s[right] )
                {
                    right++;
                }
                zval[k] = right - left;
                right--;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    calculateZ( s, zval );
    int len = s.length();
    for( int i = 0; i < len; i++ )
    {
        cnt[zval[i]]++;
    }
    for( int i = len-1; i >= 0; i-- )
    {
        cnt[i] += cnt[i+1];
    }
    int ans = 0;
    for( int i = 0; i < len; i++ )
    {
        if( zval[len-i] == i && cnt[i] >= 2 )
        {
            ans = i;
        }
    }
    if( ans != 0 )
    for( int i = 0; i < ans; i++ ) cout << s[i];
    else cout << "Just a legend";
    return 0;

}




