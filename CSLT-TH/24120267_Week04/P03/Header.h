#pragma once
#include <iostream>
#include <cstring>

using namespace std;

struct hocsinh {
    char hoTen[31];
    float diem;
};

void sapTenTangDan(hocsinh ds[], int n);
int demTenKN(hocsinh ds[], int n);
void sapXepTheoDiem(hocsinh ds[], int n);
