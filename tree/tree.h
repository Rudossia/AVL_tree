#ifndef AVL_TREE
#define AVL_TREE

#include <algorithm>
#include <iostream>
#include <string>
#include <climits>
#include <fstream>

namespace Tree{

	template <typename T, typename U>
	class avl_tree {
	public:
		struct Node 
		{
			T key_;
			unsigned char height;
			Node* left;
			Node* right;

			U information_;		
			
			Node(T key, U information = U()): key_(key), height(1), left(nullptr), right(nullptr),  information_(information){};
		};

	private:
		Node* root;
		
	private:
		int height(Node* node);
		int balance_F(Node* node);

		Node* R_rotate(Node* node);
		Node* L_rotate(Node* node);

		Node* insert(Node* node, T key, U info);

		void view_tree(Node* node);

		void generate_dot_nodes(std::ostream& out, Node* node) const;

		Node* remove(Node* node, T key);

		Node* minValue(Node* node)const;
		
	public:
		avl_tree(): root(nullptr){};
		
		void view_tree();
		void insert(T key, U info);

		void generate_dot(const std::string& filename) const;

		void remove(T key);
		

		
		
	};
}

#include "tree.tpp"
#endif



