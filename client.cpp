#include <iostream>
#include <httplib.h>
#include <header.h>
using namespace std;
using namespace httplib;

int main()
{

    Client cl("127.0.0.1", 8000);
    Game game;
    cout << "enter your id:";
    string id;
    cin >> id;
    int num_players;
    cout << "enter number of players";
    cin >> num_players;
    MultipartFormDataItems item = {{"Start", id, "", ""}};
    game.setGameboard(num_players);
    
    static string test[121];
    
    for (int i = 0; i < 121; i++)
    {
        test[i] = game.gameboard[i];
    }
    game.display_b(test);
    while (game.gameboard[60] == " . ")
    {
        cout << "w = wall , u = up ; d = down ; l = left ; r = right" << endl;
        string movement;
        cin >> movement;
        if (movement == "w")
        {
            cout << "enter coordinate:";
            string x, y;
            cin >> x >> y;
            game.gameboard[stoi(x) * 11 + stoi(y)] = " - ";
            test[stoi(x) * 11 + stoi(y)] = " - ";
        }
        else
        {
            string a, b;
            cout << "enter the start point";
            cin >> a >> b;
            string temp;
            temp = game.gameboard[stoi(a) * 11 + stoi(b)];

            if (movement == "u")
            {
                game.gameboard[stoi(a) * 11 + stoi(b)] = game.gameboard[stoi(a) * 11 + stoi(b) - 11];
                game.gameboard[stoi(a) * 11 + stoi(b) - 11] = temp;
                test[stoi(a) * 11 + stoi(b)] = test[stoi(a) * 11 + stoi(b) - 11];
                test[stoi(a) * 11 + stoi(b) - 11] = temp;
            }

            else if (movement == "d")
            {
                game.gameboard[stoi(a) * 11 + stoi(b)] = game.gameboard[stoi(a) * 11 + stoi(b) + 11];
                game.gameboard[stoi(a) * 11 + stoi(b) + 11] = temp;
                test[stoi(a) * 11 + stoi(b)] = test[stoi(a) * 11 + stoi(b) + 11];
                test[stoi(a) * 11 + stoi(b) + 11] = temp;
            }

            else if (movement == "l")
            {
                game.gameboard[stoi(a) * 11 + stoi(b)] = game.gameboard[stoi(a) * 11 + stoi(b) - 1];
                game.gameboard[stoi(a) * 11 + stoi(b) - 1] = temp;
                test[stoi(a) * 11 + stoi(b)] = test[stoi(a) * 11 + stoi(b) - 1];
                test[stoi(a) * 11 + stoi(b) - 1] = temp;
            }

            else if (movement == "r")
            {
                game.gameboard[stoi(a) * 11 + stoi(b)] = game.gameboard[stoi(a) * 11 + stoi(b) + 1];
                game.gameboard[stoi(a) * 11 + stoi(b) + 1] = temp;
                test[stoi(a) * 11 + stoi(b)] = test[stoi(a) * 11 + stoi(b) + 1];
                test[stoi(a) * 11 + stoi(b) + 1] = temp;
            }
        }
        system("clear");
        
        game.display_b(test);
    }
    if (auto res = cl.Get("/runserver"))
    {
        if (res->status == 200)
        {
            while (true)
            {
                string temp;
                cin >> temp;
                auto res = cl.Post("/pl", temp, "text/plain");
                cout << res->body << std::endl;
            }
        }
    }
}