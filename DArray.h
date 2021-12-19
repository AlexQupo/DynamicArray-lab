#include <iostream>

template <typename T>
class DArray final {
private:
	T* buffer_;
	int capacity_;
	int size_;

	//done
	void expansion(int newCapacity) {
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

	class Iterator {
	private:
		T* current_;
		T* last_;
		bool reverse_;

		int setDirection() {
			return reverse_ ? -1 : 1;
		}

	public:
		Iterator(DArray<T>& array, bool reverse = false) : reverse_(reverse) {
			if (reverse_) {
				current_ = array.buffer_ + array.size_ - 1;
				last_ = array.buffer_ - 1;
			}
			else {
				current_ = array.buffer_;
				last_ = array.buffer_ + array.size_;
			}
		}

		const T& get() const {
			return *current_;
		}

		void set(const T& value) {
			current_->~T();
			new(current_)T(value);
		}

		void next() {
			if (!hasNext()) return;

			current_ += setDirection();
		}

		bool hasNext() const {
			return current_ != last_;
		}
	};
	class ConstIterator {
	private:
		T* current_;
		T* last_;
		bool reverse_;

		int setDirection() {
			return reverse_ ? -1 : 1;
		}

	public:
		ConstIterator(const DArray<T>& array, bool reverse = false) : reverse_(reverse) {
			if (reverse_) {
				current_ = array.buffer_ + array.size_ - 1;
				last_ = array.buffer_ - 1;
			}
			else {
				current_ = array.buffer_;
				last_ = array.buffer_ + array.size_;
			}
		}

		const T& get() const {
			return *current_;
		}

		void next() {
			if (!hasNext()) return;

			current_ += setDirection();
		}

		bool hasNext() const {
			return current_ != last_;
		}
	};

public:
	//done

	DArray() : DArray(8) {
	}

	//done
	DArray(int capacity) : capacity_(capacity), size_(0) {
		//size_ = sizeof(T);
		buffer_ = static_cast<T*>(malloc(sizeof(T) * capacity_));
		if (buffer_ == nullptr) {
			exit(1);
		}
	}

	//done
	~DArray() {
		for (int i = 0; i < size_; ++i) {
			buffer_[i].~T();
		}
		free(buffer_);
		size_ = 0;
		capacity_ = 0;
	}

	//done
	int size() const {
		return size_;
	}

	//done
	T& operator[](int index) {
		return buffer_[index];
	}

	//done
	const T& operator[](int index) const {
		return buffer_[index];
	}

	//Move-Copy section -- done
	//Copy constr
	DArray(const DArray& other) : capacity_(other.capacity_), size_(other.size_) {
		buffer_ = static_cast<T*>(malloc((sizeof(T) * capacity_)));
		//std::copy(other.buffer_, other.buffer_ + size_, buffer_);
		for (int i = 0; i < size_; i++) {
			new (buffer_ + i) T(other.buffer_[i]);
		}
	}

	//Move constr применена ФИЧА
	DArray(DArray&& other) : buffer_(nullptr), size_(0), capacity_(0) {
		*this = std::move(other);
	}

	//Copy assign
	DArray& operator=(const DArray& other) {
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

	//Move assign
	DArray& operator=(DArray&& other) {
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
	int insert(const T& value) {
		return insert(size_, value);
	}

	//done
	int insert(int index, const T& value) {

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
	void remove(int index) {
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



	Iterator iterator() {
		return Iterator(*this);
	}
	ConstIterator iterator() const {
		return ConstIterator(*this, true);
	}
	Iterator reverseIterator() {
		return Iterator(*this, true);
	}
	ConstIterator reverseIterator() const {
		return ConstIterator(*this);
	}

};

