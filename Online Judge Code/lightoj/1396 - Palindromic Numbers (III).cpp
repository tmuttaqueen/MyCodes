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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        int flag = 2, x = 0; // 1 = equal, 2 = greater, 3 = less
        char s[100005];
        char ans[100005];
        scanf("%s", s);
        int l = strlen(s);
        //cout << s << endl;
        if( l == 1 && s[0] != '9' )
        {
            //debug;
            printf("Case %d: %c\n",caseno++, s[0]+1 );
            continue;
        }
        for( int i = l; i > 0; i-- )
        {
            s[i] = s[i-1];
        }
        s[0] = '0';
        s[l+1] = '0';
        s[l+2] = '\0';
        l += 2;
        int m = l/2;

        //what_is(s);

        for( int i = 0 ; i < m; i++ )
        {
            ans[i] = s[i];
            ans[l-i-1] = ans[i];
        }
        if( l%2 ) ans[m] = s[m];
        ans[l] = '\0';
        //printf("%s\n", ans);
        for( int i = 0; i < l; i++ )
        {
            if( ans[i] > s[i] ) break;
            if( s[i] > ans[i]  ) flag = 1;
        }
        for( int i = 0; i < l; i++ )
        {
            if( s[i] == ans[i]  ) x++;
        }
        if( x == l ) flag = 1;
        if( flag == 1 )
        {
            if( l%2 == 0 )
            {
                int tt = m;
                while( ans[m-1] == '9' )
                    m--;
                //what_is(m);
                for( int i = m; i < (l-m); i++ ) ans[i] = '0';
                ans[m-1]++;
                ans[l-m]++;
            }
            else
            {
                int tt = m;
                while( ans[m] == '9' )
                    m--;
                //what_is(m);
                //cout << int(ans[m]) << endl;
                for( int i = m+1; i < (l-m-1); i++ ) ans[i] = '0';
                ans[m]++;
                //cout << int(ans[m]) << endl;
                ans[l-m-1] = ans[m];
            }
        }
        if( ans[0] == '1' && ans[l-1] == '1' )
        {
            ans[l-2] = '1';
            ans[l-1] = '\0';
        }
        printf("Case %d: ", caseno++ );
        if( ans[0] == '0' && ans[l-1] == '0' )
        {
            for( int i = 1; i < (l-1); i++ ) printf("%c", ans[i]);
            printf("\n");
        }
        else
        {
            printf("%s\n", ans);
        }

    }

    return 0;
}



