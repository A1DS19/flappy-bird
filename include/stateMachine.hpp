#pragma once

#include <algorithm>
#include <memory>
#include <stack>
#include <state.hpp>

namespace Sonar {
typedef std::unique_ptr<state::State> StateRef;

class StateMachine {
public:
  StateMachine();
  ~StateMachine();
  void AddState(StateRef newState, bool isReplacing = true);
  void RemoveState();
  void ProcessStateChanges();
  StateRef &GetActiveState();

private:
  std::stack<StateRef> _states;
  StateRef _newState;
  bool _isRemoving;
  bool _isAdding;
  bool _isReplacing;
};
} // namespace Sonar
