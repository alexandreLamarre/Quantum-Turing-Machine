#include <iostream>
#include <vector>
#include <string>

class DTM{
	public:
		std::vector<int> states;
		std::vector<int> tape;
		std::vector<std::string> alphabet;
		char blankSymbol;
		int head;
		DTM(std::vector<int> states, std::string input_alphabet, char blank){
			states = states;
			blankSymbol = blank;
			head = 0;
		}
};