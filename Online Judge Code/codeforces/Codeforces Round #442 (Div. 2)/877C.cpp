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

int gett( string &a, string &b )
{
    int ans = 0;
    for( int i = 0; i < a.length(); i++ )
    {
        int j = 0;
        for( ; j < b.length(); j++ )
        {
            if( i+j >= a.length() || a[i+j] != b[j] ) break;
        }
        if( j == b.length() ) ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    string s1[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string s;
    cin >> s;
    int t = 0;
    for( int i = 0; i < 5; i++)
    {
        t += gett( s, s1[i] );
    }
    if( t == 1 )
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
