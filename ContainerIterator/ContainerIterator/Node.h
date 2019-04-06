#pragma once
template <typename T>
struct Node {
	T _elm;
	Node* _next;
	Node(const T & elm) : _elm(elm), _next(nullptr) {}
};

template <typename T>
struct TreeNode {
	T _elm;
	TreeNode *_left, *_right, *_parent;
	TreeNode(const T & elm) : _elm(elm), _left(nullptr), _right(nullptr), _parent(nullptr) {}
};