#pragma once
#include <sstream>

template <class T>
class Queue
{
	template <typename T1> friend std::ostream& operator<< (std::ostream&, const Queue<T1>&);	// обьявляется оператор вывода, "дружим" со стандартным оператором вывода
private:
	class Node;	// обьвляем элемент очереди
	Node* first;	// обьявляем первый элемент очереди(указатель)
	Node* latest;	// обьявляем последний элемент очереди(указатель)
	size_t size;// обьявляем размер очереди
public:
	Queue();	// обьявляется конструктор
	Queue(const Queue<T>& other);// обьявляется конструктор с параметрами
	~Queue(); // обьявляется деструктор
	Queue<T>& addEnd(const T& value); // добавить в конец очереди элемент
	Queue<T>& popFront();	// убрать из начала
	size_t getSize();	// узнать сколько элементов в очереди
	Node* getFirst() const;	// взять первый элемент очереди(покажет кто первый в очереди)
	void clear();	// очистить очередь
};

template <class T>
Queue<T>::Queue() {	// реализовали конструктор
	this->first = this->latest = nullptr;	//	обьявили очередь
	this->size = 0;
}

template <class T>
Queue<T>::~Queue() {
	clear();
}

template <class T>
void Queue<T>::clear() {
	Node* temp = first;	// временной переменной передели значение 1-го элемента
	while (temp != nullptr) {	// 
		temp = first->next;	// запоминаем следующий элемент(следущий после 1-го) 
		delete first;	// удаляем 1-й элемент
		first = temp;	// 2-й элемент теперь является 1-м
	}
	this->size = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {	// конструктор копирования
	Queue();
	Node* temp = other.getFirst();	// временной переменной передается значение переменной 1-го элемента другой очереди
	while (temp != nullptr) {	//
		this->addEnd(temp->value);	//	пока у другой очереди есть элементы, добавляем в новую очередь
		temp = temp->next;	// переходим к следующему элементу
	}
}

template <class T>
typename Queue<T>::Node* Queue<T>::getFirst() const {	// берем 1-й элемент очереди 
	return first;
}

template <class T>
size_t Queue<T>::getSize() {
	return size;
}

template <class T>
Queue<T>& Queue<T>::popFront() {	// убираем 1-й элемент
	if (first != nullptr) {	// если 1-й элемент не пустой
		Node* temp = first->next;	//
		delete first; //
		first = temp; //
		size--;	//	размер очереди уменьшается
	}
	return *this;	// возвращаем 1-й элемент очереди
}

template <class T>
Queue<T>& Queue<T>::addEnd(const T& value) { // добавляем в конец элемент
	Node* last = new Node(value);	// выделяем память под нового участника очереди 
	if (first == nullptr) {	//
		first = latest = last;	// 
		first->next = nullptr;	// если первый = последний, то след  элемента  нет
	}
	else {
		latest->next = last;	// после последнего элемента добавляется новый элемент
		last->next = nullptr;	// после last нет элемента
		latest = last;	// последний элемент last
	}
	size++;	//
	return *this;	//	
}

template <class T>
class Queue<T>::Node	// вложенный класс очереди
{
public:
	T value;	// один элемент  
	Node* next;	// следующий элемент
	/*Node() {
		next = nullptr;
	}*/
	Node(const T& val) {	// передается параметр value 
		//Node(); //
		value = val;	//
		next = nullptr;	//
	}
	~Node() {	//
		next = nullptr;	// 
	}
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& queue) {	// реализация стандартного оператора вывода
	if (queue.first != nullptr) {	// если очередь не пуста
		auto current = queue.first;	// берем 1-й элемент
		while (current != queue.latest) {	// пока не дошли до конца очереди
			out << current->value << " ";	// выводим элементы
			current = current->next;	// идем к следующему элементу
		}
		return out << current->value;	// выводим последний элемент
	}
	return out << "Queue is empty";		// очередь пуста
}