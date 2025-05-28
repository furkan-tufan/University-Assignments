/**
* @file 		   Iterator.cpp
* @description     Fonksiyonlarda düğümleri göstermesi için kullandığımız Iterator sınıfını içeriyor.
* @course          2.Öğretim B Grubu
* @assignment      1.Ödev
* @date            20.11.2020
* @author          Furkan İsmet Tufan - furkan.tufan@ogr.sakarya.edu.tr
*/


#include "Iterator.hpp"
#include "Node.hpp"

Iterator::Iterator() {
	current = NULL;
}
Iterator::Iterator(Node* node) {
	current = node;
}
void Iterator::StepNext() {
	current = current->next;
}
void Iterator::StepBack() {
	current = current->prev;
}
const int& Iterator::GetCurrentData()const {
	return current->data;
}

