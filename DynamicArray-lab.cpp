//#include <iostream>
//

//template<typename T>
//class DArray final {
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
#include "DArray.h"
#include <cstdlib>
//using namespace std;

//done
template <typename T>
DArray<T>::DArray() : DArray(8) {
}

//done
template <typename T>
DArray<T>::DArray(int capacity) : capacity_(capacity), size_(0) {
	//size_ = sizeof(T);
	buffer_ = static_cast<T*>(malloc(sizeof(T) * capacity_));
	if (buffer_ == nullptr) {
		exit(1);
	}
}

//done
template <typename T>
DArray<T>::~DArray() {
	for (int i = 0; i < size_; ++i) {
		buffer_[i].~T();
	}
	free(buffer_);
	size_ = 0;
	capacity_ = 0;
}

//done
template <typename T>
int DArray<T>::size() const {
	return size_;
}

//done
template <typename T>
T& DArray<T>::operator[](int index) {
	return buffer_[index];
}

//done
template <typename T>
const T& DArray<T>::operator[](int index) const {
	return buffer_[index];
}

//Move-Copy section -- done
template <typename T>//Copy constr
DArray<T>::DArray(const DArray& other) : capacity_(other.capacity_), size_(other.size_) {
	buffer_ = static_cast<T*>(malloc((sizeof(T) * capacity_)));
	//std::copy(other.buffer_, other.buffer_ + size_, buffer_);
	for (int i = 0; i < size_; i++) {
		new (buffer_ + i) T(other.buffer_[i]);
	}
}

template <typename T>//Move constr применена ФИЧА
DArray<T>::DArray(DArray&& other) : buffer_(nullptr), size_(0), capacity_(0) {
	*this = std::move(other);
}

template <typename T>//Copy assign
DArray<T>& DArray<T>::operator=(const DArray& other) {
	if (&other != this) {
		free(buffer_);
		size_ = other.size_;
		capacity_ = other.capacity_;
		buffer_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
		for (int i = 0; i < size_; i++) {
			new (buffer_ + i) T(other.buffer_[i]);
		}
	}
	return *this;
}

template <typename T>//Move assign
DArray<T>& DArray<T>::operator=(DArray&& other) {
	if (&other != this) {
		free(buffer_);
		buffer_ = other.buffer_;
		size_ = other.size_;
		capacity_ = other.capacity_;

		other.buffer_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}
	return *this;
}
//End section

//done
template <typename T>
int DArray<T>::insert(const T& value) {
	return insert(size_, value);
}

//done
template <typename T>
int DArray<T>::insert(int index, const T& value) {

	if (size_ == capacity_) {
		expansion(capacity_ * 2);
	}
	if (index < size_) {
		if (std::is_move_constructible<T>()) {
			for (int i = size_; i > index; i--) {
				new(buffer_ + i)T(std::move(*(buffer_ + i - 1)));
				(buffer_ + i - 1)->~T();
			}
		}
		else {
			for (int i = size_; i > index; i--) {
				new(buffer_ + i)T(*(buffer_ + i - 1));
				(buffer_ + i - 1)->~T();
			}
		}
	}
	new(buffer_ + index) T(value);
	size_++;
	return index;
}

//done
template <typename T>
void DArray<T>::expansion(int newCapacity) {
	T* tempBuffer = static_cast<T*>(malloc(newCapacity * sizeof(T)));
	if (std::is_move_constructible<T>()) {
		for (int i = 0; i < size_; i++) {
			new(tempBuffer + i)T(std::move(*(buffer_ + i)));
			(buffer_ + i)->~T();
		}
	}
	else {
		for (int i = 0; i < size_; i++) {
			new(tempBuffer + i)T(*(buffer_ + i));
			(buffer_ + i)->~T();
		}
	}
	free(buffer_);
	buffer_ = tempBuffer;
	capacity_ = newCapacity;
}

//done
template <typename T>
void DArray<T>::remove(int index) {
	(buffer_ + index)->~T();
	if (std::is_move_constructible<T>()) {
		for (int i = index; i < size_ - 1; i++) {
			new(buffer_ + i)T(std::move(*(buffer_ + i + 1)));
		}
	}
	else {
		for (int i = index; i < size_ - 1; i++) {
			new(buffer_ + i)T(*(buffer_ + i + 1));
		}
	}
	size_--;
}
//
//template <typename T>
//typename DArray<T>::Iterator DArray<T>::iterator() {
//	
//}
//template <typename T>
//const T& DArray<T>::Iterator::get() const {
//	
//}
//
//DArray<T>::
//





int main() {
	DArray<int> arr0;
	DArray<int> arr1(8);
	DArray<int> arr2(arr1);
	DArray<int> arr3 = arr2;
	DArray<int> arr = DArray<int>(arr1);
	arr2 = arr;
	std::cout << arr[0] << " " << arr[1];
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