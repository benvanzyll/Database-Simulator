// abstract list node class with 2 pointers

template <typename E>
class ListNode{
public:
  E element;
  ListNode* prev; // pointer to previous node
  ListNode* next; // pointer to next node

  /*
  Constructor initializes prev and next pointers
  */
  ListNode(){
    prev = nullptr;
    next = nullptr;
  }

  /*
  Overloaded constructor initializes prev and next pointers and sets value of element
  @param elemVal: data value to be added to node
  */
  ListNode(E elemVal){
    element = elemVal;
    prev = nullptr;
    next = nullptr;
  }
  ~ListNode(){};
};
