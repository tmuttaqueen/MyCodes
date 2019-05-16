#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl a[235467], b[234567];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for( int i = 0; i < n; i++ )
    {
        cin >> b[i];

    }
    int ind = -1;
    for( int i = n-1; i >= 0; i-- )
    {
        if( b[i] != 0 && b[ ((i-1)%n+n)%n ] != 0  )
        {
            ind = i;
            break;
        }
    }
    if( ind == -1 )
    {
        cout << "NO" << endl;
        return 0;
    }
    ind--;
    if( ind < 0 ) ind += n;
    a[ind] = b[ind];// cout << ind << endl;
    for( int i = 1; i < n; i++ )
    {
        ind--;
        if( ind < 0 ) ind = ind + n;
        a[ind] = a[(ind+1)%n] + b[ind%n];

    }


    int f = 1;
    for( int i = 0; i < n; i++ )
        if( a[i] == 0 )
            f = 0;
    for( int i = 0; i < n && f == 1; i++ )
    {
        if( a[i]%a[(i+1)%n] != b[i]  )
        {
            f = 0;
        }
    }

    if( f == 0 )
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for( int i = 0; i < n; i++ )
        cout << a[i] << " ";

    cout << endl;

    return 0;
}
