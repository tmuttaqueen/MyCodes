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

string s;

int cnt[M];
pii ara[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, tot = 0;
    cin >> n;
    intl ans = 0;
    for( int i = 0; i < n; i++ )
    {
        cin >> s;
        stack<char>st;
        for( int j = 0; j < s.length(); j++ )
        {
            if( s[j] == ')' && !st.empty() && st.top() == '(' )
            {
                st.pop();
            }
            else
            {
                st.push( s[j] );
            }
        }
        int x = 0, y = 0;
        while( !st.empty())
        {
            if( st.top() == '(' ) x++;
            else y++;
            st.pop();
        }
        //cout << x << " " << y << endl;
        if( x != 0 && y != 0 )
            continue;
        ara[tot++] = mp(x, y);
    }
    //what_is(ans);
    //sort( ara, ara+tot );
    //reverse( ara, ara+tot );
    for( int i = 0; i < tot; i++ )
    {
        if( ara[i].yy == 0 )
            cnt[ ara[i].xx ]++;
    }
    for( int i = 0; i < tot; i++ )
    {
        if( ara[i].xx == 0 )
        {
            ans += cnt[ara[i].yy];
        }
    }

    cout << ans << endl;
    return 0;
}
