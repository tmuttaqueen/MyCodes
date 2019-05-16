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

vector<intl>vec;
vector<intl>vect;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        bool flag = 0;
        intl n, k, l = 1;
        cin >> n >> k;
        intl ara[100];
        for( int i = 0; i < n; i++ )
            cin >> ara[i];
        int nn = n/2;
        vec.pb(0);

        for( int i = 0; i <= nn; i++ )
        {
            int tt = l;
            for( int j = 0; j < tt; j++ )
            {
                vec.pb( ara[i] + vec[j] );
                vec.pb( (ara[i]<<1) + vec[j] );
                l+=2;
            }
        }
        sort( vec.begin(), vec.end() );

        vect.pb(0);
        int ll = 1;
        for( int i = nn+1; i < n; i++ )
        {
            int tt = ll;
            for( int j = 0; j < tt; j++ )
            {
                vect.pb( ara[i] + vect[j] );
                vect.pb( (ara[i]<<1) + vect[j] );
                ll+=2;
            }
        }

        for( int i = 0; i < ll && flag == 0; i++ )
        {

            intl m = k - vect[i];
            if( binary_search( vec.begin(), vec.end(), m ) )
                flag = 1;
        }
        if( flag )
            cout << "Case " << caseno++ << ": Yes\n";
        else
            cout << "Case " << caseno++ << ": No\n";
        vec.clear();
        vect.clear();
    }

    return 0;
}


