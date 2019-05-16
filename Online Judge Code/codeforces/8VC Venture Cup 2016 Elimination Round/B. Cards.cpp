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


int main()
{
    //filein;
    int n;
    scanf("%d", &n);
    getchar();
    int r = 0, g = 0, b = 0;
    char c;
    for( int i = 0; i < n; i++ )
    {
        c = getchar();
        if( c == 'R' )
            r++;
        else if( c == 'G' )
            g++;
        else
            b++;
    }
    //what_is(r);
    //what_is(g);
    //what_is(b);
    if( r == 0 && g == 1 && b == 1 )
    {
        cout << "R\n";
        return 0;
    }
    if( r == 1 && g == 0 && b == 1 )
    {
        cout << "G\n";
        return 0;
    }
    if( r == 1 && g == 1 && b == 0 )
    {
        cout << "B\n";
        return 0;
    }
    if( (r == 0 && g == 1 && b > 1) || (r == 1 && g == 0 && b > 1) )
    {
        cout << "GR\n";
        return 0;
    }
    if( (r > 1 && g == 1 && b == 0) || (r > 1 && g == 0 && b == 1) )
    {
        cout << "BG\n";
        return 0;
    }
    if( (r == 0 && g > 1 && b == 1) || (r == 1 && g > 1 && b == 0) )
    {
        cout << "BR\n";
        return 0;
    }
    if( r > 0 && b == 0 && g == 0 )
    {
        cout << "R\n";
        return 0;
    }
    if( r == 0 && b > 0 && g == 0 )
    {
        cout << "B\n";
        return 0;
    }
    if( r == 0 && b == 0 && g > 0 )
    {
        cout << "G\n";
        return 0;
    }
    cout << "BGR\n";
    return 0;
}



