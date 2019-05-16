//assert

#include<bits/stdc++.h>
using namespace std;
#define D(x)    cout << #x " = " <<(x) << endl
#define MAX     100000
#define eps     1e-9
typedef long long int LL;

const double PI = acos(-1.00);

#define xx		first
#define yy		second
typedef long long int LL;
typedef pair<LL, LL> pii;

#define CW 		-1
#define ACW	 	 1

int direction(pii st, pii ed, pii q){
	LL xp = (LL) (ed.xx - st.xx) * (q.yy - ed.yy) - (LL) (ed.yy - st.yy) * (q.xx - ed.xx);
	if(!xp) return 0;
	if(xp > 0) return ACW;
	return CW;
}

/*
    Minimized border points, works in degenerate case
    To maximize border points
        - change != to == and swap(CW,ACW)
        - Be careful about p[0], p[back] line
*/
int convex_hull(vector <pii> p, vector<pii> &h, vector<pii> &up, vector<pii> &dwn)
{
    // constructs upper hull in clockwise order, lower hull in anti-clockwise order
	h.clear();
	up.clear();
	dwn.clear();

	sort(p.begin(), p.end());
	up.push_back(p[0]);
	dwn.push_back(p[0]);

	for(int i = 1; i < (int) p.size(); i++){
		if(direction(p[0], p.back(), p[i]) != CW){
			while(up.size() >= 2 && direction(up[up.size() - 2], up.back(), p[i]) != CW) up.pop_back();
			up.push_back(p[i]);
		}

		if(direction(p[0], p.back(), p[i]) != ACW){
			while(dwn.size() >= 2 && direction(dwn[dwn.size() - 2], dwn.back(), p[i]) != ACW) dwn.pop_back();
			dwn.push_back(p[i]);
		}
	}

	h = dwn;
	for(int i = (int) up.size() - 2; i >= 1; i--) h.push_back(up[i]);
	reverse(up.begin(), up.end());
	return h.size();
}

/*
InConvexPoly:
P contains points in acw order. Works for only convex polygon
Complexity O(lg n)
MAKE THAT LINE =>if(triArea2(P[st], P[ed], q) <= 0) return false; To excluded border region from polygon
*/

LL triArea2(pii a, pii b, pii c) // includes sign
{
    LL ret = 0;
    ret += (LL) a.xx*b.yy + (LL) b.xx*c.yy + (LL) c.xx*a.yy - (LL) a.xx*c.yy - (LL) c.xx*b.yy - (LL) b.xx*a.yy;
    return ret;
}

bool inConvexPoly(vector< pii > &P, pii q)
{
    pii fix = P[0];
    int st = 1, ed = P.size()-1, mid;

    while(ed - st > 1)
    {
        mid = (st+ed)>>1;
        if(triArea2(fix, P[mid], q) > 0 ) st = mid;
        else ed = mid;
    }

    if(triArea2(fix, P[st], q) < 0) return false;
    if(triArea2(P[st], P[ed], q) < 0) return false;
    if(triArea2(P[ed], fix, q) < 0) return false;
    return true;
}

///hull points must be sorted anti - clockwise

pii better(pii u, pii v, pii Q, int dir){
    if(direction(Q, u, v) == dir) return u;
    return v;
}

bool isGood(pii u, pii v, pii Q, int dir){
    return (direction(Q, u, v) != -dir);
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

//    for(auto x : polygon){
//        assert(direction(Q, acw_tan, x) != CW);
//    }
//
//
//     for(auto x : polygon){
//        assert(direction(Q, cw_tan, x) != ACW);
//    }

    return make_pair(acw_tan, cw_tan);
}

vector< pii > polygon, up, dwn, queries, P;

double arg(pii p){
    return atan2(p.yy, p.xx);
}

pii operator - (const pii &u, const pii &v){
    return {u.xx - v.xx, u.yy - v.yy};
}

double angle(pii l, pii m, pii r) {return abs(remainder(arg(l-m) - arg(r-m), 2.0 * PI)); } //OK


double norm(pii l){
    return sqrtl(l.xx * l.xx + l.yy * l.yy);
}

bool online(pii u, pii v, pii q){
    return fabs(norm(u - q) + norm(q - v) - norm(u - v)) < eps;
}


char str[33];
set < pii > S;

int main()
{
   freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, cs, i, n, m, x, y;

    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++){
        P.clear();
        queries.clear();
        S.clear();

        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i++){
            scanf("%d %d", &x, &y);
            P.push_back({x, y});
            S.insert({x, y});
        }
        for(i = 1; i <= m; i++){
            scanf("%d %d", &x, &y);
            queries.push_back({x, y});
            assert(S.find({x, y}) == S.end());
        }

        printf("Case %d:\n", cs);
        convex_hull(P, polygon, up, dwn);

        if(polygon.size() == 1) for(auto p : queries) printf("%0.2f\n", 0.0);
        else if(polygon.size() == 2){
            pii p0 = polygon[0];
            pii p1 = polygon.back();
            for(auto p : queries) {
                double res = (angle(p0, p , p1) * 180/PI);
                if(fabs(res - 180.0) < eps) puts("TOO WIDE");
                else printf("%0.2f\n", res);
            }
        }
        else{
            for(auto p : queries){
                x = p.xx;
                y = p.yy;
                if(inConvexPoly(polygon, p)) puts("TOO WIDE");
                else{
                    pii acw_tan = get_tangents(polygon, p).first;
                    pii cw_tan = get_tangents(polygon, p).second;

                    double res = (angle(acw_tan, p, cw_tan) * 180/PI);
                    printf("%0.2f\n", res) ;
//                    sprintf(str,"%0.2f", res);
//                    if(!strcmp(str, "180.00")) puts("TOO WIDE");
//                    else puts(str);
                }
            }
        }
    }
    return 0;
}
