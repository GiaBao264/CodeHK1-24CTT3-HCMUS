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

void numberToList(unsigned int number, Node*& head) {
	if (number == 0) {
		inputNode(head, 0);
		return;
	}

	int digits[10];
	int length = 0;

	while (number > 0) {
		digits[length++] = number % 10;
		number /= 10;
	}

	for (int i = length - 1; i >= 0; --i) {
		inputNode(head, digits[i]);
	}

	inputNode(head, -1);
}

void freeList(Node* head) {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void saveListToFile(Node* head, const string& filename) {
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "Can't open output file." << endl;
		return;
	}

	while (head) {
		outfile << head->data << " ";
		head = head->next;
	}

	outfile.close();
}

int main() {
	unsigned int number;
	ifstream infile("input.txt");
	if (!infile) {
		cerr << "Can't open input file." << endl;
		return 1;
	}
	infile >> number;
	infile.close();

	Node* head = nullptr;
	numberToList(number, head);

	saveListToFile(head, "output.txt");

	freeList(head);

	return 0;
}