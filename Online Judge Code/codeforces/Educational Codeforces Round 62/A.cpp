#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int ara[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for( int i = 1; i <= n; i++ ) cin >> ara[i];

    int day = 0, cur = 0;;
    for( int i = 1; i <= n; )
    {
        cur = ara[i];
        day++;
        for( int j = i; j <= n; j++ )
        {

            if( j > cur )
            {
                //cout << j << endl;
                i = j;
                break;
            }
            if( j == n )
            {
                i = j+1;
            }
            //cout << i << " " << j << " " << cur << endl;
            cur = max( cur, ara[j] );
        }
    }
    cout << day << endl;

    return 0;
}

