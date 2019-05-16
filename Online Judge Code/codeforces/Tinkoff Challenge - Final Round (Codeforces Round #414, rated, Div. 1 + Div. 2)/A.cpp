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

int ara[1111111], temp[111111];
map<int, int>mm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int a, b, c,x;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    for( int i = 0;i < n; i++ )
    {
        cin >> x;
        temp[i] = x;
    }
    temp[n] = a;
    temp[n+1] = b;
    temp[n+2] = c;
    sort( temp, temp+n+3 );
    for( int i = 0; i < n+3;i++ )
    {
        mm[ temp[i] ] = i;
    }
    int aa = a, bb = b, cc = c;
    for( int i = 0;i < n+3; i++ )
    {
        if( temp[i] == aa )
        {
            aa = -1;
            continue;
        }
        else if( temp[i] == bb )
        {
            bb = -01;
            continue;
        }
        else if( temp[i] == cc )
        {
            cc = -1;
            continue;
        }
        x = mm[temp[i]];
        //what_is(x);
        ara[x]++;
    }
    a = mm[a];
    b = mm[b];
    c = mm[c];
    intl ans = 0;
    for( int i = b+1; i < c; i++ )
    {
        ans += ara[i];
    }
    cout << ans << endl;
    return 0;
}



