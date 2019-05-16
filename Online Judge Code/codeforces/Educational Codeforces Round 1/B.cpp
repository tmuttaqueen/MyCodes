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

char str[10005];
char temp[10005];

void op( int x, int y, int n )
{
    if( n == 0 ) return;
    int lim = y-n, c = 0;
    for( int i = lim+1; i <= y; i++ )
        temp[c++] = str[i];
    for( int i = lim; i >= x; i-- )
        str[y--] = str[i];
    for( int i = 0; i < c; i++ )
        str[x++] = temp[i];
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    gets(str);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int n = b-a+1;
        b--;
        a--;
        op( a, b, k%n );
    }
    puts(str);

    return 0;
}



