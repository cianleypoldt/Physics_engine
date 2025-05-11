#include "Simulation.h"

Simulation::Simulation(float time_step, unsigned int iterations, Display *diaplay)
    : m_display(), m_time_step(time_step), m_iteration_cap(iterations)
{
}

void Simulation::removeRigidBody(RigidBody *rb)
{
    for (int i = 0; i < m_rigidBodies.size(); i++)
    {
        if (m_rigidBodies[i] == rb)
        {
            m_rigidBodies.erase(m_rigidBodies.begin() + i);
            return;
        }
    }
}

void Simulation::run()
{
    for (int i = 0; i < m_iteration_cap; i++)
    {
        step();
        m_iterations++;
    }
}

void Simulation::step() {}

void Simulation::handleCollisions()
{
    for (int rb_a = 0; rb_a < m_rigidBodies.size(); rb_a++)
    {
        for (int rb_b = 0; rb_b < m_rigidBodies.size(); rb_b++)
        {
            if (checkCollision(m_rigidBodies[rb_a], m_rigidBodies[rb_b]))
                collide(m_rigidBodies[rb_a], m_rigidBodies[rb_b]);
        }
    }
}

bool Simulation::checkCollision(RigidBody *rb_a, RigidBody *rb_b)
{
    sf::Vector2f diff = rb_a->getPosition() - rb_b->getPosition();
    if (diff.x * diff.x + diff.y * diff.y > rb_a->getBoundingRadius() + rb_b->getBoundingRadius())
        return false;
    if (rb_a->getColliderType() == RigidBody::ColliderType::CIRCLE &&
        rb_b->getColliderType() == RigidBody::ColliderType::CIRCLE)
        return true;
    if (rb_a->getColliderType() == RigidBody::ColliderType::BOX)
    {
    }
}

void Simulation::collide(RigidBody *rb_a, RigidBody *rb_b) {}

void Simulation::integrate(RigidBody *rb) {}
