#ifndef ICAGAC_HPP
#define ICAGAC_HPP

#include <iostream>
#include <string>
#include <IcDugum.hpp>

class IcAgac{
private:
	IcDugum* kokDugum;
	IcDugum* Insert(std::string, int, IcDugum*);
	IcDugum* NewNode(int, std::string);
	void PostOrder(IcDugum*);
	IcDugum* llDonustur(IcDugum* &t);
	IcDugum* rrDonustur(IcDugum* &t);
	IcDugum* rlDonustur(IcDugum* &t);
	IcDugum* lrDonustur(IcDugum* &t);
	int height(IcDugum* t);
public:
	IcAgac();
	void Insert(std::string, int);
	void PostOrder();
	bool Bosmu() const;
	void Temizle();
	bool DugumSil(IcDugum* &alt_Dugum);
	~IcAgac();
};

#endif