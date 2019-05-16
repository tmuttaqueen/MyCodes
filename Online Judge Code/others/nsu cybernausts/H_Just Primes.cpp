#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pb push_back
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
///call precal(max) with maxsize for every time use of fft
///every time for using fft call the multiply function
struct FFT
{
    struct node
    {
        double x,y;
        node() {}
        node(double a, double b): x(a), y(b) {}
        node operator + (const node &a) const
        {
            return node(this->x+a.x,this->y+a.y);
        }
        node operator - (const node a) const
        {
            return node(this->x-a.x,this->y-a.y);
        }
        node operator * (const node a) const
        {
            return node(this->x*a.x-this->y*a.y,this->x*a.y+a.x*this->y);
        }
    };

    int M;
    vector<node> A, B, w[2];
    vector<int>rev;
    long double pi;
    FFT( int maxSize )
    {
        M = maxSize;
        pi = 3.1415926535897932384;
        A.resize(M);
        B.resize(M);
        w[0].resize(M);
        w[1].resize(M);
        rev.resize(M);
        for (int i=0; i<M; i++)
        {
            int j=i,y=0;
            for (int x=1; x<M; x<<=1,j>>=1) (y<<=1)+=j&1;
            rev[i]=y;
        }
        for (int i=0; i<M; i++)
        {
            w[0][i] = node( cos(2*pi*i/M),sin(2*pi*i/M) );
            w[1][i] = node( cos(2*pi*i/M),-sin(2*pi*i/M) );
        }
    }
    void ftransform( vector<node> &A, int p )
    {
        for (int i=0; i<M; i++)
            if (i<rev[i])
                swap(A[i],A[rev[i]]);
        for (int i=1; i<M; i<<=1)
            for (int j=0,t=M/(i<<1); j<M; j+=i<<1)
                for (int k=0,l=0; k<i; k++,l+=t)
                {
                    node x=w[p][l]*A[i+j+k];
                    node y=A[j+k];
                    A[j+k]=y+x;
                    A[j+k+i]=y-x;
                }
        if (p)
            for (int i=0; i<M; i++)
                A[i].x/=M;
    }
    void multiply( int *P, int *Q, int *res, int n, int m )
    {
        for( int i = 0; i < M; i++ )
            A[i].x = A[i].y = B[i].x = B[i].y = 0;
        for( int i = 0; i < n; i++ )
            A[i].x = P[i];
        for( int i = 0; i < m; i++ )
            B[i].x = Q[i];
        ftransform(A,0);
        ftransform(B,0);
        for (int k=0; k<M; k++)
            A[k] = A[k]*B[k];
        ftransform(A,1);
        for( int i = 0; i < M; i++ )
            res[i] = (A[i].x + 0.5);
    }

};

const int MAX = 500005;
int ara[MAX];
vector<int>pr;

void sieve()
{
    ara[1] = 1;
    for( int i = 2; i < MAX; i++ )
    {
        if( ara[i] == 0 )
        {
            for( intl j = 1LL*i*i; j < MAX; j += i )
            {
                ara[j] = 1;
            }
        }
    }
    for( int i = 2; i <= MAX-5; i++ )
    {
        if( ara[i] == 0 )
            pr.pb(i);
    }
}

int P[MAX*3], Q[MAX*3];
int ans[MAX*3];

void precalEven()
{
    int n = MAX, m = MAX;
    for( int i = 0; i < pr.size(); i++ )
    {
        P[ pr[i] ] = Q[ pr[i] ] = 1;
    }
    int x = 1;
    while( x < n ) x <<= 1;
    x <<= 1;
    FFT fft(x);
    fft.multiply(P, Q, P, n, m);

    for( int i = 1; i < MAX; i++  )
    {
        ans[i] = P[i];
    }
    for( int i = 2; i < MAX; i+= 2 )
    {
        if( ara[ i/2 ] == 0 )
            ans[i]--;
    }
    for( int i = 1; i < MAX; i++  )
    {
        ans[i] >>= 1;

    }

}

pii even( int n )
{
    if( n <= 6 )
        return mp(-1,-1);
    return mp(2,ans[n]);
}

pii odd( int n )
{
    if( n == 1 ) return mp(-1,-1);
    if( ara[n-2] == 0 )
        return mp(2, 1);
    int as = 0;
    for( int i = 1; i < pr.size() && n - pr[i] > 0; i++ )
    {
        as += ans[ n - pr[i] ];
        if( 2*pr[i] < n && ara[ n - 2*pr[i] ] == 0 && !( n%3 == 0 && ara[n/3] == 0 ) )
            as--;
    }
    return mp(3, as/3);
}

int main()
{
    sieve();
    precalEven();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int x ;
        if( ara[n] == 0 )
            cout << 1 << " " << 1 << endl;
        else if( n % 2== 0 )
        {
            pii a = even(n);
            cout << a.xx << " " << a.yy << endl;
        }
        else
        {
            pii a = odd(n);
            cout << a.xx << " " << a.yy << endl;
        }
        //cout << ans[n] << endl;
    }
}
