/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void change_next(Node* cur_node, Node* cur_left, Node* cur_right){
        if(cur_left != nullptr){       
            cur_left->next = cur_right;
            if(cur_node->next != nullptr)
                cur_right->next = cur_node->next->left;
            else
                cur_right->next = nullptr;
            change_next(cur_left, cur_left->left, cur_left->right);
            change_next(cur_right, cur_right->left, cur_right->right);
        }
        return;
    }
    
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        change_next(root, root->left, root->right);
        return root;
        
    }
};