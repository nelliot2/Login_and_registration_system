
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Input username:" << endl; cin >> username;
    cout << "Input password" << endl; cin >> password;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password)
    {
        return true;
    }
    else return false;
}

int main()
{
    cout << "Chose option:" << endl;
    cout << "1.Log in" << endl;
    cout << "2.Registration" << endl;
    cout << "3.Exit" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "False Login!" << endl;
            system("Pause");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in";
            system("Pause");
            return 1;
        }

    }
    else if (choice == 2)
    {
        string username, password;
        cout << "Input username:" << endl; cin >> username;
        cout << "Input password" << endl; cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        cout << "Good bye!";
        system("Pause");
        return 1;
    }
    else
    {
        cout << "Incorrect input!" << endl;
        main();
    }

}

