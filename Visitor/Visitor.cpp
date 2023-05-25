#include <iostream>

// 클래스 전방선언
class ConcreteComponentA;
class ConcreteComponentB;


// interface
class Visitor{
public:
	virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
	virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;

};
	


