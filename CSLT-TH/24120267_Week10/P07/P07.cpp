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

void splitList(Node* head, Node*& out1, Node*& out2) {
	Node* temp = head;
	while (temp) {
		inputNode(out1, temp->data);
		if (temp->next) {
			temp = temp->next;
			inputNode(out2, temp->data);
		}
		else {
			break;
		}
		if (temp->next) {
			temp = temp->next;
		}
		else {
			break;
		}
	}
	inputNode(out1, 0);
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

	Node* out1 = nullptr;
	Node* out2 = nullptr;

	splitList(head, out1, out2);

	saveToFile(out1, "out1.txt");
	saveToFile(out2, "out2.txt");
	cout << "Updated!" << endl;

	freeList(head);
	freeList(out1);
	freeList(out2);

	return 0;
}