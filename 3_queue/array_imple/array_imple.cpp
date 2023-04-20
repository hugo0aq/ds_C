#include <iostream>
using namespace std;
#define N 10

class Queue {
	private:
		int A[N];
		int front, rear;
	public:

		//init
		Queue() {
			front = -1;
			rear = -1;
		}

		//Check is empty
		bool IsEmpty() {
			return (front == -1 && rear == -1);
		}

		// heck is empty
		bool IsFull() {
			return (rear + 1) % N == front ? true : false;
		}

		//
		void Enqueue(int x) {
			if (IsFull()) {
				cout << "Error: Queue is Full\n";
				return;
			}
			if (IsEmpty()) {
				front = rear = 0;
			} else {
				rear = (rear + 1) % N;
			}
			A[rear] = x;
		}

		//
		void Dequeue() {
			if (IsEmpty()) {
				cout << "Error: Queue is Empty\n";
				return;
			} else if (front == rear ) {
				rear = front = -1;
			} else {
				front = (front + 1) % N;
			}
		}
		// Returns queue front
		int Front() {
			if (front == -1) {
				cout << "Error: cannot return front from empty queue\n";
				return -1;
			}
			return A[front];
		}

		void Print() {

			int count = (rear + N - front) % N + 1;
			cout << "Queue       : ";
			for (int i = 0; i < count; i++) {
				int index = (front + i) % N;
				cout << A[index];
			}
			cout << "\n\n";
		}
};

int main() {

	Queue Q;


	Q.Enqueue(6);
	Q.Print();
	Q.Enqueue(7);
	Q.Print();
	Q.Front();
	Q.Dequeue();
	Q.Print();
}