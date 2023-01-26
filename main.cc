#include <iostream>
#include <SFML/Graphics.hpp>

int main(int, char**) 
{
    std::cout << "Hello, world!\n";
    
    sf::RenderWindow app(sf::VideoMode(400,400,32),"titre");
    
    while(app.isOpen())
    {
        sf::Event e;
        while(app.pollEvent(e))
        {
            switch(e.type)
            {
            case sf::Event::Closed: 
                app.close();
                break;
            }
        }
        app.clear(sf::Color(123,178,180));
        app.display();
    }
}
