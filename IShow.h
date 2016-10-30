#ifndef ISHOW_H_
#define ISHOW_H_

#include <iostream>
template<class T>
class IShow {
protected:
	IShow() {
	}
	~IShow() {
	}
public:
	virtual void show(std::ostream&)=0;
};

#endif /* ISHOW_H_ */

