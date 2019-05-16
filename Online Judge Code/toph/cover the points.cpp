#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double PI=acos(-1.0);
const double eps=1e-10;
const double EPS=1e-10;

#define int long long

struct PT
{
    int x , y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
};
PT operator +(PT a,PT b)
{
    return PT(a.x+b.x,a.y+b.y);
}
PT operator -(PT a,PT b)
{
    return PT(a.x-b.x,a.y-b.y);
}
PT operator *(PT a,int b)
{
    return PT(a.x*b,a.y*b);
}

PT operator /(PT a,int b)
{
    return PT(a.x/b,a.y/b);
}
int operator *(PT a,PT b) //dot
{
    return a.x*b.x+a.y*b.y;
}
int operator ^(PT a,PT b) //cross
{
    return a.x*b.y-a.y*b.x;
}

bool operator <(const PT &a,const PT &b)
{
    return make_pair(a.x,a.y)<make_pair(b.x,b.y);
}

bool operator == (const PT &a,const PT &b) {
    return ( (a.x-b.x)==0 && (a.y-b.y) == 0 ) ;
}
double len(PT a) {
    return sqrt(a*a);
}
int len2(PT a)
{
    return (a*a);
}
double dist(PT a, PT b)
{
    return sqrt((double)((a-b)*(a-b)));
}
int dist2(PT a, PT b)
{
    return ((a-b)*(a-b));
}
inline int sqr(int a)
{
    return a*a;
}

PT RotateCCW90(PT p)
{
    return PT{-p.y,p.x};
}
PT RotateCW90(PT p)
{
    return PT{p.y,-p.x};
}


//determine if p is on segment ab
bool OnSegment(PT p,PT a,PT b)
{
    return ((a-p)^(b-p)) == 0 && ((a-p)*(b-p)) < 0;
}

int triArea2(PT A,PT B,PT C)
{
    return abs((B-A)^(C-A));
}

/// triangle vertex a , b , c ; Target T // returns 1 if Point is on or inside the triangle
int PointsInTriangle (PT a , PT b , PT c , PT T) {
    int A1 = triArea2(a,b,T) , A2 = triArea2(b,c,T) , A3 = triArea2(c,a,T) , A = triArea2(a,b,c) ;
    if ( (A- (A1 + A2 + A3)) == 0) {
        return 1 ;
    }
    return 0 ;
}
/// returns 1 if CCW or collinear , returns 0 if CW
bool CCW(PT a, PT b, PT c) {
    int area = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y ;
    if( area >= 0.0 ) return 1 ;
    return 0 ;
}
/// Points in Polygon must be in CCW and no three collinear points
/// if collinear exits compute its convex to remove them
int PointsInConvexPolygon (vector <PT> &P , PT T) {
    if (P.size() < 3) return 0 ; /// not a convex polygon
    int lo = 1 , hi = P.size() - 1 ;
    while (hi-lo > 1) {
        int mid = (hi+lo)/2 ;
        if (CCW(P[0],P[mid],T)) {
            lo = mid ;
        }
        else {
            hi = mid ;
        }
    }
    return PointsInTriangle(P[0],P[lo],P[hi],T) ;
}


