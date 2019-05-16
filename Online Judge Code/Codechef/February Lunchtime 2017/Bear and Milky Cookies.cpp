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


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int n;
        int flag = 1, f = 0;
        char str[100];
        scanf("%d\n", &n);
        while(n--)
        {
            scanf("%s", str);
            if( strcmp(str, "cookie")== 0 )
            {
                if( f == 1 )
                    flag = 0;
                f = 1;
            }
            else
            {
                f = 0;
            }
        }
        if( f == 1 )
            flag = 0;
        if( flag )
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
