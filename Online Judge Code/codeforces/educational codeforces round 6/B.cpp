#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    int ara[] = {6,2,5,5,4,5,6,3,7,6};
    cin >> a >> b ;
    long long ans = 0;
    for( int i = a; i <= b; i++ )
    {
        int x = i;
        while( x > 0 )
        {
            ans += ara[x%10];
            x /= 10;
        }
    }
    cout << ans << endl;
}


