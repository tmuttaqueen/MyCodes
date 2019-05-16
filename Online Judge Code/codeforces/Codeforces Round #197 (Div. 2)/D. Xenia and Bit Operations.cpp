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
    int n, q, sz;
    cin >> n >> q;
    sz = (1<<(n+1));
    int s = 1<<n, flag = 0; //0=or, 1=x-or
    intl ara[sz+5], ans = 0, level = n;
    for( int i = s; i < sz; i++ )
    {
        cin >> ara[i];
    }
    for( int i = s-1; i > 0; i-- )
    {
        if( flag == 0 )
        {
            ara[i] = ara[i*2]|ara[i*2+1];
        }
        else
        {
            ara[i] = ara[i*2]^ara[i*2+1];
        }
        if((i&(i-1))==0)
        {
            flag = (!flag);
        }
    }
    //for( int i = 1; i < sz; i++ ) cout << ara[i] << " ";
    while(q--)
    {
        intl a, b;
        cin >> a >> b;
        int cn = s+a-1, flag = 0;
        ara[cn] = b;
        while(cn)
        {
            //what_is(cn);
            int l, r;
            if(cn%2)
            {
                l = cn-1;
                r = cn;
            }
            else
            {
                l = cn;
                r=l+1;
            }
            cn/=2;
            if(flag==0)
            {
                ara[cn] = ara[l]|ara[r];
            }
            else
            {
                ara[cn] = ara[l]^ara[r];
            }
            flag = (!flag);
        }
        cout << ara[1] << endl;
    }

    return 0;
}




