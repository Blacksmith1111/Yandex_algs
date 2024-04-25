#include <vector>
#include <string>

template <typename T>
std::vector<T>& vector_creating(std::vector<T>& vec, std::string& buffer){
	std::string temp{};
	for(auto&& str : buffer){
		if(str == ' '){
			vec.push_back(std::atol(temp.c_str()));
			temp.clear();
			continue;
		}
		temp += str;
	}
	if(!temp.empty()){
		vec.push_back(std::atol(temp.c_str()));
	}
	return vec;
}	

template <typename T>
std::vector<T>& Lomuto(std::vector<T>& vec){
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

template <typename T>
std::vector<T>& QSort(std::vector<T>& vec){
	if(vec.size() == 1){
		return vec;
	}

	std::vector<T> smaller;
	std::vector<T> greater;
	T pivot = vec[vec.size()/2]; // pivot point

	for(size_t i = 0; i < vec.size(); i++){
		if(i == vec.size() / 2){
			continue;
		}
		if(vec[i] <= vec[vec.size()/2]){
			smaller.push_back(vec[i]);
		}
		if(vec[i] > vec[vec.size()/2]){
			greater.push_back(vec[i]);
		}
	}

	vec.clear();

	if(!smaller.empty()){
		QSort(smaller);
		for(size_t i = 0; i < smaller.size(); i++){
			vec.push_back(smaller[i]);
		}
	}

	vec.push_back(pivot);
	
	if(!greater.empty()){
		QSort(greater);	
		for(size_t i = 0; i < greater.size(); i++){
			vec.push_back(greater[i]);
		}
	}
	
	return vec;
}
