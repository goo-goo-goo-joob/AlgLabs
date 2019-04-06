#pragma once
#include "pch.h"
#include <iostream>
#include "Iterator.h"

template <typename T>
class BinaryTree
{
private:
	TreeNode<T>* _head;
	bool(*_func)(T, T);
public:
	BinaryTree(bool(*func)(T, T)) {
		_head = nullptr;
		_func = func;
	}
	TreeNode<T>* copy(TreeNode<T>* node)
	{
		if (!node)
			return nullptr;
		TreeNode<T> * next = new TreeNode<T>(node->_elm);
		next->_left = copy(node->_left);
		if (next->_left)
			next->_left->_parent = next;
		next->_right = copy(node->_right);
		if (next->_right)
			next->_right->_parent = next;
		return next;
	}
	BinaryTree(const BinaryTree&tree) {
		_head = copy(tree._head);
	}
	void destroyTree(TreeNode<T> *t) {
		if (t->_left)
			destroyTree(t->_left);
		if (t->_right)
			destroyTree(t->_right);
		delete t;
	}
	~BinaryTree() {
		destroyTree(_head);
	}
	void push(const T & elm) {
		TreeNode<T>* node = new TreeNode<T>(elm);
		if (_head) {
			TreeNode<T>* next = _head;
			while (next) {
				if (_func(next->_elm, elm)) {
					if (next->_left)
						next = next->_left;
					else {
						next->_left = node;
						node->_parent = next;
						next = nullptr;
					}
				}
				else {
					if (next->_right)
						next = next->_right;
					else {
						next->_right = node;
						node->_parent = next;
						next = nullptr;
					}
				}
			}
		}
		else {
			_head = node;
		}
	}
	TreeIterator<T> begin() {
		return TreeIterator<T>(_head);
	}
	TreeIterator<T> end() {
		return TreeIterator<T>(nullptr);
	}
	ConstTreeIterator<T> begin() const {
		return ConstTreeIterator<T>(_head);
	}
	ConstTreeIterator<T> end() const {
		return ConstTreeIterator<T>(nullptr);
	}
};