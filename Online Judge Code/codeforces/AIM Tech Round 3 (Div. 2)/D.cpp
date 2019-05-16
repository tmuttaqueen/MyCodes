//you were looking so beautiful in that red sari !!
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
    intl a, b, c, d;
    cin >> a >> b >> c >> d;
    if( a == b && b == c && c == d && d == 0 )
    {
        cout << 0 << endl;
        return 0;
    }
    intl sa = sqrt(1+8*a), sd = sqrt(1+8*d);
    if( sa*sa != 1+8*a || sd*sd != (1+8*d) )
    {
        cout << "Impossible\n";
        return 0;
    }
    if( sa%2 != 1 || sd%2 != 1  )
    {
        cout << "Impossible\n";
        return 0;
    }

    intl n0 = (1+sa)/2, n1 = (1+sd)/2;
    //what_is(n0);
    //what_is(n1);
   // debug;
    if( d == 0 )
    {
        n1 = 0;
        if( (b + c) != n0 && (b+c) != 0 )
        {
            cout << "Impossible\n";
            return 0;
        }
        else
        {
            for( int i = 0; i < b; i++ )
                cout << 0;
            if( (b+c) != 0 )
                cout << 1;
            for( int i = b; i < n0; i++ )
                cout << 0;
            cout << endl;
            return 0;
        }
    }
    if( a == 0 )
    {
        if( (b + c) != n1 && (b+c) != 0 )
        {
            cout << "Impossible\n";
            return 0;
        }
        else
        {
            for( int i = 0; i < c; i++ )
                cout << 1;
            if( (b+c) != 0 )
                cout << 0;
            for( int i = c; i < n1; i++ )
                cout << 1;
            cout << endl;
            return 0;
        }
        return 0;
    }
    if( n0*n1 != b+c )
    {
        cout << "Impossible\n";
        return 0;
    }

    int mid = b%n0, last = b/n0, first = n1 - last - 1;
    if( mid == 0 )
        first++;
    for( int i = 0; i < first; i++ )
    {
        cout << 1;
    }
    for( int i = 0; i < mid; i++ )
    {
        cout << 0;
    }
    if( mid != 0 )
        cout << 1;
    for( int i = 0; i < (n0-mid); i++ )
    {
        cout << 0;
    }
    for( int i = 0; i < last; i++ )
    {
        cout << 1;
    }
    cout << endl;
    return 0;
}





