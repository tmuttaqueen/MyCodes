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
    int n, a, b;
    cin >> n;
    while(n != 0 )
    {
        vector<int> vec(n+1);
        bool flag = 1;
        for( int i = 1; i <= n; i++ )
        {
            cin >> vec[i];
        }

        for( int i = 0; i < n; i++ )
        {
            if( vec[vec[i]] != i ) flag = 0;
        }

        if( flag ) cout << "ambiguous\n";
        else cout << "not ambiguous\n";
        cin >> n;
    }

    return 0;
}



