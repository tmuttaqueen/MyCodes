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

int main()
{
    Point<int> a(2,1), b(2,5);
    cout << a.dot(b) << " " << a.cross(b) << endl;
    cout << a-b << a+b << a*2 << endl;
    cout << (a+b)*0.5 << (b-a).rotateCCW90() << endl;
    cout << a.distsq(b) << endl;
}
