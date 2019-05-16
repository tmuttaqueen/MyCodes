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

int one[2];
int two[2];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    int sum = 0;
    int c1 = 0, c2 = 0;
    for( int i = s.length() - 1; i >= 0; i-- )
    {
        int d = s[i] - '0';
        if( c1 < 2 && d%3 == 1 )
            one[c1++] = i;
        if( c2 < 2 && d%3 == 2 )
            two[c2++] = i;
        sum += d;
    }
    string ans = "";
    if( sum % 3 == 0 )
    {
        cout << s << endl;
    }
    else if( sum%3 == 1 )
    {
        if( c1 != 0 && !(one[0] == 0 && s[1] == '0' && s[2] == '0' && c2 >= 2) )
        {
            ans += s.substr( 0, one[0] ) + s.substr( one[0] + 1, s.length() - one[0] - 1 );
        }
        else if( c2 < 2 )
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans += s.substr( 0, two[1] ) + s.substr( two[1] + 1, two[0] -  two[1] - 1 ) + s.substr( two[0]+1, s.length() - two[0] - 1 );
        }

        int st = -1;
        for( int i = 0; i < ans.length(); i++ )
        {
            if( ans[i] != '0' )
            {
                st = i;
                break;
            }
        }
        if( st == -1 )
            st = ans.length() - 1;
        if( st == -1 )
        {
            cout << -1 << endl;
            return 0;
        }
        for( int i = st; i < ans.length(); i++ )
            cout << ans[i];
        cout << endl;

    }
    else if( sum % 3 == 2 )
    {
        if( c2 != 0 && !(two[0] == 0 && s[1] == '0' && s[2] == '0' && c1 >= 2) )
        {
            ans += s.substr( 0, two[0] ) + s.substr( two[0] + 1, s.length() - two[0] - 1 );
        }
        else if( c1 < 2 )
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans += s.substr( 0, one[1] ) + s.substr( one[1] + 1, one[0] -  one[1] - 1 ) + s.substr( one[0]+1, s.length() - one[0] - 1 );
        }

        int st = -1;
        for( int i = 0; i < ans.length(); i++ )
        {
            if( ans[i] != '0' )
            {
                st = i;
                break;
            }
        }
        if( st == -1 )
            st = ans.length() - 1;
        if( st == -1 )
        {
            cout << -1 << endl;
            return 0;
        }
        for( int i = st; i < ans.length(); i++ )
            cout << ans[i];
        cout << endl;
    }
    return 0;
}




