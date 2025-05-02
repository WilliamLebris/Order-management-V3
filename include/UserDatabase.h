//
// Created by William Tissi on 5/1/25.
//

#ifndef USERDATABASE_H
#define USERDATABASE_H
#include <stdio.h>
#include<map>
#include <iostream>


using namespace std;

bool isValidPassword(const std::string& password);
void createFirstAccount();
bool login();
void addNewUser();

#endif //USERDATABASE_H
