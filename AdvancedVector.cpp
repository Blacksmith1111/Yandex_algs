#include <iostream>
#include <vector>
#include <assert.h>
#include <exception>

template <typename T>
class AdvancedVector{
public:
	AdvancedVector(int a = 0):number_of_elems(a), user(a){};
	AdvancedVector(const AdvancedVector& copied):number_of_elems(copied.number_of_elems), user(copied){}
	AdvancedVector(AdvancedVector&& useless):number_of_elems(useless.number_of_elems), user(useless){}
	~AdvancedVector(){}

	AdvancedVector& operator=(const AdvancedVector& copied){
		if(*this == copied){
			return *this;
		}
		user.clear();
		number_of_elems = copied.number_of_elems;
		user = copied;
		return *this;
	}

	AdvancedVector& operator=(AdvancedVector&& copied){
		if(copied == *this){
			return *this;
		}
		number_of_elems = copied.number_of_elems;
		copied.number_of_elems = 0;
		user.insert(user.begin(), copied.user.begin(), copied.user.end());
		copied.user.clear();
	};
	
	T& operator[](int index){
		if(index < 0){
			assert(abs(index) <= user.size());
			return user[number_of_elems + index];
		}
		else{
			//std::cout << user.size() << "\n";
			assert(abs(index) < user.size());
			return user[index];
		}
	}

	void number_of_elements_getter(){
		std::cout << number_of_elems << "\n";
	}

	void push_back(const T& el){
		user.push_back(el);
	}

private:
	size_t number_of_elems;
	std::vector<T> user;
};

int main(){
	AdvancedVector<int> a;
	AdvancedVector<int> b(8);
	a.number_of_elements_getter();
	b.number_of_elements_getter();
	a.push_back(5);
	std::cout << a[0] << "\n";
	return 0;
}