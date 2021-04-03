#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Объявляем пустую очередь:" << endl;
	Queue<int> fedor;

	cout << "Выводим пустую очередь:" << endl;
	cout << fedor << endl;

	cout << "Добавляем в очередь элементы: 1, 3, 5, 6, 7, 8, 10 и 13" << endl;
	fedor.addEnd(1).addEnd(3).addEnd(5).addEnd(6).addEnd(7).addEnd(8).addEnd(10).addEnd(13);
	cout << fedor << endl;

	cout << "Скопируем очередь: " << endl;
	Queue<int> copefedor = fedor;
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;

	cout << "Удалим первые 2 элемента первой очереди:" << endl;
	fedor.popFront().popFront();
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;

	cout << "Очистим обе очереди:" << endl;
	fedor.clear();
	copefedor.clear();
	cout << "fedor: " << fedor << endl;
	cout << "copefedor: " << copefedor << endl;




	system("PAUSE");
	return 0;
}