#include <SFML/Graphics.hpp>

#include "Physics/RigidBody.h"
#include "Rendering/display.h"

int main()
{
    constexpr unsigned int rb_count = 10;

    Display display({800, 600}, "Renderdisplay", sf::Style::None, sf::State::Windowed);

    while (display.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            display.close();

        display.clear();
        display.render();
        display.display();
    }
}
