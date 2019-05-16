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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;



struct POINT{
        intl x,y;
        intl I;
        POINT( intl x = 0,intl y = 0,intl I = 0 )
        {
                this->x = x;
                this->y = y;
                this->I = I;
        }
};
bool operator<( const POINT &a,const POINT &b )
{
        if( a.x != b.x ) return a.x < b.x;
        else return a.y < b.y;
}

intl N, C;
vector<POINT> Pt(111111);
vector<bool> Del(111111);
vector<POINT> Hull(111111);

intl Area2( POINT a,POINT b,POINT c )
{
        return a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - c.x*b.y;
}

bool Cmp( const POINT &a,const POINT &b )
{
        intl Ar = Area2( Pt[0],a,b );
        if( Ar ) return Ar>0;
        intl Dx = labs( Pt[0].x-a.x ) - labs( Pt[0].x-b.x );
        intl Dy = labs( Pt[0].y-a.y ) - labs( Pt[0].y-b.y );
        if( Dx<0 || Dy<0 ){
                Del[a.I] = true;
                return true;
        }
        else if( Dx>0 || Dy>0 ){
                Del[b.I] = true;
                return false;
        }
        return true;
}
/* to del all linear point */
void Squash( void )
{
        intl i,j;
        for( i=j=0;i<N;i++){
                if( Del[Pt[i].I] ) continue;
                Pt[j] = Pt[i];
                j++;
        }
        //Pt.resize( j );
        N = j;
}
void ConvexHull( vector<POINT> &Hull )
{
        sort( Pt.begin(),Pt.begin()+N); // Pt[0] wiil contain leftmst-lowest point
        sort( Pt.begin()+1,Pt.begin()+N,Cmp );
        Squash();
        C = 0;
        if( N>=1 ) Hull[C++] = Pt[0] ;
        if( N>=2 ) Hull[C++] = Pt[1];
        //Hull.push_back( Pt[1] );
        intl i = 2;
        while( i<N ){
                intl s = C;
                if( Area2( Hull[s-2],Hull[s-1],Pt[i] )>0 ){
                        //Hull.push_back( Pt[i] );
                        Hull[C++] = Pt[i];
                        C++;
                        i++;
                }
                else C--;
        }
}



double dist( POINT a, POINT b )
{
    double d = sqrt( max(0LL,(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) );
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        N=n;
        //freopen("text1.txt","r",stdin );
        // repeated point is needed to omit by set
        for( int i = 0; i <= n; i++ )
        {
            Del[i] = 0;
        }
        for( int i = 0; i < n; i++ )
        {
            int a, b;
            cin >> a >> b;
            Pt[i] = POINT(a,b);
        }
        //debug;

        ConvexHull( Hull );
        //debug;
        double ans = 2*pi*d;
        what_is(C);
        cout << Hull[0].x << " " << Hull[0].y << endl;
        for( int i = 1; i < C; i++ )
        {
            cout << Hull[i].x << " " << Hull[i].y << endl;
            ans += dist( Hull[i], Hull[i-1] );
        }
        ans += dist( Hull[0], Hull[ C-1 ] );
        cout << "Case " << caseno++ << ": " << setprecision(10) << fixed << ans << endl;
    }
    return 0;
}

