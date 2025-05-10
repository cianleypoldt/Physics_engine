#include "RigidBody.h"

RigidBody::RigidBody(ColliderType collider_type, const sf::Vector2f &position, float rotation, float mass)
    : m_collider_type(collider_type), m_position(position), m_rotation(rotation)
{
}

void RigidBody::applyAcceleration(const sf::Vector2f &acceleration)
{
    sf::Vector2f current = m_position;

    m_position = 2.0f * m_position - m_previous_position + acceleration;
    m_previous_position = current;
}
