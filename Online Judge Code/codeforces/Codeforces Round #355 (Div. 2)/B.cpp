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
    intl n, h, k;
    cin >> n >> h >> k;
    intl ara[n];
    for( int i = 0; i < n; i++ )
        cin >> ara[i];
    intl c = 0, ans = 0, now = 0,a;
    while(1)
    {
        while( c < n && now+ara[c] <= h )
        {
            now += ara[c++];
        }
        //debug;
        //what_is(now);
        //what_is(c);
        if( c < n )
        {
            intl temp = min( h - k, max(h - ara[c], (intl)0));
            //what_is(temp);
            intl ss = now - temp;
            if( ss < k )
                ss = ss+k;
            a = ss/k;
            ans += a;
            now -= a*k;
            if( now < 0 ) now = 0;
        }

        if( c >= n )
            break;
    }
    a = now/k;
    ans += a;
    now -= a*k;
    if( now <= k && now > 0 ) ans++;

    cout << ans << endl;

    return 0;
}


