#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

void inputNode(Node*& head, int value) {
	Node* newNode = new Node(value);
	newNode->data = value;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void mergeList(Node* in1, Node* in2, Node*& out) {
	if (!in1) {
		out = in2;
		return;
	}
	if (!in2) {
		out = in1;
		return;
	}
	out = in1;
	Node* temp = in1;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = in2;
}

void saveToFile(Node* head, const string& filename) {
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "Can't open output file." << endl;
		return;
	}
	Node* temp = head;
	while (temp) {
		outfile << temp->data << " ";
		temp = temp->next;
	}
	outfile.close();
}

void freeList(Node* head) {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	Node* head1 = nullptr;
	Node* head2 = nullptr;
	ifstream inputFile1("input1.txt");
	ifstream inputFile2("input2.txt");
	string line;
	if (inputFile1.is_open()) {
		while (getline(inputFile1, line)) {
			istringstream iss(line);
			int value;
			while (iss >> value) {
				inputNode(head1, value);
			}
		}
		inputFile1.close();
	}
	if (inputFile2.is_open()) {
		while (getline(inputFile2, line)) {
			istringstream iss(line);
			int value;
			while (iss >> value) {
				inputNode(head2, value);
			}
		}
		inputFile2.close();
	}
	Node* head = nullptr;
	mergeList(head1, head2, head);
	saveToFile(head, "output.txt");
	cout << "Updated!" << endl;
	freeList(head);
	freeList(head1);
	freeList(head2);
	return 0;
}