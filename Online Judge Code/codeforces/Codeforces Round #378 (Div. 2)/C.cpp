#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

intl n, k;
pii ara[505];
intl w[505];
intl pre[505];
intl after[505];
pair<intl, char>ans[505];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> w[i];
        //pre[i] = pre[i-1] + w[i];
    }
    cin >> k;
    for( int i = 1; i <= k; i++ )
        cin >> after[i];

    int prev = 1, indk = 1, flag = 1, c = 0, cur = 1;
    while(cur <= n && flag && indk <= k)
    {
        intl mx = prev, mn = prev, sum = 0;
        while( sum < after[indk] && cur <= n )
        {
            sum += w[cur];
            if( w[mx] < w[cur] )
                mx = cur;
            if( w[mn] > w[cur] )
                mn = cur;
            cur++;
        }
        //what_is(sum);
        if( sum != after[indk] )
            flag = 0;
        if( cur - prev > 1 && w[mn] == w[mx] )
            flag = 0;
        indk++;
        ara[c].xx = prev;
        ara[c].yy = cur-1;
        c++;
        prev = cur;
    }
    //what_is(flag);
    if( cur <= n || indk <= k )
        flag = 0;
    if( flag == 0 )
    {
        cout << "NO\n";
        return 0;
    }
    else
        cout << "YES\n";
    intl precal = -1, index = 0;
    vector<int>vec;
    for( int i = 0; i < c; i++ )
    {
        precal++;
        vec.clear();
        for( int j = ara[i].xx; j <= ara[i].yy; j++ )
            vec.pb( w[j] );
        //for( int i= 0; i < vec.size(); i++ )
            //cout << vec[i] << " ";
        //cout << endl;
        while( vec.size() > 1 )
        {
            int mx = 0;
            for( int i = 0; i < vec.size(); i++ )
            {
                if( vec[i] > vec[mx] )
                    mx = i;
                if( vec[i] == vec[mx] )
                {
                    if( i == 0 )
                    {
                        if( vec[i+1] < vec[i] )
                        {
                            mx = i;
                            //cout << "1\n";
                        }
                    }

                    else if( i == vec.size() -1 )
                    {
                        if( vec[i-1] < vec[i] )
                        {
                            mx = i;
                            //cout << "2\n";
                        }

                    }
                    else if( vec[i-1] < vec[i] || vec[i+1] < vec[i] )
                    {
                        mx = i;
                        //cout << "3\n";
                    }

                }
            }
            //cout << mx << endl;
            //cin >> n;
            if( mx != 0 && mx != vec.size() - 1 )
            {
                if( vec[mx-1] < vec[mx] )
                {
                    vec[mx] = vec[mx] + vec[mx-1];
                    vec.erase( vec.begin() + mx - 1 );
                    ans[index++] = mp( mx+precal, 'L' );
                }
                else if( vec[mx+1] < vec[mx] )
                {
                    vec[mx] = vec[mx] + vec[mx+1];
                    vec.erase( vec.begin() + mx + 1 );
                    ans[index++] = mp( mx+precal, 'R' );
                }
            }
            else if( mx == 0 )
            {
                if( vec[mx+1] < vec[mx] )
                {
                    vec[mx] = vec[mx] + vec[mx+1];
                    vec.erase( vec.begin() + mx + 1 );
                    ans[index++] = mp( mx+precal, 'R' );
                }
            }
            else if( mx == vec.size() -1 )
            {
                if( vec[mx-1] < vec[mx] )
                {
                    vec[mx] = vec[mx] + vec[mx-1];
                    vec.erase( vec.begin() + mx - 1 );
                    ans[index++] = mp( mx+precal, 'L' );
                }
            }
        }
    }

    for( int i = 0; i < index;i++ )
    {
        cout << ans[i].xx+1 << " " << ans[i].yy << endl;
    }

    return 0;
}



