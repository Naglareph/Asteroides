#pragma once

// This class is specialy designed to avoid numerous file inclusions and have better performing way
// of using all the entites in the programm.
// It's currently the most basic form it can be in.
// Later on, it'll have a Listener and a Messenger with specific function for the Listener.

class Message {

public:

  int	m_id; // @todo should be an ENUM;
  auto	payload; // according to the type of message, we will have different kinds of payloads
  
};
