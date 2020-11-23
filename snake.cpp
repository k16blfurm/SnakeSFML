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
    float timer=0, delay=0.1;
    window.setFramerateLimit(60);



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
        float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time; 


        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear screen
        window.clear();


            // left key is pressed: move our character
            if(selection == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {   Start.setFillColor(sf::Color(255,255,255));
                window.draw(Start);
                selection = selection + 1;
                printf("here1\n");
            }
            if(selection == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                Exit.setFillColor(sf::Color(255,255,255));
                window.draw(Exit);
                selection = selection + 1;
                printf("here2\n");
            }

            if(selection == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                text.setFillColor(sf::Color(255,255,255));
                window.draw(text);
                selection = 0;
                printf("here3\n");
            }

        if(menu == true){
            // moves the sprite
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                snakeSprite.move(-1.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                snakeSprite.move(1.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                snakeSprite.move(0.f, -1.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                snakeSprite.move(0.f, 1.f);
            }   
            window.draw(snakeSprite);
        }


        if(selection == 0)
        {Exit.setFillColor(sf::Color(255,0,255));}

        if(selection == 1)
        text.setFillColor(sf::Color(255,0,255));

        if(selection == 2)
        Start.setFillColor(sf::Color(255,0,255));

        // Draw the sprite
        window.draw(sprite);
        // Draw the snake

        // Draw the string
        window.draw(text);
        window.draw(Start);
        window.draw(Exit);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}