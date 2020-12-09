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

/*
class Solution {
public:
    Node* connect(Node* root) {
        Node* head {root};
        Node* prev_head {nullptr};
        while (head) {
            link_level(prev_head, head);
            prev_head = head;
            head = get_next_head(head);
        }
        return root;
    }

private:
	// finds the next available head. returns null if none is available
    Node* get_next_head(Node* head) {
        while (head) {
            if (head->left) return head->left;
            if (head->right) return head->right;
            head = head->next;
        }
        return nullptr;
    }

	// links a level, given the head of the level and head of the previous level
    void link_level(Node* parent, Node* head) {
        Node* prev = head;
        while (parent) {
            if (parent->left && parent->left != prev) {
                prev->next = parent->left;
                prev = prev->next;
            }
            if (parent->right && parent->right != prev) {
                prev->next = parent->right;
                prev = prev->next;
            }
            parent = parent->next;
        }
    }
};


*/
// Test anohter solution
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                Node* tmp = q.front(); 
                q.pop();
                if(tmp->left) {
                    q.push(tmp->left);
                    if((tmp->left->next = tmp->right) == nullptr){
                        for(auto m = tmp->next; m!= nullptr; m = m->next){
                            if((tmp->left->next = m->left) != nullptr || 
                               (tmp->left->next = m->right) != nullptr)
                                break;
                        }
                    }
                }
                if(tmp->right) {
                    q.push(tmp->right);
                    if(tmp->next){
                        for(auto m = tmp->next; m!= nullptr; m = m->next){
                            if((tmp->right->next = m->left) != nullptr || 
                               (tmp->right->next = m->right) != nullptr)
                                break;
                        } 
                    } else {
                        tmp->right->next = nullptr;
                    }
                }
            }
        }
        return root;
    }
};