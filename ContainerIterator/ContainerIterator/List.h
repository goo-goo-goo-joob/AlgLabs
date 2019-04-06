#pragma once
#include <iostream>
#include "Iterator.h"

//template<typename T >
//std::ostream & operator<<(std::ostream & os,
//	const List <T> & list) {
//	for (auto i = list.begin();
//		i != list.end(); ++i)
//	{
//		os << *i;
//		os << " ";
//	}
//	os << std::endl;
//	return os;
//}

template <typename T>
class List
{
private:
	Node<T>* _head;
	size_t _size;
public:
	List() {
		_head = nullptr;
		_size = 0;
	}
	List(const List&list) {
		_head = nullptr;
		_size = 0;
		Node<T>* next(nullptr);
		for (auto i = list._head; i != nullptr;
			i = i->_next) {
			if (!_size) {
				_head = new 
					Node<T>(T(i->_elm));
				next = _head;
				_size++;
			}
			else{
				Node<T>* node = new 
					Node<T>(T(i->_elm));
				next->_next = node;
				next = node;
				_size++;
			}
		}
	}
	~List() {
		while (_head != nullptr) {
			Node<T>* old_head = _head;
			_head = _head->_next;
			delete old_head;
		}
		_size = 0;
	}
	void push(const T & elm) {
		Node<T>* node = new Node<T>(elm);
		node->_next = _head;
		_head = node;
		_size++;
	}
	T pop() {
		if (_size) {
			Node<T>* node = _head->_next;
			T elm = _head->_elm;
			delete _head;
			_head = node;
			_size--;
			return elm;
		}
	}
	Iterator<T> begin() {
		return Iterator<T>(_head);
	}
	Iterator<T> end() {
		return Iterator<T>(nullptr);
	}
	ConstIterator<T> begin() const {
		return ConstIterator<T>(_head);
	}
	ConstIterator<T> end() const {
		return ConstIterator<T>(nullptr);
	}
	size_t len() {
		return _size;
	}
};