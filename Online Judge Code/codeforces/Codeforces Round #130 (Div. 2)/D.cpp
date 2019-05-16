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

intl ara[100];
intl price[100];
intl cnt[100];
intl mm[5];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl p;
    cin >> p;
    for( int i = 0 ;i < p; i++ )
        cin >> ara[i];
    for( int i = 0; i < 5; i++ )
    {
        cin >> price[i];
    }

    intl sum = 0;
    for( int i = 0 ;i < p; i++ )
    {
        sum += ara[i];
        for( int j = 4; j >= 0; j-- )
        {
            intl d = sum/price[j];
            sum -= d*price[j];
            cnt[j] += d;
        }
    }
    cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << endl;
    cout << sum << endl;
    return 0;
}




