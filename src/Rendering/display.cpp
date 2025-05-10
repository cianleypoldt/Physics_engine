#include "display.h"

Display::Display(sf::Vector2u size, const char *title, unsigned int Style, sf::State State)
    : m_window(sf::VideoMode(size), title, Style, State)
{
    m_window.setVerticalSyncEnabled(true);
    m_window.setFramerateLimit(60);
    m_window.setPosition({0, 0});
}

Display::~Display()
{
    return;
}

void Display::addDrawable(sf::Drawable *shape)
{
    objects.push_back(shape);
}

void Display::render()
{
    for (auto &drawable : objects)
    {
        m_window.draw(*drawable);
    }
}
