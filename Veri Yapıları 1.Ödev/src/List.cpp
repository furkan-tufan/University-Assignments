/**
* @file 		   List.cpp
* @description     İki Yönlü Dairesel Bağlı Listemizin sınıfını içeriyor.
* @course          2.Öğretim B Grubu
* @assignment      1.Ödev
* @date            20.11.2020
* @author          Furkan İsmet Tufan - furkan.tufan@ogr.sakarya.edu.tr
*/

#include "List.hpp"

Iterator List::IterateFromFirstNode() const {
	if (!BosMu()){
		Iterator itr(ListeOrta);
		for(int i=0; i< (boyut-1)/2 ; i++){
			itr.StepBack();
		}
		return itr;
	}
	return NULL;
}

List::List() {
	ListeOrta = NULL;
	boyut = 0;
}

bool List::BosMu() const {
	return ListeOrta == NULL;
}

int List::Buyukluk() const{
	return boyut;
}

Node* List::getListeOrta() const{
	return ListeOrta;
}

void List::Ekle(const int* obj, const int& elemanSayisi) {
	if( BosMu() == true ){ // ekle metodu yalnızca dizi boşken çalışsın istiyoruz.
		for (int i=0; i<elemanSayisi ; i++) {
			if (boyut == 0) {
				ListeOrta=new Node();
				ListeOrta->data=obj[i];
				ListeOrta->next = ListeOrta;
				ListeOrta->prev = ListeOrta;
			}
			else if(boyut <=  (elemanSayisi-1)/2){
				Iterator itr(ListeOrta);
				for(int j=0 ; j < boyut-1 ; j++){
					itr.StepBack();
				}
				Node* newPrev = itr.current->prev;
				itr.current->prev = new Node(obj[i], itr.current, newPrev);
				newPrev->next = itr.current->prev;
			}
			else if(boyut > (elemanSayisi-1)/2 ){
				Iterator itr(ListeOrta);
				for(int j=0 ; j < boyut-((elemanSayisi+1)/2) ; j++){
					itr.StepNext();
				}
				Node* newNext = itr.current->next;
				itr.current->next = new Node(obj[i], newNext, itr.current);
				newNext->prev = itr.current->next;
			}
			boyut++;
		}
	}
}

void List::Caprazla(const int* obj, const int& elemanSayisi) {
	Iterator itr(ListeOrta);
	for(int i=0; i<elemanSayisi; i++){
		if(i <  elemanSayisi/2){
			Node* newPrev = itr.current->prev;
			itr.current->prev = new Node(obj[i], itr.current, newPrev);
			newPrev->next = itr.current->prev;
			itr.StepBack();
		}
		else if(i == elemanSayisi/2 ){
			itr.current=ListeOrta;
			Node* newNext = itr.current->next;
			itr.current->next = new Node(obj[i], newNext, itr.current);
			newNext->prev = itr.current->next;
			itr.StepNext();

		}
		else{
			Node* newNext = itr.current->next;
			itr.current->next = new Node(obj[i], newNext, itr.current);
			newNext->prev = itr.current->next;
			itr.StepNext();

		}
		boyut++;
	}
}

// bu metot, orta değer haricindeki değerleri çaprazlamaya uygun bir sırayla diziye aktarıp döndürüyor ve düğümleri siliyor.
int* List::OrtaHaricDondurVeTemizle(){
	int* sayilar= new int[boyut-1]; //boyut-1 olacak çünkü listeOrta değeri dönmeyecek
	Iterator itr(ListeOrta);
	itr.StepNext();
	for(int i=0; i < boyut-1; i++){
		if(boyut-1-i > (boyut-1)/2 ){
			sayilar[i]=itr.GetCurrentData();
			itr.StepNext();
		}
		else if(boyut-1-i==(boyut-1)/2){
			itr.current=ListeOrta;
			itr.StepBack();
			sayilar[i]=itr.GetCurrentData();
			itr.StepBack();
		}
		else{
			sayilar[i]=itr.GetCurrentData();
			itr.StepBack();
		}
	}
	
	itr.current=ListeOrta;
	int adimSayisi=(boyut-1)/2;
	for(int i=0; i<adimSayisi ; i++ ){
		Node* oldNode = itr.current->prev;
		itr.current->prev = itr.current->prev->prev;
		oldNode->prev->next = oldNode->next;
		delete oldNode;
		boyut--;
	}
	for(int i=0; i<adimSayisi ; i++ ){
		Node* oldNode = itr.current->next;
		itr.current->next = itr.current->next->next;
		oldNode->next->prev = oldNode->prev;
		delete oldNode;
		boyut--;
	}
	
	return sayilar;
}

ostream& operator<<(ostream& screen, List& list) {
	if (list.BosMu())
		screen << "Liste bos";
	else {
		Iterator itr = list.IterateFromFirstNode();
		for (int index = 0; index < list.boyut; index++){
			screen << itr.GetCurrentData() << "   ";
			itr.StepNext();
		}
	}
	return screen;
}

void List::Clear(){
	Iterator itr(ListeOrta);
	int elemanSayisi=boyut;
	for(int i=0 ; i<elemanSayisi ; i++){
		Node* oldNode = itr.current->prev;
		itr.current->prev = itr.current->prev->prev;
		oldNode->prev->next = oldNode->next;
		delete oldNode;
		boyut--;
	}
}

List::~List() {
	Clear();
	delete ListeOrta;
}