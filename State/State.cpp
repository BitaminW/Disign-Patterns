#include <iostream>
#include <typeinfo>

class Context;  // 클래스 전방선언

class State {
protected:
	Context* context;

public:
	virtual ~State() {}

	void set_context(Context* context) {
		this->context = context;
	}

	virtual void Handle1() = 0;
	virtual void Handle2() = 0;

};

class Context {
private:
	State* state;

public:
	Context(State* state) : state(nullptr) { this->TransitionTo(state); }
	~Context() { delete state; }

	void TransitionTo(State* state) {
		std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
		if (this->state != nullptr)
			delete this->state;
		this->state = state;
		this->state->set_context(this);
	}

	void Request1() {
		this->state->Handle1();
	}
	void Request2() {
		this->state->Handle2();
	}
};

class ConcreteStateA : public State {
public:
	void Handle1() override;

	void Handle2() override {
		std::cout << "ConcreteStateA handles request2.\n";
	}
};

class ConcreteStateB : public State {
public:
	void Handle1() override {
		std::cout << "ConcreteStateB handles request1.\n";
	}
	void Handle2() override {
		std::cout << "ConcreteStateB handles request2.\n";
		std::cout << "ConcreteStateB wants to change the state of the context.\n";
		this->context->TransitionTo(new ConcreteStateA);
	}
};

void ConcreteStateA::Handle1() {
	{
		std::cout << "ConcreteStateA handles request1.\n";
		std::cout << "ConcreteStateA wants to change the state of the context.\n";

		this->context->TransitionTo(new ConcreteStateB);
	}
}

void ClientCode() {
	Context* context = new Context(new ConcreteStateA);
	context->Request1();
	context->Request2();
	delete context;
}

int main() {
	ClientCode();
	return 0;
}
