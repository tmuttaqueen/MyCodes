#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 3e5+5;

int fib[M];
int ara[M], sum[M], fsum[M];


void fastscan(int &x)
{
    register char c = getchar();
    /*bool neg=false;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }*/
    x =0;
    for(; (c>47 && c<58); c=getchar())
        x = (x<<1) + (x<<3) + c -48;
    //if(neg)
        //x *=-1;
}

void fastprint( int &x )
{
    register char ara[32], c = 0;
    do
    {
        ara[c++] = '0' + x%10;
        x /= 10;
    }while(x);
    while(c)
    {
        putchar( ara[c-1] );
        c--;
    }
    putchar('\n');
}



int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    register int vag = 1e9+9;
    register int bufferx[560], buffery[560];
    //filein;
    fib[1] = fib[2] = 1;
    fsum[1] = 1;
    fsum[2] = 2;
    for( int i = 3; i < M; i++ )
    {
        fib[i] = ( fib[i-1] + fib[i-2] );
        if( fib[i] > vag ) fib[i] -= vag;
        fsum[i] = (fib[i] + fsum[i-1]);
        if( fsum[i] > vag ) fsum[i] -= vag;
    }
    int n, q, mx = 547;
    //scanf("%d %d", &n, &q);
    fastscan(n);
    fastscan(q);
    for( int i = 1; i <= n; i++ )
    {
        //scanf("%d", &ara[i]);
        fastscan(ara[i]);
        sum[i] = (sum[i-1] + ara[i]);
        if( sum[i] > vag ) sum[i] -= vag;
    }
    int cur = 0;
    while(q--)
    {
        int type, l, r;
        //scanf("%d %d %d", &type, &l, &r);
        fastscan(type);
        fastscan(l);
        fastscan(r);
        if( type == 1 )
        {
            bufferx[cur]= l;
            buffery[cur++] = r;
        }
        if( cur == mx )
        {
            for( int i = 1; i <= n; i++ )
            {
                intl add = 0;
                for( int j = 0; j < cur; j++ )
                {
                    if( bufferx[j] <= i && buffery[j] >= i )
                    {
                        add = (add + fib[i-bufferx[j]+1]);
                        if( add > vag ) add -= vag;
                    }
                }
                ara[i] = (ara[i] + add);
                if( ara[i] > vag  ) ara[i] -= vag;
                sum[i] = (ara[i] + sum[i-1]);
                if( sum[i] > vag ) sum[i] -= vag;
            }
            cur = 0 ;
        }
        if( type == 2 )
        {
            int prev = (sum[r] - sum[l-1]);
            if( prev < 0 ) prev += vag;
            if( prev > vag ) prev += vag;
            int add = 0;
            for( int i = 0; i < cur; i++ )
            {
                if( bufferx[i] > r || buffery[i] < l  ) continue;
                int st = max(l - bufferx[i] + 1, 1);
                int en = max( min( buffery[i], r ) - max( bufferx[i], l ), 0 ) + st;

                int p = (fsum[en] - fsum[st-1]);
                if( p < 0 ) p += vag;
                add += p;
                if( add > vag ) add -= vag;
            }
            prev = (prev+add);
            if( prev > vag ) prev -= vag;
            if( prev < 0 ) prev += vag;
            //printf("%d\n", prev);
            fastprint(prev);
        }
    }
    return 0;
}
