#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct Point
{
    T x, y;
    Point(T x = 0, T y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Point operator-( const Point &b ) const
    {
        return Point(this->x-b.x, this->y-b.y);
    }
    Point operator+( const Point &b ) const
    {
        return Point(this->x+b.x, this->y+b.y);
    }
    Point operator*( const int &n ) const
    {
        return Point(this->x*n, this->y*n);
    }
    Point operator*( const double &n ) const
    {
        return Point(this->x*n, this->y*n);
    }
    T cross( const Point &b )
    {
        T s = 0;
        s = this->x*b.y - this->y*b.x;
        return s;
    }
    T dot( const Point &b )
    {
        T s = 0;
        s = this->x*b.x + this->y*b.y;
        return s;
    }
    friend ostream &operator<<( ostream &output, const Point &p )
    {
        output << "x: " << p.x << " :: y: " << p.y << endl;
        return output;
    }
    Point rotateCCW90() const
    {
        return Point( -this->y, this->x );
    }
    Point rotateCW90() const
    {
        return Point( this->y, -this->x );
    }
    T distsq( const Point &b )
    {
        Point a = *this;
        return (a-b).dot( a-b );
    }
};

typedef Point<int> PT;


struct Geometry
{
    const double eps = 0.000000000001;
    Geometry()
    {
        //eps = 0.000000000001;
    }
    bool isColinear( PT &a, PT &b, PT &c )
    {
        return  abs((b-a).cross( c - a )) <= eps;
    }
    bool lineSegmentIntersection( PT &a, PT &b, PT &x, PT &y  )
    {
        if( isColinear(a,b,x) && isColinear(a,b,y) && isColinear(x, y, a) && isColinear(x, y, b)  )
        {
            if( a.distsq(x) <= eps || b.distsq(x) <= eps || a.distsq(y) <= eps || b.distsq(y) <= eps )
                return 1;
            if( (x-a).dot(x-b) <= eps || (y-a).dot(y-b) <= eps )
                return 1;
            if( (a-x).dot(a-y) <= eps || (b-x).dot(b-y) <= eps )
                return 1;
            return 0;
        }
        int d1 = (b-a).cross( x -a );
        int d2 = (b-a).cross(y-a);
        int d3 = (y-x).cross( a - x );
        int d4 = (y-x).cross( b - x );
        if( d1*d2 <= 0 && d3*d4 <= 0 )
        {
            return 1;
        }
        return 0;

    }
};

int main()
{
    Geometry g;
    PT a(1, 1), b(3,3), c(2,4), d( 3, 0) ;
    cout << g.lineSegmentIntersection( a, b, c, d ) << endl;
}
