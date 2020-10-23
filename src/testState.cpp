#include "DTM.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
	State test_state = State("q0", 1, 0, 0);
	std::cout << test_state.is_initial();
	std::cout << "\n";
	std::cout << test_state.is_accepting();
	std::cout << "\n";
	std::cout << test_state.is_rejecting();
	std::cout << "\n";
	
	return 0;
}