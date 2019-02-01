#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

const int MAXROW = 16;
const int MAXCOL = 128;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string Data;
int m;
double errorProb;
string generator;
int row, col, n, r, cntserial;

bitset<MAXCOL>bit[MAXROW], rbit[MAXROW];
bitset<MAXROW*MAXCOL>serialBit, temp, received;

//SetConsoleTextAttribute(hConsole, k);
//cout << k << " I want to be nice today!" << endl;

double getRand()
{
    return 1.0*rand()/RAND_MAX;
}

void send( int len )
{
    for( int i = 1; i <= len; i++ )
    {
        if( getRand() <= errorProb )
        {
            //cout << i << endl;
            //err.insert(i);
            received[i] = serialBit[i];
            received[i].flip();
        }
        else
            received[i] = serialBit[i];
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    srand(37);
    cout << "enter data string: ";
    getline(cin,Data);
    //cin.ignore();
    cout << Data << endl;
    cout << "enter number of data bytes in a row <m>: ";
    cin >> m;
    cout << m << endl;
    cout << "enter probability <p>: ";
    cin >> errorProb;
    cout << errorProb << endl;
    cout << "enter generator polynomial: ";
    cin >> generator;
    cout << generator << endl;



    while( Data.length()%m != 0 )
    {
        Data += "~";
    }


    cout << "\n\nData string after padding: " << Data << endl;

    row = Data.length()/m;
    col = m*8;

    for( int i = 1; i <= 10; i++ )
    {
        if( col + i+1 <= (1<<i) )
        {
            n = col+i;
            r = i;
            break;
        }
    }
    //cout << col << " " << r << endl;
    cout << "\ndata block <ascii character of m characters per row>:" << endl;



    for( int i = 1; i <= row; i++ )
    {
        int bitcnt = 1;
        for( int j = 0; j < m; j++ )
        {
            int ind = (i-1)*m+j;
            for( int k = 7; k >= 0; k-- )
            {
                while( (bitcnt&(bitcnt-1)) == 0 )
                {
                    bit[i][bitcnt++] = 0;
                }
                if( Data[ind]&(1<<k) )
                {
                    cout << "1";
                    bit[i][bitcnt++] = 1;
                }
                else
                {
                    cout << "0";
                    bit[i][bitcnt++] = 0;
                }
            }
        }
        //cout << "\n" << bitcnt << endl;
        cout << endl;
    }

    for( int i = 1; i <= row; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( (j&(j-1)) != 0 && bit[i][j] != 0 )
            {
                int x = j;
                while(x)
                {
                    int v = ( x&(-x) );
                    bit[i].flip(v);
                    x -= v;
                }
            }
        }
    }

    cout << "\ndata block after adding check bits:" << endl;
    for( int i = 1; i <= row; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( j&(j-1) )
            {
                cout << bit[i][j];
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 10);
                cout << bit[i][j];
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        cout << endl;
    }


    cntserial = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= row; j++ )
        {
            serialBit[cntserial++] = bit[j][i];
        }
    }

    cntserial--;

    cout << "\ndata bits after column-wise serialization:" << endl;
    for( int i = 1; i <= cntserial; i++ )
    {
        cout << serialBit[i];
    }
    cout << endl;



    temp = serialBit;
    for( int i = 1; i <= cntserial; i++ )
    {
        if( temp[i] == 0 )
            continue;
        for( int j = 0; j < generator.length(); j++ )
        {
            if( generator[j] == '1' )
            {
                temp[i+j].flip();
            }
        }
    }

    for( int i = cntserial+1; i <= cntserial + generator.length()-1; i++  )
        serialBit[i] =  temp[i];

    cntserial += generator.length() - 1;

    cout << "\ndata bits after CRC checksum <sent frame>:" << endl;

    for( int i = 1; i <= cntserial; i++  )
    {
        if( i > cntserial-generator.length()+1 )
        {
            SetConsoleTextAttribute(hConsole, 11);
            cout << serialBit[i];
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
            cout << serialBit[i];
    }
    cout << endl;


    send(cntserial);

    cout << "\nreceived frame:" << endl;
    for( int i = 1; i <= cntserial; i++  )
    {
        if( serialBit[i] != received[i] )
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << received[i];
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
            cout << received[i];
    }
    cout << endl;

    temp = received;
    for( int i = 1; i <= cntserial-generator.length()+1; i++ )
    {
        if( temp[i] == 0 )
            continue;
        for( int j = 0; j < generator.length(); j++ )
        {
            if( generator[j] == '1' )
            {
                temp[i+j].flip();
            }
        }
    }

    if( temp.count() > 0 )
    {
        cout << "\nerror detected" << endl;
    }

    int cnt = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= row; j++ )
        {
            rbit[j][i] = received[cnt++];
        }
    }



    cout << "\ndata block after removing CRC checksum bits:" << endl;
    for( int i = 1; i <= row; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            //rbit[i][j] = received[cnt++];
            if( rbit[i][j] != bit[i][j] )
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << rbit[i][j];
                SetConsoleTextAttribute(hConsole, 15);
            }
            else
            {
                cout << rbit[i][j];
            }
        }
        cout << endl;
    }


    ///error recovery

    for( int i = 1; i <= row; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( (j&(j-1)) == 0 )
            {
                rbit[i][j] = 0;
            }
        }
    }


    for( int i = 1; i <= row; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( (j&(j-1)) != 0 && rbit[i][j] != 0 )
            {
                int x = j;
                while(x)
                {
                    int v = ( x&(-x) );
                    rbit[i].flip(v);
                    x -= v;
                }
            }
        }
        int val = 0;
        for( int j = 1; j <= n; j++ )
        {
            if( (j&(j-1))  == 0 && rbit[i][j] != bit[i][j] )
            {
                val += j;
            }
        }
        //cout << i << " " << val << endl;
        rbit[i].flip(val);
    }

    string res = "";
    cout << "\ndata block after removing check bits:" << endl;
    for( int i = 1; i <= row; i++ )
    {
        int cnt = 7, v = 0;
        for( int j = 1; j <= n; j++ )
        {
            if( (j&(j-1)) != 0 )
            {
//                if( bit[i][j] != rbit[i][j] )
//                {
//                    SetConsoleTextAttribute(hConsole, 4);
//                    cout << rbit[i][j];
//                    SetConsoleTextAttribute(hConsole, 15);
//                }
//                else
//                    cout << rbit[i][j];
                  cout << rbit[i][j];
                  if( rbit[i][j] == 1 )
                  {
                      v += (1<<cnt);
                  }
                  cnt--;
            }
            if( cnt == -1 )
            {
                res += (char)v;
                //cout << " v: " << v << endl;
                cnt = 7;
                v = 0;
            }
        }
        cout << endl;
    }
    //cout << res << endl;
    cout << "\noutput frame: " << res << endl;

    return 0;
}
