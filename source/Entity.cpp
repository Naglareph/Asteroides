#include "Entity.hpp"

Entity::Entity() : m_isActive(true)
{

}

Component*	Entity::getComponent(const std::type_index& componentType)
{
  
}

void		Entity::addComponent(Component& Component)
{
  this->m_components.push_back(&Component);
}

void		Entity::sendMessage(Message& msg)
{
  
}

void		Entity::update(float dt)
{

}

bool		Entity::hasComponent(Component& component)
{
  return (std::find(this->m_components.begin(), this->m_components.end(), component) != this->m_components.end());
}

bool		Entity::isActive() const
{
  return this->m_isActive;
}
