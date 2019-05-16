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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    map<int,int>mm;
    for( int i = 0; i < 10; i++ )
    {
        cin >> n;
        for( int j  = 2; j <= n; j++ )
        {
            if( n%j == 0 )
            {
                while( n%j == 0 )
                {
                    mm[j]++;
                    n/=j;
                }
            }
        }

    }
    map<int,int>::iterator it;
    it = mm.begin();
    intl ans = 1;
    while( it != mm.end() )
    {
        ans = ans*((*it).yy + 1);
        ans %= 10;
        it++;
    }
    cout << ans << endl;
    return 0;
}
