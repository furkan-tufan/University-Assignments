#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Node.hpp"
using namespace std;

class Iterator {
public:
	Node* current;
	Iterator();
	Iterator(Node*);
	void StepNext();
	void StepBack();
	const int& GetCurrentData()const;
};

#endif