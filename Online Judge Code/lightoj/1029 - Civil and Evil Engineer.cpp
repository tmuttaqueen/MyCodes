#include <bits/stdc++.h>

using namespace std;

struct data
{
    int x, y, w;
};
int a, b, c, edge, v = 0, n;
int par[120];
data ara[12005];

bool comp1( data a, data b )
{
    return (a.w < b.w);
}
bool comp2( data a, data b )
{
    return (a.w > b.w);
}

void make_set()
{
    for( int i = 0; i <= n; i++ )
        par[i] = i;
    return;
}

int find_par( int p )
{
    if( par[p] == p )
        return p;
    par[p] = find_par( par[p] );
    return par[p];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        v = 0;
        int cc = 1, ans1 = 0, ans2 = 0;
        scanf("%d", &n);

        scanf("%d %d %d", &ara[v].x, &ara[v].y, &ara[v].w);
        while( ara[v].x != 0 || ara[v].y != 0 || ara[v].w != 0 )
        {
            v++;
            scanf("%d %d %d", &ara[v].x, &ara[v].y, &ara[v].w);
        }
        //cout << " n " << n <<  " v " << v << endl;
        sort( ara, ara + v, comp1 );
        make_set();

        for( int i = 0; i < v && cc <= n; i++ )
        {
            a = find_par( ara[i].x );
            b = find_par( ara[i].y );
            if( a != b )
            {
                par[a] = par[b];
                ans1 += ara[i].w;
                cc++;
            }
        }

        make_set();
        cc = 1;
        /*for( int  i = 0; i < v; i++ )
        {
            cout << ara[i].x << " " << ara[i].y << " " << ara[i].w << endl;
        }
        cout << "yes\n";*/
        for( int i = v - 1; i >= 0  && cc <= n; i-- )
        {
            //cout << "yes1\n";
            a = find_par( ara[i].x );
            //cout << "yes2\n";
            b = find_par( ara[i].y );

            if( a != b )
            {
                par[a] = par[b];
                ans2 += ara[i].w;
                cc++;
            }
        }
        if( (ans1 + ans2)%2 == 1 )
        {
            printf("Case %d: %d/2\n", caseno++, ans1 + ans2);
        }
        else
        {
            printf("Case %d: %d\n", caseno++, (ans1 + ans2)/2);
        }
    }

    return 0;
}
