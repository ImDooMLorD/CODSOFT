#include <iostream>
using namespace std;

// This shows Game Board
void showBoard(char *g)
{

    int i = 0, count = 0;

    cout<<"\033[2J\033[1;1H";                            // To clear terminal screen

    cout << "--- Game Board with the block numbers ---\n\n";

    for (i = 0; i < 9; i++)
    {
        cout << " " << *(g + i) << " ";
        if (count < 2)
        {
            cout << "|";
            count++;
        }
        else
        {
            if (i == 8)
            {
                cout << "\n   |   |   ";
                break;
            }
            cout << "\n___|___|___\n";
            count = 0;
        }
    }
}

// This checks Result
bool checkResult(char t[3][3])
{
    int countBoardFill = 0;
    int countDiagX = 0, countDiagO = 0;
    int countOffDiagX = 0, countOffDiagO = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Checks for same X/O in a row
            if ((t[i][0] == t[i][1])&&(t[i][2] == t[i][0]))
            { 
                    showBoard(&t[0][0]);
                    if (t[i][2] == 'X')
                    cout << "\n\n\n\t\t~~~~~~~~ Player - X Wins ~~~~~~~~~\n\n\n";
                    if (t[i][2] == 'O')
                    cout << "\n\n\n\t\t~~~~~~~~ Player - O Wins ~~~~~~~~~\n\n\n";
                    return false;
                
            }

            // Checks for same X/O in a column
            if (t[0][j] == t[1][j])
            {
                if (t[2][j] == t[0][j])
                {
                    showBoard(&t[0][0]);
                     if (t[2][j] == 'X')
                    cout << "\n\n\n\t\t~~~~~~~~ Player - X Wins ~~~~~~~~~\n\n\n";
                     if (t[2][j] == 'O')
                    cout << "\n\n\n\t\t~~~~~~~~ Player - O Wins ~~~~~~~~~\n\n\n";
                    return false;
                }
            }

            // Checks for same X/O in main-diagonal
            if(i == j)                            // Condition for identification of central and corner elements
            {
                if(t[i][j] == 'X') countDiagX++; 
                if(t[i][j] == 'O') countDiagO++; 
                if (countDiagX == 3)
                {
                    showBoard(&t[0][0]);
                    cout << "\n\n\n\t\t~~~~~~~~ Player - X Wins ~~~~~~~~~\n\n\n";
                    return false;
                }
                if (countDiagO == 3)
                {
                    showBoard(&t[0][0]);
                    cout << "\n\n\n\t\t~~~~~~~~ Player - O Wins ~~~~~~~~~\n\n\n";
                    return false;
                }
            }

            
            // Checks for same X/O in off-diagonal
            if( i+j == 2 )                            // Condition for identification of central and corner elements
            {
                if(t[i][j] == 'X') countOffDiagX++; 
                if(t[i][j] == 'O') countOffDiagO++; 
                if (countOffDiagX == 3)
                {
                    showBoard(&t[0][0]);
                    cout << "\n\n\n\t\t~~~~~~~~ Player - X Wins ~~~~~~~~~\n\n\n";
                    return false;
                }
                if (countOffDiagO == 3)
                {
                    showBoard(&t[0][0]);
                    cout << "\n\n\n\t\t~~~~~~~~ Player - O Wins ~~~~~~~~~\n\n\n";
                    return false;
                }
            }

            // Checks if game is a DRAW
            if ((t[i][j] == 'X')||(t[i][j] == 'O'))
            {
                countBoardFill++;
                if (countBoardFill == 9)
                {
                    showBoard(&t[0][0]);
                    cout<<"\n\n\n\t\t~~~~~~~~ Game DRAW ~~~~~~~~~\n\n\n";
                    return false;
                }
                
            }
        }
    }
    return true;
}

// Function that defines game
void game(char gameBoard[3][3])
{
    int X, O;
    bool chanceX = true;
    char *g = &gameBoard[0][0];
    while (checkResult(gameBoard))
    {
        showBoard(g);
        if (chanceX == true)
        {

            while (1)
            {
                cout << "\n1. Enter no for PLAYER X : ";
                cin >> X;

                if (X >= 1 && X <= 9 && (*(g + X - 1) != 'X') && (*(g + X - 1) != 'O'))
                {
                    *(g + X - 1) = 'X';
                    chanceX = !chanceX;
                    break;
                }
                else
                {
                    cout << "INVALID INPUT";
                }
            }
        }
        else
        {
            while (1)
            {
                cout << "\n2. Enter no for PLAYER O : ";
                cin >> O;

                if (O >= 1 && O <= 9 && (*(g + O - 1) != 'X') && (*(g + O - 1) != 'O'))
                {
                    *(g + O - 1) = 'O';
                    chanceX = !chanceX;
                    break;
                }
                else
                {
                    cout << "INVALID INPUT";
                }
            }
        }
    }
}

int main()
{

    int choice;
    while (1)
    {
        char gameBoard[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        cout << "\n1. Play Tic-Tac-Toe";
        cout << "\n2. Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        if (choice == 1)
            game(gameBoard);
        else
            break;
    }

    return 0;
}
