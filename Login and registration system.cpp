#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << username << " "
         << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}

void loginUser()
{
    string username, password;
    string u, p;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while(file >> u >> p)
    {
        if(username == u && password == p)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
        cout << "\nLogin Successful!\n";
    else
        cout << "\nInvalid Username or Password!\n";
}

int main()
{
    int choice;

    cout << "===== LOGIN SYSTEM =====\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
        registerUser();
    else if(choice == 2)
        loginUser();
    else
        cout << "Invalid Choice";

    return 0;
}
