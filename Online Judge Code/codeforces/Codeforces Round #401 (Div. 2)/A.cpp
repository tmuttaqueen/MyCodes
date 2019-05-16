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
    intl n, k;
    cin >> n >> k;
    n = n% 6;
    int ans = 0;
    if( n == 0 )
    {
        ans = k;
    }
    else if(n==1)
    {
        if( k == 0 ) ans = 1;
        if( k == 1 ) ans = 0;
        if( k == 2 ) ans = 2;
    }
    else if(n==2)
    {
        if( k == 0 ) ans = 1;
        if( k == 1 ) ans = 2;
        if( k == 2 ) ans = 0;
    }
    else if(n==3)
    {
        if( k == 0 ) ans = 2;
        if( k == 1 ) ans = 1;
        if( k == 2 ) ans = 0;
    }
    else if(n==4)
    {
        if( k == 0 ) ans = 2;
        if( k == 1 ) ans = 0;
        if( k == 2 ) ans = 1;
    }
    else
    {


        if( k == 0 ) ans = 0;
        if( k == 1 ) ans = 2;
        if( k == 2 ) ans = 1;

    }

    cout << ans << endl;
    return 0;
}




