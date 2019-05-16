#include<bits/stdc++.h>

using namespace std;

const double eps=1e-10;

struct PT
{
    double x,y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
};
PT operator +(PT a,PT b)
{
    return PT(a.x+b.x,a.y+b.y);
}
PT operator -(PT a,PT b)
{
    return PT(a.x-b.x,a.y-b.y);
}
PT operator *(PT a,double b)
{
    return PT(a.x*b,a.y*b);
}

PT operator /(PT a,double b)
{
    return PT(a.x/b,a.y/b);
}
double operator *(PT a,PT b) //dot
{
    return a.x*b.x+a.y*b.y;
}
double operator ^(PT a,PT b) //cross
{
    return a.x*b.y-a.y*b.x;
}


int dcmp(double x)
{
    if (fabs(x)<eps) return 0;
    return x<0 ? -1 : 1;
}

bool OnSegment(PT p,PT a,PT b)
{
    return dcmp((a-p)^(b-p)) == 0 && dcmp((a-p)*(b-p))<0;
}

vector<PT>vec;
vector<double>p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        vec.clear();
        p.clear();
        double x, y, r;
        int n;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> x >> y >> r;
            vec.push_back( PT(x,y) );
            p.push_back(1.0-r);
        }
        double ans = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                //cout << i << " " << j << endl;
                double ar = ( vec[i]^vec[j] ), pr = p[i]*p[j];
                for( int k = 0; k < n; k++ )
                {
                    if( k == i || k == j ) continue;
                    if( OnSegment(vec[k], vec[i], vec[j]) || dcmp( (vec[j]-vec[i])^(vec[k]-vec[j]) ) < 0 )
                    {
                        //cout << k << endl;
                        pr*= (1-p[k]);
                    }
                }
                ans += ar*pr;
            }
        }
        cout<< setprecision(10) << fixed << ans*0.5 << endl;
    }


    return 0;
}
