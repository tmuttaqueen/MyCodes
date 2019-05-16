#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

int gcd( int a, int b )
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        pii ara[n];
        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &ara[i].xx, &ara[i].yy);
        }
        int ans = -1;
        map<pii, int>mm;
        for( int i = 0; i < n; i++ )
        {
            mm.clear();
            for( int j = 0; j < n; j++ )
            {
                if(i!=j)
                {
                    if( ara[j].yy==ara[i].yy )
                    {
                        mm[mp(0,1)]++;
                        ans = max(ans, mm[mp(0,1)]);
                    }
                    else if( ara[j].xx==ara[i].xx )
                    {
                        mm[mp(1,0)]++;
                        ans = max(ans, mm[mp(1,0)]);
                    }
                    else if( (ara[j].xx-ara[i].xx > 0 && ara[j].yy-ara[i].yy > 0) || (ara[j].xx-ara[i].xx < 0 && ara[j].yy-ara[i].yy < 0) )
                    {
                        int a = abs(ara[j].xx-ara[i].xx), b = abs(ara[j].yy-ara[i].yy);
                        int g = gcd(a,b);
                        a/=g;
                        b/=g;
                        mm[mp(b,a)]++;
                        ans = max(ans, mm[mp(b,a)]);
                    }
                    else
                    {
                        int a = abs(ara[j].xx-ara[i].xx), b = abs(ara[j].yy-ara[i].yy);
                        int g = gcd(a,b);
                        a/=g;
                        b/=g;
                        mm[mp(-b,a)]++;
                        ans = max(ans, mm[mp(-b,a)]);
                    }
                }
            }
        }
        if(ans == -1) ans++;
        printf("Case %d: %d\n", caseno++, ans+1);
    }

    return 0;
}




