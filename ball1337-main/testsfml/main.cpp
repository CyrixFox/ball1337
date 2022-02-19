#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>

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
    ball.setPosition(0.0, 400.0);
    ball.scale(0.1f, 0.1f);
    
    double t = 0, x0 = 0, y0 = 400, a, v, x = 0, y, a1;
    cout << "Input v0: ";
    cin >> v;
    cout << "Input angle: ";
    cin >> a1;
    a = a1 * 3.14159 / 180.0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(176, 146, 139));
        if (x < 595)
        {
            x = x0 + v * cos(a) * t;
            y = y0 - v * sin(a) * t + 9.81 * 0.5 * t * t;
            t += 0.001;
        }
        ball.setPosition(x, y);
        window.draw(ball);
        window.display();
    }

    return 0;
}