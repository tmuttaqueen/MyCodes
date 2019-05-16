#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 40005, INC = 1e6;

struct Data
{
    int mask, y;
    vector<pii>base;
    vector<vector<pii>>point;
};


pii cur;
pii ls[6], rs[6];
pii all[MAXN];
Data ara[33];

inline intl cross( pii &cen, pii &a, pii &b ) ///ca * cb
{
    return (a.xx - cen.xx)*(b.yy-cen.yy) - (a.yy-cen.yy)*(b.xx-cen.xx);
}

bool comp( pii &a, pii &b )
{
    return cross(cur, a, b) >= 0;
}

struct PT
{
    intl x,y;
    PT() {}
    PT(const intl a, const intl b) : x(a), y(b)    {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT(const pii &p) : x(p.xx), y(p.yy)    {}
};
PT operator +(PT a,PT b)
{
    return PT(a.x+b.x,a.y+b.y);
}
PT operator -(PT a,PT b)
{
    return PT(a.x-b.x,a.y-b.y);
}
PT operator *(PT a,intl b)
{
    return PT(a.x*b,a.y*b);
}

PT operator /(PT a, intl b)
{
    return PT(a.x/b,a.y/b);
}
intl operator *(PT a,PT b) //dot
{
    return a.x*b.x+a.y*b.y;
}

intl operator ^(PT a,PT b) //cross
{
    return a.x*b.y-a.y*b.x;
}
intl dist2(PT a, PT b)
{
    return ((a-b)*(a-b));
}
bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return ((b-a)^(c-d)) == 0;
}

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d)
           && ((a-b)^(a-c)) == 0
           && ((c-d)^(c-a)) == 0;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if (LinesCollinear(a, b, c, d))
    {
        if (dist2(a, c) == 0 || dist2(a, d) == 0 ||
                dist2(b, c) == 0 || dist2(b, d) == 0 ) return true;
        if ((c-a)*(c-b) > 0 && (d-a)*(d-b) > 0 && (c-b)*(d-b) > 0)
            return false;
        return true;
    }
    if (((d-a)^(b-a))*((c-a)^(b-a)) > 0) return false;
    if (((a-c)^(d-c))*((b-c)^(d-c)) > 0) return false;
    return true;
}


int query( pii cen, int mask, int l, int r )
{
    //cout << "QUERY BEGIN" << endl;

    pii lp = ara[mask].base[l], rp = ara[mask].base[r];
    int lo = 0, hi = ara[mask].point[r].size() - 1, ansl = -1;
    while(lo <= hi)
    {
        int m = (lo+hi)/2;
        if( cross( cen, rp, ara[mask].point[r][m] ) < 0 )
        {
            lo = m+1;
            ansl = m;
        }
        else
            hi = m - 1;
    }
    int t1 = ansl - 0 + 1;
    //cout << t1 << endl;

    lo = 0; hi = ara[mask].point[l].size() - 1;
    int ansr = -1;
    while(lo <= hi)
    {
        int m = (lo+hi)/2;
        if( cross( cen, lp, ara[mask].point[l][m] ) <= 0 )
        {
            lo = m+1;
            ansr = m;
        }
        else
            hi = m - 1;
    }
    int t2 = ansr - 0 + 1;
    //cout << t2 << endl;
    //cout << "QUERY END" << endl;
    return t2 - t1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> all[i].xx >> all[i].yy;
    }
    for( int i = 0; i < m; i++ )
    {
        cin >> ls[i].xx >> rs[i].xx >> ls[i].yy;
        rs[i].yy = ls[i].yy;
    }
    int totMask = 1<<m;

    for( int i = 1; i < totMask; i++ )
    {
        ara[i].mask = i;
        ara[i].y = -1;
        for( int j = 0; j < m; j++ )
        {
            if( (i&(1<<j)) == 0 )
                continue;
            ara[i].base.push_back(ls[j]);
            ara[i].base.push_back(rs[j]);
            ara[i].y = max( ls[j].yy, 1LL*ara[i].y );
        }
        int d = ara[i].base.size();
        ara[i].point.resize(d);
        for( int j = 1; j <= n; j++ )
        {
            if( all[j].yy > ara[i].y )
            {
                for( int k = 0; k < d; k++ )
                {
                    ara[i].point[k].push_back(all[j]);
                }
            }
        }
        for( int k = 0; k < d; k++ )
        {
            cur = ara[i].base[k];
            sort( ara[i].point[k].begin(), ara[i].point[k].end(), comp );
        }
    }



    while(q--)
    {
        int ans = n;
        pii queryPoint;
        cin >> queryPoint.xx >> queryPoint.yy;

        for( int i = 1; i < totMask; i++ )
        {
            //cout << "i " << i << endl;
            int ver[2], cnt = 0;
            int bitOn = ara[i].base.size()/2;
            for( int j = 0; j < ara[i].base.size(); j++ )
            {
                if( cnt == 2 ) break;
                intl inc = 1;
                if(  ( ara[i].base[j].xx - queryPoint.xx ) != 0 )
                    inc = (1e7)/( ara[i].base[j].xx - queryPoint.xx );
                if(  ( ara[i].base[j].yy - queryPoint.yy ) != 0 )
                    inc = max( 1.0*inc, (1e7)/( ara[i].base[j].yy - queryPoint.yy ));

                pii temp = mp( ( ara[i].base[j].xx - queryPoint.xx )*inc + queryPoint.xx,
                               ( ara[i].base[j].yy - queryPoint.yy )*inc + queryPoint.yy );
                //cout << "temp " << temp.xx << " " << temp.yy << endl;
                int ins = 0;
                for( int k = 0; k < m; k++ )
                {
                    //cout << "k  " << k << endl;
                    if( (i&(1<<k)) && SegmentsIntersect( PT(queryPoint), PT(temp), PT(ls[k]), PT(rs[k]) ) )
                        ins++;
                }
                //cout << "ins " << ins << endl;
                if( ins == bitOn )
                {
                    ver[cnt++] = j;
                }
            }
            //cout << "i " << i << " " << cnt << " " << ver[0] << " " << ver[1]  << endl;
            if(cnt<2) continue;

            if( cross( queryPoint, ara[i].base[ ver[1] ], ara[i].base[ ver[0] ] ) < 0 )
                swap( ver[0], ver[1] );


//            cout << "mask " << i << " " << ara[i].base[ ver[0] ].xx << " " << ara[i].base[ ver[0] ].yy << " " <<
//                                            ara[i].base[ ver[1] ].xx << " " << ara[i].base[ ver[1] ].yy << endl;
            intl val = query( queryPoint, i, ver[0], ver[1] );
            if(bitOn&1)
                ans -= val;
            else
                ans += val;
        }

        cout << ans << endl << endl;
    }

    return 0;
}

