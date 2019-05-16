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

int ara[20][2<<18];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int num = 1<<n;
        for( int i = 1; i<= num; i++ )
        {
            scanf("%d", &ara[0][i]);
        }
        int ans = 0;
        int st = ara[0][1];
        int flag = 1;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 2; j <= num; j += 2 )
            {
                int x = ara[i-1][j-1], y = ara[i-1][j];
                int mx = max(x,y), mn = min(x,y);
                if( j == 2 && flag == 1 )
                {
                    if( ara[i-1][j-1] + k < ara[i-1][j] )
                    {
                        flag = 0;
                        ara[i][j/2] = ara[i-1][j];
                    }

                    else if( ara[i-1][j-1] > ara[i-1][j] )
                    {
                        ara[i][j/2] = ara[i-1][j-1];
                    }
                    else if( ara[i-1][j-1] + k >= ara[i-1][j] )
                    {
                        ara[i][j/2] = ara[i-1][j-1];
                        ans++;
                    }
                    continue;
                }
                if( st + k >= mx )
                {
                    ara[i][j/2] = mx;
                }
                else if( mn + k >= mx )
                {
                    ara[i][j/2] = mn;
                    ans++;
                }
                else
                {
                    ara[i][j/2] = mx;
                }
            }
            num /= 2;
            //what_is(num);
        }
        //what_is(flag);
        if( ara[n][1] != st )
            flag = 0;
        //what_is( ara[n][1] );
        //what_is(ans);
        if(flag)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }

    return 0;
}





