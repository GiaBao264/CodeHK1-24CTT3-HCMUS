#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <limits>
#include <ctime>
#include <conio.h>
#include <string>

#undef max

using namespace std;

const int consoleWidth = 500;
const int consoleHeight = 500;
const int gap = 5;

const string colorGreen = "\033[32m";
const string colorRed = "\033[31m";
const string colorWhite = "\033[37m";
const string colorYellow = "\033[33m";

bool checkpoint = false;

void createConsole()
{
    //Set window console title
    SetConsoleTitleA("Useful Script");

    //Get window console handle
    HWND wcHandle = GetConsoleWindow();
    // (wcHandle stands for windowConsoleHandle)

    //Get host's screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    //Calc the middle position of the window on the screen
    int xPos = (screenWidth - consoleWidth) / 2;
    int yPos = (screenHeight - consoleHeight) / 2;

    //Set window position and size
    MoveWindow(wcHandle, xPos, yPos, consoleWidth, consoleHeight, true);

    //Disable window resize
    SetWindowLong(wcHandle, GWL_STYLE, GetWindowLong(wcHandle, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    //Also scrolling needs to be disabled by adjusting the console buffer size match the actual window size
    //Get console handle
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    //Get screen buffer size
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

    //Set screen buffer size
    COORD newConsoleSize;
    newConsoleSize.X = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
    newConsoleSize.Y = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1;

    //Hide scrollbar
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, false);

    //Set background color and text color
    //SetConsoleTextAttribute(consoleHandle, 0xf0);
    //Problem is I can't change the scrollbar background, adding this mean it will look bad.
    //I may try fixing this later.

    //Apply new settings
    SetConsoleScreenBufferSize(consoleHandle, newConsoleSize);
}

void printGap()
{
    for (int i = 0; i <= gap; ++i) cout << " ";
}

void printHR()
{
    printGap();
    cout << colorWhite + "_______________________________________________________" << "\n \n";
}

void quitGame()
{
    printGap();
    cout << colorWhite << "Press any key to return to the main menu or press [ESC] to quit the program.";
    char ch;
    ch = _getch();
    if (ch == 27) exit(0);
}

bool checkValidDate(int d, int m, int y)
{
    int days[15] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && (y % 400 == 0 || y % 4 == 0)) days[2] = 29;
    if (d > days[m]) return false;
    return true;
}

void ageCalc()
{
    system("cls");
    cout << "\n \n";
    int dd, mm, yy;
    dd = mm = yy = 0;
    time_t t = time(0);
    tm* currentTime = localtime(&t);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    while (checkpoint == false)
    {
        printGap();
        cout << colorWhite << "Day (e.g. 23): ";
        while (true)
        {
            cin >> dd;
            if (cin.fail() || dd < 0 || dd > 31)
            {
                printGap();
                cout << colorRed << "Invalid day! Please submit a new day: " << colorWhite;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else break;
        }
        printGap();
        cout << colorWhite << "Month (e.g. 06): ";
        while (true)
        {
            cin >> mm;
            if (cin.fail() || mm < 0 || mm > 12)
            {
                printGap();
                cout << colorRed << "Invalid month! Please submit a new month: " << colorWhite;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else break;
        }
        printGap();
        cout << colorWhite << "Year (e.g. 2006): ";
        while (true)
        {
            cin >> yy;
            if (cin.fail() || yy < 0 || yy > currentTime->tm_year + 1900)
            {
                printGap();
                cout << colorRed << "Invalid year! Please submit a new year: " << colorWhite;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else break;
        }
        if (!checkValidDate(dd, mm, yy))
        {
            system("cls");
            cout << "\n \n";
            printGap();
            cout << colorRed << "The date you submitted is invalid. \n";
            printGap();
            cout << colorWhite << "Please enter a new date!";
            _getch();
            ageCalc();
        }
        else break;
    }
    if (checkpoint == true) return;
    checkpoint = true;
    int res = currentYear - yy;
    if (currentMonth < mm || (currentMonth == mm && currentDay < dd)) res--;
    system("cls");
    cout << "\n \n";
    printGap();
    cout << colorWhite << "You are now... " << res << " years old! \n \n";
    quitGame();
}

void charUppercase()
{
    system("cls");
    cout << "\n \n";
    string s;
    printGap();
    cout << colorGreen << "Please submit your paragraph: " << colorWhite;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
        if (s[i] >= 97 && s[i] <= 122) s[i] = s[i] - 32;
    system("cls");
    cout << "\n \n";
    printGap();
    cout << "Your new paragraph is now: " << colorYellow << s << "\n \n";
    quitGame();
}

void moneyDivider()
{
    system("cls");
    cout << "\n \n";
    long long num = 0;
    printGap();
    cout << "Enter your amount of money (e.g. 2500000): " << colorWhite;
    cin >> num;
    long long number = num;
    long long a = num / 500000;
    num = num - a * 500000;
    long long f = num / 200000;
    num = num - f * 200000;
    long long b = num / 100000;
    num = num - b * 100000;
    long long c = num / 50000;
    num = num - c * 50000;
    long long d = num / 20000;
    num = num - d * 20000;
    long long e = num / 10000;
    num = num - e * 10000;
    system("cls");
    cout << "\n \n";
    printGap();
    cout << colorYellow << number << colorWhite << " is now divided to: \n";
    printGap();
    cout << colorYellow << a << colorWhite << " bill(s) of 500,000VND \n";
    printGap();
    cout << colorYellow << f << colorWhite << " bill(s) of 200,000VND \n";
    printGap();
    cout << colorYellow << b << colorWhite << " bill(s) of 100,000VND \n";
    printGap();
    cout << colorYellow << c << colorWhite << " bill(s) of 50,000VND \n";
    printGap();
    cout << colorYellow << d << colorWhite << " bill(s) of 20,000VND \n";
    printGap();
    cout << colorYellow << e << colorWhite << " bill(s) of 10,000VND \n";
    printGap();
    cout << "And " << colorYellow << num << "VND" << colorWhite << " left. \n \n";
    quitGame();
}

int main()
{
    createConsole();
    while (true)
    {
        //Build menu
        system("cls");
        cout << "\n \n";
        string optA = colorWhite + "[1] Age Calculator";
        string optB = colorWhite + "[2] Convert Characters To Capitalized";
        string optC = colorWhite + "[3] Money Divider";
        string optW = colorWhite + "[9] Exit Program.";
        string optZ = colorGreen + "Choose an option from your keyboard:" + colorWhite;
        printHR();
        printGap();
        cout << optA << "\n";
        printGap();
        cout << optB << "\n";
        printGap();
        cout << optC << "\n \n";
        printGap();
        cout << optW << "\n";
        printHR();
        printGap();
        cout << optZ << " ";

        //Get user input and process
        int opt = -1;
        cin >> opt;
        switch (opt)
        {
        case 1:
            checkpoint = false;
            ageCalc();
            break;
        case 2:
            charUppercase();
            break;
        case 3:
            moneyDivider();
            break;
        case 9:
            exit(0);
        default:
            system("cls");
            cout << "\n \n";
            printGap();
            cout << colorRed << "There is no avaliable function with this number! \n";
            printGap();
            cout << colorWhite << "Press any key to return to main page.";
            _getch();
        }
    }
}