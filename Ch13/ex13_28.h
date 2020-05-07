class TreeNode {
    TreeNode()
        : value(string()), count(new int(1)), left(nullptr), right(nullptr)
    {}

    TreeNode(const TreeNode& rhs)
        : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
    {
        ++*count;
    }

    TreeNode& operator=(const TreeNode& rhs);
    ~TreeNode()
    {
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
    std::string  value;
    int         *count;
    TreeNode    *left;
    TreeNode    *right;

};