#pragma once
#include <iostream>
#include <string.h>

template <class T>
class DynamicArray
{
private:
	T* arr = nullptr;	// Element's array
	int len = 0;		// Supposed array size
	int capacity = 0;	// Actual array size

public:
	DynamicArray() { this(16); }	// Default constructor
	DynamicArray(int capacity);		// Constructor with specified capacity

	int size() { return len; }					// Returns the lenght of the array
	bool isEmpty() { return size() == 0; }		// Returns true if the array's size is 0
	
	T get(int index);							// Gets the value stored at this index
	T set(int index, T elem);					// Updates a value in the array
	void clear();								// Clears the whole array
	void add(T elem);							// Adds a new element
	T removeAt(int rmIndex);					// Remove a element with a specific index

	int indexOf(T elem);									// Returns the index of the inputted element
	bool contains(T elem) { return indexOf(elem) != -1; }	// Checks if the element is there

	void toString();							// Prints the whole array 

	void delArr() { delete[] arr; }				// Frees the memory arr used

	T inputValue();							// User inputs a value
	int inputIndex();						// User inputs an index
};

// Constructor with specified capacity
template <class T>
DynamicArray<T>::DynamicArray(int pCapacity)	
{
	try
	{
		capacity = pCapacity;			// Assign the capacity to the object
		arr = new T[capacity];			// Make an array with the capacity given
	}
	catch (std::bad_array_new_length& e) 
	{ 
		std::cerr << "Invalid array lenght. Exception thrown: " << e.what() << std::endl; 
		capacity = 1;
		arr = new T[capacity];
	}
}

// Gets the value stored at this index
template <class T>
T DynamicArray<T>::get(int index)
{
	try
	{
		// If the index is out of bounds, throw an exception
		if (index >= len || index < 0) throw 2;

		// If not, return the desired value
		return arr[index];
	}
	catch (int x) 
	{
		std::cout << "Index is out of bounds. Error no. " << x << std::endl;
		return 0;		// Returns a default value
	}
}

// Updates a value in the array
template <class T>
T DynamicArray<T>::set(int index, T elem)
{
	try
	{
		// If the index is out of bounds, throw an exception
		if (index >= len || index < 0) throw 2;

		// To then return the value it used to have
		T data = arr[index];

		// If not, return the desired value
		arr[index] = elem;

		return data;
	}
	catch (int x) { std::cout << "Index is out of bounds. Error no. " << x << std::endl; return 0; }
}

// Clears the whole array
template <class T>
void DynamicArray<T>::clear()
{
	// Makes every value 0
	for (int i = 0; i < len; i++) arr[i] = 0;

	// Updates the lenght of the array
	len = 0;
}

// Adds a new element
template <class T>
void DynamicArray<T>::add(T elem)
{
	// If the new element is surpassing the limit of the array
	if (len + 1 >= capacity)
	{
		if (capacity == 0) capacity = 1;	// If empty, start at one
		else capacity *= 2;					// Double the size
		T* newArr = new T[capacity];

		// Copies the new array but now with more slots
		for (int i = 0; i < len; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}

	// Writes the new element in the now available space
	arr[len++] = elem;
}

// Remove a element with a specific index
template <class T>
T DynamicArray<T>::removeAt(int rmIndex)
{
	try
	{
		// If the index is out of bounds, throw an exception
		if (rmIndex >= len || rmIndex < 0) throw 2;

		T data = arr[rmIndex];							// Saves the removed data
		T* newArr = new T[len - 1];						// Makes a new array to skip the one at rmIndex

		for (int i = 0, j = 0; i < len; i++, j++)
		{
			if (i == rmIndex) j--;						// If it is at rmIndex, skip it
			else newArr[j] = arr[i];					// If not, copy it
		}

		// Make the new array the main one
		delete[] arr;
		arr = newArr;

		// Update the capacity and lenght of the array
		capacity = --len;

		// Return the now removed data
		return data;
	}
	catch (int x) { std::cout << "Index is out of bounds. Error no. " << x << std::endl; return 0; }
}

// Checks the index of the inputted element
template <class T>
int DynamicArray<T>::indexOf(T elem)
{
	for (int i = 0; i < len; i++) 
		if (arr[i] == elem) return i;
	return -1;
}

// Prints the whole array 
template <class T>
void DynamicArray<T>::toString()
{

	std::cout << "\n\nLenght: " << len << std::endl;
	if (isEmpty()) std::cout << "[]";
	for (int i = 0; i < len; i++)
		std::cout << "[" << arr[i] << "]";
	std::cout << "\n\n";
}

// User inputs an index or value parameter
template <class T>
T DynamicArray<T>::inputValue()
{
	T value;
	while ((std::cout << "Enter the value: ") && (!(std::cin >> value)))
	{
		std::cerr << "\tError: Invalid value.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return value;
}

// User inputs an index
template <class T>
int DynamicArray<T>::inputIndex()
{
	if (isEmpty()) return 0;

	int index;
	while ((std::cout << "Enter the index: ") && (!(std::cin >> index) || index >= len || index < 0))
	{
		std::cerr << "\tError: Invalid index.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return index;
}