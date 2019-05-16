#include<bits/stdc++.h>

using namespace std;

///playerA starts playing

#define PlayerA 0
#define PlayerB 1

#define pii pair<int,int>
#define xx  first
#define yy  second
#define mp  make_pair

const int TOTAL_BIN = 12, BIN_PER_PLAYER = 6, NUM_OF_PLAYER = 2, MAX_DEPTH = 8;
const int INF = 1000000;

struct State
{
    int bin[TOTAL_BIN];
    int box[NUM_OF_PLAYER];
    int playerMove;

    void initialize()
    {
        box[PlayerA] = 0;
        box[PlayerB] = 0;
        playerMove = PlayerA;
        for( int i = 0; i < TOTAL_BIN; i++ )
            bin[i] = 4;
        /*box[PlayerA] = 2;
        box[PlayerB] = 5;
        playerMove = PlayerB;
        bin[0] = 6;
        bin[1] = 2;
        bin[2] = 0;
        bin[3] = 8;
        bin[4] = 2;
        bin[5] = 8;
        bin[6] = 0;
        bin[7] = 1;
        bin[8] = 3;
        bin[9] = 0;
        bin[10] = 9;
        bin[11] = 2;*/
    }

    State nextState(int binNo)
    {
        State newState = *this;

        int stone = newState.bin[binNo], curPlayer = newState.playerMove;
        newState.bin[binNo] = 0;
        int i = 1;
        if( binNo == newState.playerMove*BIN_PER_PLAYER + BIN_PER_PLAYER-1 )
        {
            i++;
            newState.box[curPlayer]++;
            ///do not change the player
        }
        int cur = binNo+1;
        for( ; i <= stone; i++ )
        {
            cur %= TOTAL_BIN;
            if( cur == newState.playerMove*BIN_PER_PLAYER + BIN_PER_PLAYER-1 )
            {
                newState.bin[cur]++;
                i++;
                if( i > stone )
                {
                    ///change the player
                    newState.playerMove ^= 1;
                }
                else if( i == stone )
                {
                    newState.box[curPlayer]++;
                    ///do not change the player
                }
                else
                {
                    newState.box[curPlayer]++;
                }
            }
            else if( i < stone )
            {
                newState.bin[cur]++;
            }
            else if( i == stone )
            {
                if( newState.bin[cur] == 0 )
                {
                    if( cur < BIN_PER_PLAYER && curPlayer == PlayerA )
                    {
                        int other = cur + 1 + 2*(5-cur);
                        int tot = newState.bin[other];
                        if( tot > 0 )
                        {
                            newState.bin[other] = 0;
                            newState.box[curPlayer] += tot;
                            newState.box[curPlayer]++;
                            newState.bin[cur] = 0;
                        }
                        else
                        {
                            newState.bin[cur]++;
                        }

                    }
                    else if( cur >= BIN_PER_PLAYER && curPlayer == PlayerB )
                    {

                        int other = cur - ( 1 + 2*(cur-6) );
                        int tot = newState.bin[other];
                        if( tot > 0 )
                        {
                            newState.bin[other] = 0;
                            newState.box[curPlayer] += tot;
                            newState.box[curPlayer]++;
                            newState.bin[cur] = 0;
                        }
                        else
                        {
                            newState.bin[cur]++;
                        }
                    }
                    else
                    {
                        newState.bin[cur]++;
                    }
                }
                else
                {
                    newState.bin[cur]++;
                }
                newState.playerMove ^= 1;
            }

            cur++;
        }
        return newState;
    }

    void print()
    {
        cout << "-------------" << endl;
        cout << "   ";
        for( int i = TOTAL_BIN-1; i >= BIN_PER_PLAYER; i-- )
        {
            cout << setw(2) << bin[i] << " ";
        }
        cout << endl;
        cout << box[PlayerB] << "\t\t      " << box[PlayerA] << endl;
        cout << "   ";
        for( int i = 0; i < BIN_PER_PLAYER; i++ )
        {
            cout << setw(2) << bin[i] << " ";
        }
        cout << endl;
        cout << "current move of player: " << playerMove << endl;
        cout << "-------------" << endl;
    }

