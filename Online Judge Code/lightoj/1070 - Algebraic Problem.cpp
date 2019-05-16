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

unsigned long long ara[2][2], temp[2][2];
unsigned long long p, q, n;

void matrixmul( unsigned long long m1[2][2], unsigned long long m2[2][2] )
{
    unsigned long long tt[2][2];
    tt[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
    tt[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
    tt[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
    tt[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];

    for( int i =0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
            m1[i][j] = tt[i][j];
    return;
}

void matrixpow( unsigned long long m1[2][2], unsigned long long a )
{
    //what_is(a);
    if( a == 1 )
    {
        m1[0][0] = p;
        m1[0][1] = -q;
        m1[1][0] = 1;
        m1[1][1] = 0;
        return;
    }
    matrixpow(m1, a/2);

    matrixmul(m1, m1);

    if( a%2 == 1 )
    {
        matrixmul(m1, temp);
    }

    /*for( int i =0; i < 2; i++ )
    {
        for( int j = 0; j < 2; j++ )
        {
            cout << m1[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\n\n";*/

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        cin >> p >> q >> n;

        temp[0][0] = ara[0][0] = p;
        temp[0][1] = ara[0][1] = -q;
        temp[1][0] = ara[1][0] = 1;
        temp[1][1] = ara[1][1] = 0;
        if( n == 0 )
        {
            cout << "Case " << caseno++ << ": " << 2 << endl;
            continue;
        }
        if( n > 1 )
            matrixpow( ara, n-1 );
        else
        {
            cout << "Case " << caseno++ << ": " << p << endl;
            continue;
        }

        ara[0][0] = ara[0][0]*p + ara[0][1]*2;
        cout << "Case " << caseno++ << ": " << ara[0][0] << endl;
    }

    return 0;
}



