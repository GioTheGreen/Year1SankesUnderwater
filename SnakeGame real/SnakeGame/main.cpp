/*
  Games Development with C++ GAV1031-N
  Snake ICA start project 
  
  Set up to use the SFML 2.5.1 64-bit API
    SFML documentation: https://www.sfml-dev.org/learn.php
*/


#include "game.h"
int main()
{
    int ans1;
    int ans2;
    std::string ans3;
    bool correct1 = false;
    bool correct2 = false;
    bool correct3 = false;

    bool player1 = false;
    bool player2 = false;
    int numOfAi = 0;
    int NumOfPlayers = 0;
    float speed = 0.3;

    do
    {
        std::cout << "How many players? Please enter 0, 1 or 2" << std::endl;
        std::cin >> ans1;
        if ((ans1 == 0) or (ans1 == 1) or (ans1 == 2))
        {
            correct1 = true;
            NumOfPlayers = ans1;
            if (ans1 == 2)
            {
                player1 = true;
                player2 = true;
            }
            else if (ans1 == 1)
            {
                player1 = true;
            }
        }
        else
        {
            std::cout << "Incorrect input, Try again" << std::endl;
        }
    } while (!correct1);

    do
    {
        std::cout << "How many AI? Please enter number from 0 to "<< 8-NumOfPlayers << std::endl;
        std::cin >> ans2;
        if (ans2 >= 0 and ans2 <= (8-NumOfPlayers))
        {
            numOfAi = ans2;
            correct2 = true;
        }
        else
        {
            std::cout << "Incorrect input, Try again" << std::endl;
        }
    } while (!correct2);

    do
    {
        std::cout << "Choose differculty! Please enter keith, easy, normal, hard or demon" << std::endl;
        std::cin >> ans3;
        if (ans3 == "keith" or ans3 == "easy" or ans3 == "normal" or ans3 == "hard" or ans3 == "demon")
        {
            correct3 = true;
            if (ans3 == "keith")
            {
                speed = 0.5;
            }
            else if (ans3 == "easy")
            {
                speed = 0.3;
            }
            else if (ans3 == "normal")
            {
                speed = 0.2;
            }
            else if (ans3 == "hard")
            {
                speed = 0.1;
            }
            else
            {
                speed = 0.05;
            }
        }
        else
        {
            std::cout << "Incorrect input, Try again" << std::endl;
        }
    } while (!correct3);

    game Game;
    Game.run(player1, player2, numOfAi, speed);

    return 0;
}
