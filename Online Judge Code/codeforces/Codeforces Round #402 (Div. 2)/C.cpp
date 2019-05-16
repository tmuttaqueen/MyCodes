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

struct data
{
    int a, b, d;
};

bool comp( data a, data b )
{
    return a.d < b.d;
}

data dt[200005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    intl sum = 0;
    cin >> n >> k;
    for( int i = 0; i < n; i++ )
    {
        cin >> dt[i].a;
    }
    for( int i = 0; i < n; i++ )
    {
        cin >> dt[i].b;
        sum += dt[i].b;
    }
    for( int i = 0; i < n; i++ )
    {
        dt[i].d = dt[i].a - dt[i].b;
    }
    sort( dt, dt + n, comp );

    for( int i = 0; i < k; i++ )
    {
        sum += dt[i].d;
    }
    for( int i = k ; i< n; i++ )
    {
        if( dt[i].d > 0 )
            break;
        sum += dt[i].d;
    }
    cout << sum << endl;
    return 0;
}



