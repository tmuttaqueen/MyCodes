#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

vector<int>all[100*100*100+5];

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t, w;
    //cin >> t >> w;
    scanf("%d %d", &t, &w);
    while(t--)
    {
        int res = -1;

        all[0].clear();
        printf("49\n");
        fflush(stdout);
        intl p;
        scanf("%lld", &p);
        intl base = 1LL<<8;
        ///r1, r4, r5
        int cnt = 0;
        for( intl x = 0; x <= 100; x++ )
        {
            for( intl y = 0; y <= 100; y++ )
            {
                for( intl z = 0; z <= 100; z++ )
                {
                    intl d = x*(1LL<<49) + y*(1LL<<12) + z*(1LL<<9);
                    intl temp = p - d;
                    //cout << temp << endl;
                    if( temp%base == 0 && temp >= 0 )
                    {
                        //cout << "temp " << temp << endl;
                        temp /= base;
                        intl r6 = temp%base;
                        temp -= r6;
                        temp /= base;
                        intl r3 = temp%base;
                        temp -= r3;
                        temp /= base;
                        intl r2 = temp;
                        if( r2*base*base*base + r3*base*base + r6*base == p - d && r2 >= 0 && r2 <= 100 && r3 >= 0 && r3 <= 100 && r6 >=0 && r6 <= 100 )
                        {
                            all[cnt].push_back(x);
                            all[cnt].push_back(r2);
                            all[cnt].push_back(r3);
                            all[cnt].push_back(y);
                            all[cnt].push_back(z);
                            all[cnt].push_back(r6);
                            //cout << "in" << endl;
                            cnt++;
                            all[cnt].clear();
                        }
                    }
                    //cout << cnt << endl;
                }
            }
        }
        //cout << cnt << endl;
        int v = 315;
        printf("%d\n", v);
        fflush(stdout);
        scanf("%lld", &p);

        for( int i = 0; i < cnt; i++ )
        {
            intl sum = 0;
            for( int j = 5; j < 6; j++ )
            {
                int x = v/(j+1);
                sum += (1LL<<x)*all[i][j];
                //cout << all[i][j] << " ";
            }
            //cout << "s " << sum << endl;
            if( sum == p )
            {
                res = i;
                break;
            }
        }

        for( int i = 0; i < 6; i++ )
        {
            if( i == 5 )
            {
                printf("%d\n", all[res][i] );
                continue;
            }
            printf("%d ", all[res][i]);
        }
        fflush(stdout);
        int r;
        scanf("%d", &r);
        if( r == -1 ) return 0;
    }

    return 0;
}
