#include <iostream>
#include <algorithm>
#include <list>
#include <string>

class Component {
protected:
	Component* m_parent;

public:
	virtual ~Component() {}
	void SetParent(Component* _parent) {
		this->m_parent = _parent;
	}
};
