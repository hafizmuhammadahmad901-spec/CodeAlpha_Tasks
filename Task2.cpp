
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registerUser()
{
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Validate input
    if (username.empty() || password.empty())
    {
        cout << "Username and password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    ifstream readFile("users.txt");

    while (readFile >> savedUsername >> savedPassword)
    {
        if (savedUsername == username)
        {
            cout << "Username already exists! Try another.\n";
            readFile.close();
            return;
        }
    }

    readFile.close();

    // Save credentials
    ofstream writeFile("users.txt", ios::app);

    if (!writeFile)
    {
        cout << "Error opening file!\n";
        return;
    }

    writeFile << username << " " << password << endl;

    writeFile.close();

    cout << "Registration successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Read saved credentials
    ifstream readFile("users.txt");

    if (!readFile)
    {
        cout << "No registered users found. Register first!\n";
        return;
    }

    bool found = false;

    while (readFile >> savedUsername >> savedPassword)
    {
        if (savedUsername == username &&
            savedPassword == password)
        {
            found = true;
            break;
        }
    }

    readFile.close();

    if (found)
    {
        cout << "Login successful! Welcome, " << username << "!\n";
    }
    else
    {
        cout << "Invalid username or password!\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "   LOGIN AND REGISTRATION\n";
        cout << "==============================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
