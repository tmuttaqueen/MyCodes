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

intl phi( intl n )
{
    intl ans = n;
    for( intl i = 2; i*i <= n; i++ )
    {
        if( n % i == 0 )
        {
            while(n%i ==0)
                n/=i;
            ans = ans/i;
            ans *= (i-1);
        }
    }
    if( n != 1 )
    {
        ans /= n;
        ans *= (n-1);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k;
    cin >> n >> k;
    k = (k+1)/2;
    for( int i = 0; i < k; i++ )
    {
        n = phi(n);
        if(n == 1)
            break;
    }
    cout << n%1000000007 << endl;
    return 0;
}




