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
    filein;
    int n;
    cin >> n;
    int ara[n+1];
    memset( ara, -1, sizeof(ara) );
    for( int i= 0; i < n; i++ )
    {
        int a;
        scanf("%d", &a);
        ara[a] = 1;
    }
    int s;
    for( int i = 0; i <= n; i++ )
    {
        if( ara[i] == -1 )
        {
            printf("%d", i);
            s = i;
            break;
        }
    }
    for( int i = s+1; i <= n; i++ )
    {
        if( ara[i] == -1 )
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}



