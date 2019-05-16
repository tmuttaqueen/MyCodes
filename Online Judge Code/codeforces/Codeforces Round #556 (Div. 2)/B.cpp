#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

string str[55];

vector<pii> vec[55][55];

int flag[55][55];

pii take[2500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> str[i];
    int cnt = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            if( str[i][j] == '.' ) cnt++;

            if( i > 0 && j > 0 && i < n - 1 && j < n - 1 && str[i][j] == '.' && str[i-1][j] == '.' && str[i][j-1] == '.' && str[i][j+1] == '.' && str[i+1][j] == '.' )
            {
                vec[i][j].push_back( mp(i,j) );
                vec[i-1][j].push_back( mp(i,j) );
                vec[i+1][j].push_back( mp(i,j) );
                vec[i][j-1].push_back( mp(i,j) );
                vec[i][j+1].push_back( mp(i,j) );
            }
        }
    }
    int c = 0, f = 1;
    if( cnt%5 == 0 )
    {
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( str[i][j] == '.' && vec[i][j].size() == 0 )
                {
                    f = 0;
                    //cout << "ops" << endl;
                    break;
                }
                else if( str[i][j] == '.' && vec[i][j].size() == 1 && flag[ vec[i][j][0].xx ][vec[i][j][0].yy] == 0 )
                {
                    flag[ vec[i][j][0].xx ][vec[i][j][0].yy] = 1;
                    take[c++] = vec[i][j][0];
                }
            }
        }
        //cout << c << endl;
        for( int i = 0; i < c; i++ )
        {
            for( int j = i+1; j < c; j++ )
            {
                if( abs( take[i].xx - take[j].xx ) + abs( take[i].yy - take[j].yy ) <= 2 )
                {

                    f = 0;
                }
            }
        }
    }
    else
        f = 0;

    if(f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
