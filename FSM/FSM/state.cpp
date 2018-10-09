#include "machine.cpp"

class State {
private:
	FiniteStateMachine _fsm;

public:
	State(FiniteStateMachine fsm) : _fsm(fsm) {};

	void OnEnter();
	void Tick();
	void OnExit();

};