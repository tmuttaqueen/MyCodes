#include<bits/stdc++.h>

using namespace std;

int main()
{
    double d;
    double a, r1, r2 , r3 , r4 , s3 = sqrt(3.0), s7 = sqrt(7.0), s21 = s3*s7;
    while( scanf("%lf", &a) == 1 )
    {
        r1 = a*s3/2;
        r2 = ( 2*s3-3 )*a;
        r3 = r1/2;
        r4 = a*s21/( 4*s3 + 2*s7 );
        printf("%.10f %.10f %.10f %.10f\n", r1, r2, r3, r4 );
    }

    return 0;
}





