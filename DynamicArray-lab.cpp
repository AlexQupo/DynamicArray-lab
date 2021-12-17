//#include <iostream>
//

//template<typename T>
//class Array final {
//
//};
//
//
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}





#include <iostream>
#include "Array.h"
#include <cstdlib>
using namespace std;

//done
template <typename T>
Array<T>::Array() : capacity_(8), size_(0) {
	//size_ = sizeof(T);
	//capacity_ = 1;
	buffer_ = static_cast<T*>(malloc(sizeof(T) * capacity_));
	if (buffer_ == nullptr) {
		exit(1);
	}
}

//done
template <typename T>
Array<T>::Array(int capacity) : capacity_(capacity) {
	//size_ = sizeof(T);
	buffer_ = static_cast<T*>(malloc(sizeof(T) * capacity_));
	if (buffer_ == nullptr) {
		exit(1);
	}
}

//done
template <typename T>
Array<T>::~Array() {
	for (int i = 0; i < size_; ++i) {
		buffer_[i].~T();
	}
	free(buffer_);
	size_ = 0;
	capacity_ = 0;
}

//done
template <typename T>
int Array<T>::size() const {
	return size_;
}

//done
template <typename T>
T& Array<T>::operator[](int index) {
	return buffer_[index];
}

//done
template <typename T>
const T& Array<T>::operator[](int index) const {
	return buffer_[index];
}









//Move-Copy section
template <typename T>
Array<T>::Array(const Array& other) : capacity_(other.capacity_), size_(other.size_) {
	buffer_ = static_cast<T*>(malloc((sizeof(T) * capacity_)));

	for (int i = 0; i < size_; i++) {
		new (buffer_ + i) T(other[i]);
	}
}

template <typename T>
Array<T>::Array(Array&& other) {
	swap(*this, other);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if(&other != this) {
		Array<T> tmp(other);
		swap(*this, tmp);
	}
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) {
	if(&other != this) {
		Array<T> tmp(move(other));
		swap(*this, tmp);
	}
	return *this;
}
//End section


template <typename T>
int Array<T>::insert(const T& value) {
	if(size_ == capacity_) {
		
	}
}

template <typename T>
int Array<T>::insert(int index, const T& value) {

}







int main() {
	Array<int> arr(5);
	arr[0] = 1;
	arr[2] = 2;

	cout << arr[0] << " " << arr[1];
}






//
//
//template<class T>
//class Queue { 
//	int size; 
//	T* queue; 
//	
//	public:
//	Queue() { 
//		size = 0;
//		queue = new T[100];
//	}
//	void add(T data) { 
//		queue[size] = data; 
//		size++;
//	}
//	void remove() { 
//		if (size == 0) { 
//			cout << "Queue is empty"<<endl; 
//			return; 
//		} 
//		else { 
//			for (int i = 0; i < size - 1; i++) { 
//				queue[i] = queue[i + 1]; 
//			} 
//			size--; 
//		} 
//	} 
//	void print() { 
//		if (size == 0) { 
//			cout << "Queue is empty"<<endl; 
//			return; 
//		} 
//		for (int i = 0; i < size; i++) { 
//			cout<<queue[i]<<" <- ";
//		} 
//		cout << endl;
//	}
//	Queue operator+(Queue &obj) {
//        Queue res;
//        for(int i=0;i<this->size;i++) {
//            res.add(this->queue[i]);
//        }
//        for(int i=0;i<obj.size;i++) {
//            res.add(obj.queue[i]);
//        }
//        return res; 
//    }
//}; 
//
//int main() { 
//	Queue<int> q1; 
//	q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
//	q1.print();
//    
//	Queue<string> q2;
//	q2.add("Dave"); q2.add("John"); q2.add("Amy");
//	q2.print();
//
//	return 0; 
//} 