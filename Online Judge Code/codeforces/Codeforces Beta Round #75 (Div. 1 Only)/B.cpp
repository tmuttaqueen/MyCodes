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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int tree[111111];
int ara[111111];



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> ara[i];
    tree[n-1] = ara[n-1];
    for( int i = n-2; i >= 0; i-- )
    {
        tree[i] = min( tree[i+1], ara[i] );
    }

    for( int i = 0; i < n; i++ )
    {
        int l = i, h = n-1, ans = i;
        while( l <= h )
        {
            int m = (l+h)/2;
            if( tree[m] < ara[i] )
            {
                l = m+1;
                ans = m;
            }
            else
            {
                h = m-1;
            }
        }
        cout << ans-i -1 << " ";
    }
    cout << endl;


    return 0;
}
