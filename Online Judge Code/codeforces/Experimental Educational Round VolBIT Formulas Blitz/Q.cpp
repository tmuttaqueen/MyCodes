#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    long long a,b,c;
    cin >> a >> b >> c;
    double ans = (a*a*a/2.0)/sqrt(2) + b*b*b/sqrt(2) + 0.5257311121*1.25*c*c*c/0.726542528;
    ans /= 3.0;
    printf("%.10lf\n", ans);

    return 0;
}



