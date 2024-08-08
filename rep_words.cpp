#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <assert.h>

std::vector<std::string>& checker(std::vector<std::string>& result){
	std::unordered_map<std::string, int> checked_numbers;
	std::string str, temp;
	size_t counter_left = 0, counter_right = 1, flag = 0;
	getline(std::cin, str);

	for(auto iter = str.begin(); iter != str.end(); iter++, counter_right++){
		assert(str != "");
		
		if(*iter == ' ' || std::next(iter) == str.end()){
			temp = str.substr(counter_left, counter_right - counter_left);
			counter_left = counter_right;
			std::cout << "counter_left is " << counter_left << "\n";
		}

		if(checked_numbers[temp] == 0 && temp != ""){
			std::cout << temp <<" Never seen\n";
			result.push_back("NO");
			flag = 1;
		}

		if(flag == 0 && checked_numbers[temp] != 0 && temp != ""){
			std::cout << temp << " Have seen, the checked_numbers[temp] is " << checked_numbers[temp] << "\n";
			result.push_back("YES");
		}
		flag = 0;
		checked_numbers[temp]++;
	}
	return result;
}

int main(){
	std::vector<std::string> res;
	checker(res);
	for(std::string temp : res){
		std::cout << temp << "\n";
	}
	return 0;
}

