#include <iostream>
#include "state.cpp"
#include "machine.cpp"

class state_1 : public State {
private:
	FiniteStateMachine _fsm;

public:
	state_1() : State() {};

	void OnEnter() {
		std::cout << "entered State1" << std::endl;
	};

	void Tick() {
		int randomValue = rand() % 2;
		if (randomValue == 1) {
			_fsm.changeState(new state_2);
		}
	};

	void OnExit() {
		std::cout << "left State1" << std::endl;
	}

};