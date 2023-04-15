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
