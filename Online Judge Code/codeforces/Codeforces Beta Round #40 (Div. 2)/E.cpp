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
    int n, k;
    bool x;
    cin >> n;
    int ara[n+1];
    vector<pii>vec;
    vector<int>e[101];
    memset( ara, 0, sizeof(ara) );
    for( int i = 2; i <= n; i++ )
    {
        x = 0;
        if( ara[1] != ara[2] )
        {
            k = ara[1];
            x = 1;
        }
        for( int j = 1; j < i && x == 1; j++ )
        {
            if( ara[j] < k )
            {
                ara[j]++;
                vec.pb( {j, i} );
                ara[i]++;
                e[j].pb(i);
                e[i].pb(j);
            }
        }
        if( x == 0 )
        {
            int temp[i+5];
            memset( temp, 0, sizeof(temp) );
            for( int j = 1; j < i; j++ )
            {
                if( temp[j] == 0 )
                {
                    vec.pb( {j, i} );
                    for( int k = 0; k < e[j].size(); k++ )
                        temp[e[j][k]] = 1;
                    e[j].pb(i);
                    e[i].pb(j);
                    ara[j]++;
                    ara[i]++;
                }
            }
        }
    }
    cout << vec.size() << endl;
    for( int i = 0; i < vec.size(); i++ )
    {
        cout << vec[i].xx << " " << vec[i].yy << "\n";
    }

    return 0;
}


