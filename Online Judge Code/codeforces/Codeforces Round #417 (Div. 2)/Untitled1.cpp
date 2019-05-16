#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ook order_of_key
#define fbk find_by_order
#define pb push_back
#define mp make_pair
#define intl long long
#define maxn 100005
#define ff first
#define ss second
#define bug printf ("bug\n")
#define sz(a) ((int)a.size())
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define si(a) scanf("%d" , &a)
#define sl(a) scanf("%lld" , &a)
#define sii(a,b) scanf("%d %d" , &a , &b)
#define sll(a,b) scanf("%lld %lld" , &a , &b)
#define FOR(i,a,b) for(intl i = (a) ; i <= (b) ; i++)
#define IN freopen("in.txt" , "r" , stdin)
#define OUT freopen("output2.txt" , "w" , stdout)
#define whats(x) printf ("x : %d\n" , x)



using namespace std ;
//using namespace __gnu_pbds;

typedef pair <int,int> pii ;
typedef pair <intl,intl> pll ;
//typedef tree < int, null_mapped_type ,less<int>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

/***************************************************************************************************/

const int N = 1e5 + 5 , md = 1000000007 ;
long long a[N] , cum[N] ;

int main () {


    int tc ;
    cin >> tc ;

    while (tc--) {

        int n ;
        cin >> n ;

        for (int i = 1 ; i <= n ; i++) {
            sl(a[i]) ;
        }
        sort (a+1,a+n+1) ;
        for (int i = 1 ; i <= n ; i++) {
            cum[i] = cum[i-1] + a[i] ;
        }

        long long ans = cum[n] ;
        long long sum = 0 ;
        for (int i = n ; i > 0 ; i--) {
            long long sz = n-i+1 ;
            sum += a[i] ;
            long long cur = sum*sz + cum[i-1] ;
            ans = max(ans,cur) ;

        }

        cout << ans << endl ;

    }



}
