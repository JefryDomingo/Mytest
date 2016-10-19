/*
 * CTree.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CTREE_H_
#define CTREE_H_

#include "IDataStructure.h"

template<class T>
class CTree: public IDataStructure<T> {
public:
	CTree() {

	}
	virtual ~CTree() {

	}
	virtual void insert(T)=0;
	virtual void erase(T)=0;
	virtual bool search(T)=0;
	virtual void clear()=0;
	virtual void show(std::ostream&)=0;
};

#endif /* CTREE_H_ */
