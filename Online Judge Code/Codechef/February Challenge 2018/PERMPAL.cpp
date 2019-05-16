#include<bits/stdc++.h>

using namespace std;

string s;
int ans[123456];
vector<int>vec[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        for( int i = 0; i < 26; i++ ) vec[i].clear();
        cin >> s;
        int n = s.length();
        for( int i = 0; i < n; i++ )
        {
            vec[ s[i] - 'a' ].push_back(i);
        }
        int c = 0;
        for( int i = 0; i < 26; i++ )
        {
            c += vec[i].size()%2;
        }
        if( c > 1 )
        {
            cout <<  -1 << endl;
            continue;
        }
        int f = 0, r = n-1;
        for( int j = 0; j < 26; j++ )
        {
            int l = vec[j].size();
            for( int i = 0; i < l; i++ )
            {
                if( i < l/2 )
                {
                    ans[f++] = vec[j][i];
                }
                else if( l%2 == 1 && i == (l-1)/2 )
                {
                    ans[ n/2 ] = vec[j][i];
                }
                else
                {
                    ans[r--] = vec[j][i];
                }
            }
        }
        for( int i = 0; i < n; i++ )
        {
            cout << ans[i]+1 << " ";
        }
        cout << endl;

    }

    return 0;
}
