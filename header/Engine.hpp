#pragma once

#include "Systems.hpp"

class Engine {

public:

  void Update(float dt);
  void MainLoop(void);
  void Add();

private:
  std::vector<System*> m_systems;
}
