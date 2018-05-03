class System {
public:

  // All systems must update during each game loop.
  virtual void Update(float dt) = 0;

  // Good practice to separate Initialization from the rest
  virtual void Init(void) = 0;

  virtual ~System() {}
};
