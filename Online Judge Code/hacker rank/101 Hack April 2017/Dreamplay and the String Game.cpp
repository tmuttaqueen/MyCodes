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

///Z-ALGORITHM O(n)
//calculateZ takes a string and an array as an input and returns Z value
int zval[2000006];

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
    cin.tie(0);
    //filein;
    string s, p;
    int n;
    cin >> n;
    while(n--)
    {
        int flag = 0, v;
        cin >> s >> p;
        string zz = p + "#" + s;
        calculateZ( zz, zval );
        int lp = p.length(), ls = s.length();
        v = ceil((ls-lp)/2.0);
        int d = ls-lp-v;
        if( ls == 2 && lp == 1 && s[0] == p[0] && s[1] == p[0] )
        {
            flag = 1;
        }
        for( int i = lp+1; i <= lp+ls; i++ )
        {
            if( zval[i] == lp )
            {
                int l = i - lp-1;
                int r = ls - lp - l;
                if( l > r ) swap(l,r);


                if( l >= v && r >= v )
                    flag = 1;
            }
        }
        if( flag )
        {
            cout << "Amanda\n";
        }
        else
        {
            cout << "Steven\n";
        }
    }
    return 0;
}




