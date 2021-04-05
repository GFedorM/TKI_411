#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "��������� ������ �������:" << endl;
	Queue<int> fedor;

	cout << "������� ������ �������:" << endl;
	cout << fedor << endl;

	cout << "��������� � ������� ��������: 1, 3, 5, 6, 7, 8, 10 � 13" << endl;
	fedor.addEnd(1).addEnd(3).addEnd(5).addEnd(6).addEnd(7).addEnd(8).addEnd(10).addEnd(13);
	cout << fedor << endl;

	cout << "��������� �������: " << endl;
	Queue<int> copefedor = fedor;
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;

	cout << "������ ������ 2 �������� ������ �������:" << endl;
	fedor.popFront().popFront();
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;

	cout << "������� ��� �������:" << endl;
	fedor.clear();
	copefedor.clear();
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;




	system("PAUSE");
	return 0;
}