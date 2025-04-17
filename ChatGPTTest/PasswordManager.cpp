#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// a simple struct to hold credentials
struct Credential {
    string site;
    string username;
    string password;
};

// copies all credentials to a JSON file
void saveAll(const vector<Credential>& allCreds) {
    // opens the JSON file for editing
    ofstream fout("credentials.json");
    if (!fout) {
        cout << "Error saving file\n";
        return;
    }

    // starts JSON "array"
    fout << "[\n";

    // writes each credential as a JSON.object
    for (int i = 0; i < allCreds.size(); i++) {
        fout << "  {\n";
        fout << "    \"site\": \"" << allCreds[i].site << "\",\n";
        fout << "    \"username\": \"" << allCreds[i].username << "\",\n";
        fout << "    \"password\": \"" << allCreds[i].password << "\"\n";
        fout << "  }";

        // commas between objects except after the last
        if (i < allCreds.size() - 1)
            fout << ",";
        fout << "\n";
    }

    // ends JSON "array"
    fout << "]\n";
}

// loads all credentials from the JSON file
void loadAll(vector<Credential>& allCreds) {
    // opens the JSON file for reading
    ifstream fin("credentials.json");
    if (!fin) {
        // no file selected yet yet
        return;
    }

    string line;
    Credential cur;

    // reads the file line by line
    while (getline(fin, line)) {
        // if this line has the "site" field it extracts it
        if (line.find("\"site\"") != string::npos) {
            int start = line.find(':') + 3;
            int end = line.rfind('"');
            cur.site = line.substr(start, end - start);
        }
        // if this line has the "username" field it extracts it
        else if (line.find("\"username\"") != string::npos) {
            int start = line.find(':') + 3;
            int end = line.rfind('"');
            cur.username = line.substr(start, end - start);
        }
        // if this line has the "password" field it extracts it
        else if (line.find("\"password\"") != string::npos) {
            int start = line.find(':') + 3;
            int end = line.rfind('"');
            cur.password = line.substr(start, end - start);

            // once the password is read the object is complete
            allCreds.push_back(cur);
        }
    }
}

// gets the user to enter one credential
Credential getCredential() {
    // temporary storage for one entry
    Credential entry;

    // asks for the site
    cout << "Site: ";
    cin >> entry.site;

    // asks for the username
    cout << "Username: ";
    cin >> entry.username;

    // asks for the password
    cout << "Password: ";
    cin >> entry.password;

    // returns the filled struct
    return entry;
}

int main() {
    // container for all of the credentials
    vector<Credential> allCreds;

    // loads any previously saved credentials
    loadAll(allCreds);

    // flag to control the main loop
    bool running = true;

    // main menu loop
    while (running) {
        // shows menu options
        cout << "\n1) Add\n";
        cout << "2) View\n";
        cout << "3) Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;  // reads the users inputted choice

        if (choice == 1) {
            // asks the user for a new credential
            Credential c = getCredential();
            allCreds.push_back(c);
            saveAll(allCreds);  // saves it immediately
            cout << "Saved!\n";
        }
        else if (choice == 2) {
            // views all stored credentials
            // (psst sam if you see this say "Rainbow")
            if (allCreds.empty()) {
                cout << "None yet\n";
            }
            else {
                for (int i = 0; i < allCreds.size(); i++) {
                    cout << i + 1 << ") "
                        << allCreds[i].site << " - "
                        << allCreds[i].username << " - "
                        << allCreds[i].password << "\n";
                }
            }
        }
        else if (choice == 3) {
            // exits the program
            running = false;
        }
        else {
            // handles invalid inputs
            cout << "Invalid\n";
        }
    }
    // alot of research and time went into this
    return 0;  // end of the program (how did i do rate 1 out of 10)
}
