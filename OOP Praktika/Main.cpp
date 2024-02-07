#include <iostream>
#include <vector>
//Создание шаблонного связного списка

template<typename Type> 

class LinkedList {
public:
	LinkedList();
	LinkedList(int n);// лист с уже созданными n элементами 
	LinkedList(const LinkedList& other);
	LinkedList(LinkedList&& other);//можно не делать но для оптимизации скорости программы полезно
		//тут не будет реализации конструктора от списка инициализации, внесем позже

	~LinkedList();

	LinkedList& operator = (const LinkedList& other); // присваивание копированием
	LinkedList& operator = (const LinkedList&& other);// присваивание переносом

	Type & operator[](int i);
	const Type& operator[](int i)const;

	Type& at(int i);
	const Type& at(int i)const;


	void push_back(const Type& obj); //добавить новый элемент  в конец и начало
	void push_front(const Type& obj);

	void pop_back();				//уничтожить данные в конце или в начале списка
	void pop_front();

	/*
	* emplace/incert - методы добавления новых данных в произвольное
	* место коллекции
	* erise - метод для удаления данных в произвольном месте коллекции
	*/

	int size() const {
		return size_ };

	/*
	* методы для прохода по коллекции умными указателями
	* мы сознательно опустим
	*/
private:

	class Node {
	public:
	Node()				// при делигации мы вызываем конструктор по умолчанию хранимого типа данных.
						//Данный синтаксис корректно отработает даже если прямой вызов такого метода
						//(например конструктора встроенных типов) недоступен.
							
		:Node(Type()) 
	{}

	Node(const Type& data, Node* place = nullptr)
		:data_(data), 
		next_(place)
		{}

	Type& Data() {
		return data_;
	}

	const Type& Data()const {
		return data_;
	}

	Node* Next()const {			//Метод для предоставления информации о полжении следующей точки в списке
		return next_;
	}

	void Next(Node* next) {		//Устанавливаем новое значение для следующей точки в списке
		next_ = next;
	}


	private:
		Type data_;
		Node* next_;
	};
	Node* start_;
	Node* end_;
	int size_;
};


int main() {
	setlocale(LC_ALL, "ru");

	
	int arr[10];
	std::vector<int> vec(10);
	LinkedList<int> list;
	arr[5] = 34;
	vec[5] = 23;
	list[5] = 12;

	return 0;
}