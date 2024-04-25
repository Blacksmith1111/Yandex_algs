#include <iostream>
#include <vector>
#include <limits>

std::vector<int>& Lomuto(std::vector<int>& vec);
std::vector<int>& vector_creating(std::vector<int>& vec, std::string& buffer);


int main(){
	std::vector<int> vec;
	int n{0};
	std::string buffer;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoring the endline character
	getline(std::cin, buffer);
	vector_creating(vec, buffer);
	Lomuto(vec);
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	return 0;
}

std::vector<int>& Lomuto(std::vector<int>& vec){
	//vec[0] is a pivotal point
	int index = 1;
	for(int i = 2; i < vec.size(); i++){
		if(vec[i] <= vec[0]){
			std::swap(vec[index], vec[i]);
			index++;
		}
	}
	std::swap(vec[0], vec[index - 1]);
	return vec;
}

std::vector<int>& vector_creating(std::vector<int>& vec, std::string& buffer){
	std::string temp{};
	for(auto&& str : buffer){
		if(str == ' '){
			vec.push_back(atoi(temp.c_str()));
			temp.clear();
			continue;
		}
		temp += str;
	}
	if(!temp.empty()){
		vec.push_back(atoi(temp.c_str()));
	}
	return vec;
}	
