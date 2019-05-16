#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

const int mx = 300005;
vector<pii>vec;
vector<int>query;
vector<int>temp;
int ara[mx];
int tt[mx];


int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q, c = 0;
        scanf("%d %d", &n, &q);
        for( int i = 0; i < n; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            vec.pb(mp(a, b));
            temp.pb(a);
            temp.pb(b);
        }
        for( int i = 0; i < q; i++ )
        {
            int a;
            scanf("%d", &a);
            query.pb(a);
            temp.pb(a);
        }
        sort( temp.begin(), temp.end()  );
        int l = temp.size();
        tt[0] = c++;
        for( int i = 1; i < l; i++ )
        {
            if( temp[i] == temp[i-1] ) tt[i] = tt[i-1];
            else tt[i] = c++;
        }
        for( int i = 0; i <= c; i++ ) ara[i] = 0;
        for( int i = 0; i < n; i++ )
        {
            int a = vec[i].xx, b = vec[i].yy;
            vector<int>::iterator p = lower_bound( temp.begin(), temp.end(), a  );
            vector<int>::iterator q = lower_bound( temp.begin(), temp.end(), b  );
            a = p - temp.begin();
            b = q - temp.begin();
            a = tt[a];
            b = tt[b];
            ara[a]++;
            ara[b+1]--;
        }
        for( int i = 1; i <= c; i++ )
            ara[i] += ara[i-1];
        printf("Case %d:\n", caseno++);
        for( int i = 0; i < q; i++ )
        {
            vector<int>::iterator p = lower_bound( temp.begin(), temp.end(), query[i] );
            int a = p - temp.begin();
            a = tt[a];
            printf("%d\n", ara[a]);
        }
        query.clear();
        vec.clear();
        temp.clear();
    }

    return 0;
}



