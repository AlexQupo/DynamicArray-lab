#include "pch.h"
#include "../DArray.h"

TEST(Operations, Initialization) {
	DArray<int> array;
	ASSERT_EQ(array.size(),0);
}
TEST(Operations, Copy) {
	DArray<int> array(1);
	array.insert(101);
	DArray<int> array2(array);
	DArray<int> array3 = array2;
	ASSERT_EQ(array[0], array3[0]);
}

TEST(Insert, Tail_WithoutExpansion) {
	DArray<int> array(5);
	for (int i = 0; i < 5; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 
	for (int i = 0; i < array.size(); i++) {
		int trueNum = i * 2;
		ASSERT_EQ(array[i], trueNum);
	}
	ASSERT_EQ(array.size(), 5);
}

TEST(Insert, Tail_WithExpansion) {
	DArray<int> array(2);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	for (int i = 0; i < array.size(); i++) {
		int trueNum = i * 2;
		ASSERT_EQ(array[i], trueNum);
	}
	ASSERT_EQ(array.size(), 10);
}

TEST(Insert, Ahead) {
	DArray<int> array(10);
	for (int i = 0; i < 9; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16
	array.insert(0, 0);
	ASSERT_EQ(array[0], 0);
	for (int i = 1; i < array.size(); i++) {
		int trueNum = (i - 1) * 2;
		ASSERT_EQ(array[i], trueNum);
	}
	ASSERT_EQ(array.size(), 10);
}

TEST(Insert, Middle) {
	DArray<int> array(10);
	for (int i = 0; i < 9; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16
	array.insert(4, 101);
	ASSERT_EQ(array[4], 101);
	ASSERT_EQ(array.size(), 10);
}

TEST(Remove, Ahead) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	array.remove(0);
	ASSERT_EQ(array[0], 2);
	ASSERT_EQ(array.size(), 9);
}

TEST(Remove, Middle) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	array.remove(4);
	ASSERT_EQ(array[4], 10);
	ASSERT_EQ(array.size(), 9);
}

TEST(Iterator, Get) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	int i = 0;
	for (auto it = array.iterator(); it.hasNext(); it.next()) {
		int trueNum = i * 2;
		i++;
		ASSERT_EQ(it.get(), trueNum);
	}
}

TEST(Iterator, Set) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	int i = 0;
	for (auto it = array.iterator(); it.hasNext(); it.next()) {
		int trueNum = i * 5;
		i++;
		it.set(trueNum);
		ASSERT_EQ(it.get(), trueNum);
	}
}

TEST(Iterator, Reverse_Get) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	int i = 18;
	for (auto it = array.reverseIterator(); it.hasNext(); it.next()) {
		int trueNum = i;
		i -= 2;
		ASSERT_EQ(it.get(), trueNum);
	}
}

TEST(Iterator, Reverse_Set) {
	DArray<int> array(10);
	for (int i = 0; i < 10; i++) {
		array.insert(i * 2);
	} // 0 2 4 6 8 10 12 14 16 18
	int i = 0;
	for (auto it = array.reverseIterator(); it.hasNext(); it.next()) {
		int trueNum = i * 5;
		i++;
		it.set(trueNum);
		ASSERT_EQ(it.get(), trueNum);
	}
}