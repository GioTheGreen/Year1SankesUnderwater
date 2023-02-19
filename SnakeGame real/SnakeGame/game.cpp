#include "game.h"
#include "collectables.h"
#include <vector>


void game::GameOver(std::vector<snake> s, int alive, int start)
{
    int maxScore = 0;
    int winner = 100;
    if (alive > 0)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i].getSnakeSize() - 1) > maxScore)
            {
                maxScore = (s[i].getSnakeSize() - 1);
                winner = i;
            }
        }
        if (winner == 100)
        {
            std::cout << "no winner" << std::endl;
        }
        else
        {
            std::cout << "winner(s): ";
            for (size_t i = 0; i < s.size(); i++)
            {
                if ((s[i].getSnakeSize() - 1) == maxScore)
                {
                    if (start == 2)
                    {
                        if (i == 0)
                        {
                            std::cout << "Player 1 ";
                        }
                        else if (i == 1)
                        {
                            std::cout << "Player 2 ";
                        }
                        else
                        {
                            std::cout << "AI_" << (i - 1) << " ";
                        }
                    }
                    else if (start == 1)
                    {
                        if (i == 0)
                        {
                            std::cout << "Player 1 ";
                        }
                        else
                        {
                            std::cout << "AI_" << i << " ";
                        }
                    }
                    else
                    {
                        std::cout << "AI_" << (i + 1) << " ";
                    }
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i].getSurvived() > maxScore)
            {
                maxScore = s[i].getSurvived();
                winner = i;
            }
        }
        if (winner == 100)
        {
            std::cout << "no winner" << std::endl;
        }
        std::cout << "winner(s): ";
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i].getSurvived()) == maxScore)
            {
                if (start == 2)
                {
                    if (i == 0)
                    {
                        std::cout << "Player 1 ";
                    }
                    else if (i == 1)
                    {
                        std::cout << "Player 2 ";
                    }
                    else 
                    {
                        std::cout << "AI_" << (i - 1) << " ";
                    }
                }
                else if (start == 1)
                {
                    if (i == 0)
                    {
                        std::cout << "Player 1 ";
                    }
                    else
                    {
                        std::cout << "AI_" << i << " ";
                    }
                }
                else
                {
                    std::cout << "AI_" << (i + 1) << " ";
                }
            }
        }

    }
    std::cout << "\n";
}

