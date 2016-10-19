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
	void erase(T) {

	}
	bool search(T) {

	}
	void clear() {

	}

	void show(std::ostream& out) {
		CNode<T> * temp = this->proot;
		while (temp->getLink(LINKS::next) != 0) {
			out << temp->getData(); // devuelve un object, int, float o cualquier tipo
			temp = temp->getLink(LINKS::next);
		}
		out << temp->getData();
	}
};

#endif /* CLISTSIMPLE_H_ */
