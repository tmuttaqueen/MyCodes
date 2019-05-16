#include <bits/stdc++.h>

using namespace std;

#define intl long long

const int MAXROW = 100, MAXCOL = 100;

int expo(int a, int b, int MOD)
{
    int res = 1;

    while (b)
    {
        if (b & 1)
            res = (long long)res * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int ar[MAXROW][MAXCOL];

/// Gaussian elimination in field MOD (MOD should be a prime)
/// n = row, m = col, res.size() == m
int gauss(int n, int m, int MOD, vector<int> &res)
{
    res.assign(m, 0);
    vector <int> pos(m, -1);
    int i, j, k, l, p, d, free_var = 0;
    const long long MODSQ = (long long)MOD * MOD;

    for (j = 0, i = 0; j < m && i < n; j++)
    {
        for (k = i, p = i; k < n; k++)
        {
            if (ar[k][j] > ar[p][j])
                p = k;
        }

        if (ar[p][j])
        {
            pos[j] = i;
            for (l = j; l <= m; l++)
                swap(ar[p][l], ar[i][l]);

            d = expo(ar[i][j], MOD - 2, MOD);
            for (k = 0; k < n && d; k++)
            {
                if (k != i && ar[k][j])
                {
                    int x = ((long long)ar[k][j] * d) % MOD;
                    for (l = j; l <= m && x; l++)
                    {
                        if (ar[i][l])
                            ar[k][l] = (MODSQ + ar[k][l] - ((long long)ar[i][l] * x)) % MOD;
                    }
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++)
    {
        if (pos[i] == -1)
            free_var++;
        else
            res[i] = ((long long)ar[pos[i]][m] * expo(ar[pos[i]][i], MOD - 2, MOD)) % MOD;
    }

    for (i = 0; i < n; i++)
    {
        long long val = 0;
        for (j = 0; j < m; j++)
            val = (val + ((long long)res[j] * ar[i][j])) % MOD;
        if (val != ar[i][m])
            return -1;
    }
    return free_var;
}

const intl mod = 1e6 + 3;

int val[] = {2,3,5,7, 11, 13, 17, 19, 23, 29, 31};
int main()
{

    for(int i = 0; i <= 10; i++)
    {
        printf("? %d\n", val[i] );
        fflush(stdout);
        intl a;

        scanf("%lld", &a);

        ar[i][11] = a;
        intl co = 1;
        for(int j = 0; j <= 10; j++)
        {
            ar[i][j] = co;
            co = (co*val[i])%mod;
        }
    }
    vector<int> res;
    int flag = gauss(11,11,mod,res);

    if( flag > 0 ) while(1);

    for(int j = 0; j <= 10; j++)
    {
        res[j] = ( res[j]%mod + mod )%mod;
    }
    for(int i = 0; i < mod; i++)
    {
        intl v = 0, co = 1;
        for(int j = 0; j <= 10; j++)
        {
            v = (v + co*res[j])%mod;
            co = (co*i)%mod;
        }

        if(v == 0)
        {
            printf("! %d\n", i );
            fflush(stdout);
            return 0;
        }
    }

    printf("! -1\n");
    fflush(stdout);

    return 0;
}
