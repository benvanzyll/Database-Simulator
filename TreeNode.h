// abstract TreeNode class

template <typename E>
class TreeNode{
public:
  E value; // data value
  string key; // key for the tree
  TreeNode* left; // left child pointer
  TreeNode* right; // right child pointer

  TreeNode(){
    key = "NULL";
    value = NULL;
    left = nullptr;
    right = nullptr;
  }
  TreeNode(string key, E value){
    this->key = key;
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
  virtual ~TreeNode(){}
};
