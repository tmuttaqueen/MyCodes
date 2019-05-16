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

stack<int>st;
int ans[1000005];
map<pii,int>mm;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    cin >> s;
    int flag = 0, p = 0;
    for( int i = 0 ;i < n; i++ )
    {
        if( s[i] == '(' )
        {
            st.push(i);
        }
        else
        {
            if( st.size() > 0)
            {
                d = st.top();
                st.pop();
                if( d == i-1 )
                {
                    mm[ mp(d,i) ] = 1;
                    ans[1]++;
                }
                else if( mm.count( mp(d+1, i-1) ) > 0 )
                {
                    int x =  mm[ mp(d+1,i-1) ] + 1;
                    mm[ mp(d,i) ] = x;
                    ans[x]++;
                }

                flag = 1;
            }
            else
            {
                ans[p]++;
                p = 0;
            }
        }
    }
    return 0;
}




