#include<bits/stdc++.h>

using namespace std;

const int M = 1005;

int ara[M];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1, n;
    cin >> t;

    while(t--)
    {
        //cout << t << endl;
        long long energy, n, honor = 0;
        cin >> energy >> n;
        for( int i  = 1; i <= n; i++ )
        {
            cin >> ara[i];
        }
        sort( ara+1, ara+n+1 );
        int st = 1, en = n, f = 1;
        while( st <= en && f )
        {
            //cout << caseno << endl;
            //cout << st << " " << en << endl;
            if( energy > ara[st] )
            {
                energy -= ara[st++];
                honor++;
            }
            else if( energy <= ara[st] )
            {
                if( ara[st] >= ara[en] || honor == 0 )
                {
                    f = 0;
                    break;
                }
                while( energy <= ara[st] && honor > 0 && f )
                {
                    energy += ara[en--];
                    honor--;
                }
            }
        }
        cout << "Case #" << caseno++ << ": " <<  honor << endl;
    }

    return 0;
}
