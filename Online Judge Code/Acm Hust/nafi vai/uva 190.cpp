#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double ax, ay, bx, by, cx, cy;

    while( scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy) == 6 )
    {
        double tx = ax, ty = ay;
        bx -= ax;
        by -= ay;
        cx -= ax;
        cy -= ay;
        double t = ((bx*cx-cx*cx)/2 + (by*cy-cy*cy)/2 )/( by*cx - bx*cy );
        //cout << t << endl;
        double h1 = bx/2 + t*(-by), k1 = by/2 + t*bx;
        double r = sqrt( h1*h1 + k1*k1 ), h = h1 + tx, k = k1 + ty;
        double c = -2*h, d = -2*k, e = r*r - h*h - k*k;
        char c1 = '-', c2 = '-', c3 = '-', c4 = '-', c5 = '-';
        if( h < 0.0 )
        {
            c1 = '+';
            c3 = '+';
        }
        if( k < 0.0 )
        {
            c2 = '+';
            c4 = '+';
        }
        if( e < 0.0 )
        {
            c5 = '+';
        }
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", c1,  abs(h), c2,  abs(k), r );
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n", c3, abs(c), c4, abs(d), c5, abs(e) );
    }

    return 0;
}
