#pragma once
#include <iostream>
#include "Iterator.h"

template <typename T>
class Queue
{
private:
	Node<T> *_head, *_tail;
	size_t _size;
public:
	Queue() {
		_head = _tail = nullptr;
		_size = 0;
	}
	Queue(const Queue&queue) {
		_head = _tail = nullptr;
		_size = 0;
		Node<T>* next(nullptr);
		for (auto i = queue._tail; 
			i != nullptr; i = i->_next) {
			push(T(i->_elm));
		}
	}
	~Queue() {
		while (_head != nullptr) {
			Node<T>* old_head = _head;
			_head = _head->_next;
			delete old_head;
		}
		_size = 0;
	}
	void push(const T & elm) {
		if (_tail == nullptr) {
			_tail = _head = new Node<T>(elm);
			_size++;
		}
		else {
			Node<T>* node = new Node<T>(elm);
			_head->_next = node;
			_head = node;
			_size++;
		}
	}
	T pop() {
		if (_size) {
			Node<T>* node = _tail->_next;
			T elm = _tail->_elm;
			delete _tail;
			_tail = node;
			_size--;
			return elm;
		}
		else
			throw std::exception("Queue is empty");
	}
	Iterator<T> begin() {
		return Iterator<T>(_tail);
	}
	Iterator<T> end() {
		return Iterator<T>(nullptr);
	}
	ConstIterator<T> begin() const {
		return ConstIterator<T>(_tail);
	}
	ConstIterator<T> end() const {
		return ConstIterator<T>(nullptr);
	}
	size_t len() {
		return _size;
	}
};