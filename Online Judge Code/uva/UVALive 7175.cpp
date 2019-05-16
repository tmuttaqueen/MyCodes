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

vector<int>pr;
bool flag[100005];

void sieve()
{
    pr.pb(2);
    for( int i = 3; i*i <= 100002; i+=2 )
    {
        if( flag[i] == 0 )
        {
            for( int j = i+i; j <= 100002; j+=i ) flag[j] = 1;
        }
    }
    for( int i = 3; i <= 100002; i+=2 )
        if(flag[i]==0)
            pr.pb(i);
}

int main()
{
    //ios::sync_with_stdio(false);
    filein;
    sieve();
    int t;
    scanf("%d", &t);
    double ans[100];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 2;
    for( int i = 4; i < 100; i++ )
    {
        double temp = 0;
        int d = i/2;
        for( int k = 1; k < d; k++ )
        {
            temp += 2*ans[i-k];
        }
        if(i%2)
            temp += 2*ans[i-d];
        else
            temp += ans[i-d];
        //what_is(temp);
        temp /= (i-1);
        //what_is(temp);
        ans[i] = 1+temp;
        //what_is(ans[i]);
    }
    while(t--)
    {
        intl n;
        scanf("%lld", &n);
        int d = 0;
        for( int i = 0; i < pr.size(); i++ )
        {
            //what_is(pr[i]);
            if(n%pr[i]==0)
            {
                while(n%pr[i]==0)
                {
                    n/=pr[i];
                    d++;
                }
            }
        }
        if(n!=1)
            d++;
        //what_is(d);
        cout << setprecision(10) << fixed << ans[d] << endl;
        //printf("%.10Lf\n", ans[d]);
    }

    return 0;
}




