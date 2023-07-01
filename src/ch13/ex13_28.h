#ifndef CP5_ex13_28_h
#define CP5_ex13_28_h  

#include <string>
using std::string;


class TreeNode {
public: 
    TreeNode():value(string()), count(new int(1)), left(nullptr), right(nullptr){}
    TreeNode(const TreeNode& rhs):value(rhs.value),count(rhs.count), left(rhs.left), right(rhs.right){  ++*count;  }
    TreeNode& operator=(const TreeNode& rhs){
        ++*rhs.count;  
        if(--*count){
            if(left){
                delete left;
                left = nullptr;
            }

            if(right){
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
        count = rhs.count;
        value = rhs.value;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }

    ~TreeNode(){
        if (--*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }
            if (right) {
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }

private:
    std::string value;
    int* count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree{
public:
    BinStrTree():root(new TreeNode()){}
    BinStrTree(const BinStrTree& rhs): root(new TreeNode(*rhs.root)){}
    BinStrTree& operator=(const BinStrTree& rhs){
        TreeNode* temp = new TreeNode(*rhs.root);
        delete root;
        root = temp;
        return *this;
    }
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};


#endif