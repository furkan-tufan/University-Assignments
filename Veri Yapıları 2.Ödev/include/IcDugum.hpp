#ifndef ICDUGUM_HPP
#define ICDUGUM_HPP

#include <iostream>
#include <string>

class IcDugum {
public:
	std::string isim;
	int basladigiYil;
	int derinlik;
	IcDugum* sagCocuk;
	IcDugum* solCocuk;
	IcDugum(std::string, int);
	IcDugum();
};

#endif