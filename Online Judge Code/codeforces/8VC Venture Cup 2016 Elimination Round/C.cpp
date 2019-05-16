#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

int n, m;
int s = 0, e = 100000000, mm;

bool pos()
{
    int t = mm/6;
    int a = mm/2 - t;
    int b = mm/3 - t;
    if( n > a )
    {
        t = t - (n-a);
    }
    if( m > b )
    {
        t = t - (m-b);
    }
    if( t >= 0 )
        return true;
    else
        return false;
}

int main()
{
    //filein;

    cin >> n >> m;
    int ans = 1000000000;

    while( s <= e )
    {
        mm = (e+s)/2;
        if( pos() )
        {
            ans = mm;
            e = mm - 1;
        }
        else
        {
            s = mm + 1;
        }
    }
    cout << ans << endl;
    return 0;
}



