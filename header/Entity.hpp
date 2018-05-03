#pragma once

#include <vector>
#include <typeindex>
#include <algorithm>

#include "Component.hpp"
#include "Message.hpp"

enum class E_ENTITY : unsigned char
{
  E_SHIP	= 0x01,
  E_ASTEROIDES	= 0x02,
  E_POWER_UP	= 0x03,
};

class Entity {

public:

  Entity();

  Component*	getComponent(const std::type_index& componentType);  

  void		addComponent(Component& component);
  void		sendMessage(Message& msg);
  void		update(float dt);
  
  bool		hasComponent(Component& component);
  bool		isActive() const;
  
private:
  
  std::vector<Component*>	m_components;
  int				m_handle;
  bool				m_isActive;
  
};
