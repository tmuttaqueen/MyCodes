#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int q;
    cin >> q;
    map< pair<intl, intl>, intl>mm;
    while(q--)
    {
        intl a, u, v, w;
        cin >> a;
        if(a==1)
        {
            cin >> u >> v >> w;
            intl lu = 0, lv = 0, tu = u, tv = v;
            while( tu > 0 )
            {
                tu/=2;
                lu++;
            }
            while( tv > 0 )
            {
                tv/=2;
                lv++;
            }
            while( lu > lv )
            {
                mm[mp(u,u/2)]+=w;
                u/=2;
                lu--;
            }
            while( lv > lu )
            {
                mm[mp(v,v/2)]+=w;
                v/=2;
                lv--;
            }
            while(u != v)
            {
                mm[mp(u,u/2)] += w;
                mm[mp(v,v/2)] += w;
                u/=2;
                v/=2;
            }

        }
        else
        {
            cin >> u >> v;
            intl lu = 0, lv = 0, tu = u, tv = v, ans = 0;
            while( tu > 0 )
            {
                tu/=2;
                lu++;
            }
            while( tv > 0 )
            {
                tv/=2;
                lv++;
            }
            while( lu > lv )
            {
                ans+=mm[mp(u,u/2)];
                u/=2;
                lu--;
            }
            while( lv > lu )
            {
                ans += mm[mp(v,v/2)];
                v/=2;
                lv--;
            }
            while(u != v)
            {
                ans+=mm[mp(u,u/2)];
                ans += mm[mp(v,v/2)];
                u/=2;
                v/=2;
            }
            //ans += mm[mp(u,u/2)];
            cout << ans << endl;
        }
    }

    return 0;
}



