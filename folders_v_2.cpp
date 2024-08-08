#include <map>
#include <string>
#include <vector>
#include <iostream>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const {
        const Node* current = &root;
        for (const auto& key : node) {
            auto it = current->children.find(key);
            if (it == current->children.end()) {
                return false;
            }
            current = &it->second;
        }
        return true;
    }

    void Insert(const std::vector<std::string>& node) {
        Node* current = &root;
        for (const auto& key : node) {
            current = &current->children[key]; 
        }
    }

    void Delete(const std::vector<std::string>& node) {
        
        Node* current = &root;
        for (const auto& key : node) {
            auto it = current->children.find(key);
            if (it == current->children.end()) {
                return; 
            }
            if (current->children.size() == 1) {
                current->children.erase(it);
                return;
            }
            current = &it->second;
        }
    }
};

int main(){
	std::vector<std::string> path, del, still;
	std::string str;
	for(int i = 0; i < 4; i++){
		std::cin >> str;
		path.push_back(str);
	}
	Tree mytree;
	mytree.Insert(path);
	if(mytree.Has(path)){
		std::cout << "Contains!\n";
	}
	for(int i = 0; i < 2; i++){
		del.push_back(path[i + 2]);
		still.push_back(path[i]);
	}
	mytree.Delete(del);
	if(!mytree.Has(del)){
		std::cout << "Deleted\n";
	}
	if(mytree.Has(still)){
		std::cout << "Smth left\n";
	}
	return 0;
}


