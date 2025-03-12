#include <iostream>
#include <iomanip>

using namespace std;

void displayLabs(int** labs, int M, int* stations) {
    cout << "\nLab   Stations\n";
    for (int i = 0; i < M; ++i) {
        cout << "Lab " << i + 1 << ": ";
        for (int j = 0; j < stations[i]; ++j) {
            cout << setw(6) << labs[i][j];
        }
        cout << endl;
    }
}

void login(int** labs, int M, int* stations) {
    int userID, labNumber, stationNumber;
    cout << "Enter User ID (5-digit): ";
    cin >> userID;
    cout << "Enter Lab Number (1-" << M << "): ";
    cin >> labNumber;
    cout << "Enter Station Number (1-" << stations[labNumber - 1] << "): ";
    cin >> stationNumber;

    if (labNumber < 1 || labNumber > M || stationNumber < 1 || stationNumber > stations[labNumber - 1]) {
        cout << "Invalid lab or station number!" << endl;
        return;
    }

    if (labs[labNumber - 1][stationNumber - 1] != 0) {
        cout << "Station already occupied!" << endl;
    }
    else {
        labs[labNumber - 1][stationNumber - 1] = userID;
        cout << "User " << userID << " logged into Lab " << labNumber << ", Station " << stationNumber << "." << endl;
    }
}

void logout(int** labs, int M, int* stations) {
    int labNumber, stationNumber;
    cout << "Enter Lab Number (1-" << M << "): ";
    cin >> labNumber;
    cout << "Enter Station Number (1-" << stations[labNumber - 1] << "): ";
    cin >> stationNumber;

    if (labNumber < 1 || labNumber > M || stationNumber < 1 || stationNumber > stations[labNumber - 1]) {
        cout << "Invalid lab or station number!" << endl;
        return;
    }

    if (labs[labNumber - 1][stationNumber - 1] == 0) {
        cout << "No user logged into this station!" << endl;
    }
    else {
        cout << "User " << labs[labNumber - 1][stationNumber - 1] << " logged out from Lab " << labNumber << ", Station " << stationNumber << "." << endl;
        labs[labNumber - 1][stationNumber - 1] = 0;
    }
}

void searchUser(int** labs, int M, int* stations) {
    int userID;
    cout << "Enter User ID to search: ";
    cin >> userID;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < stations[i]; ++j) {
            if (labs[i][j] == userID) {
                cout << "User " << userID << " is logged into Lab " << i + 1 << ", Station " << j + 1 << "." << endl;
                return;
            }
        }
    }
    cout << "User " << userID << " is not logged into any station." << endl;
}

int main() {
    int M;
    cout << "Enter the number of labs: ";
    cin >> M;

    int* stations = new int[M];
    cout << "Enter the number of stations in each lab:" << endl;
    for (int i = 0; i < M; ++i) {
        cout << "Lab " << i + 1 << ": ";
        cin >> stations[i];
    }

    int** labs = new int* [M];
    for (int i = 0; i < M; ++i) {
        labs[i] = new int[stations[i]]();
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display labs\n";
        cout << "2. Login\n";
        cout << "3. Logout\n";
        cout << "4. Search User\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayLabs(labs, M, stations);
            break;
        case 2:
            login(labs, M, stations);
            break;
        case 3:
            logout(labs, M, stations);
            break;
        case 4:
            searchUser(labs, M, stations);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    for (int i = 0; i < M; ++i) {
        delete[] labs[i];
    }
    delete[] labs;
    delete[] stations;

    return 0;
}
