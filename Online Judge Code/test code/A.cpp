#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c = 0, a = 0, b = 0;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( i == j ) continue;
            if( __gcd(n, abs(i-j)) == 2 )
            {
                //cout << abs(i-j) << endl;
                a++;
            }
            else if( __gcd(n, abs(i-j)) == 1009 )
            {
                b++;
            }
            if( abs(__gcd(n, i-j)) != 1 ) c++;
        }
    }
    cout << a << " " << b << " " << a + b << " " << c << ' ' << n*(n-1)/2 << endl;
    double s = c;
    s /= (n*(n-1));
    cout << s << endl;
    return 0;

}
