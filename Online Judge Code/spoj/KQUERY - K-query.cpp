#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define piiii       pair<pii, pii>
#define ldb         long double

bool cmmp( pii a, pii b )
{
    return a.xx < b.xx;
}

bool cmp( int a, pii b )
{
    return a < b.xx;
}

bool comp( piiii a, piiii b )
{
    return a.yy.xx < b.yy.xx;
}


int bit[30005], n;

void update(int x)
{
    while(x<=n)
    {
        bit[x] += 1;
        x += (x&(-x));
    }
}

int query( int x )
{
    int ans = 0;
    while(x>0)
    {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    scanf("%d", &n);
    pii ara[n];
    for( int i = 1; i <= n; i++ )
    {
        scanf("%d", &ara[i].xx);
        ara[i].yy = i;
    }
    int q;
    scanf("%d", &q);
    piiii qq[q];
    int off[q];
    for( int i = 0; i < q; i++ )
    {
        scanf("%d %d %d", &qq[i].xx.xx, &qq[i].xx.yy, &qq[i].yy.xx );
        qq[i].yy.yy = i;
    }
    sort( ara+1, ara+n+1, cmmp );
    sort( qq, qq+q, comp );
    int p = q-1;
    int prev = n+1;
    int ans = 0;
    while(p>=0)
    {
        piiii a = qq[p];
        int s = a.xx.xx, e = a.xx.yy, ind = a.yy.yy, val = a.yy.xx;
        auto x = upper_bound( ara + 1, ara+prev, val, cmp );
        int st = x-ara;
        //what_is(val);
        //what_is(st);
        while( --prev >= st )
        {
            //what_is(ara[prev].yy);
            update( ara[prev].yy );
        }
        prev++;

        ans = query( e ) - query(s-1);

        off[ind] = ans;
        p--;
    }

    for( int i = 0; i < q; i++ )
        printf("%d\n", off[i]);

    return 0;
}




