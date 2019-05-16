#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 300005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

int ara[6] = {4,8,15,16,23,42};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val[4];
    for( int i = 0; i < 4; i++ )
    {
        printf("? %d %d\n", i+1, i+2);
        fflush(stdout);
        scanf("%d", &val[i]);
    }
    //for( int i = 0; i < 4; i++ ) cout << val[i] << endl;
    do
    {
        //printf("= %d %d %d %d %d %d\n", ara[0], ara[1],ara[2],ara[3],ara[4],ara[5]);
        int f = 1;
        for( int i = 0; i < 4; i++ )
        {
            if( ara[i]*ara[i+1] != val[i] )
            {
                f = 0;
            }
        }
        if(f)
        {
            printf("! %d %d %d %d %d %d\n", ara[0], ara[1],ara[2],ara[3],ara[4],ara[5]);
            break;
        }
    }while( next_permutation(ara,ara+6) );

    return 0;
}
