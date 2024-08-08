#include <iostream>
// make a delete_node function, solve the leetcode task, balance the tree
namespace Trees{
	class Tree{
	private:
		class Node{
		public:
			int key;
			Node* left = nullptr, *right = nullptr, *parent = nullptr;
			Node(int val = 0): key(val){};
			~Node(){
				delete left;
				delete right;
				std::cout << "Deleted the node with the val " << key << " " <<std::endl;
			}
			Node(const Node& example) = delete;
		}; //class Node is over

		Node* root;
		using iterator = Node*;
		iterator current = root;
	public:
		Tree(int val):root(new Node(val)){};
		~Tree(){
			delete root;
			std::cout << "Deleted the tree" << std::endl;
		}
		Tree(const Tree& example) = delete;
		int getter(){
			return current -> key;
		}
		int getter_parent(){
			return current -> parent -> key;
		}
		int getter_right(){
			return (current -> right) -> key;
		}
		int getter_left(){
			return (current -> left) -> key;
		}
		void add_the_element(int val){
			current = root;
			while(1){
				if(val > current -> key && current -> right != nullptr){
					current = current -> right;
				}
				else if(val < current -> key && current -> left != nullptr){
					current = current -> left;
				}
				else{
					break;
				}
			}
			if(val > current -> key){
				current -> right = new Node(val);
				current -> right -> parent = current;
				current = current -> right;
			}
			else if(val < current -> key){
				current -> left = new Node(val);
				current -> left -> parent = current;
				current = current -> left;
			}
		}
		void del_the_el(int val){
			current = root;
			while(1){
				if(val > current -> key && current -> right != nullptr){
					current = current -> right;
				}
				else if(val < current -> key && current -> left != nullptr){
					current = current -> left;
				}
				else{
					break;
				}
			}
			current = current -> parent;

			if(current -> right != nullptr && current -> right -> key == val){
				delete current -> right;
			}
			else if(current -> left != nullptr && current -> left -> key == val){
				delete current -> left;
			}
		}
		void delete_the_element(int val){
			current = root;
			while(1){
				if(val > current -> key && current -> right != nullptr){
					current = current -> right;
				}
				else if(val < current -> key && current -> left != nullptr){
					current = current -> left;
				}
				else{
					break;
				}
			}
			
			Node* temp;
			if(current -> right != nullptr && current -> left != nullptr){
				(current -> right) -> parent = current -> parent;
				std::cout << (current -> right) -> parent -> key << " is a (current -> right) -> parent" << std::endl;
				for(temp = (current -> right); temp -> left != nullptr; temp = temp -> left){}
				std::cout << temp -> key << " current temp" <<std::endl;
				(current -> left) -> parent = temp;
				std::cout << (current -> left) -> parent -> key << " is a (current -> left) -> parent" << std::endl;
			}

			if((current -> parent) -> key > val){
					std::cout << "true1" << std::endl;
					if(current -> right != nullptr){
						std::cout << "true2" << std::endl;
						(current -> right) -> parent = current -> parent;
						(current -> parent) -> left = current -> right;
					}
					else{
						(current -> left) -> parent = current -> parent;
						(current -> parent) -> left = current -> left;
					}	
					//current -> left = nullptr;
					//delete current;
			}
			else{
				if(current -> right != nullptr){
					(current -> right) -> parent = current -> parent;
					(current -> parent) -> right = current -> right;
				}
				else{
					(current -> left) -> parent = current -> parent;
					(current -> parent) -> right = current -> left;
				}
				//current -> left = nullptr;	
				//delete current;	
			}
		}
	};	
}

int main(){
	Trees::Tree my_tree(5);
	std::cout << my_tree.getter() << std::endl;
	int elems[6] = {3,4,2,8,9,1};
	for(int i = 0; i < 6; i++){
		my_tree.add_the_element(elems[i]);
		std::cout << my_tree.getter() << std::endl;	
	}
	return 0;
}