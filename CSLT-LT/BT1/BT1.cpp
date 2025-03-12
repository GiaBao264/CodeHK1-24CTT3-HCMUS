#include <iostream>
#include <string>
#include <cctype>
#include <time.h>
#include <windows.h>

using namespace std;

// Hàm cố định kích thước console và vô hiệu hóa thay đổi kích thước
void setFixedConsoleSize(int width, int height) {
    // Lấy handle của cửa sổ console
    HWND consoleWindow = GetConsoleWindow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Thiết lập kích thước buffer (bộ đệm) của console
    COORD bufferSize = { width, height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Thiết lập kích thước cửa sổ console (window)
    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // Vô hiệu hóa khả năng thay đổi kích thước cửa sổ (bằng cách kéo chuột)
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_SIZEBOX; // Loại bỏ cờ cho phép thay đổi kích thước
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Vô hiệu hóa thanh cuộn
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole, &info);
    if (info.dwSize.Y > height) {
        info.dwSize.Y = height;
        SetConsoleScreenBufferSize(hConsole, info.dwSize);
    }
}

void menuIn(HANDLE hConsole) {
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "[1] Calculate age by date of birth.\n";
    cout << "[2] Capitalize the first letter.\n";
    cout << "[3] Divide money into multiple denominations.\n";
    cout << "\n";
    cout << "[99] Exit the program!\n";
    cout << "\n";
    cout << "Please select your choice: ";
}

int main() {

    setFixedConsoleSize(100, 25);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice;

    do {
        system("cls");
        menuIn(hConsole);
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1:
        {
            int day, month, year;
            cout << "Please enter your date of birth (dd mm yyyy): ";
            cin >> day >> month >> year;

            if (day < 1 || day > 31 || month < 1 || month > 12 || year > 2023) {
                cout << "Invalid date of birth!" << endl;
                break;
            }

            time_t hientai = time(0);
            tm* ltm = localtime(&hientai);

            int ngayhientai = ltm->tm_mday;
            int thanghientai = ltm->tm_mon + 1;
            int namhientai = ltm->tm_year + 1900;

            int tuoi = namhientai - year;
            if (thanghientai < month || (thanghientai == month && ngayhientai < day)) {
                tuoi--;
            }

            cout << "Your age is: " << tuoi << " age(s)" << endl;
            break;
        }
        case 2:
        {
            string ten;
            cout << "Please enter a character or a sentence: ";
            cin.ignore();
            getline(cin, ten);

            bool vietHoa = true;
            for (char& c : ten) {
                if (vietHoa && isalpha(c)) {
                    c = toupper(c);
                    vietHoa = false;
                }
                else {
                    c = tolower(c);
                }

                if (isspace(c)) {
                    vietHoa = true;
                }
            }

            cout << "Characters/sentences capitalize the first letter: " << ten << endl;
            break;
        }
        case 3:
        {
            int tien;
            cout << "Enter your amount: ";
            cin >> tien;

            if (tien < 0) {
                cout << "Invalid amount!" << endl;
                break;
            }

            int tienbandau = tien;

            int money500 = tien / 500000;
            tien %= 500000;

            int money200 = tien / 200000;
            tien %= 200000;

            int money100 = tien / 100000;
            tien %= 100000;

            int money50 = tien / 50000;
            tien %= 50000;

            int money20 = tien / 20000;
            tien %= 20000;

            int money10 = tien / 10000;
            tien %= 10000;

            int money5 = tien / 5000;
            tien %= 5000;

            int money2 = tien / 2000;
            tien %= 2000;

            int money1 = tien / 1000;
            tien %= 1000;

            cout << tienbandau << " = 500000x" << money500 << " + 200000x" << money200 << " + 100000x" << money100 << " + 50000x" << money50
                << " + 20000x" << money20 << " + 10000x" << money10 << " + 5000x" << money5 << " + 2000x" << money2 << " + 1000x" << money1 << endl;
            break;
        }
        case 99:
            cout << "Exiting the program.....\n";
            break;
        default:
            cout << "Invalid selection! Please try again.\n";
            break;
        }

        if (choice != 99) {
            cout << "\nPress Enter to return to the main menu...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 99);

    return 0;
}
