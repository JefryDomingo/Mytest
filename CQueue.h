/*
 * CQueue.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_

#include "IDataStructure.h"

template<class T>
class CQueue: public IDataStructure<T> {
public:
	CQueue() {
		CNode<T>* temp=this->proot;
		CSimpleNode<T>* nuevoNodo= new CSimpleNode<T>(data);
	
		nuevoNodo->setLink(LINKS::next,NULL);

	if(this->proot==NULL)
	{
		while(temp->getLink(LINKS::next)!=NULL)
		{
			temp=temp->getLink(LINKS::next);
		}
		nuevoNodo->setLink(LINKS::back,temp);
		temp->setLink(LINKS::next,nuevoNodo);

	}
	else
	{
		this->proot=nuevoNodo;
	}

	}
	~CQueue() {

	}
	void insert(T) {

	}
	void erase(T) {

	}
	bool search(T) {

	}
	void clear() {

	}
	void show(std::ostream& out) {
		CNode<T> * temp = this->proot;
		while (temp->getLink(LINKS::next) != 0) {
			out << temp->getData() << " -- "; // devuelve un object, int, float o cualquier tipo
			temp = temp->getLink(LINKS::next);
		}
		out << temp->getData() << std::endl;

	}
};

#endif /* CQUEUE_H_ */
