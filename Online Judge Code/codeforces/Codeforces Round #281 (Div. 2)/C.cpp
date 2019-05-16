#include <bits/stdc++.h>

using namespace std;

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

int x[200005], y[200005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> x[i];
    cin >> m;
    for( int i = 0; i < m; i++ ) cin >> y[i];
    x[n] = 2e9 + 5;
    n++;
    sort(x,x+n);
    sort(y, y+m);
    int d = x[0]-1;
    int *it = upper_bound(y,y+m,d );
    d = it - y;
    int a = 3*n-3, b = d*2 + (m-d)*3;
    //int a = 0, b = 2e9;
    for( int i = 0; i < n; i++ )
    {
        if( i < n-1 && x[i] == x[i+1] )
            continue;
        int d = x[i];
        //what_is(d);
        int *it = lower_bound(y,y+m,d );
        d = it - y;
        //what_is(d);
        int t1 = i*2 + (n-i-1)*3;
        if( i == n-1 )
            t1 = (n-1)*2;
        int t2 = d*2 + (m-d)*3;
        if( t1 - t2 == a - b && t1 > a )
        {
            //cout << " i " << i << endl;
            a = t1;
            b = t2;
        }
        else if( t1 - t2 > a - b )
        {
            //what_is(i);
            a = t1;
            b = t2;
        }
    }
    cout << a << ":" << b << endl;
    return 0;
}




