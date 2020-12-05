#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <stdio.h>
#include <unistd.h>
#include <SFML/System/Vector2.hpp>
#include <map>


int N=30,M=20;
int size=16;
int w = size*N;
int h = size*M;
int dir,num=4;


int main()
{
    // This is for the fps
    sf::Clock clock;
    bool menu = false;
    int selection = 0;
    int score = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Texture texture;
    sf::Texture snake;
    sf::Font font;
    sf::Text text("Welcome to Snake", font, 50);
    sf::Text Start("Start", font, 50);
    sf::Text Exit("Exit", font, 50);
    sf::Event event;
    sf::RectangleShape snakeSprite(sf::Vector2f(25.f, 25.f));
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    sf::RectangleShape snakeSnack(sf::Vector2f(25.f, 25.f));
    //sf::IntRect boundsSnake();
    //sf::IntRect boundsSnack();
    const sf::Vector2f boundaries(25.0f, 25.0f);
    sf::Music music;

    int SnakeMovement;
    int count;
    bool eaten = true;



    //setting background to black
    background.setFillColor(sf::Color::Black);

    snake.loadFromFile("assets/whiteDot.png");

    // Create a graphical text to display
    if (!font.loadFromFile("assets/arial.ttf"))
        return EXIT_FAILURE;
    
    snakeSnack.setFillColor(sf::Color::White);

    text.setPosition(100.f, 100.f);
    Start.setPosition(100.f, 200.f);
    Exit.setPosition(100.f, 300.f);

    // Load a music to play

    if (!music.openFromFile("music.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    // Start the game loop
    while (window.isOpen())
    {

        // Process events
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Clear screen
            window.clear();

            if(selection == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                Exit.setFillColor(sf::Color(255,255,255));
                selection = selection + 1;
            }

            if(selection == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                return(0);
            }

            // left key is pressed: move our character
            if(selection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {   Start.setFillColor(sf::Color(255,255,255));
                selection = selection + 1;
            }

            if(selection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {   
                menu = true;
            }
            

            if(menu == true){
                // moves the sprite
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    SnakeMovement = 0;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    SnakeMovement = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    SnakeMovement = 2;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    SnakeMovement = 3;
                }   
                window.draw(snakeSprite);
            }

            if(selection == 1)
            {
                Exit.setFillColor(sf::Color(255,0,255));
                selection = selection + 1;
            }

            if(selection == 3)
            {
                Start.setFillColor(sf::Color(255,0,255));
                selection = 0;
            }

        }   

        count = count + 1;

        printf("%d \n", count);

        if(count >= 50)
        {
            
            if(SnakeMovement == 0)
            {
                if(snakeSprite.getPosition().x > 0)
                {
                    snakeSprite.move(-4.f, 0.f);
                }
                
            }

            if(SnakeMovement == 1)
            {
                if(snakeSprite.getPosition().x < 775)
                    snakeSprite.move(4.f, 0.f);
                
            }

            if(SnakeMovement == 2)
            {
                if(snakeSprite.getPosition().y > 0)
                    snakeSprite.move(0.f, -4.f);
                
            }

            if(SnakeMovement == 3)
            {
                if(snakeSprite.getPosition().y < 575)
                    snakeSprite.move(0.f, 4.f);
                
            }
            count = 0;
        }

        // Draw the sprite
        window.draw(background);

         // Draw the menu if first starting the game
        if( menu == false)
        {
            window.draw(text);
            window.draw(Start);
            window.draw(Exit);
        }
        
        if(menu == true)
        {
            // Draw the snake/dot to be eaten 
            window.draw(snakeSprite);
            window.draw(snakeSnack);
 
            if((snakeSprite.getPosition().x + boundaries.x) > snakeSnack.getPosition().x)
            {
                if((snakeSprite.getPosition().x - boundaries.x) < snakeSnack.getPosition().x)
                {
                   if((snakeSprite.getPosition().y - boundaries.y) < snakeSnack.getPosition().y)
                    {   
                        if((snakeSprite.getPosition().y + boundaries.y) > snakeSnack.getPosition().y)
                        { 
                        eaten = true;
                        score = score + 1; 
                        }
                    }
                }
            }
 

            if(eaten == true)
            {   // this is for redrawing in a different area
                snakeSnack.setPosition(rand()%801, rand() %601);
                eaten = false;
            }
        }

        window.display();

    }
    return EXIT_SUCCESS;
}
