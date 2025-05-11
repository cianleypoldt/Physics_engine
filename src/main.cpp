#include <SFML/Graphics.hpp>

#include "Physics/RigidBody.h"
#include "Rendering/display.h"

int main()
{
    Display display({800, 600}, "Renderdisplay", sf::Style::None, sf::State::Windowed);

    RigidBody rigidbody(RigidBody::ColliderType::CIRCLE, {100, 100});

    rigidbody.applyAcceleration({10, 0});

    while (display.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            display.close();

        display.clear();
        display.render();
        display.display();
    }
}
