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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    int ara[111];
    while(t--)
    {
        memset( ara, 0, sizeof ara );
        char s[111], s2[111];
        gets(s);
        gets(s2);
        int l1 = strlen(s), l2 = strlen(s2);
        for( int i = 0; i < l1; i++ )
        {
            if( s[i] >= 'A' && s[i] <= 'Z' ) ara[ s[i]-'A' ]++;
            else if( s[i] >= 'a' && s[i] <= 'z'  ) ara[ s[i] - 'a' ]++;
        }
        for( int i = 0; i < l2; i++ )
        {
            if( s2[i] >= 'A' && s2[i] <= 'Z' ) ara[ s2[i]-'A' ]--;
            else if( s2[i] >= 'a' && s2[i] <= 'z'  ) ara[ s2[i] - 'a' ]--;
        }
        int f = 1;
        for( int i = 0; i < 26; i++ )
        {
            if( ara[i] != 0 )
            {
                f = 0;
            }
        }
        if(f)
        {
            printf("Case %d: Yes\n", caseno++);
        }
        else
        {
            printf("Case %d: No\n", caseno++);
        }

    }
    return 0;
}
