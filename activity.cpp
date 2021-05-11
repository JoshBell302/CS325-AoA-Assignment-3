#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#define LAYER_VAL 5
#define ROW_LEN 20
#define COL_LEN 3

int main() {
	// Initialize variables
	int array[LAYER_VAL][ROW_LEN][COL_LEN];
	int lengthOfActs[LAYER_VAL];
	int numOfActs = 0;
	int layerNum = -1;
	int indexForActs = 0;
	int indexForArr = 0;
	std::string str;

	// Begin reading file called "act.txt"
	std::ifstream file("act.txt");
	if(file.is_open()){
		// This loop goes untill there are no more activities to read
		while (std::getline(file, str)) {
			numOfActs = std::stoi(str);
			lengthOfActs[indexForActs] = numOfActs;
			indexForActs++;
			layerNum++;
			// The getline above obtains the number of activities to read, that number is placed in the for loop to read each activity
			// Each activity has 3 values: 
			// First 	- 	The Activity number
			// Second 	- 	The starting number
			// Thrid 	- 	The ending number 
			for(int i = 0; i < numOfActs; i++) {
				// This grabs the line with all values for the activity
				std::getline(file, str);
				// This loop is to decifer the values in the string and correctly read them into the array
				for (int j = 0; j < str.length(); j++) {
					if (str[j+1] == ' ' || str[j+1] == '\0') {
						array[layerNum][i][indexForArr] = str[j] - '0';
						indexForArr++;
						j++;
					}
					else {
						array[layerNum][i][indexForArr] = (str[j+1] - '0') + 10;
						indexForArr++;
						j = j + 2;
					}
				}
				indexForArr = 0;
			}
	  	}
	}
	else
		std::cout << "Could not load the file";

	for (int i = 0; i < layerNum + 1; i++) {
		std::cout << "Activity number " << i + 1 << std::endl;
		for (int j = 0; j < lengthOfActs[i]; j++){
			for (int k = 0; k < COL_LEN; k++){
				std::cout << array[i][j][k] << " ";
			}
			std::cout << "---Thats one act\n";
		}
		std::cout << "--- Thats all from that one\n\n\n";
	}
	return 0;
}