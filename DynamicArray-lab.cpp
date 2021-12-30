#include <iostream>
#include "DArray.h"
#include <cstdlib>

int main() {
	DArray<int> arr(2);

	std::cout << "Adding elements to the array: 1, 2, 5, 8."<< std::endl;
	arr.insert(1);
	arr.insert(2);
	arr.insert(5);
	arr.insert(8);
	std::cout << "Output the entire array to the screen." << std::endl;
	for (auto it = arr.iterator(); it.hasNext(); it.next()) {
		std::cout << it.get() << std::endl;
	}
	std::cout << "Delete the element with index 2 (the value of this element is 5)." << std::endl;
	arr.remove(2);
	std::cout <<"Array size: " << arr.size() << std::endl;
	std::cout << "Output the entire array to the screen." << std::endl;
	for (auto it = arr.iterator(); it.hasNext(); it.next()) {
		std::cout << it.get() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Checking the iterator. Multiply each value by 15." << std::endl;
	for (auto it = arr.iterator(); it.hasNext(); it.next()) {
		it.set(it.get() * 15);
		std::cout << it.get() << std::endl;
	}
}
