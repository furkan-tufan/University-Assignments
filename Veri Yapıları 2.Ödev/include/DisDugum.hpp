#ifndef DISDUGUM_HPP
#define DISDUGUM_HPP

#include <iostream>
#include <string>

#include <IcAgac.hpp>

class DisDugum {
public:
	std::string firmaIsmi;
	int calisanSayisi;
	int derinlik;
	IcAgac* calisanlar;
	DisDugum* sagCocuk;
	DisDugum* solCocuk;
	DisDugum(std::string, int);
	DisDugum();
	~DisDugum();
};

#endif