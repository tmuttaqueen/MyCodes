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

map<pii, pii>mm;
map<pii,pii>index;
map<pii,pii>::iterator i1, i2, i3;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, aa[3];
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> aa[0] >> aa[1] >> aa[2];
        sort(aa,aa+3);
        if( mm.find( mp(aa[0], aa[1])) == mm.end() )
        {
            mm[mp(aa[0], aa[1] )] = mp(0LL,0LL);
            index[mp(aa[0], aa[1] )] = mp(0LL,0LL);
        }
        if( mm.find( mp(aa[1], aa[2])) == mm.end() )
        {
            mm[mp(aa[1], aa[2] )] = mp(0LL,0LL);
            index[mp(aa[0], aa[1] )] = mp(0LL,0LL);
        }
        if( mm.find( mp(aa[0], aa[2])) == mm.end() )
        {
            mm[mp(aa[0], aa[2] )] = mp(0LL,0LL);
            index[mp(aa[0], aa[1] )] = mp(0LL,0LL);
        }
        i1 = mm.find( mp(aa[0], aa[1]));
        i2 = index.find(mp(aa[0], aa[1]));
        if( (*i1).yy.xx <= aa[2] )
        {
            (*i1).yy.yy = (*i1).yy.xx;
            (*i1).yy.xx = aa[2];
            (*i2).yy.yy = (*i2).yy.xx;
            (*i2).yy.xx = i+1;
        }
        else if( (*i1).yy.yy < aa[2] )
        {
            (*i1).yy.yy = aa[2];
            (*i2).yy.yy = i+1;
        }

        i1 = mm.find( mp(aa[0], aa[2]));
        i2 = index.find(mp(aa[0], aa[2]));
        if( (*i1).yy.xx <= aa[1] )
        {
            (*i1).yy.yy = (*i1).yy.xx;
            (*i1).yy.xx = aa[1];
            (*i2).yy.yy = (*i2).yy.xx;
            (*i2).yy.xx = i+1;
        }
        else if( (*i1).yy.yy < aa[1] )
        {
            (*i1).yy.yy = aa[1];
            (*i2).yy.yy = i+1;
        }

        i1 = mm.find( mp(aa[1], aa[2]));
        i2 = index.find(mp(aa[1], aa[2]));
        if( (*i1).yy.xx <= aa[0] )
        {
            (*i1).yy.yy = (*i1).yy.xx;
            (*i1).yy.xx = aa[0];
            (*i2).yy.yy = (*i2).yy.xx;
            (*i2).yy.xx = i+1;
        }
        else if( (*i1).yy.yy < aa[0] )
        {
            (*i1).yy.yy = aa[0];
            (*i2).yy.yy = i+1;
        }
    }

    i1 = mm.begin(), i2 = index.begin();
    intl ans = -1, index1 = -1, index2 = -1;
    while( i1 != mm.end() && i2 != index.end() )
    {
        intl a = (*i1).xx.yy, b = (*i1).yy.xx + (*i1).yy.yy, c = (*i1).xx.xx;
        intl d = min( a, min(b,c) );
        if( ans < d )
        {
            index1 = (*i2).yy.xx;
            index2 = (*i2).yy.yy;
        }
        i1++;
        i2++;
    }
    if( index1 != 0 && index2 != 0 && index1 != index2 )
    {
        cout << 2 << "\n" << index1 << " " << index2 << endl;
    }
    else
    {
        if( index1 == 0 )
        {
            cout << 1 << "\n" << index2 << endl;
        }
        else
            cout << 1 << "\n" << index1 << endl;
    }

}
