//what am i doing? i really don't know. why do i wait for u in library even
//after knowing that u have someone else in your life? please ignore me and save me
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

intl exam[100005], day[100005];
intl n,m;
int vis[100005];

bool ispos( intl d )
{
    intl av = d - m, k = 0;
    memset( vis, 0, sizeof vis );
    for( intl i = d; i >= 1; i-- )
    {
        if( exam[i] > 0 && vis[ exam[i] ] == 0 )
        {
            av -= day[ exam[i] ];
            //what_is(exam[i]);
            vis[ exam[i] ] = 1;
            k++;
        }
        av = min( av, i - m + k - 1 );
    }
    //what_is(av);
    //what_is(k);
   // debug;
    if( av >= 0 && k == m )
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> exam[i];
    }
    for( int i = 1; i <= m; i++ )
    {
        cin >> day[i];
    }
    intl l = 1, h = n;
    intl ans = -1;
    while( l <= h )
    {
        intl m = (l+h)/2;
        //what_is(m);
        if( ispos(m) )
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m+1;

    }
    cout << ans << endl;

    return 0;
}



