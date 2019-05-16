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


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        intl sq = sqrt(n);
        intl s = n;
        intl prev = n;
        for( int i = 2; i <= sq; i++ )
        {
            intl temp = n/i;
            s += (prev - temp)*(i-1);
            s += temp;
            prev = temp;
        }
        //what_is(s);
        s += (prev-sq)*sq;
        printf("Case %d: %lld\n", caseno++, s);
    }

    return 0;
}



