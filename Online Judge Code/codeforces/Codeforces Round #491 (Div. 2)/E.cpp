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
intl ans = 0;
vector<int>vec(10, 0), all(10, 0);
intl fact[20];
map< vector<int>, int >mm;

intl dp( vector<int>cnt )
{
    mm[cnt] = 1;
    intl c = 0, z = cnt[0];
    for( int i = 0; i < 10; i++ )
    {
        c += cnt[i];
    }
    //what_is(c);
    intl d = fact[c];
    for( int i = 0; i < 10; i++ )
    {
        d /= fact[ cnt[i] ];
    }
    if( z > 0 )
    {
        c--;
        intl p = fact[c];
        p /= fact[ cnt[0] -1 ];
        for( int i = 1; i < 10; i++ )
        {
            p /= fact[ cnt[i] ];
        }
        d -= p;
    }
    //what_is(d);
    ans += d;
    //what_is(ans);
    vector<int>temp;
    for( int i = 0; i < 10; i++ )
    {
        if( cnt[i] < vec[i] )
        {
            temp = cnt;
            temp[i]++;
            if( mm[temp] == 0 )
                dp(temp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    fact[0] = 1;
    for( int i = 1; i <= 19; i++ ) fact[i] = i*fact[i-1];
    string s;
    cin >> s;
    for( int i = 0; i < s.size(); i++ )
    {
        vec[ s[i] - '0' ]++;
    }
    for( int i = 0; i < 10; i++ )
    {
        if( vec[i]) all[i]++;
    }
    dp( all );
    cout << ans << endl;
    return 0;
}
