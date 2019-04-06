#include "pch.h"
#include "List.h"
#include "Queue.h"
#include "BinaryTree.h"


template<typename T >
std::ostream & operator<<(std::ostream & os,
	const Queue <T> & list) {
	for (auto i : list)
	{
		os << i;
		os << " ";
	}
	os << std::endl;
	return os;
}

template<typename T >
std::ostream & operator<<(std::ostream & os,
	const BinaryTree <T> & list) {
	for (auto i : list)
	{
		os << i;
		os << " ";
	}
	os << std::endl;
	return os;
}

template<typename T>
bool compare(T node, T newnode) {
	return abs(node) > abs(newnode);
}

int main()
{
	BinaryTree<int> tree(&compare);
	tree.push(123);
	tree.push(1);
	tree.push(2);
	tree.push(5);
	tree.push(6);
	tree.push(4);
	tree.push(234);
	tree.push(6);
	tree.push(-2);
	tree.push(-5);
	tree.push(-6);
	tree.push(-4);
	std::cout << tree;
	BinaryTree<int> tree1(tree);
	tree.push(-100);
	std::cout << tree1;
	Queue<double> queue;
	queue.push(1.7);
	queue.push(0.333);
	Queue<double> queue2(queue);
	std::cout << queue;
	queue2.pop();
	std::cout << queue2;
	std::cout << queue2.len();
	return 0;
}
