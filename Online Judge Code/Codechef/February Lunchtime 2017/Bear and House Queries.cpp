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
    int low = 0, high = 1000;
    int ans = -1;
    char str[100];
    while( low <= high )
    {
        int mid = (low+high)/2;
        printf("? %d 0\n", mid);
        fflush(stdout);
        scanf("%s", str);
        //gets(str);
        if( strcmp(str, "YES") == 0 )
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    int x = ans*2;
    low = 0; high = 1000;
    ans = -1;
    //str[100];
    while( low <= high )
    {
        int mid = (low+high)/2;
        printf("? 0 %d\n", mid);
        fflush(stdout);
        //gets(str);
        scanf("%s", str);
        if( strcmp(str, "YES") == 0 )
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    int h = ans - x;
    low = 0; high = 1000;
    ans = -1;
    //char str[100];
    while( low <= high )
    {
        int mid = (low+high)/2;
        printf("? %d %d\n", mid, x);
        fflush(stdout);
        //gets(str);
        scanf("%s", str);
        if( strcmp(str, "YES") == 0 )
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    int y = ans;
    printf("! %d\n", x*x + h*y );
    fflush(stdout);
    return 0;
}




