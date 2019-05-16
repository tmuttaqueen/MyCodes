#include<bits/stdc++.h>

using namespace std;

#define intl long long

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        intl n, m, x, k;
        cin >> n >> m >> x >> k;
        cin.ignore();
        cin >> s;
        intl o = 0, e = 0;
        for( int i = 0; i < s.length(); i++  )
        {
            if( s[i] == 'O' ) o++;
            else e++;
        }
        intl a = 0;
        int p = 0;
        for( int i = 1; i <= m; i++ )
        {
            if( i%2 )
            {
                 p = min( x, o );
                 a += p;
                 o -= p;
            }
            else
            {
                p = min(x, e);
                a += p;
                e -= p;
            }
        }
        if( a >= n )
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }


    return 0;
}



