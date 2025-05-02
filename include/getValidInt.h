//
// Created by William Tissi on 5/1/25.
//

#ifndef GETVALIDINT_H
#define GETVALIDINT_H
#include <stdio.h>
#include <string>
#include<iostream>
//declaring our int validator to make sure the user can't crash our program
namespace intValidation{
    int getValidInt(int min, int max);
    bool isValidDate(const std::string& date);
    int validateLettersOrDigits(const std::string& input);
}

#endif //GETVALIDINT_H
