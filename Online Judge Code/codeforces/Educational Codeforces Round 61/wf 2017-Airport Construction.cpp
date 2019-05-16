#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define ld long double

const ld eps = 1e-9, EPS = 1e-9;

struct PT
{
    ld x,y;
    PT() {}
    PT(ld x,ld y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
};
PT operator +(PT a,PT b)
{
    return PT(a.x+b.x,a.y+b.y);
}
PT operator -(PT a,PT b)
{
    return PT(a.x-b.x,a.y-b.y);
}
PT operator *(PT a,ld b)
{
    return PT(a.x*b,a.y*b);
}
PT operator /(PT a,ld b)
{
    return PT(a.x/b,a.y/b);
}
ld operator *(PT a,PT b)  //dot
{
    return a.x*b.x+a.y*b.y;
}
ld operator ^(PT a,PT b)   //cross
{
    return a.x*b.y-a.y*b.x;
}

int dcmp(ld x)
{
    if (fabs(x)<eps)
        return 0;
    return x<0 ? -1 : 1;
}

vector<PT>ara;
int n;
ld mx = 1e9;

ld dist2(PT a, PT b)
{
    return ((a-b)*(a-b));
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs((b-a)^(c-d)) < eps;
}

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d)
           && fabs((a-b)^(a-c)) < eps
           && fabs((c-d)^(c-a)) < eps;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if (LinesCollinear(a, b, c, d))
    {
        if (dist2(a, c) < eps || dist2(a, d) < eps ||
                dist2(b, c) < eps || dist2(b, d) < eps) return true;
        if ((c-a)*(c-b) > 0 && (d-a)*(d-b) > 0 && (c-b)*(d-b) > 0)
            return false;
        return true;
    }
    if (((d-a)^(b-a))*((c-a)^(b-a)) > 0) return false;
    if (((a-c)^(d-c))*((b-c)^(d-c)) > 0) return false;
    return true;
}

bool SegmentsIntersectStrict(PT a, PT b, PT c, PT d)
{
    int x = dcmp( (b-a)^(c-a) ), y = dcmp( (b-a)^(d-a) );
    if( x*y < 0 ) return true;
    return false;
}

//intersection of line ab and cd
ld ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    b=b-a;
    d=c-d;
    c=c-a;
    assert((b*b) > EPS && (d*d) > EPS);
    return (c^d)/(b^d);
}

bool colinear( PT a, PT b, PT c )
{
    ld v = (b-a)^(c-a);
    return dcmp(v) == 0;
}

ld dist(PT a, PT b)
{
    return sqrt((a-b)*(a-b));
}

bool OnSegment(PT p,PT a,PT b)
{
    return dcmp((a-p)^(b-p)) == 0 && dcmp((a-p)*(b-p))<=0;
}

///// Point in simple polygon,1/-1:on/inside;0:strictly out
int isPointOnPolygon(PT p, vector<PT> &poly)
{
    int wn=0;
    int n=poly.size();
    for(int i = 0; i < n; i++)
    {
        if (OnSegment(p,poly[i],poly[(i+1)%n])) return -1; //on edge
        int k=dcmp((poly[(i+1)%n]-poly[i])^(p-poly[i]));
        int d1 = dcmp(poly[i].y-p.y);
        int d2 = dcmp(poly[(i+1)%n].y-p.y);
        if ( k > 0 && d1 <= 0 && d2 > 0 ) wn++;
        if ( k < 0 && d2 <= 0 && d1 > 0 ) wn--;
    }
    if (wn!=0) return 1; //inside
    return 0; //outside
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    ara.resize(n);
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].x >> ara[i].y;
    }
    ld ans = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = i+1; j < n; j++ )
        {
            int f = 1;
            PT mm = (ara[i] + ara[j])*0.5;
            if( !isPointOnPolygon(mm, ara) )
            {
                f = 0;
                continue;
            }

            for( int k = 0; k < n; k++ )
            {
                if( k == i || k == j || (k+1)%n == i || (k+1)%n == j ) continue;
                if( SegmentsIntersect( ara[i], ara[j], ara[k], ara[ (k+1)%n ] ) )
                {
                    f = 0;
                    break;
                }
            }
            for( int k = 0; k < n; k++ )
            {
                if( k == i || k == j ) continue;
                if( OnSegment(ara[k], ara[i], ara[j] ))
                {
                    f = 0;
                    break;
                }
            }
            if(f == 0) continue;

            ld l = -mx, r = mx;

            for( int k = 0; k < n; k++ )
            {
                if( SegmentsIntersectStrict( ara[i], ara[j], ara[k], ara[ (k+1)%n ] ) )
                {
                    ld t = ComputeLineIntersection( ara[i], ara[j], ara[k], ara[ (k+1)%n ] );

                    if( t > 1.0 )
                    {
                        r = min(t, r);
                    }
                    if(  t < 0.0 )
                    {
                        l = max(l, t);
                    }
                }
            }

            vector<ld>vec;
            vec.push_back(l);
            vec.push_back(r);

            ld dd = dist( ara[i], ara[j] );
            for( int k = 0; k < n; k++ )
            {
                if( colinear( ara[i], ara[j], ara[k] ) )
                {
                    ld t = dist(ara[k], ara[i])/dd;

                    if( dcmp((ara[k]-ara[i])*(ara[j]-ara[i])) < 0 )
                    {
                        t = -t;
                    }
                    if( t < l || t > r )
                        continue;
                    vec.push_back(t);
                }
            }
            sort( vec.begin(), vec.end() );

            ld lo = 0, hi = 1;
            int zero = 0;
            for( int k = 0; k < vec.size(); k++ )
            {
                if( dcmp(vec[k]) == 0 )
                {
                    zero = k;
                    break;
                }
            }

            for( int k = zero; k >= 1; k-- )
            {
                PT p = ara[i] + (ara[j]-ara[i])*vec[k-1], q = ara[i] + (ara[j]-ara[i])*vec[k];
                PT mid = (p+q)*0.5;
                if( isPointOnPolygon(mid, ara) )
                {
                    lo = vec[k-1];
                }
                else
                    break;
            }

            for( int k = zero+1; k < vec.size(); k++ )
            {
                PT p = ara[i] + (ara[j]-ara[i])*vec[k-1], q = ara[i] + (ara[j]-ara[i])*vec[k];
                PT mid = (p+q)*0.5;
                //cout << mid.x << ": " << mid.y << endl;
                if( isPointOnPolygon(mid, ara) )
                {
                    //cout << k << " " << hi << endl;
                    hi = vec[k];
                }
                else
                    break;
            }

            if( lo > hi ) continue;
//            cout << "***********" << endl;
//            for( double v: vec )
//                cout << v <<endl;

            //cout << i << " " << j << " " << lo << " " << hi << " " << ans << endl;



            PT p = ara[i] + (ara[j]-ara[i])*lo, q = ara[i] + (ara[j]-ara[i])*hi;



            ans = max(ans, dist(p,q) );

        }

    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}

/*
12
0 0
5 0
6 1
8 1
7 1
10 0
10 1
9 1
9 2
5 2
4 1
1 1
*/

