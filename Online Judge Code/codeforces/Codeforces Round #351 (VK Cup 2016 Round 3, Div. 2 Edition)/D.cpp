#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

void rever( int ara[], int n )
{
    int x = n/2;
    for( int i = 0; i < x; i++ )
    {
        int temp = ara[i];
        ara[i] = ara[n-i-1];
        ara[n-i-1] = temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    cin >> n >> k;
    int a, b, cx, dx;
    cin >> a >> b >> cx >> dx;
    if( k < (n+1) )
    {
        cout << -1 << endl;
        return 0;
    }
    int x = a, y = b;
    if( a > b )
    {
        x = b;
        y = a;
    }

    int ans[n+1], c = 0;
    for( int i = x; i > 0; i-- ) ans[c++] = i;
    for( int i = x+1; i < y; i++ ) ans[c++] = i;
    for( int i = n; i >= y; i++ ) ans[c++] = i;

    if( a > b )
    {
        rever(ans, n);
    }

    for( int i = 0; i < c; i++ )
    {
        cout << ans[i] <<   ' ';

    }
    cout << endl;
    c = 0;
    x = cx;
    y = dx;
    if( dx < cx )
    {
        x = dx;
        y = cx;
    }
    for( int i = x; i > 0; i-- ) ans[c++] = i;
    for( int i = x+1; i < y; i++ ) ans[c++] = i;
    for( int i = n; i >= y; i++ ) ans[c++] = i;
    if( dx < cx )
    {
        rever(ans, n);
    }
    for( int i = 0; i < c; i++ )
    {
        cout << ans[i] <<   ' ';

    }
    cout << endl;
    return 0;
}


