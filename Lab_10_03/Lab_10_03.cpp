#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Note {
    string surname;
    string name;
    string phone;
    int birthDate[3];
};

void displayNotesFromFile(const string& filename);
void addNotesToFile(const string& filename);
void overwriteFile(const string& filename);
bool searchByPhoneInFile(const string& filename, const string& phone);

int main() {
    string filename;
    int menuItem;
    string phone;

    cout << "Enter the filename: ";
    getline(cin, filename);

    do {
        cout << "\nMenu:" << endl;
        cout << "1 - Display data from file" << endl;
        cout << "2 - Overwrite data in file" << endl;
        cout << "3 - Add new data to file" << endl;
        cout << "4 - Search by phone number" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> menuItem;
        cin.ignore();

        switch (menuItem) {
        case 1:
            displayNotesFromFile(filename);
            break;
        case 2:
            overwriteFile(filename);
            break;
        case 3:
            addNotesToFile(filename);
            break;
        case 4:
            cout << "Enter phone number: ";
            getline(cin, phone);
            if (searchByPhoneInFile(filename, phone)) {
                cout << "Record found with phone number: " << phone << endl;
            }
            else {
                cout << "Record not found." << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Error! Enter a valid number." << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void displayNotesFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    Note tempNote;
    cout << left << setw(15) << "\nSurname" << setw(15) << "Name" << setw(15) << "Phone" << "Birthdate" << endl;
    while (fin >> tempNote.surname >> tempNote.name >> tempNote.phone
        >> tempNote.birthDate[0] >> tempNote.birthDate[1] >> tempNote.birthDate[2]) {
        cout << left << setw(15) << tempNote.surname << setw(15) << tempNote.name
            << setw(15) << tempNote.phone << tempNote.birthDate[0] << "."
            << tempNote.birthDate[1] << "." << tempNote.birthDate[2] << endl;
    }

    fin.close();
}

void addNotesToFile(const string& filename) {
    ofstream fout(filename, ios::app);
    if (!fout) {
        cout << "Error opening file for appending!" << endl;
        return;
    }

    int N;
    cout << "Enter the number of records to add: ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        Note tempNote;
        cout << "\nRecord " << i + 1 << ":" << endl;
        cout << "Surname: "; getline(cin, tempNote.surname);
        cout << "Name: "; getline(cin, tempNote.name);
        cout << "Phone number: "; getline(cin, tempNote.phone);
        cout << "Birthdate (day month year): ";
        cin >> tempNote.birthDate[0] >> tempNote.birthDate[1] >> tempNote.birthDate[2];
        cin.ignore();

        fout << tempNote.surname << " " << tempNote.name << " " << tempNote.phone << " "
            << tempNote.birthDate[0] << " " << tempNote.birthDate[1] << " " << tempNote.birthDate[2] << endl;
    }

    fout.close();
    cout << "Data added to the file." << endl;
}

void overwriteFile(const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    int N;
    cout << "Enter the number of records to overwrite: ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        Note tempNote;
        cout << "\nRecord " << i + 1 << ":" << endl;
        cout << "Surname: "; getline(cin, tempNote.surname);
        cout << "Name: "; getline(cin, tempNote.name);
        cout << "Phone number: "; getline(cin, tempNote.phone);
        cout << "Birthdate (day month year): ";
        cin >> tempNote.birthDate[0] >> tempNote.birthDate[1] >> tempNote.birthDate[2];
        cin.ignore();

        fout << tempNote.surname << " " << tempNote.name << " " << tempNote.phone << " "
            << tempNote.birthDate[0] << " " << tempNote.birthDate[1] << " " << tempNote.birthDate[2] << endl;
    }

    fout.close();
    cout << "File overwritten with new data." << endl;
}

bool searchByPhoneInFile(const string& filename, const string& phone) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file for reading!" << endl;
        return false;
    }

    Note tempNote;
    bool found = false;
    while (fin >> tempNote.surname >> tempNote.name >> tempNote.phone
        >> tempNote.birthDate[0] >> tempNote.birthDate[1] >> tempNote.birthDate[2]) {
        if (tempNote.phone == phone) {
            cout << "Found: " << tempNote.surname << " " << tempNote.name << endl;
            cout << "Phone: " << tempNote.phone << endl;
            cout << "Birthdate: " << tempNote.birthDate[0] << "."
                << tempNote.birthDate[1] << "." << tempNote.birthDate[2] << endl;
            found = true;
            break;
        }
    }

    fin.close();
    if (!found) {
        cout << "Record not found." << endl;
    }
    return found;
}

