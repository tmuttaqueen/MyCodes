//its like you are telling him all your stories and dreams and i am there telling myself it's okay

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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

int ara[2005];
int num[2005];
set<pii>ss;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    set<pii>::iterator it, s, e;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        if( ara[i] <= m )
            num[ ara[i] ]++;
    }
    int low = n/m;
    for( int i = 1; i <= m; i++ )
    {
        ss.insert( mp(num[i],i) );
    }
    int ans1 , ans2 = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( ara[i] > m )
        {
            it = ss.begin();
            pii x = *it;
            if( x.xx == low )
                break;
            ss.erase(it);
            ara[i] = x.yy;
            x.xx++;
            ss.insert(x);
            ans2++;
        }
    }
    //what_is(ans2);
    while(1)
    {
        s = ss.begin();
        e = ss.end();
        e--;
        pii x = *s, y = *e;
        if( y.xx - x.xx <= 1 )
            break;
        if( x.xx == low )
            break;
        ss.erase(s);
        ss.erase(e);
        for( int i = 1; i <= n; i++ )
        {
            if( ara[i] == y.yy )
            {
                ara[i] = x.yy;
                //cout << "x " << x.xx <<  " " << x.yy << endl;
                //cout << "y " << y.xx << " " << y.yy << endl;
                x.xx++;
                y.xx--;
                ans2++;
                break;
            }
        }
        ss.insert(x);
        ss.insert(y);
    }
    s = ss.begin();
    ans1 = (*s).xx;
    cout << ans1 << " " << ans2 << endl;
    for( int i = 1; i< n; i++ )
    {
        cout << ara[i] << " ";
    }
    cout << ara[n] <<  endl;


    return 0;
}




