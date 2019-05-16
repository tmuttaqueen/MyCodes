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
const int M = 7678;

char str[M];
int cnt[M], freq[M];

int main()
{

    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int k;
        memset( cnt, 0, sizeof cnt );
        memset( freq, 0, sizeof freq );
        int z = 26;
        freq[0] = 26;
        scanf("%s %d", str, &k);
        int ans = 0;
        //cout << str << endl;
        for( int i = 0; str[i]; i++ )
        {
            for( int j = i; str[j]; j++ )
            {
                int d = str[j] - 'a';
                int p = cnt[d];
                cnt[d]++;
                freq[p]--;
                freq[ cnt[d] ]++;
                if( freq[0] <= ( 26 - k) && (j-i+1)%( 26 - freq[0] ) == 0 )
                {
                    int x = (j-i+1)/( 26 - freq[0] );
                    if( freq[x] == ( 26 - freq[0] ) )
                        ans++;
                }
            }
            for( int j = i; str[j]; j++ )
            {
                int d = str[j] - 'a';
                int p = cnt[d];
                cnt[d]--;
                freq[p]--;
                freq[ cnt[d] ]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
