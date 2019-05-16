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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    for( int i = 1; i*i < n ; i++ )
    {
        intl t = n-i*i, l = sqrt(t);
        if( n%i==0 )
        {
            if((n/i+i)%2==0 && (n/i-i)%2==0)
            {
                intl v = (n/i+i)/2, u = (n/i-i)/2;
                intl m = v*v+u*u, k = 2*v*u;
                cout << k << " " << m << endl;
                return 0;
            }
            else if( (n/i)%2 == 0 )
            {
                intl v = (n/i)/2, u = i;
                if(v==u)
                    continue;
                intl m = v*v + u*u, k = abs(v*v-u*u);
                cout << k << " " << m << endl;
                return 0;
            }
        }
        else if( l*l == t )
        {
            intl v = l, u = i;
            if(v==u)
                continue;
            intl m = abs(v*v-u*u), k = 2*v*u;
            cout << m << " " << k << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}




