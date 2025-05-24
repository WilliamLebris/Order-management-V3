//
// Created by William Tissi on 5/23/25.
//

#ifndef EXCEPTION_H
#define EXCEPTION_H



#include <stdexcept>

class OrderException : public std::runtime_error {
public:
    explicit OrderException(const std::string& msg) : std::runtime_error(msg) {}
};

class OrderNotFoundException : public OrderException {
public:
    OrderNotFoundException() : OrderException("Order not found") {}
};

class FileAccessException : public OrderException {
public:
    FileAccessException() : OrderException("File access error") {}
};

#endif