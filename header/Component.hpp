#pragma once

class Component {
public:
  virtual ~Component(void);

  virtual void SendMessage() = 0;
  virtual void Update(float dt) = 0;
  virtual void Init(void) = 0;
  virtual void Shutdown(void) = 0;

  bool Active(void) const;
  
private:

  int	m_idType; // type of Component
  bool	m_isActive;
};
