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

struct data
{
    intl v, vs, vh;
};

bool comp( data &a, data &b )
{
    return a.vs*b.vh > b.vs*a.vh;
}

data ara[123456];
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> str;
        //what_is(str);
        intl s = 0, h = 0, v = 0;
        for( int j = 0; j < str.length(); j++ )
        {
            if( str[j] == 's' )
            {
                s++;
            }
            else
            {
                v += s;
                h++;
            }
        }
        //what_is(i);
        ara[i].v = v;
        ara[i].vs = s;
        ara[i].vh = h;
        //what_is(i);

    }
    sort( ara, ara+n, comp );
    intl ans = 0, s = 0;
    for( int i = 0; i < n; i++ )
    {
        ans += ara[i].v + s*ara[i].vh;
        s += ara[i].vs;
    }
    cout << ans << endl;
    return 0;
}
