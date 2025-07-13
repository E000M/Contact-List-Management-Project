#include <iostream>
#include <string>
#include <ctime>
using namespace std;
 
// Maximum number of contacts (1D array size)
const int MAX_CONTACTS = 100;
 
 
// Patrik's Work
 
// Function to get current date and time as string
string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}
 
// Function to add a contact
void addContact(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int &count) {
    if (count >= MAX_CONTACTS) {
        cout << "Contact list is full!\n";
        return;
    }
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, names[count]);
    cout << "Enter Phone: ";
    cin >> phones[count];
    cout << "Enter Email: ";
    cin >> emails[count];
    cout << "Enter Category (Family, Friends, Work): ";
    cin >> categories[count];
    cout << "Mark as favorite? (1 for Yes, 0 for No): ";
    cin >> isFavorite[count];
    cout << "Contact added on: " << getCurrentDateTime();
    count++;
    cout << "Contact added successfully.\n";
}
 
 
// Isra's Work
 
// Function to update a contact
void updateContact(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int count) {
    string name;
    cout << "Enter the name of the contact to update: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (names[i] == name) {
            cout << "Enter new Phone: ";
            cin >> phones[i];
            cout << "Enter new Email: ";
            cin >> emails[i];
            cout << "Enter new Category: ";
            cin >> categories[i];
            cout << "Mark as favorite? (1 for Yes, 0 for No): ";
            cin >> isFavorite[i];
            cout << "Contact updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}
 
// Function to delete a contact
void deleteContact(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int &count) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (names[i] == name) {
            for (int j = i; j < count - 1; j++) {
                names[j] = names[j + 1];
                phones[j] = phones[j + 1];
                emails[j] = emails[j + 1];
                categories[j] = categories[j + 1];
                isFavorite[j] = isFavorite[j + 1];
            }
            count--;
            cout << "Contact deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}
 
 
// Martina's Work
 
// Function to display all contacts
void displayContacts(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int count) {
    if (count == 0) {
        cout << "No contacts available.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Contact " << i + 1 << ":\n";
        cout << "Name: " << names[i] << "\n";
        cout << "Phone: " << phones[i] << "\n";
        cout << "Email: " << emails[i] << "\n";
        cout << "Category: " << categories[i] << "\n";
        cout << "Favorite: " << (isFavorite[i] ? "Yes" : "No") << "\n";
        cout << "------------------------\n";
    }
}
 
// Function to display favorite contacts
void displayFavoriteContacts(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int count) {
    bool found = false;
    cout << "Favorite Contacts:\n";
    for (int i = 0; i < count; i++) {
        if (isFavorite[i]) {
            cout << "Name: " << names[i] << "\n";
            cout << "Phone: " << phones[i] << "\n";
            cout << "Email: " << emails[i] << "\n";
            cout << "Category: " << categories[i] << "\n";
            cout << "Favorite: Yes\n";
            cout << "------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No favorite contacts found.\n";
    }
}
 
 
// Eristela's Work
 
// Function to search contacts by category
void searchByCategory(string names[], string phones[], string emails[], string categories[], bool isFavorite[], int count, string category) {
    bool found = false;
    cout << "Contacts in category: " << category << "\n";
    for (int i = 0; i < count; i++) {
        if (categories[i] == category) {
            cout << "Name: " << names[i] << "\n";
            cout << "Phone: " << phones[i] << "\n";
            cout << "Email: " << emails[i] << "\n";
            cout << "Category: " << categories[i] << "\n";
            cout << "Favorite: " << (isFavorite[i] ? "Yes" : "No") << "\n";
            cout << "------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No contacts found in this category.\n";
    }
}
 
// Function to display the menu
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add Contact\n";
    cout << "2. Update Contact\n";
    cout << "3. Delete Contact\n";
    cout << "4. Display Contacts\n";
    cout << "5. Search Contacts by Category\n";
    cout << "6. Display Favorite Contacts\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}
 
 
// Elsa's Work
 
int main() {
    string names[MAX_CONTACTS], phones[MAX_CONTACTS], emails[MAX_CONTACTS], categories[MAX_CONTACTS];
    bool isFavorite[MAX_CONTACTS] = {false}; // Initialize favorite status
    int count = 0; // Current number of contacts
    int choice;
 
    do {
        displayMenu();
        cin >> choice;
 
        if (choice == 1) {
            addContact(names, phones, emails, categories, isFavorite, count);
        }
        else if (choice == 2) {
            updateContact(names, phones, emails, categories, isFavorite, count);
        }
        else if (choice == 3) {
            deleteContact(names, phones, emails, categories, isFavorite, count);
        }
        else if (choice == 4) {
            displayContacts(names, phones, emails, categories, isFavorite, count);
        }
        else if (choice == 5) {
            string category;
            cout << "Enter category to search: ";
            cin >> category;
            searchByCategory(names, phones, emails, categories, isFavorite, count, category);
        }
        else if (choice == 6) {
            displayFavoriteContacts(names, phones, emails, categories, isFavorite, count);
        }
        else if (choice == 7) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
 
    return 0;
}

