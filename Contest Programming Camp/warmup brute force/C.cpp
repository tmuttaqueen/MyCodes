#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<pii>vec[1111];
intl n, b;
int c = 0, j = 1;

bool isPossible( int q )
{
    intl v = 0;
    for( int i = 0; i < c; i++ )
    {
        intl p = 2000000000;
        for( int j = 1; j < vec[i][0].xx; j++  )
        {
            if( vec[i][j].yy >= q )
            {
                p = min(p, vec[i][j].xx );
            }
        }
        v += p;
    }
    what_is(q);
    what_is(v);
    return v <= b;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t;
    scanf("%d", &t);
    char str1[100], str2[100], str3[100];
    for( int i = 0; i < 1111; i++ ) vec[i].resize(1111);
    while(t--)
    {
        scanf("%lld %lld\n", &n, &b);
        c = 0;
        j = 1;
        for( int i = 0; i < n; i++ )
        {
            scanf("%s %s %lld %lld\n", str1, str2, &vec[c][j].xx, &vec[c][j++].yy );
            if( i == 0 )
                strcpy(str3, str1);
            if( strcmp(str3, str1) != 0 )
            {
                vec[c][0].xx = j-1;
                c++;
                vec[c][1] = vec[c-1][j-1];
                j = 2;
            }
            if( i == n-1 && strcmp(str3, str1) == 0 )
            {
                vec[c][0].xx = j;
                c++;
            }
            strcpy(str3, str1);
        }
        for( int i = 0; i < c; i++ )
        {
            for( int j = 1; j < vec[i][0].xx; j++ )
            {
                cout << vec[i][j].xx << " " << vec[i][j].yy << endl;
            }
        }
        int l = 0, h = 1000000000, ans = 0;
        while( l <= h )
        {
            int m = (l+h)/2;
            if( isPossible(m) )
            {
                l = m+1;
                ans = m;
            }
            else
                h = m-1;
        }
        printf("%d\n", ans);

    }
    return 0;
}
