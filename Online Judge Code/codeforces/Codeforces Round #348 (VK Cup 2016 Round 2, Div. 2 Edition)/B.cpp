#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

bool flag[100000+5];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    memset( flag, 0, sizeof(flag) );
    cin >> n;
    string s;
    cin >> s;
    int ara[n+5];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i+1];
    }
    int pos = 1;
    bool ans = 1;
    for( int i = 0; i <= (2*n) && ans == 1; i++ )
    {
        if( pos >= 1 && pos <= n )
        {
            if( flag[pos] == 1 )
            {
                ans = 0;
                break;
            }
            flag[pos] = 1;
            if( s[pos-1] == '>' )
                pos = pos + ara[pos];
            else
                pos = pos - ara[pos];
        }
        else
        {
            ans = 1;
            break;
        }
        //what_is(pos);
    }
    if( ans )
        cout << "FINITE\n";
    else
        cout << "INFINITE\n";
    return 0;
}


