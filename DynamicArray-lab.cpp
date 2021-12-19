#include <iostream>
#include "DArray.h"
#include <cstdlib>













int main() {
	DArray<int> array(5);
	for (int i = 0; i < 9; i++) {
		array.insert(i * 2);
	}
	array.insert(0, 0);
	//DArray<int> arr(2);
	//arr.insert(1);
	//arr.insert(2);
	//arr.insert(5);
	//arr.insert(8);
	//arr.remove(12);
	std::cout << array.size() << std::endl;
	std::cout << std::endl;
	for (auto it = array.iterator(); it.hasNext(); it.next()) {
		std::cout << it.get() << std::endl;
		//it.set(it.get() * 15);
		//std::cout << it.get() << std::endl;
	}
}
