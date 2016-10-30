/*
 * CListSimple.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CLISTSIMPLE_H_
#define CLISTSIMPLE_H_

#include "CList.h"

template<class T>
class CListSimple: public CList<T> {

public:
	CListSimple() {
		this->proot = 0;
	}
	~CListSimple() {

	}
	void insert(T dato) {
		CSimpleNode<T> * _new = new CSimpleNode<T>(dato);
		if (this->proot == 0) {
			this->proot = _new;

		} else {
			CNode<T> *temp = this->proot;
			while (temp->getLink(LINKS::next) != 0) {
				temp = temp->getLink(LINKS::next);
			}
			temp->setLink(LINKS::next, _new);
		}
	}

	void erase(T data) {
		CNode<T>* temp1, *temp2;
		temp1 = this->proot;
		temp2 = this->proot;
		while (temp1 != 0) {
		    if (temp1->getData() == data) {
			    if (temp1 == this->proot) {
				    std::cout << "data " << temp1->getData()
						    << " is equal and is root" << std::endl;
				    temp2 = temp1->getLink(LINKS::next);
				    this->proot = temp2;
				    delete temp1;
				    temp1 = this->proot;
			    }
			    else {
				    if (temp1->getLink(LINKS::next) != 0) {
					    temp2->setLink(LINKS::next,   temp1->getLink(LINKS::next));
					    delete temp1;
					    temp1 = temp2->getLink(LINKS::next);
				    } else {
					    std::cout<<"is a final node ";
					    temp2->setLink(LINKS::next, 0);
					    delete temp1;
					    temp1=0;
				    }
			    }
		    }
		    else {
			temp2 = temp1;
			temp1 = temp1->getLink(LINKS::next);
		    }
	    }
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

#endif /* CLISTSIMPLE_H_ */
