#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define xx first
#define yy second
#define mp make_pair

const int off = 100005, m = 200012;
map<int,vector<pii>>v[5];
int ans[m];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int x, y;
        cin >> x >> y;
        v[0][x].pb( mp(y,i) );
        v[1][y].pb( mp(x,i) );
        v[2][x+y].pb( mp(-x+y, i) );
        v[3][-x+y].pb( mp(x+y, i) );
    }
    for( int i = 0; i < 4; i++ )
    {
        for( auto it = v[i].begin(); it != v[i].end(); it++)
        {
            //cout << it->xx << ": " << endl;
            vector<pii> vec = it->yy;
            sort( vec.begin(), vec.end() );
            int d = vec.size();
            for( int j = 0; j < vec.size(); j++ )
            {
                //cout << j << " " << vec[j].xx << " " << vec[j].yy << endl;
                if( j-1 >= 0 ) ans[ vec[j].yy ]++;
                if( j+1 < d ) ans[ vec[j].yy ]++;
            }
        }
        //cout << "ok" << endl;
    }
    for( int i = 0; i <= 8; i++ )
    {
        int tot = 0;
        for( int j = 0; j < m; j++ )
        {
            if( ans[j] == i ) tot++;
        }
        cout << tot << " ";
    }
    cout << endl;


    return 0;
}

