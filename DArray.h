#include <iostream>

template <typename T>
class DArray final {
private:
	T* buffer_;
	int capacity_;
	int size_;

	void expansion(int newCapacity);

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
			if(!hasNext()) return;

			current_ += setDirection();
		}

		bool hasNext() const {
			return current_ != last_;
		}
	};
	class ConstIterator{
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
	DArray();
	DArray(int capacity);

	~DArray();

	int insert(const T& value);
	int insert(int index, const T& value);

	void remove(int index);

	const T& operator[](int index) const;
	T& operator[](int index);

	int size() const;

	//Constructor
	//Copy
	DArray(const DArray& other);

	//Move
	DArray(DArray&& other);

	//Assignment
	//Copy
	DArray& operator=(const DArray& other);
	//Move
	DArray& operator=(DArray&& other);

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

