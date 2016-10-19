/*
 * CList.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CLIST_H_
#define CLIST_H_
#include "IDataStructure.h"
#include "CNode.h"

template<class T>
class CList: public IDataStructure<T> {

protected:
	CNode<T>* proot;
public:
	CList() {
	}
	;
	virtual ~CList() {
	}
	;
	virtual void insert(T)=0;
	virtual void erase(T)=0;
	virtual bool search(T)=0;
	virtual void clear()=0;
	virtual void show(std::ostream&)=0;
};

#endif /* CLIST_H_ */
