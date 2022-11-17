#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char * argv[])

{  
    //create a new window of size w*h
    //top left of window is (0,0) botton right is (w,h)
    const int wWidth = 1280;
    const int wHeight = 720;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works homie!");
    window.setFramerateLimit(60);

    int r = 0;
    int g = 255;
    int b = 255;

    //make a shape to draw 
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color(r, g, b));
    circle.setPosition(300.0f, 300.0f);         //set top left circle start pos
    float circleMoveSpeed = 0.01f;              //0.01 pixels per frame x 60fps and 6 pixels per second.

    float rx = 300;
    float ry = 200;
    sf::Vector2f rSize(rx, ry);
    sf::RectangleShape rect(rSize);
    rect.setPosition(100, 5);
    rect.setFillColor(sf::Color(255, 255, 0));
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(20);

    sf::RectangleShape rect2(rSize);
    rect2.setPosition(400, 200);
    rect2.setFillColor(sf::Color(255, 0, 0));

     // let's load a font so we can display some text!

    sf::Font myFont;
    
   // attempt to load the font from a file.
    if (!myFont.loadFromFile("bin/Roboto/Roboto-Regular.ttf"))
    {
        //if we can't load the font, print an error to the error console and exit.
        std::cerr << "Could not load font!\n";
        exit(-1);
    }

    sf::Text text("Sample Text", myFont, 24);

    text.setPosition(0, wHeight - (float)text.getCharacterSize());

    std::vector<sf::CircleShape> circles;
    circles.push_back(circle);
    std::vector<sf::RectangleShape> rectangles;

    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            sf::RectangleShape rect(sf::Vector2f(15, 15));
            rect.setPosition(x*20, y*20);
            rect.setFillColor(sf::Color(x*10, y*10, 0));
            rectangles.push_back(rect);

        }
    }

    //main loop -- continues for each frame while window is open
    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // this event triggers when the window is closed.
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }


            if (event.type == sf::Event::KeyPressed)
            {
                // print the key that was pressed to the console
                std::cout << "Key pressed with code = " << event.key.code << "\n";
                if (event.key.code == sf::Keyboard::X)
                {
                    window.close();
                }
            }
        }

        // basic animation -- move each frame if it's still in frame
        float sx = 0.5f;
        float sy = 0.5f;
        circle.setPosition(circle.getPosition().x + sx, circle.getPosition().y + sy);


        // basic rendering function calls
        window.clear();

        for (auto& circle : circles)
        {
            window.draw(circle);
        }

        for (auto& rect : rectangles)
        {
            window.draw(rect);
        }
        window.draw(text);
        window.display();
    }

    return 0;
}