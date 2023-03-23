#include <iostream>

struct SharedState{
	std::string _brand;
	std::string _model;
	std::string _color;

	SharedState(const std::string& brand, const std::string& model, std::string& color) 
					: _brand(brand), _model(model), _color(color) { }


};
