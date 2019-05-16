#include <bits/stdc++.h>
using namespace std ;


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

const int M = 100005;

namespace SA
{
const int N = int(1e5)+10;
int cmp(int *r,int a,int b,int l)
{
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) wws[i]=0;
    for(i=0; i<n; i++) wws[x[i]=r[i]]++;
    for(i=1; i<m; i++) wws[i]+=wws[i-1];
    for(i=n-1; i>=0; i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) wws[i]=0;
        for(i=0; i<n; i++) wws[wv[i]]++;
        for(i=1; i<m; i++) wws[i]+=wws[i-1];
        for(i=n-1; i>=0; i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) rnk[sa[i]]=i;
    for(i=0; i<n; height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1]; r[i+k]==r[j+k]; k++);
}

int sa[N],data[N],n,p,q;


void CreateSA(char *A, int saa[], int lcp[])
{
    n = strlen(A) ;
    for( int i = 0; i <= n; i++ )
    {
        /*sa[i] = 0;
        wa[i] = 0;
        wb[i] = 0;
        wws[i] = 0;
        wv[i] = 0;
        rnk[i] = 0;
        height[i] = 0;*/
        data[i] = 0;
    }
    for (int i = 0 ; i < n ; i++)
    {
        data[i] = A[i] ;
    }
    DA(data,sa,n+1,128);
    calheight(data,sa,n);
    ///so far sa and height contains 1 based SA
    ///transforming it into 0-based SA
    for (int i = 0 ; i < n ; i++)
    {
        saa[i] = sa[i+1] ;
        lcp[i] = height[i+1] ;
        cout << saa[i] << " " << lcp[i] << endl;
    }
}
}

///1D BIT O(logn)
///point update cumulative query
struct BIT1D
{
    int mx;
    vector<int>bit;
    void init( int n = 1002 )
    {
        mx = (n+2);
        bit.clear();
        bit.resize(mx+2,0);
    }
    void update( int x, int val ) //add val to index x
    {
        while( x <= mx )
        {
            bit[x] += val;
            x += (x&(-x));
        }
    }

    int query( int x ) //sum from 1 to x (inclusive)
    {
        int sum = 0;
        while( x > 0 )
        {
            sum += bit[x];
            x -= (x&(-x));
        }
        return sum;
    }
};

void all(BIT1D &bit)
{
    for( int i = 1; i <= 10; i++ )
    {
        cout << i << " bit " << bit.query(i) - bit.query(i-1) << endl;
    }
}


char str[M];
int sa[M], lcp[M], ans[M], invsa[M];
vector<pii> query[M];
vector<int> pref[M];
int val[M];
int main ()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        for( int i = 0; i < M; i++ )
        {
            query[i].clear();
            pref[i].clear();
        }
        memset( ans, -1, sizeof ans );
        //memset( val, 0, sizeof val );
        scanf ("%s", str) ;
        int n = strlen(str);
        SA::CreateSA(str, sa, lcp);
        for( int i = 0; i < n; i++ )
        {
            invsa[ sa[i] ] = i;
        }

        for( int i = 0; i < n; i++ )
        {
            pref[lcp[i]].pb( i );
        }
        int q;
        scanf("%d", &q);
        for( int i = 0; i < q; i++ )
        {
            int k, m;
            scanf("%d %d", &k, &m);
            query[k].pb(mp(m,i));
        }
        BIT1D bit;
        bit.init(n+5);
        int cur = 0;
        for( int i = n; i > 0; i-- )
        {
            sort( pref[i].begin(), pref[i].end() );
            //what_is( invsa[n-i] );
            bit.update( invsa[n-i]+1, 1 );
            //val[ invsa[n-i]+1 ] = 1;
            for( int x: pref[i] )
            {
                int del = x;
                //what_is(x);
                if( x>0 && sa[x-1] > sa[x] )
                    del = x-1;
                what_is(del);
                //val[del+1] = 0;
                bit.update(del+1, -1);
                //val[del+1] = 0;
            }
            //all(bit);
            for( pii q: query[i] )
            {
                int l = 1, r = n, sol = -1;
                while(l <= r)
                {
                    int m = (l+r)/2;
                    if( bit.query(m) >= q.xx )
                    {
                        sol = m;
                        r = m - 1;
                    }
                    else
                        l = m + 1;
                }
                if( sol == -1 )
                    ans[q.yy] = -1;
                else
                    ans[q.yy] = sa[sol-1];
            }

        }
        for( int i = 0; i < q; i++ )
        {
            if( ans[i] == -1 )
                printf("Not found\n");
            else
                printf("%d\n", ans[i]);
        }


    }

    return 0;
}


