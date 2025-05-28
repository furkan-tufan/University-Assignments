#ifndef DISAGAC_HPP
#define DISAGAC_HPP

#include <iostream>
#include <algorithm>
#include <string>

#include <DisDugum.hpp>
#include <IcDugum.hpp>
#include <IcAgac.hpp>
class DisAgac{
private:
	DisDugum* kokDugum;
	DisDugum* Insert(std::string, int, DisDugum*);
	DisDugum* NewNode(std::string,int);
	bool Search(std::string, DisDugum*);
	DisDugum* BulVeGetir(std::string,DisDugum*);
	DisDugum* llDonustur(DisDugum* &t);
	DisDugum* rrDonustur(DisDugum* &t);
	DisDugum* rlDonustur(DisDugum* &t);
	DisDugum* lrDonustur(DisDugum* &t);
	int height(DisDugum* t);
	void PostOrder(DisDugum*);
public:
	DisAgac();
	void Insert(std::string, int);
	bool Search(std::string);
	DisDugum* BulVeGetir(std::string);
	void calisanSayisiArttir(DisDugum*);
	void PostOrder();
	bool Bosmu() const;
	void Temizle();
	bool DugumSil(DisDugum* &alt_Dugum);
	~DisAgac();
};

#endif