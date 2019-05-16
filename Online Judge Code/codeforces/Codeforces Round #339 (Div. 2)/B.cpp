#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, len, ans = 0, per, prev;
    bool flag = 0;
    scanf("%d\n", &n);
    char str[100005], save[100005];
    for( int i = 0; i < n; i++ )
    {
        scanf("%s", str);
        len = strlen(str);
        int num = 0;
        prev = ans;
        //cout << "\n" << len << "\n" << endl;
        for( int j = 0; j < len; j++ )
        {
            if( str[j] != '1' && str[j] != '0' && flag == 0 )
            {
                 //for( int k =0; k < len;k++ )
                    //printf("%c", str[k]);
                num++;
                //printf("%s", str);
                for( int k = 0; k < len; k++ )
                {
                    save[k] = str[k];
                }
                save[len] = '\0';
                ans = prev;
                break;
            }
            else if( str[j] == '1' && flag == 0 )
            {
                num++;
                if( num > 1 )
                {
                    //for( int k =0; k < len;k++ )
                        //printf("%c", str[k]);
                    //printf("%s", str);
                    for( int k = 0; k < len; k++ )
                    {
                        save[k] = str[k];
                    }
                    save[len] = '\0';
                    ans = prev;
                    break;
                }
            }
            else if( str[j] == '0' )
            {
                ans++;
                //printf("\n%s", str);
            }
        }
        if( num == 0 )
            flag = 1;
    }
    if( flag == 1 )
    {
         cout << "0" << endl;
         return 0;
    }
    printf("%s", save);
    if( strlen(save) == 0 )
        cout << "1";
    for( int i  = 0; i < ans ;i++ )
        printf("0");
    cout << endl;
    //cout << ans << endl;
    return 0;
}

