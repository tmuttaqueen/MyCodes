#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 5005*5005;
string s;

/*
    -------------------------------> SUFFIX ARRAY + LONGEST COMMON PREFIX (LCP) <-------------------------------------------
    suffix array in O(nlogn)
    lcp from suffix_array via kasai algo in O(n)
*/


#include <bits/stdc++.h>
using namespace std ;

namespace SA
{
const int N = 50000;
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


void CreateSA(const char *A, int saa[], int lcp[], int pos[])
{
    n = strlen(A) ;
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
        pos[ saa[i] ] = i;
        //cout << saa[i] << " " << lcp[i] << endl;
    }
}
}

int sa[5005], lcp[5005], pos[5005];
int mnn[5005][5005];
int nnn[5005][5005];
intl dp[5005];

void precal( int n )
{
    for( int i = 1; i <= n; i++ )
    {
        mnn[i][i] = lcp[i];
        for( int j = i-1; j >= 1; j-- )
        {
            mnn[j][i] = min( mnn[j+1][i], lcp[j] );
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        nnn[i][i] = sa[i];
        for( int j = i-1; j >= 1; j-- )
        {
            nnn[j][i] = min( nnn[j+1][i], sa[j] );
        }
    }
}

pii compute( int p, int target )
{
    int l = 0, r = p, lft = -1;
    while( l <= r )
    {
        int m = (l+r)/2;
        if( mnn[m][p] >= target )
        {
            lft = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    l = p + 1;
    r = s.length() - 1;
    int rgt = -1;
    while( l <= r )
    {
        int m = (l+r)/2;
        if( mnn[p+1][m] >= target )
        {
            rgt = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    if( lft == -1 && rgt == -1 )
        return mp(-1,-1);
    if( lft == -1 )
        return mp(p, rgt);
    if( rgt == -1 )
        return mp( lft - 1, p );
    return mp( lft - 1, rgt );
}

int solve( int ind )
{
    int len = -1, l = 1, r = s.length()-1;
    while( l <= r )
    {
        int m = (l+r)/2;
        int prev = ind - m + 1;
        if( prev < 1 )
        {
            r = m -1;
            continue;
        }
        pii v = compute( pos[prev], m );

        //cout << "calc " << ind << " " << prev << " " << v.xx << " " << v.yy << endl;

        if( v.xx == -1 && v.yy == -1 )
        {
            r = m-1;
            continue;
        }
        if( nnn[v.xx][v.yy] + m > prev )
        {
            r = m- 1;
        }
        else
        {
            len = m;
            l = m + 1;
        }
    }
    return len;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;

    cin >> n >> a >> b;

    cin >> s;
    s = "$" + s;
    dp[1] = a;
    SA::CreateSA(s.c_str(), sa, lcp, pos);
    precal(n);
    for( int i = 2; i <= n; i++ )
    {
        int lft = solve( i );
        dp[i] = dp[i-1] + a;
        //cout << i << " len " << lft << endl;
        if( lft != -1 )
        {
            dp[i] = min( dp[i], dp[i-lft] + b);
        }

    }

    cout << dp[n] << endl;

    return 0;
}
