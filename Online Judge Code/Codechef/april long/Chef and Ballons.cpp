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
    int t;
    cin >> t;
    while(t--)
    {
        intl ara[3], ans, k, tt;
        cin >> ara[0] >> ara[1] >> ara[2] >> k;
        sort( ara, ara+3 );
        if( k <= ara[0] )
        {
            //cout << "aaaaaaaaaaaaaaaa\n";
            ans = (k-1)*3+1;
        }
        else if( k <= ara[1] )
        {
            //cout << "bbbbbbbbbbbbbbb\n";
            ans = ara[0]*3 + (k-ara[0]-1)*2 + 1;
        }
        else
        {
            //cout << "ccccccccccccccccccccc\n";
            ans = ara[0]*3 + (ara[1]-ara[0])*2 + (k - ara[1]);
        }
        cout << ans << endl;
    }


    return 0;
}



