//
// Created by William Tissi on 5/2/25.
//
#include <gtest/gtest.h>
#include "../include/getValidInt.h"

TEST(NameValidationTest, AcceptsLetters) {
    EXPECT_TRUE(intValidation::validateLettersOrDigits("JohnDoe"));
}

TEST(NameValidationTest, AcceptsDigits) {
    EXPECT_TRUE(intValidation::validateLettersOrDigits("123456"));
}

TEST(NameValidationTest, RejectsMixed) {
    EXPECT_FALSE(intValidation::validateLettersOrDigits("John123"));
}

TEST(NameValidationTest, RejectsSpecialCharacters) {
    EXPECT_FALSE(intValidation::validateLettersOrDigits("John_Doe!"));
}
