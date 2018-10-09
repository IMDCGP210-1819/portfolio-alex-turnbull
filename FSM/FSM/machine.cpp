#include "state.cpp"

class FiniteStateMachine {
private:
	State * currentState;
public:
	FiniteStateMachine() {

	};

	void start() {
		changeState(new state_1);
	}

	void update() {
		currentState->Tick();
	}
	void changeState(State * newState) {

		if (currentState != nullptr)
			currentState->OnExit();

		currentState = newState;

		currentState->OnEnter();
	}
};