#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Node.hpp"
#include "Iterator.hpp"
using namespace std;

class List {
private:
	Node* ListeOrta;
	int boyut;
	Iterator IterateFromFirstNode() const;
public:
	List();
	bool BosMu() const;
	int Buyukluk() const;
	Node* getListeOrta() const;
	void Ekle(const int*, const int&);
	void Caprazla(const int*, const int&);
	int* OrtaHaricDondurVeTemizle();
	friend ostream& operator<<(ostream&, List&);
	void Clear();
	~List();
};

#endif