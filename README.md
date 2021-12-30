# DynamicArray-lab
 
One of the most important tasks in the development of programs is the task
of organizing storage and providing access to data. This task
is solved with the help of various data containers that provide
memory management necessary for data storage and
provide interfaces for accessing stored data.

Task
Your task is to implement a dynamic array AD
```C++
template<typename T>
class Array final
```
must support the following operations:
```
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
```
Memory management should be implemented through the malloc() and
free() functions.

The iterator should be implemented as an internal class for Array<T>, and
provide the following interface:
```
const T& get() const;
Retrieves the array value at the current iterator position.

void set(const T& value);
Sets the value at the current iterator position.

void next();
Moves the current iterator position to the next element.

bool hasNext() const;
Returns true if the iterator can move to the next
element, or false otherwise.
```
 
To develop Google Test for these classes.
