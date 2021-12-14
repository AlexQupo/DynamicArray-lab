#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Iterator {
	const T& get() const;

	void set(const T& value);

	void next();

	bool hasNext() const;
};

template <typename T>
class Array final {
public:
	Array();
	Array(int capacity);

	~Array();

	int insert(const T& value);
	int insert(int index, const T& value);

	void remove(int index);

	const T& operator[](int index) const;
	T& operator[](int index);

	int size() const;

	Iterator iterator();
	ConstIterator iterator() const;

	Iterator reverseIterator();
	ConstIterator reverseIterator() const;
};

