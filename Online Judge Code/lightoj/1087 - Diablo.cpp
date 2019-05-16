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

const int mx = 200000;
int flag[mx];
int id[mx], cur;

void update( int x, int val )
{
    while(x <= mx)
    {
        flag[x] += val;
        x += (x&(-x));
    }
}

int query( int x )
{
    int sum = 0;
    while( x > 0 )
    {
        sum += flag[x];
        x -= (x&(-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        char c;
        memset( flag, 0, sizeof(flag) );
        scanf("%d %d", &cur, &q);
        for( int i = 1; i <= cur; i++ )
        {
            scanf("%d", &n);
            id[i] = n;
            update( i, 1 );
        }
        cur++;
        printf("Case %d:\n", caseno++);
        while(q--)
        {
            getchar();
            scanf("%c %d", &c, &n);
            if( c == 'a' )
            {
                id[cur] = n;
                update(cur, 1);
                cur++;
            }
            else
            {
                if( query(cur) < n )
                {
                    printf("none\n");
                }
                else
                {
                    int s = 1, e = cur, ans;
                    while( s <= e )
                    {
                        int m = (s+e)/2;
                        int num = query(m);
                        if( num < n )
                        {
                            s = m+1;
                        }
                        else if( num > n )
                        {
                            e = m-1;
                        }
                        else
                        {
                            ans = m;
                            e = m-1;
                        }
                    }
                    update( ans, -1 );
                    printf("%d\n", id[ans]);
                }
            }
        }
    }

    return 0;
}


