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

int ara[10];
int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    intl mn = n;
    for( int i = 0; i < s1.length(); i++ )
    {
        ara[ s1[i] - '0' ]++;
    }
    for( int i = 0; i < s1.length(); i++ )
    {
        int x = s2[i] - '0';
        for( int j = x; j >= 0; j-- )
        {
            if( ara[j] > 0 )
            {
                ara[j]--;
                mn--;
                break;
            }
        }
    }

    intl mx = 0;
    memset( ara, 0, sizeof ara );
    for( int i = 0; i < s1.length(); i++ )
    {
        ara[ s1[i] - '0' ]++;
    }
    for( int i = 0; i < s1.length(); i++ )
    {
        int x = s2[i] - '0';
        for( int j = x-1; j >= 0; j-- )
        {
            if( ara[j] > 0 )
            {
                ara[j]--;
                mx++;
                break;
            }
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}



