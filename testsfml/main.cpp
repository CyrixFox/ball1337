#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "SFML works!");
    
    Image im;
    im.loadFromFile("images/ball.png");

    Texture texture;
    texture.loadFromImage(im);


    Sprite ball;
    ball.setTexture(texture);
    ball.setPosition(20.0, 50.0);
    ball.scale(0.1f, 0.1f);
    
    float i = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(176, 146, 139));
        
        ball.setPosition(50, 300 - i);
        i+=0.01;
        if (i > 300) i = 0;
        window.draw(ball);
        window.display();
    }

    return 0;
}