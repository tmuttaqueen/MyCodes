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
#define filein      freopen("A-large.in", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        string s, s1, s2;
        cin >> s;
        s1 = s;
        s2 = s;
        intl ans = 0;
        for( int i = 0; i < s.length(); i++ )
        {
            if( s[i] == '9' )
            {
                s1[i] -= 1;
                for( int j = i + 1; j < s.length(); j++ )
                {
                    s1[j] = '8';
                }
                ans = abs(atol(s1.c_str()) - atol(s.c_str()));
                break;
            }
            else if( (s[i] - '0')%2 )
            {
                s1[i] -= 1;
                for( int j = i + 1; j < s.length(); j++ )
                {
                    s1[j] = '8';
                }
                s2[i] += 1;
                for( int j = i + 1; j < s.length(); j++ )
                {
                    s2[j] = '0';
                }
                ans = min( abs( atol( s1.c_str())- atol( s.c_str() )), abs(  atol( s2.c_str())- atol( s.c_str() ))  );
                break;
            }


        }
        cout << "Case #" << caseno++ << ": " << ans << endl;

    }
    return 0;
}
