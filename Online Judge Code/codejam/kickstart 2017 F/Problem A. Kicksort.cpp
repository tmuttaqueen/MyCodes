#include<bits/stdc++.h>

using namespace std;

const int mx = 10002;
int bit[mx];
int ara[mx];

void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int cnt = 0, Min = 1, Max = n;
        for( int i = 0; i <= n; i++ ) bit[i] = 0;

        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i];
            update(i,1);
        }
        for( int i = n; i > 1; i-- )
        {
            int l = 1, r = n, target = (i-1)/2+1, ind = -1;
            while(l <= r )
            {
                int m = (l+r)/2;
                int sum = query(m);
                //cout << m << " " << sum << endl;
                if( sum >= target )
                {
                    ind = m;
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            //cout << ind << " " << target << " " << ara[ind] << endl;
            update( ind, -1 );
            if( ara[ind] == Max )
            {
                cnt++;
                Max--;
            }
            else if( ara[ind] == Min )
            {
                cnt++;
                Min++;
            }
        }
        if( cnt == n-1 )
        {
            cout << "Case #" << caseno++ << ": YES" << endl;
        }
        else
        {
            cout << "Case #" << caseno++ << ": NO" << endl;
        }

    }

    return 0;
}
