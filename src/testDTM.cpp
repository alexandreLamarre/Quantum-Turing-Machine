#include "DTM.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
	std::vector<int> test_states;
	std::string test_string = "abc";
	char blank = '#';
	DTM test_declaration = DTM(test_states, test_string, blank);
	
	return 0;
}