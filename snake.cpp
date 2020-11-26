#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <stdio.h>
#include <unistd.h>

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
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Texture texture;
    sf::Texture snake;
    sf::Font font;
    sf::Text text("Welcome to Snake", font, 50);
    sf::Text Start("Start", font, 50);
    sf::Text Exit("Exit", font, 50);
    sf::Event event;



    if (!texture.loadFromFile("assets/cute_image.jpg"))
        return EXIT_FAILURE;

    snake.loadFromFile("assets/whiteDot.png");
   

    //  snakeSprite.Resize( 10, 10);
    sf::Sprite snakeSprite(snake);
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    
    if (!font.loadFromFile("assets/arial.ttf"))
        return EXIT_FAILURE;
    

    text.setPosition(100.f, 100.f);
    Start.setPosition(100.f, 200.f);
    Exit.setPosition(100.f, 300.f);

    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("nice_music.ogg"))
     //   return EXIT_FAILURE;
    // Play the music
    //music.play();
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
                //window.draw(Exit);
                selection = selection + 1;
                printf("here2\n");
            }

            if(selection == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                return(0);
            }

            // left key is pressed: move our character
            if(selection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {   Start.setFillColor(sf::Color(255,255,255));
                //window.draw(Start);
                selection = selection + 1;
                printf("here1\n");
            }

            if(selection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {   
                menu = true;
            }
            

        if(menu == true){
            // moves the sprite
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                snakeSprite.move(-5.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                snakeSprite.move(5.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                snakeSprite.move(0.f, -5.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                snakeSprite.move(0.f, 5.f);
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


        // Draw the sprite
        window.draw(sprite);
        if(menu == true)
        {
            // Draw the snake
            window.draw(snakeSprite);
        }

        // Draw the string
        if( menu == false)
        {
        window.draw(text);
        window.draw(Start);
        window.draw(Exit);
        }
        // Update the window
        window.display();

        }
    
    }
    return EXIT_SUCCESS;
}