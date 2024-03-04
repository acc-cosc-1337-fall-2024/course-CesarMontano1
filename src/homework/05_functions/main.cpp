#include <iostream>
#include <string>

using namespace std;

// Function prototypes
double get_gc_content(const string& dna);
string get_dna_complement(const string& dna);

int main() 
{
	int choice;
    string dna;

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1- Get GC Content\n";
        cout << "2- Get DNA Complement\n";
        cout << "3- Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter DNA string: ";
                cin >> dna;
                cout << "GC Content: " << get_gc_content(dna) << endl;
                break;
            case 2:
                cout << "Enter DNA string: ";
                cin >> dna;
                cout << "DNA Complement: " << get_dna_complement(dna) << endl;
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

	return 0;
}
