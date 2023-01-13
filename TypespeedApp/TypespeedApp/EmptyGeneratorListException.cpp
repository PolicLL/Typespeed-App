#include "EmptyGeneratorListException.hpp"
#include <string>

std::string EmptyGeneratorListException::getMessage(){
	return "Generator's list is empty ! ";
}
