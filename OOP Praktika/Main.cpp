#include <iostream>
#include <vector>

//Создание шаблонного связного списка

template<typename Type> 

class LinkedList {
public:
	LinkedList()								//конструктор по умолчанию
		:start_(nullptr),
		end_(nullptr),
		size_(0)
	{ }
	// лист с уже созданными n элементами 
	LinkedList(int n) :LinkedList() {
		if (n < 0) throw - 1;
		if (n == 0)return;
		Node *tmp{};
		
		int count{ 0 };
		tmp = new Node{};
		start_ = tmp;
		end_ = tmp;
		count += 1;
		while (count < n) {
			tmp = new Node{};// создаем новую точку
			end_->Next(tmp); // старому концу списка говорим что конечый элемент существует
			end_ = tmp; //запоминаем в списке элемент сейчас последний
			count += 1;
		}

		size_ = n;
	}
	
		
	LinkedList(const LinkedList& other):LinkedList() {
		if (other.size() == 0)return;
		start_ = new Node(other.start_->Data()); //в начале нового списка создали новую точку в которую перенесли данные из предидущего списка
		end_ = start_;
		for (Node *current = other.start_->Next();current!=nullptr;current = current->Next()) {
			//Node* tmp = new Node(other[i]); так лучше не делать, квадратные скобки самый медленный способ
			Node* tmp = new Node(current->Data());
			end_ -> Next(tmp);
			end_ = tmp;
		}
		size_ = other.size_;
	}

	LinkedList(LinkedList&& other):LinkedList() {
		std::swap(start_, other.start_);				//можно не делать но для оптимизации скорости программы полезно
		std::swap(end_, other.end_);					//тут не будет реализации конструктора от списка инициализации, внесем позже
		std::swap(size_, other.size_);
													
													
	}

	~LinkedList() {
		Node* current = start_; 
		while (current != nullptr;) {
			Node* tmp = current->Next())
			delete current;
			current = tmp;
		}
		
	}

	void clear() {
		Node* current = start_;
		while (current != nullptr;) {
			Node* tmp = current->Next())
			delete current;
			current = tmp;
		}
		start_ = nullptr;
		end_ = nullptr;
		size_ = 0;
	}

	// присваивание копированием
	LinkedList& operator = (const LinkedList& other) {
		clear();
		if (other.size() == 0) return *this;
		start_ = new Node(other.start_->Data()); //в начале нового списка создали новую точку в которую перенесли данные из предидущего списка
		end_ = start_;
		for (Node* current = other.start_->Next(); current != nullptr; current = current->Next()) {
			Node* tmp = new Node(current->Data());
			end_->Next(tmp);
			end_ = tmp;
		}
		size_ = other.size_;
		return *this;
	}
			

	// присваивание переносом
	LinkedList& operator = (const LinkedList&& other) {
		clear();
		std::swap(start_, other.start_);				//можно не делать но для оптимизации скорости программы полезно
		std::swap(end_, other.end_);					//тут не будет реализации конструктора от списка инициализации, внесем позже
		std::swap(size_, other.size_);
		return *this;
	}

	//оператор доступа к хранящимся данным
	Type& operator[](int i) {
		int count{};
		Node* tmp = start_;
		while (count < i) {
			tmp = tmp->Next;
			count += 1;
		}
		return tmp->Data();
	}


	const Type& operator[](int i)const {
		int count{};
		Node* tmp = start_;
		while (count < i) {
			tmp = tmp->Next;
			count += 1;
		}
		return tmp->Data();
	}

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
		return size_;
	}

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