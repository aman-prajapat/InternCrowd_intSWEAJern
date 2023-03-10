#include <iostream>
using namespace std;
#include <iomanip>

int OccupiedBox[9]; // stores which box is filled by which player

// Funtion to chech if any player make a horizontal,vertical or diagonal line
// or to check if someone win??
int CheckLine()
{
    int getPlayer = -1;

    if (OccupiedBox[0] == OccupiedBox[1] && OccupiedBox[1] == OccupiedBox[2])
    {
        getPlayer = OccupiedBox[0];
    }
    else if (OccupiedBox[0] == OccupiedBox[4] && OccupiedBox[4] == OccupiedBox[8])
    {
        getPlayer = OccupiedBox[0];
    }
    else if (OccupiedBox[0] == OccupiedBox[3] && OccupiedBox[3] == OccupiedBox[6])
    {
        getPlayer = OccupiedBox[0];
    }
    else if (OccupiedBox[1] == OccupiedBox[4] && OccupiedBox[4] == OccupiedBox[7])
    {
        getPlayer = OccupiedBox[1];
    }
    else if (OccupiedBox[2] == OccupiedBox[5] && OccupiedBox[5] == OccupiedBox[8])
    {
        getPlayer = OccupiedBox[2];
    }
    else if (OccupiedBox[3] == OccupiedBox[4] && OccupiedBox[4] == OccupiedBox[5])
    {
        getPlayer = OccupiedBox[3];
    }
    else if (OccupiedBox[6] == OccupiedBox[7] && OccupiedBox[7] == OccupiedBox[8])
    {
        getPlayer = OccupiedBox[6];
    }
    else if (OccupiedBox[2] == OccupiedBox[4] && OccupiedBox[4] == OccupiedBox[6])
    {
        getPlayer = OccupiedBox[2];
    }

    if (getPlayer == 1)
    {
        return 1;
    }
    else if (getPlayer == 2)
    {
        return 2;
    }
    else
        return -1;
}

/*
print X or O in the cells
if there is nothing in cell then print index of the cell
for the convenience of player
*/

void OXprinter(int player, int i)
{

    if (player == 1)
    {
        cout << "X";
    }
    else if (player == 2)
    {
        cout << "O";
    }
    else
        cout << i;
}

/*funtion to print structure  of game
take two arguments cell number and player who choose that cell
*/
void DisplayGrid(int choice, int player)
{

    for (int i = 0; i < 9; i++)
    {
        if (i == choice)
            OXprinter(player, i);
        else
            OXprinter(OccupiedBox[i], i);

        if (i == 2 || i == 5)
            cout << "\n----------\n";

        if (i == 2 || i == 5 || i == 8)
            continue;
        cout << " | ";
    }
    cout << "\n";
}

int main()
{
    int choice, result = -1;
    int RoundDetails[3] = {0, 0, 0}; // Collect details of rounds played by players
    string player1, player2;

lable:
    RoundDetails[0]++;
    for (int i = 0; i < 9; i++)
    {
        OccupiedBox[i] = -1;
    }

    cout << "\n1 : To play game \n2 : To exit game\n"
         << setw(25) << "Enter your choice: ";
    cin >> choice;
    cout << "\n";

    switch (choice)
    {
    case 1:
        if (RoundDetails[0] == 1)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Player one Name: ";
            getline(cin, player1);
            cout << "Player two Name: ";
            getline(cin, player2);
            cout << '\n';
        }

        DisplayGrid(10, 10);
        for (int i = 0; i < 10; i++)
        {
            if (i >= 5)
            {
                result = CheckLine();

                if (result == 1)
                {
                    cout << "\n"
                         << player1 << " Won the MAtch" << endl;
                    RoundDetails[1]++;
                    break;
                }
                else if (result == 2)
                {
                    cout << "\n"
                         << player2 << " Won the MAtch" << endl;
                    RoundDetails[2]++;
                    break;
                }
            }
            if (i == 9)
            {
                cout << "\n"
                     << setw(25) << player1 << setw(5) << "vs" << setw(5) << player2 << endl;
                cout << "                ------------DRAW--------------" << endl;
                break;
            }

            if (i % 2 == 0)
            {
            retry:
                cout << "\n" << player1 << "'s turn[X]: ";
                cin >> choice;
                cout << "\n";

                if (OccupiedBox[choice] == -1)
                {
                    OccupiedBox[choice] = 1;
                    DisplayGrid(choice, 1);
                    cout << "\n";
                }
                else
                {
                    cout << "Enter a box number which is not occupied: ";
                    goto retry;
                }
            }
            else
            {
            retry1:
                cout << player2 << "'s turn[O]: ";
                cin >> choice;
                cout << "\n";

                if (OccupiedBox[choice] == -1)
                {
                    OccupiedBox[choice] = 2;
                    DisplayGrid(choice, 2);
                }
                else
                {
                    cout << "Enter a box number which is not occupied: ";
                    goto retry1;
                }
            }
        }
        break;

    case 2:
        cout << "Total Rounds played: " << RoundDetails[0] << "\n";
        cout << player1 << " won " << RoundDetails[1] << " Rounds\n";
        cout << player2 << " won " << RoundDetails[2] << " Rounds\n\n";

        if (RoundDetails[1] > RoundDetails[2])
        {
            cout << player1 << " is WINNER" << endl;
        }
        else if (RoundDetails[1] == RoundDetails[2])
        {
            cout << "Its a DRAW " << endl;
        }
        else
        {
            cout << player2 << " is WINNER" << endl;
        }
        cout << "\n" << setw(25) << "------:Exiting the Game:-----\n";
        abort();

    default:
        cout << "\n"
             << setw(25) << "-----Select a valid choice-----\n";
        break;
    }
    goto lable;
    return 0;
}