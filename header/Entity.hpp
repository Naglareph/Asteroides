#pragma once

#include <vector>
#include <typeindex>

#include "Component.hpp"

class Entity {

public:

  Entity();

  Component*	getComponent(const std::type_index& componentType);  
  void		addComponent(Component& component);
  bool		hasComponent(Component& component);
  
private:
  
  std::vector<Component*> m_components;
  
};
