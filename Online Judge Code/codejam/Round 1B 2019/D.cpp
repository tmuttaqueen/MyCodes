#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
int ara[] = {1,63,126,189,252,315};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for( int i = 0; i < 6 ; i++ )
    {
        int res = 0;
        for( int j = 1; j <= 6; j++ )
        {
            cout << ara[i]/j << " ";
        }
        cout << endl;

    }

    for( int i = 1; i <= 377; i++ )
    {
        cout << i << ": " << endl;
        for( int j = 1; j <= 6; j++ )
        {
            cout << i/j << " ";
        }
        cout << endl;
    }

    return 0;
}
