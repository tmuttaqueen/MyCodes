#include <bits/stdc++.h>

using namespace std;

int x[500000], y[500000];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ara[n];
    int ans = 0;

    set<int>ss;
    for( int i = 0; i < n; i++ )
    {
        scanf("%d", &ara[i]);
    }
    int f = 1, l = f;
    for( int i = 0; i < n; i++ )
    {
        int c = ss.count( ara[i] );
        if( c == 0)
        {
            ss.insert( ara[i] );
            l++;
        }
        else
        {
            //l++;
            x[ans] = f;
            y[ans] = l;
            f = i+2;
            l = f;
            ss.clear();
            ans++;
        }
    }
    if( f != l )
    {
        l--;
        y[ans-1] = l;
    }

    if( ans == 0 )
    {
        cout << "-1" << endl;
        return 0;
    }

    cout << ans <<  endl;
    for( int i = 0; i < ans; i++ )
    {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;

}