//input p[]: given points in plane
//output sol[]: convex hull of p[]
PT ch[101000];
void ConvexHull( vector<PT> &p, vector<PT> &sol)
{
    sort(p.begin(),p.end());
    int m = 0;
    int n = p.size();
    for( int i = 0; i < n; i++ )
    {
        while(m>1 && ((ch[m-1]-ch[m-2])^(p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    int k = m;
    for( int i = n-2; i >= 0; i-- )
    {
        while(m>k && ((ch[m-1]-ch[m-2])^(p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    if ( n > 1 ) m--;
    for( int i = 0; i < m; i++ ) sol.push_back(ch[i]);
}

//input: polygon poly[], line AB(point representation)
//output: intersecting points of AB and polygon and upper/lower




/*tangent lines to a convex polygon from a point outside*/

#define CW 		-1
#define ACW	 	 1
#define pii pair<int, int>
#define xx first
#define yy second
#define LL long long

int direction(pii st, pii ed, pii q){
	LL xp = (LL) (ed.xx - st.xx) * (q.yy - ed.yy) - (LL) (ed.yy - st.yy) * (q.xx - ed.xx);
	if(!xp) return 0;
	if(xp > 0) return ACW;
	return CW;
}

bool isGood(pii u, pii v, pii Q, int dir){
    return (direction(Q, u, v) != -dir);
}

pii better(pii u, pii v, pii Q, int dir){
    if(direction(Q, u, v) == dir) return u;
    return v;
}

pii tangents(vector<pii> &hull, pii Q, int dir, int lo, int hi){
    int mid;

    while(hi - lo + 1 > 2){
        mid = (lo + hi)/2;
        bool pvs = isGood(hull[mid], hull[mid - 1], Q, dir);
        bool nxt = isGood(hull[mid], hull[mid + 1], Q, dir);

        if(pvs && nxt) return hull[mid];
        if(!(pvs || nxt)){
            pii p1 = tangents(hull, Q, dir, mid+1, hi);
            pii p2 = tangents(hull, Q, dir, lo, mid - 1);
            return better(p1, p2, Q, dir);
        }

        if(!pvs){
            if(direction(Q, hull[mid], hull[lo]) == dir)  hi = mid - 1;
            else if(better(hull[lo], hull[hi], Q, dir) == hull[lo]) hi = mid - 1;
            else lo = mid + 1;
        }
        if(!nxt){
            if(direction(Q, hull[mid], hull[lo]) == dir)  lo = mid + 1;
            else if(better(hull[lo], hull[hi], Q, dir) == hull[lo]) hi = mid - 1;
            else lo = mid + 1;
        }
    }

    pii ret = hull[lo];
    for(int i = lo + 1; i <= hi; i++) ret = better(ret, hull[i], Q, dir);
    return ret;
}

/// [ACW, CW] Tangent
pair< pii, pii> get_tangents(vector<pii> &polygon, pii Q){

    pii acw_tan = tangents(polygon, Q, ACW, 0, (int) polygon.size() - 1);
    pii cw_tan = tangents(polygon, Q, CW, 0, (int) polygon.size() - 1);



    return make_pair(acw_tan, cw_tan);
}

/****finish point to polygon tangent***/

double angle( PT p, PT a, PT b )
{
    double dot = (a-p)*(b-p);
    dot /= dist(a,p);
    dot /= dist(b,p);
    double deg = acos(dot)*(180.0/acos(-1.0));
    return deg;
}


vector<PT> vec, hull;
vector<pii> hl ;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    int t, caseno = 1;
    cin >> t;
    while(t--) {
        vec.clear();
        hull.clear();
        hl.clear();
        int n, q, x, y;
        cin >> n >> q;
        for( int i = 0; i < n; i++ )
        {
            cin >> x >> y;
            vec.push_back( {x,y} );
        }
        ConvexHull(vec,hull);
        cout << "Case " << caseno++ << ":\n";
        if( hull.size() == 1 )
        {
            for( int i = 0; i < q; i++ )
            {
                cin >> x >> y;
                cout << "0.00\n";
            }
        }
        else if( hull.size() == 2 )
        {
            for( int i = 0; i < q; i++ )
            {
                cin >> x >> y;
                PT a(x,y);
                if(OnSegment(a,hull[0], hull[1]))
                {
                    cout << "TOO WIDE\n";
                }
                else
                {
                    double d = angle(a, hull[0], hull[1]);
                    cout << setprecision(2) << fixed << d << "\n";
                }
            }
        }
        else
        {
             for (int i = 0 ; i < hull.size() ; i++) hl.push_back({hull[i].x,hull[i].y}) ;
            for( int i = 0; i < q; i++ )
            {
                pii a;
                cin >> a.xx >> a.yy;
                if( PointsInConvexPolygon(hull, PT(a.xx,a.yy)) )
                {
                    cout << "TOO WIDE\n";
                }
                else
                {
                    pair<pii, pii> pp = get_tangents(hl,a);
                    double d = angle( PT(a.xx,a.yy), PT(pp.xx.xx, pp.xx.yy), PT(pp.yy.xx, pp.yy.yy));
                    cout << setprecision(2) << fixed << d << "\n";
                }
            }
        }
    }
    return 0;
}
