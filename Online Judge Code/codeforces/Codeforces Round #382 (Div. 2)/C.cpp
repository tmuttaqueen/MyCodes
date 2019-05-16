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
    intl n;
    cin >> n;
    int i = 0;
    if( n == 1 )
    {
        cout << 0 << endl;
        return 0;
    }
    else if( n == 2 )
    {
        cout << 1 << endl;
        return 0;
    }
    else if( n == 3 )
    {
        cout << 2 << endl;
        return 0;
    }
    intl p1 = 3, p2 = 5;
    intl c = 5;
    i = 2;
    while(c <= n)
    {
        i++;
        c = p1+p2;
        p1 = p2;
        p2 = c;
    }
    cout << i << endl;
    return 0;
}



