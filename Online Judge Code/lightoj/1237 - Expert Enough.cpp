#include <bits/stdc++.h>

using namespace std;

struct data
{
    char ch[50];
    int l;
    int h;
};

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n1, n2, qry, base,a;
        data temp;
        scanf("%d", &n1);
        base = n1;
        vector<data> vv;
        while(n1--)
        {
            scanf("%s %d %d", &temp.ch, &temp.l, &temp.h);
            vv.push_back(temp);
        }
        scanf("%d", &n2);
        while(n2--)
        {
            int counter = 0;
            scanf("%d", &qry);
            for( int i = 0; i < base && counter < 2; i++ )
            {
                if( qry >= vv[i].l && qry <= vv[i].h )
                {
                    counter++;
                    if(counter==1) a = i;
                }
            }
            if( counter == 1 )
            {
                printf("%s\n", vv[a].ch);
            }
            else
            {
                printf("UNDETERMINED\n");
            }
        }
        if(t != 0) printf("\n");
    }

    return 0;
}
