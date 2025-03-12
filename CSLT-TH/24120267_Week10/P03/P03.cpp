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

void reverseNode(Node*& head) {
	Node* previous = nullptr;
	Node* zeroNode = new Node(0);
	zeroNode->next = head;
	head = zeroNode;
	while (head) {
		Node* next = head->next;
		head->next = previous;
		previous = head;
		head = next;
	}
	head = previous;
	if (head && head->data == 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
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
	Node* head = nullptr;
	ifstream inputFile("input.txt");

	if (!inputFile) {
		cerr << "Can't open input file." << endl;
		return 1;
	}

	string line;
	getline(inputFile, line);
	inputFile.close();

	stringstream ss(line);
	int num;
	while (ss >> num) {
		inputNode(head, num);
	}

	reverseNode(head);

	saveToFile(head, "output.txt");
	cout << "Updated!" << endl;

	freeList(head);

	return 0;
}