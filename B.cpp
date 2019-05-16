#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const intl MAXN = 1000000;

intl lx, rx;

intl gcd(intl a, intl b, intl &x, intl &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    intl x1, y1;
    intl d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(intl a, intl b, intl c, intl &x0, intl &y0, intl &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution (intl & x, intl & y, intl a, intl b, intl cnt) {
    x += cnt * b;
    y -= cnt * a;
}

intl find_all_solutions (intl a, intl b, intl c, intl minx, intl maxx, intl miny, intl maxy) {
    intl x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;  b /= g;

    intl sign_a = a>0 ? +1 : -1;
    intl sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    intl lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    intl rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    intl lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    intl rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    lx = max (lx1, lx2);
    rx = min (rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}


vector<intl>vec;

int verify()
{

}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl k;
    cin >> k;
    intl tr = 0;
    for( intl d = 3; d <= 2000; d++ )
    {
        for( intl f = 1; f < d; f++ )
        {
            if( find_all_solutions(d, -f, k+d, 0, MAXN*f, 0, MAXN*f) >= 1 )
            {
                tr = verify();
                if(tr)
                    break;
            }
        }
    }
    if(tr == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << vec.size() << endl;
    for( intl i = 0; i < vec.size(); i++ )
    {
        cout << vec[i] << " ";
    }

    return 0;
}

