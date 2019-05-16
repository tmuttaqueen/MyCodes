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

intl ara[400005], pre[400005];
intl val[400005], calk[400005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    intl anss = 0;
    cin >> n;
    for( intl i = 0; i < n; i++ )
    {
        cin >> ara[i];
        val[ara[i]] += 1;
    }
    for( intl i = 1; i <= 400000; i++  ) val[i] += val[i-1];

    sort( ara, ara + n );
    for( intl i = 0; i < n; i++ )
    {
        intl d = ara[i];
        intl ans = 0;
        //what_is(d);
        if( calk[d] == 0 )
        {
            for( intl j = d; j <= 200000; j+=d )
            {
                ans += ( val[j+d-1] - val[j-1] )*j;
                //what_is(j);
            }
            //what_is(ans);
            calk[d] = ans;
            anss = max(ans, anss);
        }

    }
    cout << anss << endl;
    return 0;
}




