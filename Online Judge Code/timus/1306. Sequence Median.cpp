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
#define piii        pair<pii, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    unsigned int ara[n];
    for( int i = 0; i < n; i++ ) scanf("%u", &ara[i]);
    sort( ara, ara+n );
    if( n&1 )
    {
        printf("%.1f\n", ara[n/2]/1.0 );
    }
    else
    {
        printf("%.1f\n", (ara[n/2-1]+ara[n/2])/2.0 );
    }

    return 0;
}



