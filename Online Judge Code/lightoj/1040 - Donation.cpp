#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx      first
#define yy      second
#define mp      make_pair
#define intl    long long
#define filein  freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", "stdout")
#define debug   printf("yes \n")
#define pbb      push_back
#define pii     pair<int,int>
#define eb      emplace_back

int n, ara[51][51], par[51];

bool comp( pair< pair<int,int>, int > a, pair< pair<int,int>, int > b )
{
    return a.yy < b.yy;
}

int fpar( int a )
{
    if( par[a] == a )
        return a;
    par[a] = fpar( par[a] );
    return par[a];
}


int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        scanf("%d", &n);
        for(int  i = 1; i <= n; i++ )
        {
            for(int j = 1; j <= n; j++ )
            {
                scanf("%d", &ara[i][j]);
            }
        }
        vector< pair< pair<int,int>, int > > vec;
        int sum = 0, num = 0;
        for( int i = 1; i<= n; i++ )
        {
            for( int  j = i; j <= n; j++ )
            {
                if( i == j )
                {
                    sum += ara[i][j];
                }
                else if( ara[i][j] > 0 && ara[j][i] > 0 )
                {
                    vec.eb( mp(i,j) , min(ara[i][j],ara[j][i]) );
                    num++;
                    sum += max( ara[i][j],ara[j][i] );
                }
                else if( ara[i][j]|ara[j][i] > 0  )
                {
                    vec.eb( mp(i,j), max(ara[i][j],ara[j][i]) );
                    num++;
                }
            }
        }
        sort( vec.begin(), vec.end(), comp );
        for( int  i = 1; i <= n; i++  )
        {
            par[i] = i;
        }

        for( int i = 0; i < num; i++ )
        {
            int pa = fpar( vec[i].xx.xx ), pb = fpar( vec[i].xx.yy );
            if( pa != pb )
            {
                par[pa] = pb;
            }
            else
            {
                sum += vec[i].yy;
            }
        }

        int x = fpar(1);
        for( int  i = 2; i <= n; i++  )
        {
            int y = fpar(i);
            if( x != y )
            {
                sum = -1;
            }
        }
        printf("Case %d: %d\n", caseno++, sum);
    }
    return 0;
}

