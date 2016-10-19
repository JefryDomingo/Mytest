/*
 * iDataStructure.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef IDATASTRUCTURE_H_
#define IDATASTRUCTURE_H_

#include <iostream>
#include "CNode.h"
template<class T>
class IDataStructure {
protected:
	IDataStructure() {
	}
	~IDataStructure() {
	}
public:
	virtual void insert(T)=0;
	virtual void erase(T)=0;
	virtual bool search(T)=0;
	virtual void clear()=0;
	virtual void show(std::ostream&)=0;
};

class LINKS {
public:
	static const int next = 0;
	static const int back = 1;
	static const int top = 0;
	static const int down = 1;
	static const int right = 0;
	static const int left = 1;
};

#endif /* IDATASTRUCTURE_H_ */
