#pragma once
#include "Node.h"

template <typename T>
class TreeIterator {
private:
	TreeNode<T>* _ptr;
public:
	TreeIterator(TreeNode<T>* ptr) : _ptr(ptr) {
		//leftmost node is the begining
		while (_ptr && _ptr->_left)
		{
			_ptr = _ptr->_left;
		}
	}
	~TreeIterator() {}
	TreeIterator& operator++() {
		//find the right leftmost node
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			TreeNode<T>* _tmp = _ptr->_parent;
			//if we are at the right node; go by right
			while (_tmp && _ptr == _tmp->_right) {
				_ptr = _tmp;
				_tmp = _tmp->_parent;
			}
			//go by left side
			if (_ptr->_right != _tmp)
				_ptr = _tmp;
			if (!_tmp) {
				_ptr = nullptr;
			}
		}
		return *this;
	}
	TreeIterator operator++(int) {
		TreeIterator i = *this;
		operator++();
		return i;
	}
	T& operator*() const {
		return _ptr->_elm;
	}
	bool operator==(const TreeIterator& rhs) const {
		return _ptr == rhs._ptr;
	}
	bool operator!=(const TreeIterator& rhs) const {
		return !(_ptr == rhs._ptr);
	}
};

template <typename T>
class ConstTreeIterator {
private:
	TreeNode<T>* _ptr;
public:
	ConstTreeIterator(TreeNode<T>* ptr) : _ptr(ptr) {
		//leftmost node is the begining
		while (_ptr && _ptr->_left)
		{
			_ptr = _ptr->_left;
		}
	}
	~ConstTreeIterator() {}
	ConstTreeIterator& operator++() {
		//find the right leftmost node
		if (_ptr->_right) {
			_ptr = _ptr->_right;
			while (_ptr->_left)
				_ptr = _ptr->_left;
		}
		else {
			TreeNode<T>* _tmp = _ptr->_parent;
			//if we are at the right node; go by right
			while (_tmp && _ptr == _tmp->_right) {
				_ptr = _tmp;
				_tmp = _tmp->_parent;
			}
			//go by left side
			if (_ptr->_right != _tmp)
				_ptr = _tmp;
			if (!_tmp) {
				_ptr = nullptr;
			}
		}
		return *this;
	}
	ConstTreeIterator operator++(int) {
		TreeIterator i = *this;
		operator++();
		return i;
	}
	const T& operator*() const {
		return _ptr->_elm;
	}
	bool operator==(const ConstTreeIterator& rhs) const {
		return _ptr == rhs._ptr;
	}
	bool operator!=(const ConstTreeIterator& rhs) const {
		return !(_ptr == rhs._ptr);
	}
};

template <typename T>
class Iterator {
private:
	Node<T>* _ptr;
public:
	Iterator(Node<T>* ptr) : _ptr(ptr) {}
	~Iterator() {}
	Iterator& operator++() {
		_ptr = _ptr->_next;
		return *this;
	}
	Iterator operator++(int) {
		Iterator i = *this;
		_ptr = _ptr->_next;
		return i;
	}
	T& operator*() const {
		return _ptr->_elm;
	}
	bool operator==(const Iterator& rhs) const {
		return _ptr == rhs._ptr;
	}
	bool operator!=(const Iterator& rhs) const {
		return !(_ptr == rhs._ptr);
	}
};

template <typename T>
class ConstIterator {
private:
	Node<T>* _ptr;
public:
	ConstIterator(Node<T>* ptr) : _ptr(ptr) {}
	~ConstIterator() {}
	ConstIterator& operator++() {
		_ptr = _ptr->_next;
		return *this;
	}
	ConstIterator operator++(int) {
		ConstIterator i = *this;
		_ptr = _ptr->_next;
		return i;
	}
	const T& operator*() const {
		return _ptr->_elm;
	}
	bool operator==(const ConstIterator& rhs) const {
		return _ptr == rhs._ptr;
	}
	bool operator!=(const ConstIterator& rhs) const {
		return !(_ptr == rhs._ptr);
	}
};