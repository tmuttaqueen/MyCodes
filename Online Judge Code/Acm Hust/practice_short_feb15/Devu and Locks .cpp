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
const int M = 345678;
intl mod = 998244353, p =16;
struct NTT
{
    vector<int>A, B, w[2], rev;
    int P, M, G;

    NTT( int mod )
    {
        P = mod;
        G = 3;
    }
    int Pow(int a, int b)
    {
        int res=1;
        for (; b; b>>=1,a=a*1LL*a%P) if (b&1) res=res*1LL*a%P;
        return res;
    }
    void init( int n )
    {
        //for (M=1; M<n; M<<=1);
        M = (n<<1);
        A.resize(M);
        B.resize(M);
        w[0].resize(M);
        w[1].resize(M);
        rev.resize(M);
        for (int i=0; i<M; i++)
        {
            int x=i, &y=rev[i];
            y=0;
            for (int k=1; k<M; k<<=1,x>>=1)
                (y<<=1)|=x&1;
        }
        int x=Pow(G,(P-1)/M),y=Pow(x,P-2);
        w[0][0]=w[1][0]=1;
        for (int i=1; i<M; i++)
        {
            w[0][i]=w[0][i-1]*1LL*x%P;
            w[1][i]=w[1][i-1]*1LL*y%P;
        }
    }

    void ntransform(vector<int> &a, int f)
    {
        for (int i=0; i<M; i++)
            if (i<rev[i]) swap(a[i],a[rev[i]]);
        for (int i=1; i<M; i<<=1)
            for (int j=0,t=M/(i<<1); j<M; j+=i<<1)
                for (int k=0,l=0; k<i; k++,l+=t)
                {
                    int x=a[j+k+i]*1ll*w[f][l]%P;
                    int y=a[j+k];
                    a[j+k+i]=y-x<0?y-x+P:y-x;
                    a[j+k]=y+x>=P?y+x-P:y+x;
                }
        if (f)
        {
            int x=Pow(M,P-2);
            for (int i=0; i<M; i++) a[i]=a[i]*1ll*x%P;
        }
    }

    void multiply( vector<int> &X, vector<int> &Y, vector<int> &res)
    {
        init(max(X.size(), Y.size()));
        for( int i = 0; i < M; i++ )
            A[i] = B[i] = 0;
        for( int i = 0; i < X.size(); i++ )
            A[i] = X[i];
        for( int i = 0; i < Y.size(); i++ )
            B[i] = Y[i];
        /*for( int x: A )
            cout << x << " ";
        cout << endl;
        for( int x: B )
            cout << x << " ";
        cout << endl;*/
        ntransform(A,0);
        ntransform(B,0);
        res.clear();
        res.resize(M);
        for (int i=0; i<M; i++)
            res[i]=A[i]*1LL*B[i]%P;
        ntransform(res,1);
        res.resize(M/2);
        /*for( int i = 0; i < res.size(); i++ )
            cout << res[i] << " ";
        cout << endl;*/
    }
};


NTT ntt(mod);
int m = 16384, mm;

long long expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

vector<vector<int>> expo( int n )
{
    //what_is(n);
    vector<vector<int>>vec;
    vec.resize(p);
    for( int i = 0; i < p; i++ )
        vec[i].resize(m, 0);

    if( n == 1 )
    {
        for( int i = 0; i <= 9 && i <= mm; i++ )
        {
            vec[i%p][i]++;
        }
        return vec;
    }

    vector< vector<int> > res = expo(n/2);
    int d = expo(10LL, n/2, p);
    for( int i = 0; i < p; i++ )
    {
        for( int j = 0; j < p; j++ )
        {
            int rem = (d*i+j)%p;
            vector<int> temp;
            ntt.multiply( res[i], res[j], temp );
            for( int k = 0; k < m; k++ )
                vec[rem][k] = (vec[rem][k]+temp[k])%mod;
        }
    }
    if(n&1)
    {
        vector<vector<int>>temp;
        temp.resize(p);
        for( int i = 0; i < p; i++ )
            temp[i].resize(m, 0);
        for( int i = 0; i < p; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                for( int k = 0; k < 9; k++ )
                {
                    if( j+k >= m ) continue;
                    int rem = (10*i+k)%p;
                    temp[rem][j+k] = (temp[rem][j+k]+vec[i][j])%mod;
                }
            }
        }
        for( int i = 0; i < p; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                vec[i][j] = temp[i][j];
            }
        }
    }
    return vec;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n >> p >> m;
    mm = m;
    int d = 1;
    while(d <= m) d<<=1;
    m = d;
    vector<vector<int>> v = expo(n);
    intl ans = 0;
    for( int i = 0; i <= mm; i++ )
    {
        //cout << v[0][i] << " ";
        ans = (ans+v[0][i])%mod;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
