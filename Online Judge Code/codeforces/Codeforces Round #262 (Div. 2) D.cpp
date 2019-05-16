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

intl l, r, k, ans[10], n  = 0;

intl next( intl a )
{
    intl x = 2;
    intl an = a;
    while( x <= a )
    {
        if( (x&a) == 0 )
        {
            an += x;
        }
        else
        {
            an -= x;
        }
        x<<=1;
        //what_is(x);
    }
    //what_is(an);
    if( an < a )
    {
        an += x;
        if( an > r )
        {
            an -= x;
            an += (x>>1);
        }
    }
    //what_is(an);
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    cin >> l >> r >> k;
    if( k == 1 )
    {
        ans[0] = l;
        n++;
    }
    else if( k == 2 )
    {
        if( (r - l) >= 2 )
        {
            if(l&1)
            {
                ans[0] = l+1;
                ans[1] = l+2;
            }

            else
            {
                ans[0] = l;
                ans[1] = l + 1;
            }
            n+= 2;
        }
        else
        {
            if( l&1 )
            {
                if( (l^r) < l )
                {
                    ans[0] = l;
                    ans[1] = r;
                    n+=2;
                }
                else
                {
                    ans[0] = l;
                    n++;
                }
            }
            else
            {
                ans[0] = l;
                ans[1] = r;
                n+=2;
            }
        }
    }
    else if( k > 3 )
    {
        if( l&1 )
        {
            ans[0] = l+1;
            ans[1] = l+2;
            n+=2;
        }
        else
        {
            ans[0] = l;
            ans[1] = l+1;
            n+=2;
        }
        intl temp = next(ans[1]);
        //what_is(temp);
        if( ans[0]^ans[1]^(temp)^(temp-1) == 0 )
        {
            ans[2] = temp -1;
            ans[3] = temp;
            n+=2;
        }
    }
    else
    {
        if( l&1 )
        {
            ans[0] = l+1;
            ans[1] = l+2;
            n+=2;
        }
        else
        {
            ans[0] = l;
            ans[1] = l+1;
            n+=2;
        }
    }
    intl ss = 0;
    for( int i = 0; i < n; i++ )
    {
        ss = ss^ans[i];
        //what_is(ss);
    }
    cout << ss <<endl;
    cout << n << endl;
    cout << ans[0];
    for( int i = 1; i < n; i++ )
    {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}



