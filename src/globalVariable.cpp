//
// Created by William Tissi on 5/1/25.
//
#include "../include/globalVariable.h"

double totalRevenue = 0;



int numProducts = 0, numFields = 0, orderCount = 0;

map<string, double> productMap;

string customerFields[5];
vector<unique_ptr<Order>> orders; // now using unique pointer for my orders, Let'ss gooo
vector<shared_ptr<SpecialProduct>> specialProducts; // and share pointer for out special product, like a 500K wine
