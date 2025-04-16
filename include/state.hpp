#pragma once

namespace state {
class State {
public:
  virtual void Init() = 0;
  virtual void HandleInput() = 0;
  virtual void Update() = 0;
  virtual void Draw(const float dt) = 0;
  virtual void Pause() = 0;
  virtual void Resume() = 0;
};
} // namespace state
