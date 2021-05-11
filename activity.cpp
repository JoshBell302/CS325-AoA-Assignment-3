#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#define ROW_LEN 20
#define COL_LEN 3

int main() {
	int array[ROW_LEN][COL_LEN];
	int numOfActs = 0;
	int index = 0;
	std::string str;

	std::ifstream file("act.txt");
	if(file.is_open()){
		while (std::getline(file, str)) {
			numOfActs = std::stoi(str);
			std::cout << "The number of activites is: " << numOfActs << std::endl;
			for(int i = 0; i < numOfActs; i++) {
				std::getline(file, str);
				for (int j = 0; j < str.length(); j++) {
					if (str[j+1] == ' ' || str[j+1] == '\0') {
						array[i][index] = str[j] - '0';
						std::cout << array[i][index] << " ";
						index++;
						j++;
					}
					else {
						array[i][index] = (str[j+1] - '0') + 10;
						std::cout << array[i][index] << " ";
						index++;
						j = j + 2;
					}
				}
				index = 0;
				std::cout << "\n";
			}
    		
	  	}
	}
	else
		std::cout << "Could not load the file";

	return 0;
}