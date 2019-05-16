#include<bits/stdc++.h>

using namespace std;

/* sa = 1-based suffix array
   lcp = 1-based , lcp[i] = lcp between i'th and (i-1)'th suffix */
const int N = 500005;
const int LOG = 20;

struct SuffixArray
{

    int sa[N],data[N],rnk[N],lcp[N],n;
    int wa[N],wb[N],wws[N],wv[N];
    void init()
    {
        for (int i=1; i<=n; i++)
            sa[i]=data[i]=rnk[i]=lcp[i]=wa[i]=wb[i]=wws[i]=wv[i]=0 ;
    }
    int cmp(int *r,int a,int b,int l)
    {
        return (r[a]==r[b]) && (r[a+l]==r[b+l]);
    }
    void DA(int *r,int *sa,int n,int m)
    {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++)
            wws[i]=0;
        for(i=0; i<n; i++)
            wws[x[i]=r[i]]++;
        for(i=1; i<m; i++)
            wws[i]+=wws[i-1];
        for(i=n-1; i>=0; i--)
            sa[--wws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p)
        {
            for(p=0,i=n-j; i<n; i++)
                y[p++]=i;
            for(i=0; i<n; i++)
                if(sa[i]>=j)
                    y[p++]=sa[i]-j;
            for(i=0; i<n; i++)
                wv[i]=x[y[i]];
            for(i=0; i<m; i++)
                wws[i]=0;
            for(i=0; i<n; i++)
                wws[wv[i]]++;
            for(i=1; i<m; i++)
                wws[i]+=wws[i-1];
            for(i=n-1; i>=0; i--)
                sa[--wws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
    void callcp(int *r,int *sa,int n)
    {
        int i,j,k=0;
        for(i=1; i<=n; i++)
            rnk[sa[i]]=i;
        for(i=0; i<n; lcp[rnk[i++]]=k)
            for(k?k--:0,j=sa[rnk[i]-1]; r[i+k]==r[j+k]; k++);
    }
    void suffix_array (string &A)
    {
        n = A.length() ;
        init();
        for (int i = 0 ; i < n ; i++)
        {
            data[i] = A[i] ;
        }
        DA(data,sa,n+1,128);
        callcp(data,sa,n);
    }
};

struct RMQ
{
    //1-based
    //ara[i][j] contains minimum value of i, i+1....i+(1<<j)-1 [inclusive]
    int ara[N][LOG];
    int log[N];
    int n;
    void init( vector<int>v )
    {
        n = v.size();
        for( int i = 1; i < n; i++ )
        {
            ara[i][0] = v[i];
        }
        for( int j = 1; j < LOG; j++ )
        {
            for( int i = 1; i < n; i++ )
            {
                if( i+(1<<j)-1 >= n ) break;
                ara[i][j] = min( ara[i][j-1], ara[i+(1<<(j-1))][j-1] );
            }
        }
        log[1] = 0;
        for( int i = 2; i <= n; i++ )
            if( (i&(i-1)) == 0 ) log[i] = log[i-1] + 1;
            else log[i] = log[i-1];
    }
    int query( int a, int b )
    {
        int v = log[b-a+1];
        return min(ara[a][v], ara[b-(1<<v)+1][v]);
    }

    int left( int ind, int val )
    {
        int l = 1, r = ind-1, ans = ind;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( query(m+1, ind) >= val )
            {
                ans = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        return ans;
    }
    int right( int ind, int val )
    {
        int l = ind+1, ans = ind, r = n-1;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( query(ind+1, m) >= val )
            {
                ans = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        return ans;
    }
};

int dp[N];
int tree[6*N];

void update( int cn, int s, int e, int ind, int v )
{
    if( s > ind || e < ind ) return;
    if( s == e )
    {
        tree[cn] = v;
        return;
    }

    int m = (s+e)/2, l = cn<<1, r=  l+1;
    update(l, s, m, ind, v);
    update(r, m+1, e, ind, v);
    tree[cn] = max( tree[l], tree[r] );
}

int query( int cn, int s, int e, int l, int r )
{
    if( s > r || e < l )
        return 0;
    if( s >= l && e <= r )
    {
        return tree[cn];
    }
    int m = (s+e)>>1, cl = cn<<1, cr = cl+1;
    int a = query( cl, s, m, l, r );
    int b = query( cr, m+1, e, l, r );
    return max( a, b );
}

int rnk[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    SuffixArray sf;
    RMQ rmq;

    int n;
    string s;
    cin >> n >> s;

    sf.suffix_array(s);

    vector<int>v(sf.lcp, sf.lcp+n+1);
    rmq.init( v );

    //cout << rmq.query(5,6) << " qq" << endl;

    for( int i = 1; i <= n; i++ )
    {
        rnk[ sf.sa[i] ] = i;
    }
    /*for( int i = 1; i <= n; i++ )
    {
        cout << sf.sa[i] << " " << sf.lcp[i] << " " << rnk[i-1] << endl;
    }*/

    dp[n] = 1;
    dp[n-1] = 1;
    int ans = 1;
    int pnt = n;
    for( int i = n-2; i >= 1; i-- )
    {
        //cout << "i: " << i << endl;

        for( int len = dp[i+1]+1; len > 0; len-- )
        {
            while( i+len <= pnt && pnt > 0 )
            {
                //cout << "upd: " << rnk[pnt-1] << " " << dp[pnt] << endl;
                update( 1,1,n, rnk[pnt-1], dp[pnt] );
                pnt--;
            }
            if( i+len > n )
                continue;
            int pos = rnk[i-1];
            int l = rmq.left( pos, len-1 ), r = rmq.right( pos, len-1 );
            int q = query( 1,1,n,l,r );
            //cout << pos << " " << len <<  " " << l << " " << r << " " << q << endl;
            if( q >= len-1 )
            {
                dp[i] = len;
                break;
            }
            pos = rnk[i];
            l = rmq.left( pos, len-1 ); r = rmq.right( pos, len-1 );
            q = query( 1,1,n,l,r );
            //cout << pos << " " << len <<  " " << l << " " << r << " " << q << endl;
            if( q >= len-1 )
            {
                dp[i] = len;
                break;
            }
        }
        //cout << "i: " << i << " dp[i]: " << dp[i] << endl;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
