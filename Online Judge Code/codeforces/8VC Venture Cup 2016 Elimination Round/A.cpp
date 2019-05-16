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
    char str[210];
    scanf("%d", &n);
    getchar();
    gets(str);
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = i+1; j < n; j++ )
        {
            int x = 0, y = 0;
            for( int a = i; a <= j; a++ )
            {
                if( str[a] == 'R' )
                    x++;
                else if( str[a] == 'L' )
                    x--;
                else if( str[a] == 'U' )
                    y++;
                else if( str[a] == 'D' )
                    y--;
            }
            if( x==0 && y==0 )
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}



