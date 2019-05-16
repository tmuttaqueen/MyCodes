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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    long long n, a, b, ans1 = 0 , ans2 = 0;
    cin >> n;
    long long ara1[n], ara2[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara1[i];
        ans1 = ans1|ara1[i];
    }
    for( int i = 0; i < n; i++ )
    {
        cin >> ara2[i];
        ans2 = ans2|ara2[i];
    }
    cout << ans1 + ans2 << endl;
    return 0;
}



