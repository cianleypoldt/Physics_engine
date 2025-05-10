#include <SFML/Graphics.hpp>

class Display
{
  public:
    Display(sf::Vector2u size, const char *, unsigned int, sf::State);
    ~Display();

    void addDrawable(sf::Drawable *shape);
    void render();

    bool isOpen() { return m_window.isOpen(); }
    void close() { m_window.close(); }
    void clear() { m_window.clear(); }
    void draw(sf::Drawable &drawable) { m_window.draw(drawable); }

    void display() { m_window.display(); }
    sf::Vector2u size() { return m_window.getSize(); }

  private:
    sf::RenderWindow m_window;
    std::vector<sf::Drawable *> objects;
};
