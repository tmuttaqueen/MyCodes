#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define intl long long


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
    vector<node> A, w[2];
    vector<int>rev;
    double pi;
    FFT()
    {
        pi = 3.1415926535897932384;
    }
    void init(int n)
    {
        M = 1;
        while(M < n) M <<= 1;
        M <<= 1;
        A.resize(M);
        //B.resize(M);
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
    /// multiply P*Q and keeps the result in res
    ///degree of P is n and degree of Q is m
    ///P, Q is given in standard power form, in increasing
    void multiply( vector<intl> &P, vector<intl> &res)
    {
        if( P.size() <= 1 )
        {
            //smultiply(P, res);
            return ;
        }
        init( (int)P.size() );
        for( int i = 0; i < M; i++ )
            A[i].x = A[i].y = 0;
        for( int i = 0; i < P.size(); i++ )
            A[i].x = P[i];
        ftransform(A,0);
        //ftransform(B,0);
        //for( int i = 0; i < A.size(); i++ ) B[i] = A[]
        for (int k=0; k<M; k++)
            A[k] = A[k]*A[k];
        ftransform(A,1);
        res.resize(M);
        for( int i = 0; i < M; i++ )
            res[i] = (A[i].x + 0.5);
    }
    void smultiply(  vector<intl> &P, vector<intl> &res )
    {
        vector<intl>t;
        t.resize( 2*P.size() + 2, 0 );
        for( int i = 0; i < P.size(); i++ )
        {
            for( int j = 0; j < P.size(); j++ )
            {
                t[ i+j ] += P[i]*P[j];
            }
        }
        res.resize( t.size() );
        for( int i = 0; i < t.size(); i++ ) res[i] = t[i];
    }

};

const int M = 50005, LOGN = 20;
int isprime[10*M];

void sieve()
{
    int M = 2*100006;
    isprime[1] = 1;
    for( int i = 4; i < M; i += 2 )
        isprime[i] = 1;
    for( int i = 3; i < M; i+= 2 )
    {
        if( isprime[i] == 0 )
            for( int j = i+i; j < M; j += i )
            {
                isprime[j] = 1;
            }
    }
    for( int i = 1; i < M; i++ ) isprime[i] = !isprime[i];
}

vector<int>edge[M], tree[M];
int sz[M], par[M], dist[LOGN][M], level[M], mark[M];
//dist[i][j] = distance from j to i'th level parent

void dfsSZ( int u, int p )
{
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        dfsSZ(v, u);
        sz[u] += sz[v];
    }
}

void calculate( int u, int p, int stop, int l, int d = 0 )
{
    //cout << u << " d: " << d << endl;
    dist[l][u] = d;
    for( int v: edge[u] )
    {
        if( v != p && mark[v] == 0 )
        {
            calculate(v, u, stop, l, d + 1);
        }
    }
}

void centroid( int u, int p )
{
    int node = -1, mx = -1;
    for( int v: edge[u] )
    {
        if( sz[v] > mx && par[v] == 0 )
        {
            mx = sz[v];
            node = v;
        }
    }
    if( mx <= sz[u]/2 )
    {
        mark[u] = 1;
        par[u] = p;
        (p == -1) ? level[u] = 0: level[u] = level[p] + 1;
        //cout << "u: " << u << " level: " << level[u] << endl;
        calculate(u, -1, p, level[u], 0);


        for( int v: edge[u] )
        {
            if( par[v] == 0 && v != p )
            {
                centroid(v, u);
            }
        }
    }
    else
    {
        sz[node] = sz[u];
        sz[u] -= mx;
        centroid(node, p);
    }
}

intl ans = 0;
vector<intl>v1, v2;

void dfs( int u, int p )
{
    v1.pb(u);
    for( int v: tree[u] )
    {
        if( v == p ) continue;
        dfs(v, u);
    }
}

FFT fft;

void calc( int u, int p, int ind, int f )
{
    v1.clear();
    dfs(u, p);
    int mx = 0;
    for( int i = 0; i < v1.size(); i++ )
    {
        //cout << "u " << u << " ind " << ind << " v1[i] " << v1[i] << " d " << dist[ind][ v1[i] ] << endl;
        mx = max( dist[ind][ v1[i] ], mx );
    }
    //cout << endl;
    v2.clear();
    v2.resize( mx+2, 0 );
    for( int i = 0; i < v1.size(); i++ )
    {
        v2[ dist[ind][ v1[i] ] ]++;
    }

    fft.multiply( v2, v2 );
    for( int i = 0; i < v2.size(); i++ )
    {
        if( isprime[i] )
        {
            ans += f*v2[i];
        }
    }


}

void solve( int u, int p )
{
    int ind = level[u];
    calc(u, p, ind, 1);
    for( int v: tree[u] )
    {
        if( v == p ) continue;
        calc(v, u, ind, -1);
        solve(v, u);
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfsSZ(1, -1);
    centroid(1, -1);
    int root = 0;
    for( int i = 1; i <= n; i++ )
    {
        //cout << i << " i " << par[i ]<< endl;
        if( par[i] == -1 )
        {
            root = i;
        }
        else
        {
            tree[i].pb( par[i] );
            tree[ par[i] ].pb(i);
        }
    }
    //what_is(root);
    solve(root, -1);
    double d = n;
    d *= (n-1);
    cout << setprecision(10 ) << fixed <<  ans/d << endl;
    return 0;
}
