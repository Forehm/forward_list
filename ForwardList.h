#pragma once
#include <iostream>



template <typename T>
class MyList
{
public:
	MyList();
	~MyList();

	T& operator [](const int index);
	
	int GetSize() { return Size; }
	void pop_front();
	void pop_back();
	void clear();
	void push_front(T data);
	void push_back(T data);
	void insert(T data, const int index);


private:
	template <typename T>
	class Node
	{
	public:

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

		Node* pNext;
		T data;
	};


	int Size = 0;
	Node<T>* head;
};

template <typename T>
MyList<T>::MyList()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
MyList<T>::~MyList()
{
	clear();
}

template<typename T>
void MyList<T>::push_back(T data)
{

	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	++Size;
}

template<typename T>
T& MyList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		++counter;
	}
}

template<typename T>
void MyList<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	--Size;
}

template<typename T>
void MyList<T>::pop_back()
{
	Node<T>* current = this->head;
	while (current->pNext->pNext != nullptr)
	{
		current = current->pNext;
	}
	current->pNext = nullptr;
	--Size;

}

template<typename T>
void MyList<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void MyList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	--Size;
}

template <typename T>
void MyList<T>::insert(T data, const int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);

	}
	--Size;
}


