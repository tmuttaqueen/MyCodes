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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

char ans[4444444];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    string s1, s2;
    cin >> s1 >> s2;
    sort( s1.begin(), s1.end());
    sort( s2.begin(), s2.end() );
    reverse( s2.begin(), s2.end() );

    int st = 0, lt = s1.size() - 1;
    int len = lt+1;
    int a = 0, b = 0, aa = ceil(len/2.0)-1, bb = len - aa-2;
    for( int i = 0; i < len; i++ ) ans[i] = '.';
    ans[len] = '\0';
    for( int i = 0; i < len; i++ )
    {
        if( i%2 == 0 )
        {
            if( s1[a] < s2[b] )
            {
                ans[st++] = s1[a++];
            }
            else
            {
                ans[lt--] = s1[aa--];
            }
        }
        else
        {
            if( s1[a] < s2[b] )
            {
                ans[st++] = s2[b++];
            }
            else
            {
                ans[lt--] = s2[bb--];
            }
            //b++;
        }
        //cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}




