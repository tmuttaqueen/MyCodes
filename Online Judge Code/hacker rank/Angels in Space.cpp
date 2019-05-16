#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

struct point
{
    int x, y, z;
};

vector<point>vec(105);

double angle( point a, point b, point c )
{
    point p, q;
    p.x = a.x - b.x;
    p.y = a.y - b.y;
    p.z = a.z - b.z;
    q.x = c.x - b.x;
    q.y = c.y - b.y;
    q.z = c.z - b.z;
    double v1 = sqrt( p.x*p.x + p.y*p.y + p.z*p.z ), v2 = sqrt( q.x*q.x + q.y*q.y + q.z*q.z );
    double ans = acos( (p.x*q.x + p.y*q.y + p.z*q.z)/(v1*v2) );

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    int a, b, c;
    for( int i = 0; i < n; i++ )
        cin >> vec[i].x >> vec[i].y >> vec[i].z;
    double sum = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = i+1; j < n; j++ )
        {
            for( int k = j+1; k < n; k++ )
            {
                sum += angle( vec[i], vec[j], vec[k] );
            }
        }
    }

    cout << setprecision(10) << fixed << sum/(n*(n-1)*(n-2)/6) << endl;

    return 0;
}



