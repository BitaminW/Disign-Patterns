#include <iostream>
#include <string_view>

class Strategy{
public:
	virtual ~Strategy() = default;
	virtual std::string doAlogorithm(std::string_view data) const = 0;

};

