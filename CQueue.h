/*
 * CQueue.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_
#include "CNode.h"
#include "IDataStructure.h"

template<class T>
class CQueue: public IDataStructure<T> {
protected:
	CNode<T>*proot;
public:
	CQueue() {
		this->proot=0;
	}
	~CQueue() {

	}
	void insert(T data) {
		if(this->proot==NULL){
			CSimpleNode<T> *aux= new CSimpleNode<T>(data);
			this->proot=aux;
		}
		else{
			CSimpleNode<T> *aux= new CSimpleNode<T>(data);
			CNode<T>*temp=this->proot;
			while(temp->getLink(LINKS::next)){
				temp=temp->getLink(LINKS::next);
			}
			temp->setLink(LINKS::next,aux);
		}
	}
	void erase(T) {
	
	}
	bool search(T data) {
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
		if(this->proot==NULL){
			std::cout<<"No data papu"<<std::endl;
		}
		if(this->proot==this->proot->getLink(LINKS::down)){
			std::cout<<this->proot->getData()<<std::endl;
		}else{
				CNode<T> *temp;
				temp=this->proot->getLink(LINKS::next);
				delete this->proot;
				this->proot=temp;
			}
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
