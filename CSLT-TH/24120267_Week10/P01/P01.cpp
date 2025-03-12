#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void inputNode(Node*& head, int value) {
	Node* newNode = new Node;
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

void removeX(Node*& head, int x) {
	while (head && head->data == x) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	Node* current = head;
	while (current && current->next) {
		if (current->next->data == x) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else {
			current = current->next;
		}
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

	int x;
	cout << "Please enter X: ";
	cin >> x;

	removeX(head, x);

	saveToFile(head, "output.txt");
	cout << "Updated!" << endl;

	freeList(head);

	return 0;
}