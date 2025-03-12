#include <iostream>
using namespace std;

struct node {
    int key;
    node* next;
};

void printList(node* h) {
    while (h != nullptr) {
        cout << h->key << " ";
        h = h->next;
    }
    cout << endl;
}

void destroyList(node*& h) {
    while (h != nullptr) {
        node* temp = h;
        h = h->next;
        delete temp;
    }
}

node* getNode(int k) {
    node* p = new node;
    p->key = k;
    p->next = nullptr;
    return p;
}

void makeOrderedList(node*& h, int k) {
    node* newNode = getNode(k);
    if (h == nullptr || h->key <= k) {
        newNode->next = h;
        h = newNode;
        return;
    }
    node* current = h;
    while (current->next != nullptr && current->next->key > k) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    node* head = nullptr;
    int k;
    cout << "Vui long nhap so : " << endl;
    while (true) {
        cin >> k;
        if (k == 0) {
            break;
        }
        makeOrderedList(head, k);
    }
    cout << "Danh sach da sap xep: ";
    printList(head->next);
    destroyList(head);
    return 0;
}