#include <iostream>
#include <random>

class FiniteStateMachine;

class GenericState {
public:
	GenericState(){};

	virtual void OnEnter() = 0;
	virtual void Tick() = 0;
	virtual void OnExit() = 0;
};

class state_1 : public GenericState {
public:
	state_1() : GenericState() {};
	void OnEnter() {
		std::cout << "Entered State 1" << std::endl;
	}

	void Tick() {
		
	}

	void OnExit() {
		std::cout << "Left State 1" << std::endl;
	}
};

class state_2 : public GenericState {
public:
	state_2() : GenericState() {};
	void OnEnter() {
		std::cout << "Entered State 2" << std::endl;
	}

	void Tick() {
		
	}

	void OnExit() {
		std::cout << "Left State 2" << std::endl;
	}
};

class FiniteStateMachine {
private:
	GenericState * currentState;
public:
	FiniteStateMachine() {};

	void start() {
		changeState(new state_1);
	}

	void update() {
		currentState->Tick();
	}
	void changeState(GenericState * newState) {

		if (currentState != nullptr)
			currentState->OnExit();

		currentState = newState;

		currentState->OnEnter();
	}
};

FiniteStateMachine * FSM = new FiniteStateMachine();

int main() {

	FSM->start();
	while (true) {
		FSM->update();
	}

	return 1;
};