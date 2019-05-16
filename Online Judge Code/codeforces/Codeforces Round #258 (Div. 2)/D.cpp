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

char ara[100005], str[100005], rev[100005];
int cnt[100005];
intl even[100005], odd[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, len = -1;
    scanf("%s", ara);
    str[++len] = ara[0];
    cnt[len]++;
    for( int i = 1; ara[i]; i++ )
    {
        if( ara[i] != ara[i-1] )
        {
            str[++len] = ara[i];
            cnt[len]++;
        }
        else
        {
            cnt[len]++;
        }
    }
    str[++len] = '\0';
    odd[0] = 1;
    even[0] = 0;
    int c = 0;
    intl o = 1, e = 0;
    for( int i = 1; ara[i] ; i++ )
    {
        if( ara[i-1] == ara[i] )
        {
            even[i] = odd[i-1];
            odd[i] = even[i-1] + 1;
        }
        else
        {
            c++;
            int ind = i - cnt[c-1] - 1;
            if( cnt[c-1] % 2 == 1 )
            {
                even[i] = (ind < 0 ? 0: even[ind]);
                odd[i] = (ind < 0 ? 1: odd[ind] + 1);
            }
            else
            {
                even[i] = (ind < 0 ? 0: odd[ind]);
                odd[i] = (ind < 0 ? 1: even[ind] + 1);
            }
        }
        //cout << even[i] << " " << odd[i] << endl;
        o += odd[i];
        e += even[i];
    }
    cout << e << " " << o << endl;
    return 0;
}



