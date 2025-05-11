#include <SFML/Graphics.hpp>

#include "../Rendering/display.h"
#include "RigidBody.h"

class Simulation
{
  public:
    Simulation(float time_step = 0.1, unsigned int iterations = 0, Display *diaplay = nullptr);
    void initialize();

    void addRigidBody(RigidBody &rb);
    void removeRigidBody(RigidBody &rb);

    void run();

    void addDisplay(Display *display) { m_display = display; }
    void iterationCap(unsigned int cap) { m_iteration_cap = cap; }

  private:
    sf::Clock m_clock;
    Display *m_display;
    float m_time_step;

    unsigned int m_iterations;
    unsigned int m_iteration_cap;
    float m_elapsedTime;

    void integrate(RigidBody &rb);
};
