//
// Created by Alexandr on 05.06.2022.
//

struct User {
    User *next;
    bool Case;
    // false - Admin true - Customer
    char name[256];
    union {
        struct {
            int id;
            char position[256];
            char department[256];
        } Admin;

        struct {
            int customerID;
        } Customer;
    };
};
