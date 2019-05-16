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
#define piii        pair<pii, int>

char str[100];

int main()
{
    //filein;
    int n, a ,b, flag =0;
    scanf("%d", &n);
    for( int i = 0; i < n; i++ )
    {
        getchar();
        scanf("%s %d %d", str, &a, &b);
        if( b > a && a >= 2400 )
        {
            flag =1;
            break;
        }
    }
    if( flag )
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

