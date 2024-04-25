#include <iostream>
#include <vector>
#include "sort.hpp"
#include <limits>


int main(){
	std::vector<long> vec;
	int n{0};
	std::string buffer;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoring the endline character
	getline(std::cin, buffer);
	vector_creating(vec, buffer);
	QSort(vec);
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	return 0;
}

