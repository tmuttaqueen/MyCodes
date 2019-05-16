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
bool cut[10001001];
vector<i64>prm;

vector <i64> a_pow , b_pr , b_pow , a_pr ;

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

i64 M(i64 n)
{
    i64 s= sqrt(n) ;
    if(s*s==n) return s;
    if((s+1)*(s+1)==n) return s+1 ;
    if((s-1)*(s-1)==n) return s-1 ;
    return 0 ;
}

int main()
{
  // filein;

    sieve() ;
    //what_is(prm[664578]);
    long long div, a, b , lj;
    i64 i , j , k , l , m , n , t=1 , tc , gcd , sqa , sqb , c , d;


  //  debug ;

    sf("%lld",&tc) ;
    while(t<=tc)
    {
        sf("%lld %lld",&a,&b) ;

        i = 0 ;
   //     debug ;
        k = prm.size() ;

        if(M(a))
        {
            while(i<k )
          {
            c = M(a) ;
            pf("%d\n",c) ;
                   if(c%prm[i]==0){
                 a_pr.pb(prm[i]) ;
                 a_pow.eb(0) ;
                 l = a_pow.size() ;
                 l-- ;
                 while(c%prm[i]==0){
                    c = c/prm[i] ;
                    a_pow[l]++ ;
                }
            }
            a_pow[l] = a_pow[l]*2;
            if(c==1) break ;
        //   if(prm[i]>sqa) break ;
            if(prm[i]*prm[i]>c) break ;
            i++ ;
        }
        if(c!=1){
            a_pow.pb(2) ;
            c = 1 ;
        }
        }

        else{
            while(i<k )
        {

            if(a%prm[i]==0){
                 a_pr.pb(prm[i]) ;
                 a_pow.eb(0) ;
                 l = a_pow.size() ;
                 l-- ;
                 while(a%prm[i]==0){
                    a = a/prm[i] ;
                    a_pow[l]++ ;
                }
            }

            if(a==1) break ;
        //   if(prm[i]>sqa) break ;
            if(prm[i]*prm[i]*prm[i]>a) break ;
            i++ ;
        }
        }
      //  pf("%d\n",a_pow[0]) ;
        i = 0 ;
        if(M(b))
        {
        while(i<k)
        {
            d = M(b) ;
            if(d%prm[i]==0){
                 b_pr.eb(prm[i]) ;
                 b_pow.eb(0) ;
                 l = b_pow.size() ;
                 l-- ;
                 while(d%prm[i]==0){
                    d = d/prm[i] ;
                    b_pow[l]++ ;
                }
            }
            b_pow[l] = b_pow[l]*2 ;
            if(d==1) break ;
     //      if(prm[i]>sqb) break ;
            if(prm[i]*prm[i]>d) break ;
            i++ ;
        }
        if(d!=1){
            b_pow.pb(2) ;
            b_pr.pb(d) ;
            d = 1 ;
        }
        }
        else{
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
            if(prm[i]*prm[i]*prm[i]>b) break ;
            i++ ;
        }
        }
        if(a!=1) a_pow.eb(1) ;
        if(b!=1){
            b_pow.eb(1) ;
            b_pr.eb(b) ;
        }
        pf("%d\n",b_pow[0]) ;
        gcd = 0 ;
        k = a_pow.size();
        for( i=0;i<k;i++) gcd= our_gcd(a_pow[i],gcd) ;
        pf("%lld\n",gcd) ;
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

       pf("Case %lld: %lld\n",t,div-1) ;
    t++ ;

        b_pr.clear() ;
        a_pow.clear() ; b_pow.clear() ;
    }

    return 0;
}