game::game()
{
    //attaemp to make grid                                             not enough time to finish
    /*for (size_t i = 0; i < width - snakeSize; i+= snakeSize)
    {
        for (size_t j = 0; j < height - snakeSize; j+= snakeSize)
        {
            map.push_back(graphNode(i,j));
        }
    }
    for (int i = 0; i < map.size(); i++)
    {
        if (i-1 >= 0 and !(i% (width / snakeSize)))
        {
            map[i].addChild(&map[i - 1]);
        }
        if (i+1 <= map.size() and !((i % (width / snakeSize)) -1))
        {
            map[i].addChild(&map[i + 1]);
        }
        if (i - (width / snakeSize) >= 0)
        {
            map[i].addChild(&map[i - (width / snakeSize)]);
        }
        if (i + (width / snakeSize) <= map.size() - 1)
        {
            map[i].addChild(&map[i + (width / snakeSize)]);
        }
    }*/
}
void game::run(bool p1, bool p2, int numAi, float speed)
{
    // All SFML types and functions are contained in the sf namespace
    //for (size_t i = 0; i < map.size(); i++)
    //{
    //    std::cout << map[i].i
    //}
   // Create an instance of the SFML RenderWindow type which represents the display
   // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(width, height + infoHeight), "C++ Snake ICA : B1050622");

    //creating the snakes container
    std::vector<snake> snakes;
    if (p1)
    {
        snakes.push_back(snake(snakeSize * 3, snakeSize * 3, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
    }
    if (p2)
    {
        snakes.push_back(snake(snakeSize * 18, snakeSize * 3, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
    }
    for (size_t i = 0; i < numAi; i++)
    {
        if (i== 0)
        {
            snakes.push_back(snake(snakeSize * 3, snakeSize * 7, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
            
        }
        else if (i== 1)
        {
            snakes.push_back(snake(snakeSize * 18, snakeSize * 7, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
            
        }
        else if (i == 2)
        {
            snakes.push_back(snake(snakeSize * 3, snakeSize * 11, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
            
        }
        else if (i== 3)
        {
            snakes.push_back(snake(snakeSize * 18, snakeSize * 11, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
           
        }
        else if (i == 4)
        {
            snakes.push_back(snake(snakeSize * 3, snakeSize * 15, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
            
        }
        else if (i == 5)
        {
            snakes.push_back(snake(snakeSize * 18, snakeSize * 15, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
        }
        else if (i == 6 and p2 == false)
        {
            snakes.push_back(snake(snakeSize * 18, snakeSize * 3, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
        }
        else if (i == 7 and p1 == false)
        {
            snakes.push_back(snake(snakeSize * 3, snakeSize * 3, sf::Color(rand() % 255, rand() % 255, rand() % 255)));
        }
    }
    
    std::list <collectables> fruits;
    fruits.push_back(collectables(1));
    fruits.push_back(collectables(1));
    fruits.push_back(collectables(2));
    fruits.push_back(collectables(2));
    fruits.push_back(collectables(3));
    /*for (size_t i = 0; i < 100; i++)
    {
        fruits.push_back(collectables(1));
    }*/

    //creating a tank
    sf::Clock tankDrop;
    tankDrop.restart();
    float dropintaval = gameTime / ((height/snakeSize) - 2 );
    float airlevel = snakeSize;
    sf::RectangleShape tank(sf::Vector2f(width - (2*snakeSize),height -(2*snakeSize)));
    tank.setFillColor(sf::Color(10, 120, 107));
    tank.setPosition(snakeSize, airlevel);

    sf::Font font;
    if (!font.loadFromFile("Data/Fonts/game_over.ttf"))
    {
        std::cout << "ERROR could not load font" << std::endl;
    }
    sf::Text score1;
    score1.setFont(font);
    score1.setCharacterSize(40);
    if (!p1)
    {
        score1.setString("AI_1 Score : 0");
    }
    else
    {
        score1.setString("P1 Score : 0");
    }
    score1.setFillColor(sf::Color::White);
    score1.setPosition(snakeSize, height);

    sf::Text score2;
    score2.setFont(font);
    score2.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score2.setString("AI_2 Score : 0");
        }
        else
        {
            score2.setString("AI_1 Score : 0");
        }
    }
    else
    {
        score2.setString("P2 Score : 0");
    }
    score2.setFillColor(sf::Color::White);
    score2.setPosition(snakeSize * 12, height);

    sf::Text score3;
    score3.setFont(font);
    score3.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score3.setString("AI_3 Score : 0");
        }
        else
        {
            score3.setString("AI_2 Score : 0");
        }
    }
    else
    {
        score3.setString("AI_1 Score : 0");
    }
    score3.setFillColor(sf::Color::White);
    score3.setPosition(snakeSize * 23, height);

    sf::Text score4;
    score4.setFont(font);
    score4.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score4.setString("AI_4 Score : 0");
        }
        else
        {
            score4.setString("AI_3 Score : 0");
        }
    }
    else
    {
        score4.setString("AI_2 Score : 0");
    }
    score4.setFillColor(sf::Color::White);
    score4.setPosition(snakeSize, height + (snakeSize * 2));

    sf::Text score5;
    score5.setFont(font);
    score5.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score5.setString("AI_5 Score : 0");
        }
        else
        {
            score5.setString("AI_4 Score : 0");
        }
    }
    else
    {
        score5.setString("AI_3 Score : 0");
    }
    score5.setFillColor(sf::Color::White);
    score5.setPosition(snakeSize* 12, height + (snakeSize * 2));

    sf::Text score6;
    score6.setFont(font);
    score6.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score6.setString("AI_6 Score : 0");
        }
        else
        {
            score6.setString("AI_5 Score : 0");
        }
    }
    else
    {
        score6.setString("AI_4 Score : 0");
    }
    score6.setFillColor(sf::Color::White);
    score6.setPosition(snakeSize * 23, height + (snakeSize * 2));

    sf::Text score7;
    score7.setFont(font);
    score7.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score7.setString("AI_7 Score : 0");
        }
        else
        {
            score7.setString("AI_6 Score : 0");
        }
    }
    else
    {
        score7.setString("AI_5 Score : 0");
    }
    score7.setFillColor(sf::Color::White);
    score7.setPosition(snakeSize, height + (snakeSize * 4));

    sf::Text score8;
    score8.setFont(font);
    score8.setCharacterSize(40);
    if (!p2)
    {
        if (!p1)
        {
            score8.setString("AI_8 Score : 0");
        }
        else
        {
            score8.setString("AI_7 Score : 0");
        }
    }
    else
    {
        score8.setString("AI_6 Score : 0");
    }
    score8.setFillColor(sf::Color::White);
    score8.setPosition(snakeSize * 12, height + (snakeSize * 4));


    // to know how many players
    int tempstart = 2;
    if (!p2)
    {
        if (!p1)
        {
            tempstart = 0;
        }
        else
        {
            tempstart = 1;
        }
    }
    // Create an instance of the SFML CircleShape and initialise it so radius is 100

    // Set the shape's fill colour attribute to Green

    // We can still output to the console window
    std::cout << "SnakeGame: Starting" << std::endl;

    // Main loop that continues until we call window.close()
    sf::Clock clock;
    clock.restart();
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        for (size_t i = 0; i < snakes.size(); i++)
        {
            if (snakes[i].getPos().y < airlevel)
            {
                snakes[i].setAirLeft(maxAir);
            }
        }

        if (p1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                snakes[0].setDir(directions::up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                snakes[0].setDir(directions::down);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                snakes[0].setDir(directions::left);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                snakes[0].setDir(directions::right);
            }
        }
        if (p2)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                snakes[1].setDir(directions::up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                snakes[1].setDir(directions::down);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                snakes[1].setDir(directions::left);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                snakes[1].setDir(directions::right);
            }
        }
        
        
        for (size_t i = tempstart; i < snakes.size(); i++)
        {
            snakes[i].setDir(snakes[i].closestFruit(fruits, airlevel));
        }

        // We must clear the window each time around the loop
        window.clear();
        window.draw(tank);

        if (clock.getElapsedTime().asSeconds() >= speed)
        {
            for (size_t i = 0; i < snakes.size(); i++)
            {
                snakes[i].update(airlevel);
            }
            clock.restart();
        }
  
        std::list<collectables>::iterator currentfruit = fruits.begin();
        std::list<collectables>::iterator endfruit = fruits.end();
        for (; currentfruit != endfruit; ++currentfruit)
        {
            std::list<collectables>::iterator currentfruit2 = fruits.begin();
            std::list<collectables>::iterator endfruit2 = fruits.end();
            for (; currentfruit2 != endfruit2; ++currentfruit2)
            {
                if ((currentfruit != currentfruit2) and currentfruit->getPos() == currentfruit2->getPos())   //so two fruits cant be in the same location
                {
                    currentfruit->kill();
                }
            }
            for (size_t i = 0; i < snakes.size(); i++)
            {
                if (snakes[i].getPos() == currentfruit->getPos())
                {
                    if (snakes[i].getAlive())
                    {
                        snakes[i].addTail(currentfruit->getScore());
                        currentfruit->kill();
                    }
                }
            }
        }
        // collition dettection between snakes, self, walls and surface
        for (size_t i = 0; i < snakes.size(); i++)
        {
            if ((snakes[i].getPos().x > (width - (snakeSize * 2))))     //walls
            {
                snakes[i].setAlive(false);
            }
            else if ((snakes[i].getPos().x < snakeSize))
            {
                snakes[i].setAlive(false);
            }

            for (size_t j = 0; j < snakes.size(); j++)     // self
            {
                if (i == j)
                {
                    for (auto currenttail : snakes[i].getTailpos())
                    {
                        if (snakes[i].getPos() == sf::Vector2f(currenttail.x, currenttail.y))
                        {

                            snakes[i].setAlive(false);

                        }
                    }
                }
                else
                {
                    for (auto currenttail : snakes[i].getTailpos())      // other snakes
                    {
                        if (snakes[j].getPos() == sf::Vector2f(currenttail.x, currenttail.y))
                        {

                            snakes[j].setAlive(false);
                        }
                        else if (snakes[j].getPos() == snakes[i].getPos())
                        {
                            snakes[i].setAlive(false);
                            snakes[j].setAlive(false);
                        }
                    }
                }
            }
        }
        //survied check for win condition
        numOfAlive = 0;
        for (size_t i = 0; i < snakes.size(); i++)
        {
            if (snakes[i].getAlive())
            {
                numOfAlive++;
            }
        }
        if (numOfAlive == 0 or airlevel == (height -(2*snakeSize)))
        {
            GameOver(snakes, numOfAlive, tempstart);
            window.close();
        }

        //spawn fruits

        for (size_t i = 0; i < snakes.size(); i++)
        {
            snakes[i].render(window);
        }
        std::list<collectables>::iterator currentfruit1 = fruits.begin();
        std::list<collectables>::iterator endfruit1 = fruits.end();
        for (; currentfruit1 != endfruit1; ++currentfruit1)
        {
            if (currentfruit1->getLive())
            {
                if (currentfruit1->getPos().y < airlevel)
                {
                    currentfruit1->spwan(currentfruit1->getPos().x, airlevel);
                }
                currentfruit1->render(window);
            }
            else
            {
                currentfruit1->spwan(((rand()% ((width / snakeSize)-2)) * snakeSize) + snakeSize, ((rand() % ((height / snakeSize)-2)) * snakeSize) + snakeSize);
            }
        }

        if (tankDrop.getElapsedTime().asSeconds() >= dropintaval)
        {
            airlevel += snakeSize;
            tank.setPosition(snakeSize ,airlevel);
            tank.setSize(sf::Vector2f(tank.getSize().x, (tank.getSize().y) - snakeSize));
            tankDrop.restart();
        }
        // updating the score/oxigen display for all snakes
        if (p1)
        {
            score1.setString("P1 Score : " + std::to_string(snakes[0].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[0].getAirLeft()));
            window.draw(score1);
        }
        if (p2)
        {
            score2.setString("P2 Score : " + std::to_string(snakes[1].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[1].getAirLeft()));
            window.draw(score2);
        }
        for (size_t i = 0; i < numAi; i++)
        {
            if (i == 0)
            {
                if (!p1)
                {
                    score1.setString("AI_1 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score1);
                }
                else if (!p2)
                {
                    score2.setString("AI_1 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score2);
                }
                else
                {
                    score3.setString("AI_1 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score3);
                }
            }
            else if (i == 1)
            {
                if (!p1)
                {
                    score2.setString("AI_2 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score2);
                }
                else if (!p2)
                {
                    score3.setString("AI_2 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score3);
                }
                else
                {
                    score4.setString("AI_2 Score : " + std::to_string(snakes[tempstart+i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart+i].getAirLeft()));
                    window.draw(score4);
                }
            }
            else if (i == 2)
            {
                if (!p1)
                {
                    score3.setString("AI_3 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score3);
                }
                else if (!p2)
                {
                    score4.setString("AI_3 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score4);
                }
                else
                {
                    score5.setString("AI_3 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score5);
                }
            }
            else if (i == 3)
            {
                if (!p1)
                {
                    score4.setString("AI_4 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score4);
                }
                else if (!p2)
                {
                    score5.setString("AI_4 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score5);
                }
                else
                {
                    score6.setString("AI_4 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score6);
                }
            }
            else if (i == 4)
            {
                if (!p1)
                {
                    score5.setString("AI_5 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score5);
                }
                else if (!p2)
                {
                    score6.setString("AI_5 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score6);
                }
                else
                {
                    score7.setString("AI_5 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score7);
                }
            }
            else if (i == 5)
            {
                if (!p1)
                {
                    score6.setString("AI_6 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score6);
                }
                else if (!p2)
                {
                    score7.setString("AI_6 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score7);
                }
                else
                {
                    score8.setString("AI_6 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score8);
                }
            }
            else if (i == 6)
            {
                if (!p1)
                {
                    score7.setString("AI_7 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score7);
                }
                else if (!p2)
                {
                    score8.setString("AI_7 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score8);
                }

            }
            else if (i == 7)
            {
                if (!p1)
                {
                    score8.setString("AI_8 Score : " + std::to_string(snakes[tempstart + i].getSnakeSize() - 1) + "  o2:  " + std::to_string(snakes[tempstart + i].getAirLeft()));
                    window.draw(score8);
                }
            }
        }
        // Get the window to display its contents
        window.display();
    }

    std::cout << "SnakeGame: Finished" << std::endl;
}
