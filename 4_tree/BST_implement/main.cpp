#include <iostream>
using namespace std;

class BSTNode {
	private:
		int data;
		BSTNode *left;
		BSTNode *right;

	public:
		BSTNode(int data) {
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
		BSTNode *GetLeftPtr() {
			return this->left;
		}
		BSTNode *GetRightPtr() {
			return this->right;
		}
		void Insert(int data) {
			if (data <= this->data) {
				if (this->left == NULL) {
					this->left = new BSTNode(data);
				} else {
					this->left -> Insert(data);
				}
			} else {
				if (this->right == NULL) {
					this->right = new BSTNode(data);
				} else {
					this->right -> Insert(data);
				}
			}
		}

		bool Search(int val) {
			if (this->data == val) {
				cout << "Found" << endl;
				return true;
			} else if (this->data >= val) {
				if (this->left == NULL) {
					cout << "Not Found" << endl;
					return false;
				} else {
					return (this->left)->Search(val);
				}
			} else {
				if (this->right == NULL) {
					cout << "Not Found" << endl;
					return false;
				} else {
					return (this->right)->Search(val);
				}
			}
		}
		void print_node () {
			cout << "Value at the node: " << this -> data << endl;
			if (this -> left != NULL)
				cout << "Value at left node: " << this -> left -> data << endl;
			if (this -> right != NULL)
				cout << "Value at right node: " << this -> right -> data << endl;
		}

};

int main(int argc, char **argv) {
	cout << "Hello, World!" << endl;

	BSTNode *root = new BSTNode(6);

	root->print_node();
	root->Insert(2);
	root->Insert(9);
	root->Insert(3);
	
	root->print_node();
	BSTNode *root_child_L = root->GetLeftPtr();
	BSTNode *root_child_R = root->GetRightPtr();
	root_child_L->print_node();
	return 0;
}