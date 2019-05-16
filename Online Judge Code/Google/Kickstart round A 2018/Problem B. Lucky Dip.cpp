#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define maxn 200005
#define IN freopen("B-large.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 28
#define off 1
#define sq(x) ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

// typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef pair<i64, i64> pii;

double val[maxn] , cum[maxn] ;

int main()
{
    //IN ;
    //OUT ;
    int i , j , k , l , m , n , t=1 , tc ;

    scanf("%d",&tc) ;

    while(t<=tc)
    {
        scanf("%d %d",&n,&k) ;

        for(i=1 ; i<=n ; i++) scanf("%lf",&val[i]) ;
        sort(val+1,val+n+1) ;

        for(i=1 ; i<=n ; i++) cum[i] = cum[i-1] + val[i] ;

        double ex = 0 ;

        for(i=0 ; i<=k ; i++)
        {
            int idx = upper_bound(val+1,val+n+1,ex)-val-1 ;

            ex = ((idx+0.0)/n)*ex + ((1.0)/n)*( cum[n]-cum[idx] ) ;
            cout << "ex: " << ex << endl;
        }

        printf("Case #%d: %0.12f\n",t++,ex) ;
    }

    return 0 ;
}
