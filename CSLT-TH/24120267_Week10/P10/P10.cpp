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

unsigned int listToNumber(Node* head) {
	unsigned int number = 0;
	while (head && head->data != -1) {
		number = number * 10 + head->data;
		head = head->next;
	}
	return number;
}

void freeList(Node* head) {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	Node* head = nullptr;
	ifstream infile("input.txt");
	if (!infile) {
		cerr << "Can't open input file." << endl;
		return 1;
	}
	string line;
	getline(infile, line);
	istringstream iss(line);
	int value;
	while (iss >> value) {
		inputNode(head, value);
	}
	infile.close();
	unsigned int number = listToNumber(head);
	ofstream outfile("output.txt");
	if (!outfile) {
		cerr << "Can't open output file." << endl;
	}
	outfile << number;
	outfile.close();
	freeList(head);
	return 0;
}