#include "tree.h"

namespace Tree {

	template<typename T, typename U>
	void avl_tree<T, U>::generate_dot(const std::string& filename) const {
	    std::ofstream out(filename);
	    out << "digraph G {\n";
	    generate_dot_nodes(out, root);
	    out << "}\n";
	}

	template<typename T, typename U>
	void avl_tree<T, U>::generate_dot_nodes(std::ostream& out, Node* node) const {
	    if (!node) return;

	    out << "    \"" << node->key_ << "\\n" << node->information_ << "\";\n";

	    if (node->left) {
	        out << "    \"" << node->key_ << "\\n" << node->information_ << "\" -> \"" 
	            << node->left->key_ << "\\n" << node->left->information_ << "\";\n";
	        generate_dot_nodes(out, node->left);
	    }

	    if (node->right) {
	        out << "    \"" << node->key_ << "\\n" << node->information_ << "\" -> \"" 
	            << node->right->key_ << "\\n" << node->right->information_ << "\";\n";
	        generate_dot_nodes(out, node->right);
	    }
	}




	template <typename T, typename U>
	int avl_tree<T, U>::height(Node* node) {
		if (node == nullptr){
			return 0;
		}
		return node->height;
	}

	template <typename T, typename U>
	int avl_tree<T, U>::balance_F(Node* node){
		if (node == nullptr){
			return 0;
		}
		return height(node->left) - height(node->right);		
	}
	
	template <typename T, typename U>
	typename avl_tree<T, U>::Node* avl_tree<T,U>::R_rotate( Node* node){
		Node* one = node->left;
		Node* two = one->right;

		one->right = node;
		node->left = two;

		node->height = std::max(height(node->left), height(node-> right)) + 1;

		one->height = std::max(height(one->left), height(one->right)) + 1;
		
		return one;
	}

	template <typename T, typename U>
	typename avl_tree<T, U>::Node* avl_tree<T, U>::L_rotate( Node* node){
		Node* one = node->right;
		Node* two = one->left;

		one->left = node;
		node->right = two;

		node->height = std::max(height(node->left), height(node-> right)) + 1;

		one->height = std::max(height(one->left), height(one->right)) + 1;
		
		return one;
	}



	template <typename T, typename U>
	typename avl_tree<T, U>::Node* avl_tree<T, U>::insert(Node* node, T key, U info){
		if (node == nullptr) {
			return new Node(key, info);
		}
		if (key < node->key_) {
			node->left = insert(node->left, key, info);
		}
		else if (key > node->key_){
			node->right = insert(node->right, key, info);
		}
		else{
			return node;
		}
		node->height = 1 + std::max(height(node->left), height(node->right));
		int balance = balance_F(node);		

        if (balance > 1 && key < node->left->key_)
            return R_rotate(node);
        // Right Right Case
        if (balance < -1 && key > node->right->key_)
            return L_rotate(node);
        // Left Right Case
        if (balance > 1 && key > node->left->key_) {
            node->left = L_rotate(node->left);
            return R_rotate(node);
        }
        // Right Left Case
        if (balance < -1 && key < node->right->key_) {
            node->right = R_rotate(node->right);
            return L_rotate(node);
        }
        return node;		
	}
		
	//POETRY OF INSERTION
	template <typename T, typename U>
	void avl_tree<T, U>::insert(T key, U info){
		root = insert(root, key, info);
	}

	template <typename T, typename U>
	void avl_tree<T, U>::view_tree(Node* root) {
		if (root){
			view_tree(root->left);
			std::cout << "Key:" << root->key_ << "|| information:" << root->information_ << std::endl;

			view_tree(root->right);
		}
	}

	template <typename T, typename U>
	void avl_tree<T,U>::view_tree(){
		view_tree(root);
	}

	template <typename T, typename U>
	typename avl_tree<T, U>:: Node* avl_tree<T, U>::minValue(Node* node) const{
		Node* curr = node;
		while(curr -> left != nullptr){
			curr = curr->left;
		}
		return curr;
	}
	
	


	template <typename T, typename U>
	typename avl_tree<T, U>:: Node* avl_tree<T, U>::remove(Node* node, T key) {
		if (node == nullptr){
			return node;
		}
		if (key < node->key_) {
			node->left = remove(node->left, key);
		}
		else if(key > node->key_){
			node->right = remove(node->right, key);
		}
		else{
			if((node->left == nullptr) || (node->right == nullptr)){
				Node *temp = node->left ? node->left : node->right;

				if (temp == nullptr) {
					temp = node;
					node = nullptr;
				}
				else{
					*root = *temp;
				}
				delete temp;
			}
			else{
				Node *temp = minValue(node->right);

				node->key_ = temp ->key_;
				node->right = remove(node->right, temp->key_);
				
			}
		}

		if (node == nullptr){
			return node;
		}

		node->height = 1 + std::max(height(node->left), height(node -> right));

		int bal = balance_F(node);

        if (bal> 1 && balance_F(node->left) >= 0){
            return R_rotate(node);
        }
        if (bal > 1 && balance_F(node->left) < 0) {
            node->left = L_rotate(node->left);
            return R_rotate(node);
        }
        if (bal < -1 && balance_F(node->right) <= 0){
            return L_rotate(node);
		}
        if (bal < -1 && balance_F(node->right) > 0) {
            node->right = R_rotate(node->right);
            return L_rotate(node);
        }

        return node;
	} 


	template <typename T, typename U>
	void avl_tree<T, U>::remove(T key){
		root = remove(root, key);
	}
	
	
}
