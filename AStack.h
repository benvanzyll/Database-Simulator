// array-based stack class

#include "Stack.h"

template <typename E>
class AStack : public Stack<E> {
    
    private:
        int maxSize; // max size of stack
        int stackSize; // number of elements in stack right now
        E* stackArray; // array holding all the elements in the stack
    
    public:
        // constructor
        AStack(int size);

        // destructor
        ~AStack();

        // clears the stack
        void clear();

        // pushes item onto stack
        void push(const E& item);

        // removes top item from stack and returns it
        E pop();

        // returns the top item in the stack
        E topValue();

        // returns the size of the stack
        int length();

};

/*
AStack()

This is the constructor for the AStack
object. It takes an integer value as a
parameter and creates and array with a
maximum size of whatever value is passed.
The stack is based on that array.

param: int size
return: n/a
*/
template<typename E>
AStack<E>::AStack(int size) {
    maxSize = size;
    stackSize = 0;
    stackArray = new E[maxSize];
}

/*
~AStack()

This is the destructor for the AStack
object. It deletes the array that the
stack is derived from.

param: n/a
return: n/a
*/
template<typename E>
AStack<E>::~AStack() {
    delete[] stackArray;
}

/*
clear()

This is the clear method for the AStack
object. It deletes the array that the
stack is derived from, assigns the stack
size to zero, then creates another empty
array of size maxSize to simulate removing
the contents of the stack.

param: n/a
return: n/a
*/
template<typename E>
void AStack<E>::clear() {
    delete[] stackArray;
    stackSize = 0;
    stackArray = new E[maxSize];
}

/*
push()

This is the push method for the AStack
object. It adds an item of type E to the
top of the stack. It checks to make sure
that there is space in the array that the 
stack is derived from; if there IS space,
it iterates through the stack and moves
each item up one space, then assigning the
first element of the array that the stack is
derived from to whatever item is passed as a
parameter. Finally, it increments the stack
size.

param: const E& item
return: n/a
*/
template<typename E>
void AStack<E>::push(const E& item) {
    if (stackSize >= maxSize) {
        return;
    }
    for (int i = stackSize; i > 0; i--) {
        stackArray[i] = stackArray[i-1];
    }
    stackArray[0] = item;
    stackSize++;
}

/*
pop()

This is the pop method for the AStack
object. It returns and removes the item
at the top of the stack. It checks to make
sure the stack is not empty; if it IS NOT 
empty, it creates a new item of type E whose
value is the first element of the array that
the stack is derived from. It then iterates
through the array and moves each item back one
space, decrements the stack size, and returns 
the item variable that was assigned the old 
top value from the stack.

param: n/a
return: E item
*/
template<typename E>
E AStack<E>::pop() {
    if (stackSize <= 0) {
        E item = E();
        return item;
    }
    E item = stackArray[0];
    for (int i = 0; i < stackSize; i++) {
        stackArray[i] = stackArray[i+1];
    }
    stackSize--;
    return item;
}

/*
topValue()

This is the topValue method for the AStack
object. It returns the top item from the stack,
or the first item in the array that the stack is
derived from. It checks to make sure the array is
not empty; if it is not, it returns the first
element in the array, or "top value" of the stack.

param: n/a
return: E item
*/
template<typename E>
E AStack<E>::topValue() {
    if (stackSize <= 0) {
        E item = E();
        return item;
    }
    return stackArray[0];
}

/*
length()

This is the length method for the AStack
object. It returns the length of the array
that the stack is derived from, simply
returning the value of the stackSize 
variable.

param: n/a
return: int stackSize
*/
template<typename E>
int AStack<E>::length() {
    return stackSize;
}
