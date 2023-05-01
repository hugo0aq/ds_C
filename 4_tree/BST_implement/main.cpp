#include <iostream>
#include <queue>
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

		int Min() {
			BSTNode *tmp = this;

			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
			return tmp->data;
		}

		int Max() {
			BSTNode *tmp = this;
			while (tmp->right != NULL) {
				tmp = tmp->right;
			}
			return tmp->data;
		}

		int Height() {
			int LeftH, RightH;
			if (this == NULL) {
				return 0;
			}
			LeftH = this->left->Height();
			RightH = this->right->Height();
			return (LeftH >= RightH ) ? LeftH + 1 : RightH + 1;
		}


		//Use Queue
		void Levelorder() {
			if (this == NULL)
				return;
			queue<BSTNode *>Q;
			Q.push(this);
			while (!Q.empty()) {
				BSTNode *current = Q.front();
				cout << current->data << ' ';
				if (current->left != NULL)
					Q.push(current->left);
				if (current->right != NULL)
					Q.push(current->right);
				Q.pop();
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

	BSTNode *root = new BSTNode(6);
	BSTNode *root_child_L;
	BSTNode *root_child_R;
	root->print_node();
	root->Insert(2);
	root->Insert(9);
	root->Insert(3);
	root->Insert(1);
	root_child_L = root->GetLeftPtr();
	root_child_R = root->GetRightPtr();
	root->print_node();
	cout << "min=" << root->Min() << endl;
	cout << "max=" << root->Max() << endl;
	cout << "height=" << root->Height() << endl;
	cout << "tree level order=" ;
	root->Levelorder();
//	root_child_L->print_node();
	return 0;
}