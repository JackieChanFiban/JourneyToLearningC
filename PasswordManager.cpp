// Password manager saves them to JSON run EXE and view password and saves
// password, asks for the site, username, and password

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Credential {
    // Declare the variables we need
    std::string site;
    std::string username;
    std::string password;
};

Credential Credintials()
{
    // Declare the variables
    string Site;
    string Username;
    string Password;

    cout << "What is the Site? ";
    cin >> Site;

    cout << "What is the Username? ";
    cin >> Username;

    cout << "What is the Password? ";
    cin >> Password;

    // Assigns the entered info to variables
    Credential entry;
    entry.site = Site;
    entry.username = Username;
    entry.password = Password;
    return entry;
}

int main()
{
    Credintials();
    vector<Credential> allCreds;
    bool running = true;

    while (running) {
        // Step one show the menu
        cout << "\n1 - Add a credential\n"
            << "2 - View all credentials\n"
            << "3 - Exit the program\n"
            << "Choose an option: ";

        // Step two read the users choice
        int choice;
        cin >> choice;

        // Step three acting on the users input choice
        if (choice == 1) {
            // Only now prompt for Site/Username/Password
            Credential newCred = Credintials();
            allCreds.push_back(newCred);
            cout << "\n";
            cout << "Credential added!\n";
        }
        else if (choice == 2) {
            // Loop over allCreds and print each entry
            cout << "\nSaved credentials:\n";
            for (size_t i = 0; i < allCreds.size(); ++i) {
                const auto& c = allCreds[i];
                cout << i + 1 << ". Site: " << c.site
                    << ", Username: " << c.username
                    << ", Password: " << c.password
                    << "\n";
            }
            if (allCreds.empty()) {
                cout << "  (none yet)\n";
            }
        }
        else if (choice == 3) {
            running = false;  // Exits the loop
        }
        else {
            cout << "Invalid option, try again.\n";
        }
    }

    return 0;
}