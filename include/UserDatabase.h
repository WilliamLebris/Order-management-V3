//
// Created by William Tissi on 5/1/25.
//

#ifndef USERDATABASE_H
#define USERDATABASE_H
#include <stdio.h>
#include<map>
#include <iostream>


using namespace std;

// Declare external user database so test can access it
extern std::unordered_map<std::string, std::string> userDatabase;

bool isValidPassword(const std::string& password);
void createFirstAccount();
bool login();
void addNewUser();

#endif //USERDATABASE_H
