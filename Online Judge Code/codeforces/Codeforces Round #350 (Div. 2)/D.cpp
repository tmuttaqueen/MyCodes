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
#define pii         pair<intl, intl>

intl s1 = 0, k, n, s2 = 0;

bool ispos( intl x, pii vec[] )
{
    intl sum = 0, temp;
    for( int i = 0; i < n; i++ )
    {
        temp = x*vec[i].xx - vec[i].yy;
        if( temp >= 0 )
            sum += temp;
        if( sum > k )
            return 0;
    }
    //what_is(sum);
    return sum <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl ans, xp = 1e10;
    cin >> n >> k;
    pii vec[n];
    ans = -1;
    for( int i = 0; i < n; i++ )
    {
        cin >> vec[i].xx;
        s1 += vec[i].xx;
    }
    for( int i = 0; i < n; i++ )
    {
        cin >> vec[i].yy;
        s2 += vec[i].yy;
        xp = min( xp, vec[i].yy/vec[i].xx );
    }
    intl need = 0;
    for( int i = 0; i < n; i++ )
    {
        need += (vec[i].yy - xp*vec[i].xx);
    }
    need = s1 - need;
    if( need > k  )
    {
        cout << xp << endl;
        return 0;
    }
    intl l = 0, r = 2000000001;
    while(l <= r)
    {
        intl m = (l+r)/2;
        if( ispos(m, vec) )
        {
            ans = m;
            l = m+1;
        }
        else
            r = m-1;
        //cout << " l " << l << " r " << r << endl;
    }
    cout << ans << endl;
    return 0;
}


