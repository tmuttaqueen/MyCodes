#include<bits/stdc++.h>

using namespace std;

#define intl long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        intl n, a, s = 0, p, q, r;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> a;
            if( i > 0 )
            {
                s += max(0LL, a-s);
            }
            else
                s = a;
            p = a;
        }
        cin >> p >> q >> r;
        s = (p-1)*s;
        cout << s << endl;
    }

    return 0;
}



