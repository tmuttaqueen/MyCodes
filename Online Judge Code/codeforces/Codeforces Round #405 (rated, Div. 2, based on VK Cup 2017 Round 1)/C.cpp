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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    char str[100][10];
    string ch[100];
    int ara[100];
    memset( ara, -1, sizeof ara );
    for( int i = 1; i <= 26; i++ )
    {
        str[i][0] = 'A' + i - 1;
        str[i][1] = '\0';
    }

    for( int i = 27; i < 52; i++ )
    {
        str[i][0] = 'A';
        str[i][1] = 'a' + i - 27;
        str[i][2] = '\0';
    }
    int c = 1;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n-k+1; i++ )
    {
        cin >> ch[i];
    }
    if( n == k && ch[0] == "NO" )
    {
        ara[0] = ara[1] = c++;
        for( int i = 2; i < n; i++ ) ara[i] = c++;
    }
    else if( n == k && ch[0] == "YES" )
    {
        for( int i = 0; i < n; i++ ) ara[i] = c++;
    }
    else
    {
        for( int i = 0; i < n; i++ ) ara[i] = c++;
        for( int i = n-k; i >= 0 ; i-- )
        {
            if( ch[i] == "NO" )
            {
                ara[i] = ara[i+k-1];
            }
        }
        for( int i = n-k+1; i < n; i++ )
        {
            if( ara[i] == -1 )
                ara[i] = c++;
        }
    }
    for( int i = 0; i < n; i++ )
        cout << str[ara[i]] << " ";
    cout << endl;
    return 0;

}



