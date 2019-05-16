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
    intl n, q;
    intl one = 1, two = 2;
    scanf("%I64d %I64d", &n, &q);
    for( int i = 0; i < q; i++ )
    {
        intl t, x;
        scanf("%I64d", &t);
        if( t == 1 )
        {
            scanf("%I64d", &x);
            one += x;
            two += x;
        }
        else
        {
            if( one % 2 == 1 )
                one++;
            else
                one--;
            if( two%2 == 1 )
                two++;
            else
                two--;
        }
        one = (one%n+n)%n;
        two = (two%n+n)%n;
    }
    //what_is(one);
    //what_is(two);
    intl ans[n+5];
    for( int i = 1; i <= n; i++ )
    {
        if(i&1)
        {
            intl pos = one + i - 1;
            pos = (pos%n + n)%n;
            if( !pos )
                pos = n;
            ans[pos] = i;
        }
        else
        {
            intl pos = i + two - 2;
            pos = (pos%n + n)%n;
            if(!pos)
                pos = n;
            ans[pos] = i;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}



