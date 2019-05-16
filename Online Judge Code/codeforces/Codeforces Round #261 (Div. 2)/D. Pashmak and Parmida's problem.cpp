#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define ldb         long double

intl mx = 1000005, bit[1000055], ara[1000005];
pii ff[1000005], ll[1000005];
int n;

bool comp( pii a, pii b )
{
    return a.xx < b.xx;
}

void update( int x )
{
    while(x <= n+10 )
    {
        bit[x] += 1;
        x += (x&(-x));
    }
}

intl query( int x )
{
    intl ans = 0;
    while( x > 0 )
    {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> ara[i];
    map<intl, intl>mm;
    for( int i = 1; i<= n; i++ )
    {
        mm[ara[i]]++;
        ff[i].xx = mm[ara[i]];
        ff[i].yy = i;

    }


    mm.clear();
    for( int i = n; i > 0; i-- )
    {
        mm[ara[i]]++;
        ll[i].xx = mm[ara[i]];
        ll[i].yy = i;
    }

    sort( ll+1, ll+n+1, comp );
    sort( ff+1, ff+n+1, comp );


    intl ans = 0, c = 1;
    for( int i = 1; i <= n; i++ )
    {
        int val = ff[i].xx;
        while( c <= n && ll[c].xx < val )
        {
            update( ll[c].yy );
            c++;
        }
        int idx = ff[i].yy;
        ans += ( query(n) - query(idx) );
    }
    cout << ans << endl;
    return 0;
}




