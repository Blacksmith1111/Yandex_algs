#include <iostream>

int Fib(int n){
	int fib1 = 0, fib2 = 1;
	if(n == 1){
		return fib1;
	}
	if(n == 2){
		return fib2;
	}
	return Fib(n-2) + Fib(n-1);
}



int main(){
	std::cout << Fib(7) << "\n";
	return 0;
}