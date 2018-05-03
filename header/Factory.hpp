#pragma once

#include <vector>

#include "Component.hpp"
#include "Entity.hpp"

class Factory {

public:

  Factory();
  static Component*	getComponent(unsigned int idComponent);
  static unsigned int	addComponent(Component* component);
};