    bool isEnd()
    {
        int t = 0;
        for( int i = 0; i < BIN_PER_PLAYER; i++ )
        {
            t += bin[i];
        }
        if( t == 0 )
        {
            for( int i = BIN_PER_PLAYER; i < TOTAL_BIN; i++ )
            {
                box[PlayerB] += bin[i];
                bin[i] = 0;
            }
            return 1;
        }

        t = 0;
        for( int i = BIN_PER_PLAYER; i < TOTAL_BIN; i++ )
        {
            t += bin[i];
        }
        if( t == 0 )
        {
            for( int i = 0; i < BIN_PER_PLAYER; i++ )
            {
                box[PlayerA] += bin[i];
                bin[i] = 0;
            }
            return 1;
        }
        return 0;
    }
};

int player, opponent;
const int W1 = 70, W2 = 30, W3 = 1, W4 = 1;

int heuristic1( State &s )
{
    if( player == PlayerA )
    {
        return s.box[PlayerA] - s.box[PlayerB];
    }
    else
        return -(s.box[PlayerA] - s.box[PlayerB]);
}

int heuristic2( State &s )
{
    int a = 0;
    int b = 0;
    for( int i = 0; i < BIN_PER_PLAYER; i++ )
        a += s.bin[i];
    for( int i = BIN_PER_PLAYER; i < TOTAL_BIN; i++ )
        b += s.bin[i];

    if( player == PlayerA )
    {
        return W1*(s.box[PlayerA] - s.box[PlayerB]) + W2*(a-b);
    }
    else
        return -(W1*(s.box[PlayerA] - s.box[PlayerB]) + W2*(a-b));
}

int estimate( State curState )
{
    if( player == PlayerA )
    {
        return heuristic2(curState);
    }
    else
    {
        return heuristic1(curState);
    }
}

int solve( State curState, int isMax = 1, int alpha = -INF, int beta = INF, int depth = 0 )
{
    if( curState.isEnd() )
    {
        return estimate(curState);
    }

    if( depth == MAX_DEPTH )
    {
        return estimate(curState);
    }

    if( isMax )
    {
        int val = -INF;
        //State best;
        for( int i = curState.playerMove*BIN_PER_PLAYER; i < curState.playerMove*BIN_PER_PLAYER+BIN_PER_PLAYER; i++ )
        {
            if( curState.bin[i] > 0 )
            {
                State nxt = curState.nextState(i);
                int temp;
                if( nxt.playerMove == curState.playerMove )
                    temp = isMax;
                else
                    temp = isMax^1;
                int v = solve( nxt, temp, alpha, beta, depth+1 );
                val = max(v, val);
                alpha = max(alpha, v);
                if( beta <= alpha )
                    break;
            }

        }
        return val;
    }
    else
    {
        int val = INF;
        //State best;
        for( int i = curState.playerMove*BIN_PER_PLAYER; i < curState.playerMove*BIN_PER_PLAYER+BIN_PER_PLAYER; i++ )
        {
            if( curState.bin[i] > 0 )
            {
                State nxt = curState.nextState(i);
                int temp;
                if( nxt.playerMove == curState.playerMove )
                    temp = isMax;
                else
                    temp = isMax^1;
                int v = solve( nxt, temp, alpha, beta, depth+1 );
                val = min(v, val);
                beta = min(beta, v);
                if( beta <= alpha )
                    break;
            }

        }
        return val;
    }

    return 0;
}

State findBestMove( State curState )
{
    State best;
    int val = -INF;
    player = curState.playerMove;
    opponent = player^1;
    for( int i = curState.playerMove*BIN_PER_PLAYER; i < curState.playerMove*BIN_PER_PLAYER+BIN_PER_PLAYER; i++ )
    {
        if( curState.bin[i] > 0 )
        {
            State nxt = curState.nextState(i);
            //nxt.print();
            int v = solve( nxt, 0 );
            //cout << "v: " << v << endl;
            if( v > val )
            {
                val = v;
                best = nxt;
                //cout << "best: " << endl;
                //best.print();
            }
        }

    }
    return best;
}


int main()
{
    State cur;

    cur.initialize();
    cur.print();
    cout << "--------------------------------------start----------------------------------" << endl;
    //for( int i = 0; i < 20; i++ )
    while(1)
    {
        int binNo;

        //cout << "move bin ";
        //cin >> binNo;
        cur = findBestMove(cur);
        cur.print();
        if( cur.isEnd() )
        {
            cout << cur.box[PlayerA] << " " << cur.box[PlayerB] << endl;
            break;
        }
    }
}
