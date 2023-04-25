#include <iostream>
#include <string_view>

class Strategy{
public:
	virtual ~Strategy() = default;
	virtual std::string doAlogorithm(std::string_view data) const = 0;

};

class Context {
private:
	std::unique_ptr<Strategy> strategy_;

public:
	explicit Context(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy)) {

	}
};
