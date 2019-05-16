#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

map<intl, intl>mm;

///2D BIT O(log^2n)
long long tree[4][2510][2510];
intl n,m;
void update(intl x,intl y,intl val,intl i)
{
    intl y1;
    while(x<=n){
        y1=y;
        while(y1<=m)
        {
            tree[i][x][y1]+=val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
long long query(intl x,intl y,intl i)
{
    long long ans=0;
    intl y1;
    while(x>0){
        y1=y;
        while(y1>0)
        {
            ans+=tree[i][x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return ans;
}

intl rd() {
	return rand() << 15 | rand() ^ rand() << 7;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl a, r1, c1, r2, c2, c = 1, q, x1, x2, y1, y2;
    cin >> n >> m >> q ;
    for( intl i = 1; i <= q; i++ )
    {
        cin >> a >> x1 >> y1 >> x2 >> y2;
        if( a == 1 || a == 2 )
        {
            intl d = ((x1*10000+y1)*10000+x2)*10000+y2;
            intl k;
            if( a == 1 )
            {
                intl x = rd()^rand();
                intl y = rd();
                x = (x|y<<12);
                //what_is(x);
                mm[d] = x;
                k = x;
            }
            else
            {
                k = -mm[d];
            }
            update(x1,y1,k,0);
	        update(x1,y2+1,-k,0);
	        update(x2+1,y1,-k,0);
	        update(x2+1,y2+1,k,0);

	        update(x1,y1,k*(1-y1),1);
	        update(x1,y2+1,k*y2,1);
	        update(x2+1,y1,k*(y1-1),1);
	        update(x2+1,y2+1,-y2*k,1);

	        update(x1,y1,k*(1-x1),2);
	        update(x1,y2+1,k*(x1-1),2);
	        update(x2+1,y1,k*x2,2);
	        update(x2+1,y2+1,-x2*k,2);

	        update(x1,y1,(x1-1)*(y1-1)*k,3);
	        update(x1,y2+1,-y2*(x1-1)*k,3);
	        update(x2+1,y1,-x2*(y1-1)*k,3);
	        update(x2+1,y2+1,x2*y2*k,3);
        }
        else
        {
            intl r1 = x1, c1 = y1, r2 = x2, c2 = y2;
            x1 = r1;
            x2 = r1;
            y1 = c1;
            y2 = c1;
            long long val1=query(x2,y2,0)*x2*y2+query(x2,y2,1)*x2+query(x2,y2,2)*y2+query(x2,y2,3);
	        long long val2=query(x2,y1-1,0)*x2*(y1-1)+query(x2,y1-1,1)*x2+query(x2,y1-1,2)*(y1-1)+query(x2,y1-1,3);
	        long long val3=query(x1-1,y2,0)*(x1-1)*y2+query(x1-1,y2,1)*(x1-1)+query(x1-1,y2,2)*y2+query(x1-1,y2,3);
	        long long val4=query(x1-1,y1-1,0)*(x1-1)*(y1-1)+query(x1-1,y1-1,1)*(x1-1)+query(x1-1,y1-1,2)*(y1-1)+query(x1-1,y1-1,3);

	        long long ans1=val1-val2-val3+val4;
	        x1 = r2;
            x2 = r2;
            y1 = c2;
            y2 = c2;
            val1=query(x2,y2,0)*x2*y2+query(x2,y2,1)*x2+query(x2,y2,2)*y2+query(x2,y2,3);
	        val2=query(x2,y1-1,0)*x2*(y1-1)+query(x2,y1-1,1)*x2+query(x2,y1-1,2)*(y1-1)+query(x2,y1-1,3);
	        val3=query(x1-1,y2,0)*(x1-1)*y2+query(x1-1,y2,1)*(x1-1)+query(x1-1,y2,2)*y2+query(x1-1,y2,3);
	        val4=query(x1-1,y1-1,0)*(x1-1)*(y1-1)+query(x1-1,y1-1,1)*(x1-1)+query(x1-1,y1-1,2)*(y1-1)+query(x1-1,y1-1,3);

	        long long ans2=val1-val2-val3+val4;
	        //cout << ans1 << " " << ans2 << endl;
	        if( ans1 == ans2 )
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
