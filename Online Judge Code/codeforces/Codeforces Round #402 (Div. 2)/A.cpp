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

int a1[6], a2[6];
int ara1[1000], ara2[1000];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;

    for( int i= 0; i <n ;i++ )
    {
        cin >> ara1[i];
        a1[ara1[i]]++;
    }
    for( int i= 0; i <n ;i++ )
    {
        cin >> ara2[i];
        a2[ara2[i]]++;
    }
    for( int i = 1; i <= 5; i++ )
    {
        if( (a1[i]+a2[i])%2 )
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;

    for( int i = 1; i <= 5; i++ )
    {
        int x = a1[i] + a2[i];
        x /= 2;
        ans += abs( x-a1[i] );
    }

    cout << ans/2 << endl;

    return 0;

}



