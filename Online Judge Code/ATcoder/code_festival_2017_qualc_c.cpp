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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

int ara[111];
char str[211111];
int temp[211111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    string s;
    cin >> s;
    int st = 0;
    for( int i = 0; i < (int)s.length(); i++ )
    {
        ara[s[i]-'a']++;
        if( s[i] != 'x' )
        {
            str[st] = s[i];
            temp[st++] = i;
        }
    }
    int ans = 0;
    for( int i = 0; i < st ; i++ )
    {
        if( str[i] != str[st-1-i] )
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if( st%2 == 0 )
    {
        int d = temp[st/2] - temp[st/2-1];
        if( d > 1 ) ans--;
    }
    for( int i = 0; i < (int)s.length(); i++ )
    {
        if( s[i] == 'x' && s[ s.length() - 1 - i] != 'x' )
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
