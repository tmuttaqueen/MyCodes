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
const int M = 1e6+5;

///1D BIT O(logn)
const int mx = 1000002;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

vector<pii> qr[M];
vector<int>val[M];
int ans[M];
string s;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> s;
    s = "0"+s;
    stack<int>st;
    for( int i = 1; i < s.length(); i++ )
    {
        if( s[i] == '(' )
        {
            st.push(i);
        }
        else if( s[i] == ')' && !st.empty() && s[ st.top() ] == '(' )
        {
            int t = st.top();
            st.pop();
            val[i].pb(t);
        }
        else
        {
            st.push(i);
        }
    }
    int q, l, r;
    cin >> q;
    for( int i =1; i <= q; i++ )
    {
        cin >> l >> r;
        qr[r].pb( mp(l,i) );
    }
    for( int i = 1; i <= 1000000; i++ )
    {
        for( int x: val[i] )
        {
            update(x, 1);
        }
        for( pii a: qr[i] )
        {
            ans[ a.yy ] = query(i) - query( a.xx-1 );
        }
    }
    for( int i = 1; i <= q; i++ )
    {
        cout << ans[i]*2 << "\n";
    }
    return 0;
}
