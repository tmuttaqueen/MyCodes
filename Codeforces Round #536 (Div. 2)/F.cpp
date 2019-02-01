#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl ara[105][105], res[105][105];
intl mod = 998244353, mm = mod-1;
int k;

//bool operator<( pii a, pii b )
//{
//    if( a.xx < b.xx ) return 1;
//    else return a.yy < b.yy;
//}
//
//bool operator>( pii a, pii b )
//{
//    if( a.xx > b.xx ) return 1;
//    else return a.yy > b.yy;
//}
//
//bool operator<=( pii a, pii b )
//{
//    if( a.xx <= b.xx ) return 1;
//    else return a.yy <= b.yy;
//}

void mul( intl a[105][105], intl b[105][105], intl res[105][105] )
{
    intl temp[105][105];
    memset( temp, 0, sizeof temp );
    for( int i = 0; i < k; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            for( int p = 0; p < k; p++ )
            {
                temp[i][j] += a[i][p]*b[p][j];
                temp[i][j] %= mm;
            }
        }
    }
    for( int i = 0; i < k; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            res[i][j] = temp[i][j];
        }
    }
}

void expoo( intl res[105][105], intl p )
{
    if(p==1)
    {
        //cout << "in" << endl;
        for( int i = 0; i < k; i++ )
        {
            for( int j = 0; j < k; j++ )
            {
                res[i][j] = ara[i][j];
            }
        }
        //cout << res[0][0] << endl;
        return ;
    }
    expoo(res, p/2);
    mul(res, res, res);
    if(p&1)
        mul(res, ara, res);

}


intl gcd (intl a, intl b)
{
    return a ? gcd (b%a, a) : b;
}

intl powmod (intl a, intl b, intl p)
{
    intl res = 1;
    while (b)
        if (b & 1)
            res = (res * 1ll * a % p),  --b;
        else
            a = (a * 1ll * a % p),  b >>= 1;
    return res;
}

intl generator (int p)
{
    vector<intl> fact;
    int phi = p-1,  n = phi;
    for (intl i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (intl res=2; res<=p; ++res)
    {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)
            return res;
    }
    return -1;
}

intl solve( int n, int k, int a )
{
    if (a == 0)
    {
        return 0;
    }

    intl g = generator (n);

    intl sq = (intl) sqrt (n + .0) + 1;
    vector < pair<intl,intl> > dec (sq);
    for (intl i=1; i<=sq; ++i)
        dec[i-1] = make_pair (powmod (g, (i * sq * 1ll * k % (n - 1)), n), i);
    sort (dec.begin(), dec.end());
    int any_ans = -1;
    for (int i=0; i<sq; ++i)
    {
        intl my = (powmod (g,  (i * 1ll * k % (n - 1)), n) * 1ll * a % n);
        pii d = make_pair (my, 0);
        vector < pair<intl,intl> >::iterator it = lower_bound (dec.begin(), dec.end(), d);
        if (it != dec.end() && it->first == my)
        {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1)
    {
        return -1;
    }

    int delta = (n-1) / gcd (k, n-1);
    if( any_ans%delta < n-1 )
        return powmod (g, any_ans%delta, n);
    return -1;
//    vector<intl> ans;
//    for (int cur=any_ans%delta; cur<n-1; cur+=delta)
//        ans.push_back (powmod (g, cur, n));
//    sort (ans.begin(), ans.end());
//    printf ("%d\n", ans.size());
//    for (size_t i=0; i<ans.size(); ++i)
//        printf ("%d ", ans[i]);

}


int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for( int i = 0; i < k; i++ )
    {
        cin >> ara[0][i];
    }

    intl n, m;
    cin >> n >> m;

    for( int i = 1; i < k; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            if( j==i-1 )
                ara[i][j] = 1;
        }
    }

    expoo( res, n-k );

    intl p = res[0][0];
    //cout << "p " << p << endl;
    intl s = solve(mod, p, m);
    cout << s << endl;

    return 0;
}

