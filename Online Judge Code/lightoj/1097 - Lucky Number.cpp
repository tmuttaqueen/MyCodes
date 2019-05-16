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

const int mx = 1429500, total = 100000;
int ara[mx+5];
int temp[mx+5];
int c = 0;
vector<int>pre;
bool flag[mx+5];

void update( int x, int val )
{
    while( x < mx )
    {
        ara[x] += val;
        x += (x&(-x));
    }
}

int query( int x )
{
    int sum = 0;
    while( x > 0 )
    {
        sum += ara[x];
        x -= (x&(-x));
    }
    return sum;
}

int node( int j )
{
    int l = 0, h = mx-1, n;
    while( l <= h )
    {
        int m = (l+h)/2;
        int sum = query(m);
        if( sum > j )
            h = m-1;
        else if( sum < j )
            l = m+1;
        else
        {
            n = m;
            h = m-1;
        }
    }
    //what_is(j);
    return n;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1, sum;
    scanf("%d", &t);
    for( int i = 1; i < mx; i+=2 )
    {
        update( i, 1 );
        flag[i] = 1;
    }
    c = 0;
    sum = query(mx-1);

    for( int i = 3; i <= total;  )
    {
        for( int j = i; j < sum; j+=i )
        {
            //what_is(j);
            int n = node(j);
            temp[c++] = n;
            flag[n] = 0;
            //what_is(j);
        }
        for( int j = 0; j < c; j++ )
            update( temp[j] , -1);
        c = 0;
        for( int j = i+1; j < mx; j++ )
        {
            if( flag[j] == 1 )
            {
                 i = j;
                 break;
            }
        }
        sum = query( mx-1 );
        //what_is(i);
    }
    for( int i = 1; i < mx; i+=2 )
        if( flag[i] == 1 )
            pre.pb(i);
    while(t--)
    {
        int a;
        scanf("%d", &a);
        printf("Case %d: %d\n", caseno++, pre[a-1]);
    }

    return 0;
}



