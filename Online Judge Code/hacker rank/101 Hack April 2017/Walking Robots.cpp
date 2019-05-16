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


stack<char>st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    while(n--)
    {

        string s;
        cin >> s;
        int ans = 0;
        //what_is(s);
        for( int i = 0; i < s.length(); i++ )
        {
            if( s[i] == 'd' )
            {
                while( !st.empty() && st.top() == 'r' )
                {
                    ans++;
                    st.pop();
                }
                st.push('d');
            }
            else if( s[i] == 'l' )
            {
                int t = ans;
                if( !st.empty() && (st.top() == 'r' || st.top() == 'd') )
                    ans++;

                while( !st.empty() && (st.top() == 'r') )
                {
                    st.pop();
                    ans++;
                }
                if(t != ans)
                    st.push('d');
                else
                    st.push('l');
                //what_is(ans);
            }
            else
            {
                st.push('r');
            }
            //what_is(ans);
        }
        cout << ans << endl;
        while( !st.empty() ) st.pop();
    }
    return 0;
}




