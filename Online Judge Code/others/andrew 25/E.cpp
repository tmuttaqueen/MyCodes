#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0, x =0, y = 0, c = 0;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j > 0; j = (j-1)&i )
        {
            c++;
            //cout << i << ' ' << j << ' ' << (i&j) << endl;
        }
    }
    cout << c << endl;

    return main();
}
