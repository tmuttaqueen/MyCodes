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
    //ios::sync_with_stdio(false);
    //filein;
    intl n, flag = 0;
    scanf("%lld", &n);
    for( intl i = 0; flag == 0 && i < 1000; i++ )
    {
        intl t = n - i*1234567;
        if(t<0)
            break;
        for( intl j = 0; flag == 0 && j < 10000; j++ )
        {
            int k = t - j*123456;
            if( k < 0 )
                break;
            if( k%1234 == 0 )
            {
                flag = 1;
            }
        }
    }
    if( flag )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}



