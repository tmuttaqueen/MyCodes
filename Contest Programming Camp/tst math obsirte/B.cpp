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

int ara[10000005];
int sum[10000005];
int mx =10000000;
bitset<10000005>f;

void sieve()
{
    for( int i = 2; i <= mx; i+=2 )
    {
        sum[2] += ara[i];
        f[i] = 1;
    }
    for( int i = 3; i <= mx; i+=2 )
    {
        if( f[i] == 1 ) continue;
        //what_is(i);
        for( int j = i; j <= mx; j+=i )
        {
            sum[i] += ara[j];
            f[j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    int a;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        ara[a]++;
    }
    sieve();
    int m;
    cin >> m;
    for( int i = 1; i<= mx; i++ )
    {
        sum[i] += sum[i-1];
    }
    for( int i =0; i < m; i++ )
    {
        int l, r;
        cin >> l >> r;
        l = min(l,mx);
        r = min(mx,r);
        cout << sum[r] - sum[l-1] << endl;
    }
    return 0;
}
