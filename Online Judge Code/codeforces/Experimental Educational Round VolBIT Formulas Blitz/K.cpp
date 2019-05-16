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
    long long n;
    cin >> n;

    cout << n - n/2 - n/3 - n/5 - n/7 + n/6 + n/10 + n/14 + n/15 + n/21 + n/35 - n/30 - n/70 - n/42 - n/105 + n/210 << endl;


    return 0;
}



