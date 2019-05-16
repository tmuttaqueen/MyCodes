#include<bits/stdc++.h>

using namespace std;

#define intl long long

struct PT
{
    intl x, y;
    PT() {}
    PT(intl x, intl y) : x(x), y(y) {}
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
PT operator *(PT a,double b)
{
    return PT(a.x*b,a.y*b);
}

PT operator /(PT a,double b)
{
    return PT(a.x/b,a.y/b);
}
double operator *(PT a,PT b) //dot
{
    return a.x*b.x+a.y*b.y;
}
double operator ^(PT a,PT b) //cross
{
    return a.x*b.y-a.y*b.x;
}

bool operator <(const PT &a,const PT &b)
{
    return make_pair(a.x,a.y)< make_pair(b.x,b.y);
}
bool operator==(const PT &a,const PT &b)
{
    return (a.x-b.x)==0 && (a.y-b.y) == 0;
}

double dist(PT a, PT b)
{
    double d = ((a-b)*(a-b));
    return sqrt(d);
}

bool onSegemnt( PT a, PT b, PT p )
{
    return ( (a-p)^(b-p) ) == 0 && ( (a-p)*(b-p) ) < 0;
}

intl triArea2( PT a, PT b, PT c )
{
    return abs( (a-b)^(c-b) );
}

PT ch[101000];
void ConvexHull( vector<PT> p, vector<PT> &sol)
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


/// triangle vertex a , b , c ; Target T // returns 1 if Point is on or inside the triangle
int PointsInTriangle (PT a , PT b , PT c , PT T) {
    intl A1 = triArea2(a,b,T) , A2 = triArea2(b,c,T) , A3 = triArea2(c,a,T) , A = triArea2(a,b,c) ;
    if ( A == A1 + A2 + A3) {
        return 1 ;
    }
    return 0 ;
}
/// returns 1 if CCW or collinear , returns 0 if CW
bool CCW(PT a, PT b, PT c) {
    intl area = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y ;
    if( area >= 0 ) return 1 ;
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



#define CW 		-1
#define ACW	 	 1
#define pii pair<intl,intl>
#define xx first
#define yy second
#define LL long long

int direction(PT st, PT ed, PT q){
    intl xp = (ed.x - st.x) * (q.y - ed.y) - (ed.y - st.y) * (q.x - ed.x);
	if(!xp) return 0;
	if(xp > 0) return ACW;
	return CW;
}

bool isGood(PT u, PT v, PT Q, int dir){
    return (direction(Q, u, v) != -dir);
}

PT better(PT u, PT v, PT Q, int dir){
    if(direction(Q, u, v) == dir) return u;
    return v;
}

PT tangents(vector<PT> &hull, PT Q, int dir, int lo, int hi){
    int mid;

    while(hi - lo + 1 > 2){
        mid = (lo + hi)/2;
        bool pvs = isGood(hull[mid], hull[mid - 1], Q, dir);
        bool nxt = isGood(hull[mid], hull[mid + 1], Q, dir);

        if(pvs && nxt) return hull[mid];
        if(!(pvs || nxt)){
            PT p1 = tangents(hull, Q, dir, mid+1, hi);
            PT p2 = tangents(hull, Q, dir, lo, mid - 1);
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

    PT ret = hull[lo];
    for(int i = lo + 1; i <= hi; i++) ret = better(ret, hull[i], Q, dir);
    return ret;
}

/// [ACW, CW] Tangent
pair< PT, PT> get_tangents(vector<PT> &polygon, PT Q){

    PT acw_tan = tangents(polygon, Q, ACW, 0, (int) polygon.size() - 1);
    PT cw_tan = tangents(polygon, Q, CW, 0, (int) polygon.size() - 1);



    return make_pair(acw_tan, cw_tan);
}

vector<PT>vec, hull;

double angle( PT p, PT a, PT b )
{
    double dot = (a-p)*(b-p);
    dot /= dist(a,p);
    dot /= dist(b,p);
    double deg = acos(dot)*(180.0/acos(-1.0));
    return deg;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        vec.clear();
        hull.clear();
        int n, q, x, y;
        cin >> n >> q;
        for( int i = 0; i < n; i++  )
        {
            cin >> x >> y;
            vec.push_back( PT(x,y) );
        }



        ConvexHull(vec, hull);
        /*for( int i = 0; i < hull.size(); i++ )
        {
            cout << hull[i].x << " " << hull[i].y << endl;
        }*/
        cout << "Case " << caseno++ << ": " << endl;
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
                PT p(x,y);
                if( onSegemnt( hull[0], hull[1], p ) )
                    cout << "TOO WIDE\n";
                else
                    cout << setprecision(2) << fixed << angle(p,hull[0], hull[1]) << "\n";
            }
        }
        else
        {
            for( int i = 0; i < q; i++ )
            {
                cin >> x >> y;
                PT p(x,y);
                if( PointsInConvexPolygon( hull, p ) )
                    cout << "TOO WIDE\n";
                else
                {
                    pair<PT, PT> pp = get_tangents(hull, p);
                    cout << setprecision(2) << fixed << angle(p,pp.xx, pp.yy) << "\n";
                }
            }
        }
    }

    return 0;
}
