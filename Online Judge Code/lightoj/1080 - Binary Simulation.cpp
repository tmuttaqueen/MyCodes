#include <bits/stdc++.h>

using namespace std;

int tree[300015];

void build_tree( int node, int first, int last )
{
    /*if( first == last )
    {
        tree[first] = 0;
        return;
    }
    int mid = (first+last)/2;
    build_tree( node*2, first, mid );
    build_tree( node*2+1, mid+1, last );
    tree[node] = 0;
    return;*/
    last = 3*last;
    for( int i =1; i <= last; i++ )
        tree[i] = 0;
    return;
}

void update( int node, int first, int last, int i, int j)
{
    if( last < i || first > j )
        return;
    if( first >= i && last <= j )
    {
        tree[node]++;
        return;
    }
    int mid = (first+last)/2;
    update( node*2, first, mid, i, j);
    update( node*2+1, mid+1, last, i, j );
    return;
}

int query( int node, int first, int last, int i, int carry = 0 )
{
    if( i < first || i > last )
        return 0;
    if( first == last )
    {
        return tree[node]+carry;
    }
    int mid = (first+last)/2;
    int p1 = query( node*2, first, mid, i, carry+tree[node]);
    int p2 = query( node*2+1, mid+1, last, i, carry+tree[node] );
    return p1+p2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t, caseno=1;
    scanf("%d\n", &t);
    while(t--)
    {
        char str[100005];
        gets(str);
        int n = strlen(str);
        build_tree(1,1,n);
        int q;
        scanf("%d\n", &q);
        printf("Case %d:\n", caseno++);
        while(q--)
        {
            char c;
            int x, y;
            scanf("%c", &c);
            if( c == 'I' )
            {
                scanf("%d %d\n", &x, &y);
                update(1, 1, n, x, y);
            }
            else
            {
                scanf("%d\n", &x);
                int a = query( 1,1,n,x );
                //cout << " a " << a << endl;
                if( a%2==0 )
                {
                    printf("%c\n", str[x-1]);
                }
                else
                {
                    (str[x-1] == '1')? printf("0\n"): printf("1\n");
                }
            }
        }
    }
    return 0;
}
