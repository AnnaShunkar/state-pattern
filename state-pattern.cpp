#include <iostream>
using namespace std;
class State {
public:
	virtual void handle() = 0;
	virtual ~State() = default;
};
class StateA : public State {
public:
	void handle() override {
		cout << "handling State A" << endl;
	}
};
class StateB : public State {
public:
	void handle() override {
		cout << "handling State B" << endl;
	}
};
class Context {
private:
	State* currentState = nullptr;
public:
	void setState(State* s) {
		currentState = s;
	}
	void request() {
		if (currentState)
			currentState->handle();
	}
};
int main() {
	Context context;
	StateA stateA;
	StateB stateB;

	context.setState(&stateA);
	context.request();
	context.setState(&stateB);
	context.request();
	return(0);
}