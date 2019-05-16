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

const int mx = 10005;

int ara[mx];
set<int>ss;
bool flag[mx];
long long precal[mx];
vector<pii>vec;
int num[mx];
vector<int>qq;
void sieve()
{
    for( int i = 1; i < mx; i++ )
        flag[i] = 1;
    for( int i=4; i<mx; i+=2 )
        flag[i] = 0;

    for( int i = 3; i < mx; i+=2 )
    {
        if( flag[i] )
        {
            for( int j = i+i; j < mx; j+=i )
                flag[j] = 0;
        }
    }
    //debug;
    for( intl i = 4; i < mx; i++ )
        precal[i] = i*(i-1)*(i-2)*(i-3)/24;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    sieve();
    int t;
    int caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(num, 0, sizeof num);
        qq.clear();
        vec.clear();
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
            int temp = ara[i];
            for( int j = 2; j*j <= ara[i]; j++ )
            {
                if( ara[i]%j == 0 && flag[j] == 1 )
                {
                    while(temp%j==0)
                    {
                        temp/=j;
                        ara[i]/=j;
                    }
                    ara[i] *= j;
                    ss.insert(j);
                }
            }
            if(temp > 1)
            {
                ss.insert(temp);
            }
            num[ ara[i] ]++;
        }
        //for( int i = 1; i <  137; i++ ) cout << num[i] << " ";
        //cout << endl;
        vec.pb(mp(1,0));
        qq.pb(0);
        set<int>::iterator it;
        /*it = ss.begin();
        while( it != ss.end() )
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;*/
        while( !ss.empty() )
        {
            it = ss.begin();
            int a = *it;
            ss.erase(it);
            //what_is(a);
            int k;
            int l = vec.size();
            for( int i = 0; i < l; i++ )
            {
                int d = vec[i].xx;
                d = a*d;
                k = 0;
                for( int j = d; j < mx; j += d )
                {
                    k += num[j];
                }

                if( k >= 4 )
                {
                    vec.pb( mp(d, vec[i].yy+1 ) );
                    qq.pb(k);
                    //cout << "d " << d << " k " << k << endl;
                }
            }
        }
        ss.clear();
        intl ans = precal[n];
        for( int i = 1; i < vec.size(); i++ )
        {
            if( vec[i].yy%2 == 1 )
                ans -= precal[ qq[i] ];
            else
                ans += precal[ qq[i] ];
        }
        printf("Case %d: %lld\n", caseno++, ans);
        //debug;

    }


    return 0;
}




