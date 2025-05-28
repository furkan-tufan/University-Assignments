/**
* @file 		   Node.cpp
* @description     Düğümler için kullandığımız Node sınıfını içeriyor.
* @course          2.Öğretim B Grubu
* @assignment      1.Ödev
* @date            20.11.2020
* @author          Furkan İsmet Tufan - furkan.tufan@ogr.sakarya.edu.tr
*/

#include "Node.hpp"

Node::Node(const int& data, Node* next=NULL, Node* prev=NULL) {
	this->data=data;
	this->next=next;
	this->prev=prev;
}

Node::Node() {
	data = int();
	next = NULL;
	prev = NULL;
}