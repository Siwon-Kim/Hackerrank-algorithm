#ifndef CALCLIST_H
#define CALCLIST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "CalcListInterface.hpp"

// Define the node class
class CalNode
{
    // Define the necessary member variables
    friend class CalcList;
    CalNode *nxt;
    FUNCTIONS node_operator;
    double node_total;
    double node_operand;
};

// Define the CalcList class
class CalcList : public CalcListInterface
{
private:
    // Declare a variable to track the current node
    CalNode *curr_node;

protected:
    // Declare the necessary functions to add node elements
    void add_element(double &node_element);

    // Initialize a variable to count the number of operations
    int counter = 0;

public:
    // Declare the class constructor
    CalcList();

    // Define the isEmpty() function to check if the linked list is empty
    bool isEmpty()
    {
        // Return the value of counter as 0
        return (counter == 0);
    }

    // Declare the necessary member functions
    double total() const;
    void newOperation(const FUNCTIONS func, const double operand);
    void removeLastOperation();
    std::string toString(unsigned short precision) const;
};

#endif /* !CALCLIST_H */
