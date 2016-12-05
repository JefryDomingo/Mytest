/*
 * CStack.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CSTACK_H_
#define CSTACK_H_
#include "CNode.h"
#include "IDataStructure.h"

template<class T>
class CStack: public IDataStructure<T> {
protected:
	CNode<T>*proot;
public:
	CStack() {
		this->proot=0;
	}
	~CStack() {

	}
	void insert(T data) {
		if(this->proot==NULL){
			CSimpleNode<T> * aux= new CSimpleNode<T>(data);
			this->proot=aux;			
		}
		else{
			CSimpleNode<T> * nuevoNodo= new CSimpleNode<T>(data);	
			CNode<T>*temp=this->proot;
			this->proot=nuevoNodo;
			nuevoNodo->setLink(LINKS::next,temp);
		}
	}
	void erase(T) {
	
	}
	bool search(T  data) {
		CNode<T>* temp=this->proot;
		int cont=0;
		int cont2=0;
		while(temp){
			if(temp->getData()==data){
				return true;
				cont2++;
			}
			temp=temp->getLink(LINKS::next);
			cont++;
		}
		if(cont2==0)
			return false;
	}
	void clear() {
		CNode<T> *temp=this->proot;
		this->proot=this->proot->getLink(LINKS::next);
		delete temp;
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

#endif /* CSTACK_H_ */
