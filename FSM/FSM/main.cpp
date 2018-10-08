#include <iostream>
#include <random>

int main() {
	FiniteStateMachine * FSM;
	FSM = new FiniteStateMachine;
	FSM->start();
	while (true) {
		FSM->update();
	};
}

class State {
private:
	FiniteStateMachine * fsm;

public:
	State(FiniteStateMachine fsm)
	{
		State fsm = fsm;
	};

	void OnEnter();
	void Tick();
	void OnExit();

};

class state_1 : public State {
private:
	FiniteStateMachine * fsm;

public:
	state_1() : State()
	{
		this->fsm = fsm;
	};

	void OnEnter() {
		std::cout << "entered State1" << std::endl;
	};

	void Tick() {
		int randomValue = rand() % 2;
		if (randomValue == 1) {
			fsm->changeState(new state_2);
		}
	};

	void OnExit() {
		std::cout << "left State1" << std::endl;
	}

};

class state_2 : public State {
private:
	FiniteStateMachine * fsm;

public:
	state_2() : State(){
		this->fsm = fsm;
	};

	void OnEnter() {
		std::cout << "entered State1" << std::endl;
	};

	void Tick() {
		int randomValue = rand() % 2;
		if (randomValue == 1) {
			fsm->changeState(new state_1);
		}
	};

	void OnExit() {
		std::cout << "left State1" << std::endl;
	}

};


class FiniteStateMachine {
private:
	State * currentState;
public:
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

