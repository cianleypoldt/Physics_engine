#include <SFML/Graphics.hpp>

#include "../Rendering/display.h"
#include "RigidBody.h"

class Simulation
{
  public:
    Simulation(float time_step = 0.1, unsigned int iterations = 0, Display *diaplay = nullptr);

    void addRigidBody(RigidBody *rb) { m_rigidBodies.push_back(rb); }
    void removeRigidBody(RigidBody *rb);

    void setTimestep(float timestep) { m_time_step = timestep; }
    void addDisplay(Display *display) { m_display = display; }
    void iterationCap(unsigned int cap) { m_iteration_cap = cap; }

    void run();

  private:
    sf::Clock m_clock;
    Display *m_display;
    float m_time_step;

    unsigned int m_iterations;
    unsigned int m_iteration_cap;
    float m_elapsedTime;

    std::vector<RigidBody *> m_rigidBodies;

    void step();
    void handleCollisions();

    bool checkCollision(RigidBody *rb_a, RigidBody *rb_b);
    void collide(RigidBody *rb_a, RigidBody *rb_b);
    void integrate(RigidBody *rb);
};
