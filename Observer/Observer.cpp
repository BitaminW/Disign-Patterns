#include <iostream>
#include <list>
#include <string>

class IObserver {
public:
	virtual ~IObserver() {};
	
	virtual void Update(const std::string& message_from_subject) = 0;
};


class ISubject{
public:
	virtual ~ISubject() {};

	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};

class Subject : public ISubject{
public:
	virtual ~Subject() {
		std::cout << "Goodbye, I was the Subject.\n";
	}

};


int main() {


	return 0;
}
