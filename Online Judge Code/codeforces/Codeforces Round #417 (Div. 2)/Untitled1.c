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

const int N = 2505 , md = 1e9 + 7 , NN = 1e7 + 5 ;
int a[N][N] , len[N] ;

int main () {

    int tc ;
    cin >> tc ;

    while (tc--) {

        int n , K ;
        cin >> n >> K ;
        for (int i = 1 ; i <= n ; i++) {
             cin >> len[i] ;
             for (int j = 1 ; j <= len[i] ; j++) {
                cin >> a[i][j] ;
             }
        }

        int ans = 0 ;


        for (int i = 1 ; i <= n ; i++) {

            int cnt[N] ;
            set0(cnt) ;
            int count = 0 ;
            for (int j = 1 ; j <= len[i] ; j++) {
                if (cnt[a[i][j]] == 0) count++ ;
                cnt[a[i][j]]++ ;
            }

            int temp = count ;

            for (int j = i+1 ; j <= n ; j++) {

                for (int k = 1 ; k <= len[j] ; k++) {
                    if (cnt[a[j][k]] == 0 ) coutn++ ;
                    cnt[a[j][k]]++ ;
                }

                if (count == K) ans++ ;
                count = temp ;
                for (int k = 1 ; k <= len[j] ; k++) {
                    cnt[a[j][k]]-- ;
                }
            }
        }

        cout << ans << endl ;



    }



}
