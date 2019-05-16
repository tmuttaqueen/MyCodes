#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define i64        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define sf          scanf
#define pf          printf

const int MX =10000000;
i64 ran = 100000000000000 ;
bool cut[10001001];
vector<int>prm;

vector <int> a_pow , b_pr , b_pow ;

void sieve()
{
    int sq=sqrt(MX) , i , j;
    for(i=4 ; i<=MX ; i+=2) cut[i] = 1 ;
    for(int i=3;i<=sq;i+=2)
    {
        if(cut[i]) continue;
        for( j=i+i;j<=MX;j+=i)
        {
            cut[j]=1;
        }
    }
    prm.eb(2)  ;
    for(int i=3;i<=MX;i+=2) if(!cut[i])  prm.push_back(i);
}

inline int our_gcd(int a, int b){
    if(b==0) return a ;
     return our_gcd(b,a%b) ;
}

int main()
{
   filein;

    sieve() ;
    //what_is(prm[664578]);
    long long div, a, b , lj , li;
    int i , j , k , l , m , n , t=1 , tc , gcd , sqa , sqb;
    map <i64,int> M;
  //  debug ;

 //  debug ;

    sf("%d",&tc) ;
    while(t<=tc)
    {
        sf("%lld %lld",&a,&b) ;

        i = 0 ;
   //     debug ;
        k = prm.size() ;

        i = 0 ;
        while(i<k)
        {
            if(b%prm[i]==0){
                 b_pr.eb(prm[i]) ;
                 b_pow.eb(0) ;
                 l = b_pow.size() ;
                 l-- ;
                 while(b%prm[i]==0){
                    b = b/prm[i] ;
                    b_pow[l]++ ;
                }
            }
            if(b==1) break ;
     //      if(prm[i]>sqb) break ;
            i++ ;
            if(prm[i]*prm[i]>b) break ;
        }
        if(a!=1) a_pow.eb(1) ;
        if(b!=1){
            b_pow.eb(1) ;
            b_pr.eb(b) ;
        }

        if(!M.count(a)) gcd = 1 ;
        else gcd = M[a] ;

        i = 0 ;
        while(i<=3 && gcd != 1)
        {
            if(gcd%prm[i]==0){
                k = b_pr.size() ;
                for(j=0,l=-1 ; j<k; j++)
                {
                    if(b_pr[j]==prm[i]){
                        l = j ;
                        break ;
                    }
                }
                 if(l==-1){
                    l = b_pr.size() ;
                    b_pr.eb(prm[i]) ;
                    b_pow.eb(0);
                 }

                while(gcd%prm[i]==0){
                    gcd = gcd/prm[i] ;
                    b_pow[l]++ ;
                }
            }
            i++ ;
        }
        k=b_pow.size();
        for(i=0,div=1 ; i<k; i++)
        {
            div = div*(b_pow[i]+1) ;
        }

       //pf("Case %d: %lld\n",t,div-1) ;
    t++ ;

        b_pr.clear() ;
        a_pow.clear() ; b_pow.clear() ;
    }

    return 0;
}



