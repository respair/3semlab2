#pragma once
#include <stdexcept>

const auto IndexOutOfRangeExcept = "Invalid range of index!";
const auto NegativeSizeOfArrayExcept = "Array size is negative!";


template <class T>
class LinkedList
{
private:
	int size = 0;
	struct node {
		T items = 0;
		node* next = nullptr;
	};
	node* head = nullptr;
public:
	LinkedList(const T* items, const int count) : LinkedList()
	{
		if (count <= 0) throw std::length_error(NegativeSizeOfArrayExcept);
		this->size = count;
		node** nodetmp = &this->head; //ïåðâûé óêàçàòåëü ïðåðàùàåò àäðåñ îáðàòíî â íîä à âòîðîé äåëàåò óêàçàòåëåì
		for (int i = 0; i < count; i++)
		{
			*nodetmp = new node;
			(*nodetmp)->items = items[i];
			nodetmp = &((*nodetmp)->next);
		}
	}
	LinkedList() : size(0), head(nullptr) {};
	LinkedList(const LinkedList <T>& list) {
		if (list.size <= 0) throw std::length_error(NegativeSizeOfArrayExcept);
		this->size = list.size;
		node* nodecopy = list.head;
		node** nodetmp = &this->head;
		for (int i = 0; i < list.size; i++) {
			*nodetmp = new node;
			(*nodetmp)->items = nodecopy->items;
			nodecopy = nodecopy->next;
			nodetmp = &((*nodetmp)->next);
		}
	}
public:
	T& operator [] (const int index) const
	{
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRangeExcept);
		node* node_temp = this->head;
		for (int i = 0; i < index; ++i) node_temp = node_temp->next;
		return node_temp->items;
	}
	T GetFirst() const { return this->head->items; }
	T GetLast() const {
		node* tmp = this->head;
		while (tmp->next != nullptr) tmp = tmp->next;
		return tmp->items;
	}
	T Get(int index) const {
		if (index > this->size || index < 0)
			throw std::out_of_range(IndexOutOfRangeExcept);
		node* tmp = this->head;
		for (int i = 0; i < index; i++) tmp = tmp->next;
		return tmp->items;
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
		if (startIndex > this->size || endIndex > this->size || startIndex < 0 || endIndex < 0)
			throw std::out_of_range(IndexOutOfRangeExcept);
		int size = endIndex - startIndex + 1;
		T* array = new T[size];
		node* tmp = this->head;
		for (int i = 0; i < startIndex; i++)  tmp = tmp->next;
		for (int i = startIndex - 1; i < endIndex; i++) {
			array[i - startIndex - 1] = tmp->items;
			tmp = tmp->next;
		}
		LinkedList<T>* newList = new LinkedList<T>(array, size);
		delete[] array;
		return  newList;
	}
	int GetSize() const { return this->size; }
	LinkedList<T>& operator = (const LinkedList<T>& list) {
		if (this == &list) return *this;
		node* node_temp;
		node* node_ = this->head;
		for (int i = 0; i < this->size; ++i)
		{
			node_temp = node_->next;
			delete node_;
			node_ = node_temp;
		}
		this->head = nullptr;
		this->size = 0;
		this->size = list.size;
		node** node_tmp = &this->head;
		node* node1 = list.head;
		for (int i = 0; i < list.size; ++i)
		{
			*node_tmp = new node;
			(*node_tmp)->items = node1->items;
			node_tmp = &((*node_tmp)->next);
			node1 = node1->next;
		}
		return *this;
	}
public:
	void Prepend(T item) {
		if (this->size == 0)
			throw std::length_error(NegativeSizeOfArrayExcept);
		node* tmp = new node;
		if (this->size == 0) {
			this->head->items = item;
			this->head->next = tmp;
		}
		else {
			tmp->next = head;
			head = tmp;
			tmp->items = item;
		}
		this->size++;
	}

	void Append(T item) {
		if (this->size == 0)
			throw std::length_error(NegativeSizeOfArrayExcept);
		node* tmp = new node;
		if (this->size == 0) {
			this->head->items = item;
			this->head->next = tmp;
			this->size++;
		}
		else {
			tmp = this->head;
			for (int i = 0; i < this->size; i++) tmp = tmp->next;
			tmp->items = item;
			node* temp = new node;
			tmp->next = temp;
			this->size++;
		}
	}

	void InsertAt(T item, int index) {
		if (index < 0 || index > this->size) throw std::out_of_range(IndexOutOfRangeExcept);
		node* tmp = new node;
		if (index == 0) {
			tmp->next = head;
			head = tmp;
		}
		else {
			node* current = new node;
			current = head;
			for (int i = 0; i < index - 1; i++) current = current->next;
			tmp->next = current->next;
			current->next = tmp;
		}
		tmp->items = item;
		this->size++;
	}

	LinkedList<T>* Concat(LinkedList<T>* list) {
		int size = list->size + this->size;
		T* array = new T[size];
		node* tmp = this->head;
		for (int i = 0; i < this->size; i++) { tmp = tmp->next; array[i] = tmp->items; }
		tmp = list->head;
		for (int i = this->size; i < size; i++) { tmp = tmp->next; array[i] = tmp->items; }
		LinkedList<T>* newnode = new LinkedList<T>(array, size);
		delete[] array;
		return  newnode;
	}
	void Delete_(const int index) {
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRangeExcept);
		const int new_size = this->size - 1;
		node* del_node = this->head;
		node* node_temp = this->head;
		if (index == 0) {
			this->head = this->head->next;
			delete del_node;
		}
		else {
			for (int i = 0; i < index - 1; ++i) node_temp = node_temp->next;
			del_node = node_temp->next;
			node_temp->next = del_node->next;
			delete del_node;
		}
		this->size = new_size;
	}
	~LinkedList() {
		node* node_temp;
		node* node_ = this->head;
		for (int i = 0; i < this->size; ++i)
		{
			node_temp = node_->next;
			delete node_;
			node_ = node_temp;
		}
		this->head = nullptr;
		this->size = 0;
	}
};