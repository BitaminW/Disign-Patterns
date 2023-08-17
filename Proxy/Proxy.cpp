#include <iostream>

// 인터페이스
class ISubject {
public:
	virtual void Request() const = 0;
};

class Subject : ISubject{
public:
	void Request() const override {
		std::cout << "Subject: Handling request.\n";
	}
};

class Proxy : public ISubject {
private:
	Subject* _subject;

	bool CheckAccess() const {
		std::cout << "Proxy: Checking access prior to firing a real request.\n";
		return true;
	}
	void LogAcccess() const {
		std::cout << "Proxy: Logging the time of request.\n";
	}

public:
	Proxy(Subject* subject) : _subject(new Subject(*subject)) {}

	~Proxy() {
		delete _subject;
	}

	void Request() const override {
		if (this->CheckAccess()) {
			this->_subject->Request();
			this->LogAcccess();
		}
	}
};

void ClientCode(const ISubject& subject) {
	// ...
	subject.Request();
	// ...
}

int main() {
	std::cout << "Client: Executing the client code with a real subject:\n";
	Subject* subject = new Subject;
	ClientCode(*subject);

	std::cout << "\n";
	std::cout << "Client: Executing the same client code with a proxy:\n";

	Proxy* proxy = new Proxy(subject);
	ClientCode(*proxy);

	delete subject;
	delete proxy;

	return 0;
}

