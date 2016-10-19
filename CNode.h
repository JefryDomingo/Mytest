/*
 * CNode.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CNODE_H_
#define CNODE_H_

template<class T>
class CNode {
protected:
	T data;
	int numLinks;
	CNode<T>** pointers;
public:
	virtual T getData() {
		//Why protected elements needs this to perform correctly
		//http://stackoverflow.com/questions/605497/accessing-inherited-variable-from-templated-parent-class
		return this->data;
	}
	virtual CNode<T>* getLink(int _link) {
		return this->pointers[_link];

	}
	virtual void setLink(int _link, CNode<T>* _temp) {
		this->pointers[_link] = _temp;
	}
	CNode(T _data, int _links) {
		data = _data;
		numLinks = _links;
		pointers = new CNode<T>*[_links];
		for (int iter = 0; iter < _links; iter++) {
			pointers[iter] = 0;
		}
	}
	virtual ~CNode() {

		for (int iter = 0; iter < numLinks; iter++) {
			pointers[iter] = 0;
		}
		delete[] pointers;
	}
};

template<class T>
class CSimpleNode: public CNode<T> {
public:
	CSimpleNode(T _data) :
			CNode<T>(_data, 1) {
	}
};

template<class T>
class CDoubleNode: public CNode<T> {
public:
	CDoubleNode(T _data) :
			CNode<T>(_data, 2) {
	}
};

#endif /* CNODE_H_ */
