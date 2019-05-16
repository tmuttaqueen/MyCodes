#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long llong;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct vt
{
    int x, y, z;
    inline vt(){}
    inline vt(int _x, int _y, int _z)
    {
        x = _x, y = _y, z = _z;
    }
    inline friend vt operator +(vt a, vt b)
    {
        return vt(a.x + b.x, a.y + b.y, a.z + b.z);
    }
    inline friend vt operator -(vt a, vt b)
    {
        return vt(a.x - b.x, a.y - b.y, a.z - b.z);
    }
    inline friend llong operator *(vt a, vt b)
    {
        return (llong)a.x * b.x + (llong)a.y * b.y + (llong)a.z * b.z;
    }
    inline friend vt operator ^(vt a, vt b)
    {
        return vt(a.y * b.z - a.z * b.y, b.x * a.z - a.x * b.z, a.x * b.y - b.x * a.y);
    }
    inline bool iszero()
    {
        return x == 0 && y == 0 && z == 0;
    }
};

const int N = 100;

vt P[N];
double al[N];

int n;

inline double expected_faces()
{
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j || i == j)
                    continue;
                vt vn = ((P[i] - P[j]) ^ (P[j] - P[k]));
                double p = al[i] * al[j] * al[k];
                for (int t = 0; t < n; t++)
                    if (vn * (P[t] - P[i]) < 0)
                        p *= 1.0 - al[t];
                ans += p;
            }
    return ans / 3;
}


double expected_fix()
{
    double ans = 0;

    double p = 1;
    for (int i = 0; i < n; i++)
        p *= 1.0 - al[i];
    ans += 2 * p;

    for (int i = 0; i < n; i++)
    {
        double p = al[i];
        for (int j = 0; j < n; j++)
            if (i != j)
                p *= 1.0 - al[j];
        ans += p * 1;
    }

    return ans;
}

// V = 2 + F / 2 - fix
// k = 1 -> fix = 1
// k = 0 -> fix = 2

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf %d %d %d", &al[i], &P[i].x, &P[i].y, &P[i].z);

    double fix = expected_fix();
    eprintf("fix = %.10f\n", fix);
    double F = expected_faces();
    eprintf("F = %.10f\n", F);
    double ans = 2 + F / 2.0 - fix;
    printf("%.10f\n", ans);
}
