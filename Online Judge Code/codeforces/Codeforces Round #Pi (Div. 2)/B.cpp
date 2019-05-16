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
#define pii         pair<char, int>
int ara[1000008];

int main()
{
    filein;
    int n;
    cin >> n ;
    char c;
    int x;
    //memset( ara, 0, sizeof(ara) );
    vector<int> vec;
    vector<pii> v;
    for( int i = 0; i < n; i++ )
    {
        getchar();
        cin >> c >> x;
        v.pb( mp(c,x) );
        if( c == '+' )
            ara[x] = 1;
        if( c == '-' )
        {
            if( ara[x] == 0 )
            {
                ara[x] = 1;
                vec.pb(x);
            }
            else
                ara[x] = 0;
        }
    }

    memset( ara, 0, sizeof(ara) );

    int l = vec.size();
    for( int i = 0; i < l; i++ )
    {
        ara[ vec[i] ] = 1;
    }
    int ans = 0, temp = 0;
    for( int j = 0; j <= 1000000; j++)
    {
        if( ara[j] == 1 )
        {
            temp++;
        }
    }
    ans = max(temp, ans);
    for( int i = 0; i < n; i++ )
    {
        c = v[i].xx;
        x = v[i].yy;

        if( c == '+' )
        {
            ara[x] = 1;
            temp =0;
            for( int j = 0; j <= 1000000; j++)
            {
                if( ara[j] == 1 )
                {
                    temp++;
                }
            }
            ans = max(temp, ans);
        }
        else
        {
            ara[x] = 0;
        }

    }
    cout << ans << endl;
    return 0;
}



