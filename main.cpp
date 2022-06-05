#include <iostream>

#include "User.cpp"

using namespace std;

void printUser(User *user) {
    cout << "User info below -------------------------- User info below" << endl
         << "name is: " << user->name << endl;

    if (user->Case) {
        cout << "Customer ID is: " << user->Customer.customerID << endl;
    } else {
        cout << "Admin ID id: " << user->Admin.id << endl
             << "Position is: " << user->Admin.position << endl
             << "Department: " << user->Admin.department << endl;
    }
    cout << "User info atop -------------------------- User info atop" << endl << endl << endl;
}

User getNewUserFromConsole() {
    User newUser{};

    cout << "input 0 if user is admin end 1 if user is customer";
    cin >> newUser.Case;

    cout << "Enter name:   ";
    cin >> newUser.name;

    if (!newUser.Case) {
        cout << "Enter id:   " << endl;
        cin >> newUser.Admin.id;

        cout << "Enter position:   " << endl;
        cin >> newUser.Admin.position;

        cout << "Enter department:   " << endl;
        cin >> newUser.Admin.department;
    } else {

        cout << "Enter customer ID:   " << endl;
        cin >> newUser.Customer.customerID;
    }

    newUser.next = NULL;

    return newUser;
}

User* getUserViaIndex(User *list, int index) {
    User *iter = list;
    while (iter != NULL && index--) {
        iter = iter->next;
    }
    return iter;
}

void addUserToList(User *list, User userToAdd) {
    if (list == NULL) {
        list = new User(userToAdd);
        list->next = NULL;
    } else {
        User *iter = list;
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = new User(userToAdd);
    }
}

void printUserList(User *list) {
    User *iter = list;

    while (iter != NULL) {
        printUser(iter);
        iter = iter->next;
    }
}

void deleteViaIndex(User *list, int index) {
    User *iter;

    if (list == NULL) return;

    if (index) {
        User *p = list;
        while (p->next != NULL && --index) {
            p = p->next;
        }
        iter = p->next;
        if (iter != NULL) {
            p->next = iter->next;
            delete iter;
        }
    } else {
        iter = list;
        list = iter->next;
        delete iter;
    }
}


int main() {
    User *list = NULL;

    while (true) {
        int action;
        cout << "DataBase actions:           (input appropriate number)" << endl
             << "( 1 )  Get user info via array index" << endl
             << "( 2 )  Get all info" << endl
             << "( 3 )  Add User" << endl
             << "( 4 )  Delete user via array index" << endl
             << "( 5 )  End session" << endl;
        cin >> action;
        cout << endl;

        switch (action) {
            case 1: {
                cout << "Input index number from 0 to 29:" << endl;
                int index;
                cin >> index;

                printUser(getUserViaIndex(list, index));
                break;
            }
            case 2: {
                printUserList(list);
                break;
            }
            case 3: {
                User newUsr = getNewUserFromConsole();

                addUserToList(list, newUsr);
                break;
            }
            case 4: {
                int index;
                cout << "input position to delete user" << endl;
                cin >> index;

                deleteViaIndex(list, index);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Wrong number! Try one more time" << endl;
                break;
            }
        }
    }
}
