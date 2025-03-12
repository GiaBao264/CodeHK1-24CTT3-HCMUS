#include <iostream>
#include <malloc.h>

using namespace std;

int headSize = sizeof(int) + sizeof(int);

struct SOPHUC {
	int x, y;
};

istream& operator>>(istream& is, SOPHUC& sp) {
	is >> sp.x >> sp.y;
	return is;
}

ostream& operator<<(ostream& os, const SOPHUC& sp) {
	os << sp.x << " " << sp.y;
	return os;
}

int memSize(int nItem, int szItem) {
	return headSize + nItem * szItem;
}

void* origin_addr(void* aData) {
	if (aData != NULL) {
		return (char*)aData - headSize;
	}
	return NULL;
}

void* data_addr(void* aOrigin) {
	if (aOrigin != NULL) {
		return (char*)aOrigin + headSize;
	}
	return NULL;
}

void* sizeItem_addr(void* aData) {
	if (aData != NULL) {
		return (char*)aData - sizeof(int);
	}
	return NULL;
}

int arrSize(void* aData) {
	if (aData != NULL) {
		return *(int*)origin_addr(aData);
	}
	return 0;
}

int arrItemSize(void* aData) {
	if (aData != NULL) {
		return *(int*)sizeItem_addr(aData);
	}
	return 0;
}

//Item 2: giải phóng bộ nhớ nhưng con trở chưa set về NULL dễ gây lỗi.
void arrFree(void** aData) {
	if (aData != NULL && *aData != NULL) {
		free(origin_addr(*aData));
		*aData = NULL;
	}
}

void* arrInit(int nItem, int szItem) {
	int sz = memSize(nItem, szItem);
	void* aOrigin = malloc(sz);
	if (aOrigin != NULL) {
		memset(aOrigin, 0, sz);
		void* aData = data_addr(aOrigin);
		*(int*)origin_addr(aData) = nItem;
		*(int*)sizeItem_addr(aData) = szItem;
		return aData;
	}
	return NULL;
}

void* arrResize(void* aData, int nItem) {
	if (aData == NULL || nItem < 0)return NULL;
	void* aOrigin = origin_addr(aData);
	int sizeItem = *(int*)sizeItem_addr(aData);
	int sz = memSize(nItem, sizeItem);
	void* aNew = realloc(aOrigin, sz);
	if (aNew != NULL) {
		aData = data_addr(aNew);
		*(int*)origin_addr(aData) = nItem;
		return aData;
	}
	return NULL;
}

int arrPushback(void** aData, void* x) {
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* aNew = arrResize(*aData, 1 + nItem);
	if (aNew != NULL) {
		memmove((char*)aNew + nItem * szItem, x, szItem);
		*aData = aNew;
		return 1;
	}
	return 0;
}

void* arrPopback(void** aData) {
	int nItem = arrSize(*aData), szItem = arrItemSize(*aData);
	void* x = malloc(szItem);
	if (*aData != NULL && nItem > 0) {
		nItem--;
		memmove(x, (char*)(*aData) + nItem * szItem, szItem);
		void* aNew = arrResize(*aData, nItem);
		if (aNew != NULL)*aData = aNew;
	}
	return x;
}

SOPHUC* soPhucArrIn() {
	SOPHUC* a = (SOPHUC*)arrInit(0, sizeof(SOPHUC));
	SOPHUC x = { 0,0 };
	while (cin >> x) {
		arrPushback((void**)&a, &x);
	}
	cin.clear();
	return a;
}

SOPHUC* soPhucArrOut(SOPHUC* a) {
	int n = arrSize(a);
	for (int i = 0; i < n; i++) {
		cout << a[i].x << " " << a[i].y << endl;
	}
	return a;
}

void main() {
	cout << "Input complex items\n";
	SOPHUC* B = soPhucArrIn();
	SOPHUC* x = (SOPHUC*)arrPopback((void**)&B);
	cout << "After pop: \n";
	soPhucArrOut(B);
	cout << "\nPopped element: " << *x << endl;
	free(x);
	arrFree(B);
}