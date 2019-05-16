#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int pf, pi, gf, gi, sf, si, bf, bi, ap, ag, as, temp;
    scanf("%d %d %d %d %d %d %d %d %d", &bi, &bf, &si, &sf, &gi, &gf, &pi, &pf);
    ap = pf - pi;
    ag = gf - (gi-ap);
    as = sf - (si-ag);
    printf("%d\n", as);
    printf("%d\n", ag);
    printf("%d\n", ap);
    return 0;
}
