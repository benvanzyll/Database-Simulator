template<typename E>
class Stack {
    public:    
        Stack() {}
        virtual ~Stack() {}

        // reinitializes the stack
        virtual void clear() = 0;

        // push an element onto the top of the stack
        // param: element being pushed
        virtual void push(const E& item) = 0;

        // remove element from top of stack, return element at top
        // return the element at top
        virtual E pop() = 0;

        // return the element at the top
        virtual E topValue() = 0;

        // return the number of elements in the stack
        virtual int length() = 0;
};