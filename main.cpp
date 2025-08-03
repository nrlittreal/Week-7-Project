#include<iostream>

using namespace std;

void CreateBoard(char board[3][3]);
void PlaceBoard(char board[3][3], int);
void CheckBoard(char board[3][3], int, int, int);
void DisplayBoard(char board[3][3]);
void Outcome(char board[3][3]);

int main()
{

    int turn;

    char board[3][3] = {
    {'?', '?', '?'},
    {'?', '?', '?'},
    {'?', '?', '?'}};

    cout << "Welcome to Tic-Tac-Toe!" << endl << "Player 1 is X and Player 2 is O.\n" << "Player 1 goes first!\n";
    
    CreateBoard(board);

    for (turn = 0; turn < 9; turn++)
        {
            PlaceBoard(board, turn);
            Outcome(board);
        }

    return 0;
}

void CreateBoard(char board[3][3])
{
    cout << "    1 2 3" << endl << "   -------" << endl;
    
    for (int i = 0; i < 3; i++)
        {
            cout << "|" << i + 1 << "| ";
            
            for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j] << " ";
                }
            cout << endl;
        }  
}

void PlaceBoard(char board[3][3], int turn)
{
    int row, col;

    cout << "Please enter the row and column where you would like to place your mark: " << endl;

    cin >> row >> col;

    CheckBoard(board, row, col, turn);
}

void CheckBoard(char board[3][3], int row, int col, int turn)
{
    while (board[row - 1][col - 1] != '?')
    {
        cout << "That spot is already taken. Please choose another spot.\n";

        cin >> row >> col;
    }
    board[row - 1][col - 1] = turn % 2 == 0 ? 'X' : 'O';

    DisplayBoard(board);
}

void DisplayBoard(char board[3][3])
{
    cout << "    1 2 3" << endl << "   -------" << endl;

    for (int i = 0; i < 3; i++)
        {
            cout << "|" << i + 1 << "| ";

            for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j] << " ";
                }
            cout << endl;
        }
}


void Outcome(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '?')
            {
                cout << "Player " << (board[i][0] == 'X' ? "1" : "2") << " wins!\n";
                exit(1);
            }
        }
    for (int j = 0; j < 3; j++)
        {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '?')
            {
                cout << "Player " << (board[0][j] == 'X' ? "1" : "2") << " wins!\n";
                exit(1);
            }
        }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '?')
    {
        cout << "Player " << (board[0][0] == 'X' ? "1" : "2") << " wins!\n";
        exit(1);
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '?')
    {
        cout << "Player " << (board[0][2] == 'X' ? "1" : "2") << " wins!\n";
        exit(1);
    }
    else if (board[0][0] != '?' && board[0][1] != '?' && board[0][2] != '?' && board[1][0] != '?' && board[1][1] != '?' && board[1][2] != '?' && board[2][0] != '?' && board[2][1] != '?' && board[2][2] != '?')
    {
        cout << "It's a tie!\n";
        return;
    }
    else
    {
        return;
    }
}