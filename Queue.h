#pragma once
#include <sstream>

template <class T>
class Queue
{
	template <typename T1> friend std::ostream& operator<< (std::ostream&, const Queue<T1>&);	// ����������� �������� ������, "������" �� ����������� ���������� ������
private:
	class Node;	// �������� ������� �������
	Node* first;	// ��������� ������ ������� �������(���������)
	Node* latest;	// ��������� ��������� ������� �������(���������)
	size_t size;// ��������� ������ �������
public:
	Queue();	// ����������� �����������
	Queue(const Queue<T>& other);// ����������� ����������� � �����������
	~Queue(); // ����������� ����������
	Queue<T>& addEnd(const T& value); // �������� � ����� ������� �������
	Queue<T>& popFront();	// ������ �� ������
	size_t getSize();	// ������ ������� ��������� � �������
	Node* getFirst() const;	// ����� ������ ������� �������(������� ��� ������ � �������)
	void clear();	// �������� �������
};

template <class T>
Queue<T>::Queue() {	// ����������� �����������
	this->first = this->latest = nullptr;	//	�������� �������
	this->size = 0;
}

template <class T>
Queue<T>::~Queue() {
	clear();
}

template <class T>
void Queue<T>::clear() {
	Node* temp = first;	// ��������� ���������� �������� �������� 1-�� ��������
	while (temp != nullptr) {	// 
		temp = first->next;	// ���������� ��������� �������(�������� ����� 1-��) 
		delete first;	// ������� 1-� �������
		first = temp;	// 2-� ������� ������ �������� 1-�
	}
	this->size = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {	// ����������� �����������
	Queue();
	Node* temp = other.getFirst();	// ��������� ���������� ���������� �������� ���������� 1-�� �������� ������ �������
	while (temp != nullptr) {	//
		this->addEnd(temp->value);	//	���� � ������ ������� ���� ��������, ��������� � ����� �������
		temp = temp->next;	// ��������� � ���������� ��������
	}
}

template <class T>
typename Queue<T>::Node* Queue<T>::getFirst() const {	// ����� 1-� ������� ������� 
	return first;
}

template <class T>
size_t Queue<T>::getSize() {
	return size;
}

template <class T>
Queue<T>& Queue<T>::popFront() {	// ������� 1-� �������
	if (first != nullptr) {	// ���� 1-� ������� �� ������
		Node* temp = first->next;	//
		delete first; //
		first = temp; //
		size--;	//	������ ������� �����������
	}
	return *this;	// ���������� 1-� ������� �������
}

template <class T>
Queue<T>& Queue<T>::addEnd(const T& value) { // ��������� � ����� �������
	Node* last = new Node(value);	// �������� ������ ��� ������ ��������� ������� 
	if (first == nullptr) {	//
		first = latest = last;	// 
		first->next = nullptr;	// ���� ������ = ���������, �� ����  ��������  ���
	}
	else {
		latest->next = last;	// ����� ���������� �������� ����������� ����� �������
		last->next = nullptr;	// ����� last ��� ��������
		latest = last;	// ��������� ������� last
	}
	size++;	//
	return *this;	//	
}

template <class T>
class Queue<T>::Node	// ��������� ����� �������
{
public:
	T value;	// ���� �������  
	Node* next;	// ��������� �������
	/*Node() {
		next = nullptr;
	}*/
	Node(const T& val) {	// ���������� �������� value 
		//Node(); //
		value = val;	//
		next = nullptr;	//
	}
	~Node() {	//
		next = nullptr;	// 
	}
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& queue) {	// ���������� ������������ ��������� ������
	if (queue.first != nullptr) {	// ���� ������� �� �����
		auto current = queue.first;	// ����� 1-� �������
		while (current != queue.latest) {	// ���� �� ����� �� ����� �������
			out << current->value << " ";	// ������� ��������
			current = current->next;	// ���� � ���������� ��������
		}
		return out << current->value;	// ������� ��������� �������
	}
	return out << "Queue is empty";		// ������� �����
}