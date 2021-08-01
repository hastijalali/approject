#include <iostream>
#include <string>
using namespace std;
class Game
{
public:
    string gameboard[121] = {
    " 1 ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " 2 ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ",
    " 3 ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " 4 ",
    };
    Game();
    void setGameboard(int a);
    void display_board();
    void display_b(string temp[]);
};

Game::Game() {}

void Game::setGameboard(int a)
{
    if (a == 2)
    {
        gameboard[120] = gameboard[110] = " . ";
    }
    else if (a == 3)
    {
        gameboard[120] = " . ";
    }
}
void Game::display_board()
{
    int count = 0;
    while (count != 11)
    {
        for (int i = 0; i < 11; i++)
        {
            cout << gameboard[i + count * 11];
        }
        cout << endl;
        count++;
    }
}
void Game::display_b(string temp[])
{
    int i = 1;
    for (i = 1; i <= 121; i++)
    {
        cout << temp[i-1];
        if (i % 11 == 0)
        {
            cout << endl;
        }
    }
}