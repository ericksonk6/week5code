#include <iostream>
#include <list>
using namespace std;

//compute the maximum number of nodes in any level of the binary tree
//level order traversal of the tree and calculate the number of nodes at that level
//calculate the maximum number of nodes in any level in the tree


//store Binary Tree node
struct Node{
    int key;
    Node* left; //left edge
    Node* right; //right edge

   Node(int key){
        this->key = key;
        this->left = this->right = nullptr;
    }

};

void MaxWidth(Node* root){
    //return if tree is empty
    if(root == nullptr) {
        return;
    }
        //create a queue containing the roots
        list<Node *> queue;

        //push root to first element of the queue
        queue.push_back(root);

        //create pointer to store current node
        Node* curr = nullptr;

        //maximum
        int max = 0;

        //loop until queue empty
        while (!queue.empty()){

            //calculate the number of nodes in the cur level
            int width = queue.size();

            //update maximum width of nodes in cur level
            if(max < width){
                max = width;
            }

            //process every node of cur level and enqueue their
            // non empty left & right child into the queue
            while (width--){
                curr = queue.front();
                queue.pop_front();

                if (curr->left){
                    queue.push_back(curr->left);
                }

                if(curr->right){
                    queue.push_back(curr->right);
                }
            }

        }

        cout << "Maximum width is " << max;
    }


int main() {
    Node* root = nullptr;

    root = new Node(15);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    MaxWidth(root);

    return 0;
}
