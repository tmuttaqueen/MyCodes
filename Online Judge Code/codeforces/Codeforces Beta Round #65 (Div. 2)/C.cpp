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
#define ldb        long double

bool flag[200005];

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    vector<int>pr;
    int num = n;
    if( n%4==0 )
        pr.pb(4);
    while(n%2==0)
        n/=2;
    for( int i = 3; i*i <= n; i+=2 )
    {
        if(n%i==0)
        {
            pr.pb(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        pr.pb(n);
    for( int i = 1; i <= num; i++ )
    {
        int a;
        scanf("%d", &a);
        flag[i] = flag[num+i] = a;
    }
    int ans = 0;
    for( int i = 0; i < pr.size() && ans == 0; i++ )
    {
        int p = pr[i], d = num/p;
        //what_is(p);
        for( int s = 1; s <= d && ans == 0; s++ )
        {
            int tt = 1;
            for( int k = s; k <= num+s && tt; k+=d )
            {
                //what_is(k);
                if( flag[k] == 0 )
                    tt = 0;
            }
            if( tt )
                ans = 1;
        }
    }
    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}




