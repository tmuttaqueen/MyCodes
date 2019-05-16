#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl cross( intl ax, intl ay, intl bx, intl by )
{
    return ax*by - ay*bx;
}

intl x[101], y[101];
int n;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while( 1 )
    {
        cin >> n;
        if(n==0) break;
        for( int i = 0; i < n; i++ )
        {
            cin >> x[i] >> y[i];
        }
        int f = 1;
        for( int i = 0; i < 100; i++ )
        {
            int a = i%n, b = (i+1)%n, c = (i+2)%n, d = (i+3)%n;
            intl c1 = cross( x[b] - x[a], y[b] - y[a], x[c] - x[a], y[c] - y[a] );
            intl c2 = cross( x[c] - x[b], y[c] - y[b], x[d] - x[b], y[d] - y[b] );
            if( c1*c2 < 0 )
            {
                f = 0;
            }
        }
        if(f)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;

    }



    return 0;
}
