#include <SFML/Graphics.hpp>

struct RigidBody
{
    enum ColliderType : unsigned char { NONE, CIRCLE, BOX };
    RigidBody(ColliderType collider_type, const sf::Vector2f &position = {0, 0}, float rotation = 0, float mass = 1);

    [[nodiscard]] sf::Vector2f getPosition() const { return m_position; }
    [[nodiscard]] float getRotation() const { return m_rotation; }
    [[nodiscard]] float getBoundingRadius() const { return m_bounding_radius; }
    [[nodiscard]] unsigned char getColliderType() const { return m_collider_type; }

    void setPosition(const sf::Vector2f &position) { m_position = position; }
    void setRotation(float rotation) { m_rotation = rotation; }
    void setBoundingRadius(float radius) { m_bounding_radius = radius; }
    void setColliderType(ColliderType type) { m_collider_type = type; }
    void setVelocity(const sf::Vector2f &velocity) { m_previous_position = m_position - velocity; }

    void applyForce(const sf::Vector2f &force) { applyAcceleration(force / m_mass); }
    void applyAcceleration(const sf::Vector2f &acceleration);

  private:
    ColliderType m_collider_type;
    float m_mass;
    sf::Vector2f m_previous_position;
    sf::Vector2f m_position;
    float m_previos_rotation;
    float m_rotation;
    float m_bounding_radius;
};
