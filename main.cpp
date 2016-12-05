/*
 * main.cpp
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#include "CListSimple.h"
#include "CListDouble.h"
#include "CListCircular.h"
#include "CStack.h"
#include "CTree.h"
#include "CQueue.h"
#include <map>

class object {
protected:
	int dato1;
	int dato2;
public:
	object() {

	}
	object(int data1, int data2) {
		dato1 = data1;
		dato2 = data2;
	}
	int getDato1() {
		return dato1;
	}

	int getDato2() {
		return dato2;
	}

	void operator =(const object &obj) {
		this->dato1 = obj.dato1;
		this->dato2 = obj.dato2;
	}
};

void operator <<(std::ostream &out, object data) {
	out << data.getDato1() << "--" << data.getDato2() << std::endl;
}

class dato2D {
protected:
	int x, y;
public:
	dato2D() {

	}
	dato2D(int _X, int _Y) {
		x = _X;
		y = _Y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

void operator <<(std::ostream& out, dato2D object) {
	out << "X:" << object.getX() << "-- Y:" << object.getY() << std::endl;
}

int main() {
	/*
	 * Deben de implementar los metodos restantes para que funcione la
	 * pila, cola, lista doblemente enlazada y circular, probar con diversos
	 * tipos de datos.
	 */
	CListSimple<int> mySimpleList;
	mySimpleList.insert(400);
	mySimpleList.insert(500);
	mySimpleList.insert(100);
	mySimpleList.insert(200);
	mySimpleList.insert(300); // observar esto !!!!
	mySimpleList.insert(400);
	mySimpleList.insert(500);
	mySimpleList.insert(400);
	mySimpleList.insert(500);
	mySimpleList.insert(400);
	mySimpleList.insert(400);
	mySimpleList.show(std::cout);
	mySimpleList.erase(400);
	mySimpleList.show(std::cout);
	std::cout<<mySimpleList.search(600)<<std::endl;
	mySimpleList.clear();
	std::cout << std::endl;
	CStack<int> myStack;
	myStack.insert(100);
	myStack.insert(555);
	myStack.insert(777);
	myStack.insert(458);
	myStack.insert(333);
	myStack.insert(999);
	myStack.insert(789);
	std::cout<<myStack.search(999)<<std::endl;
	myStack.show(std::cout);
	myStack.clear();
	myStack.show(std::cout);
	std::cout << std::endl;
	CQueue<int> myQueue;
	myQueue.insert(123);
	myQueue.insert(321);
	myQueue.insert(546);
	myQueue.insert(354);
	myQueue.insert(456);
	myQueue.insert(777);
	myQueue.insert(453);
	myQueue.show(std::cout);
	myQueue.clear();
	std::cout<<myQueue.search(222)<<std::endl;
	myQueue.show(std::cout);
	/*
	 * Pero la verdadera tarea es que las siguientes de lineas de codigo
	 * funcionen, esto ocurre cuando deseo ingresar otros tipos de datos
	 * no primitivos (object), el metodo show falla a menos que implementemos una sobrecarga de operador <<
	 * Esto significa que debemos de sobrecargar el operador por cada clase nueva que queramos insertar.
	 */
/*	CListSimple<object> myObjectSimpleList;
	myObjectSimpleList.insert(object(100, 100));
	myObjectSimpleList.insert(object(200, 200));
	myObjectSimpleList.insert(object(300, 300));
	myObjectSimpleList.insert(object(400, 400));
	myObjectSimpleList.insert(object(500, 500));
	 myObjectSimpleList.show(std::cout);*/
	/*
	 * El problema se agrava cuando queremos almacenar punteros, el método show imprime las direcciones de memoria de
	 * los datos, no podemos cambiar la implementación de show para cada tipo de dato sea puntero o no.
	 * Por ello el método show debe de ser eliminado y reemplazado por iteradores para su recorrido o utilizar un
	 * metodo show en el nodo que permita la impresion del contenido del nodo
	 */
	/*CListSimple<dato2D*> myDato2DSimpleList;
	myDato2DSimpleList.insert(new dato2D(12, 12));
	myDato2DSimpleList.insert(new dato2D(13, 14));
	myDato2DSimpleList.insert(new dato2D(15, 16));
	myDato2DSimpleList.show(std::cout);

	std::map<std::string, object> datos;
	datos.insert(std::pair<std::string, object>("Primero", object(100, 100)));
	 std::cout << datos["Primero"].getDato1();*/

	return 0;
}
