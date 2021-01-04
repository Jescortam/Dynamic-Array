#include "DynamicArray.h"
#include <iostream>

int main()
{
	// If true, exit the program
	bool is_finished = false;

	// Asking for array lenght
	int inCapacity;
	while ((std::cout << "\nHow many slots should the array have? ") && (!(std::cin >> inCapacity) || inCapacity <= 0))
	{
		std::cerr << "\tError: Invalid input.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Constructing the data structure
	DynamicArray<int> dataStruct(inCapacity);

	while (!is_finished) {

		// Displaying options
		std::cout << "\n__________________________________________________________________\n";
		std::cout << "\n\tWhat would you like to do?\n\n";
		std::cout << "1. Add an element.\n";
		std::cout << "2. Replace an element.\n";
		std::cout << "3. Search an element by its index.\n";
		std::cout << "4. Search an element by its value.\n";
		std::cout << "5. Show all elements.\n";
		std::cout << "6. Delete an element.\n";
		std::cout << "7. Delete all elements.\n";
		std::cout << "8. Exit.\n\n";

		// Chooses a function and validates the input
		int choice;
		while ((std::cout << "Choose a function: ") && (!(std::cin >> choice) || choice < 1 || choice > 8))
		{
			std::cerr << "\tError: Invalid input.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "\n__________________________________________________________________\n\n";

		int data;

		// Selecting the chosen function
		switch (choice)
		{
		case 1:		// Adds an element to the end of the array
			dataStruct.add(dataStruct.inputValue());
			break;
		case 2:		// Updates an element of the array and prints the value it had
			data = dataStruct.set(dataStruct.inputIndex(), dataStruct.inputValue());
			std::cout << "Last value: " << data << std::endl;
			break;
		case 3:		// Searches an element by its index and prints the value
			data = dataStruct.get(dataStruct.inputIndex());
			std::cout << "Value: " << data << std::endl;
			break;
		case 4:		// Searches an element by its value and prints the index
			data = dataStruct.indexOf(dataStruct.inputValue());
			if (data != -1)
				std::cout << "Element found at index: " << data << std::endl;
			else std::cout << "Element not found\n";
			break;
		case 5:		// Prints the entire array in a string
			dataStruct.toString();
			break;
		case 6:		// Removes an element of the array and prints the value it had
			data = dataStruct.removeAt(dataStruct.inputIndex());
			std::cout << "Value deleted: " << data << std::endl;
			break;
		case 7:		// Clears all the values the array had
			dataStruct.clear();
			std::cout << "Succesfully cleared the array.\n";
			break;
		case 8:		// Breaks the loop and frees the memory
			is_finished = true;
			dataStruct.delArr();
			break;
		}
	}
}