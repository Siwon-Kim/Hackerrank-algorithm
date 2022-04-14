// Include the CalcList.hpp file
#include "CalcList.hpp"

// Define the Class constructor
CalcList::CalcList() : CalcListInterface()
{
    /*Creating a circular linked list*/
    curr_node = new CalNode;

    // Initialize curr_node -> node_operator as ADDITION
    curr_node->node_operator = ADDITION;

    // Initialize curr_node -> node_operand as 0.0
    curr_node->node_operand = 0.0;

    // Initialize curr_node -> node_total as 0.0
    curr_node->node_total = 0.0;

    // Point the current node's next to current node
    curr_node->nxt = curr_node;
}

// Define the add_element() function
void CalcList::add_element(double &node_element)
{
    // Increment the counter variable
    ++counter;

    // Define a variable for the node before the current node
    CalNode *prev_node = new CalNode;

    // Point the prev_node's next to null
    prev_node->nxt = nullptr;

    // Point the prev_node's total to 0.0
    prev_node->node_total = 0.0;

    // Point the prev_node's operand to 0.0
    prev_node->node_operand = 0.0;

    // Point the prev_node's operator to ADDITION
    prev_node->node_operator = ADDITION;

    // Check if the curr_node points to null
    if (curr_node == nullptr)
    {
        // Assign the node value to the prev_node's total
        prev_node->node_total = node_element;

        // Assign the value at prev_node to curr_node
        curr_node = prev_node;

        // Assign the value at prev_node to curr_node's next
        curr_node->nxt = prev_node;
    }
    else
    {
        // Assign the curr_node's next to prev_node's next
        prev_node->nxt = curr_node->nxt;

        // Assign curr_node's next total to prev_node's total
        prev_node->node_total = curr_node->nxt->node_total;

        // Assign the value at prev_node to curr_node's next
        curr_node->nxt = prev_node;
    }
}

// Define the total() function
double CalcList::total() const
{
    // Return the total from current node's next
    return curr_node->nxt->node_total;
}

// Define the newOperation() function
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{
    // Initialize a variable to zero
    double elem = 0;

    // Call the add_element() with zero as its parameter
    add_element(elem);

    // Check if the value of func is ADDITION
    if (func == ADDITION)
    {
        // Assign ADDITION to curr_node's next operator
        curr_node->nxt->node_operator = ADDITION;

        // Assign the value of operand to curr_node's next operand
        curr_node->nxt->node_operand = operand;

        // Assign the sum to the curr_node's next total
        curr_node->nxt->node_total += operand;
    }

    // Check if the value of func is SUBTRACTION
    else if (func == SUBTRACTION)
    {
        // Assign SUBTRACTION to curr_node's next operator
        curr_node->nxt->node_operator = SUBTRACTION;

        // Assign the value of operand to curr_node's next operand
        curr_node->nxt->node_operand = operand;

        // Assign the difference to the curr_node's next total
        curr_node->nxt->node_total -= operand;
    }

    // Check if the value of func is MULTIPLICATION
    else if (func == MULTIPLICATION)
    {
        // Assign MULTIPLICATION to curr_node's next operator
        curr_node->nxt->node_operator = MULTIPLICATION;

        // Assign the value of operand to curr_node's next operand
        curr_node->nxt->node_operand = operand;

        // Assign the product to the curr_node's next total
        curr_node->nxt->node_total *= operand;
    }

    // Check if the value of func is DIVISION
    else if (func == DIVISION)
    {
        // Check if the value of operand is zero
        if (operand == 0)
        {
            // Call the removeLastOperation() function
            removeLastOperation();

            // Display division by zero
            throw("Division by zero!");
        }

        // Assign DIVISION to curr_node's next operator
        curr_node->nxt->node_operator = DIVISION;

        // Assign the value of operand to curr_node's next operand
        curr_node->nxt->node_operand = operand;

        // Assign the division value to the curr_node's next total
        curr_node->nxt->node_total /= operand;
    }
    else
    {
        // Display invalid operation
        std::cout << "Invalid operation selected! Select from ADDITION, SUBTRACTION, MULTIPLICATION or DIVISION." << std::endl;
    }
}

// Call the removeLastOperation() function
void CalcList::removeLastOperation()
{
    // Check if the linked list is empty
    if (isEmpty())
    {
        // Display node cannot be removed
        throw("No node is present. Cannot remove nodes.");
    }
    else
    {
        // Decrement the counter variable
        --counter;

        // Define a variable for the node to be removed
        CalNode *last_node = curr_node->nxt;

        // Check if the last_node is equal to the curr_node
        if (last_node == curr_node)
        {
            // Assign null to the curr_node
            curr_node = nullptr;
        }
        else
        {
            // Assign the value at last_node's next to curr_node's next
            curr_node->nxt = last_node->nxt;
        }
        // Delete the value at last_node
        delete last_node;
    }
}

// Define the toString() function
std::string CalcList::toString(unsigned short precision) const
{
    // Create a stringtream object
    std::stringstream s;

    // Initialize an empty string variable
    std::string to_string = "";

    // Assign the value of counter to a variable
    int back = counter;

    // Define a ptr variable for node
    CalNode *ptr = new CalNode;

    // Assign the value of curr_node's next to ptr
    ptr = curr_node->nxt;
    s.precision(precision);

    // Loop till the ptr's total is not equal to zero
    while (ptr->node_total != 0)
    {
        // Display the position value of the node
        s << back << ": ";

        // Display the value at ptr->nxt->node_total
        s << std::fixed << ptr->nxt->node_total;

        if (ptr->node_operator == ADDITION)
        {
            // Display the operator
            s << "+";
        }
        else if (ptr->node_operator == SUBTRACTION)
        {
            // Display the operator
            s << "-";
        }
        else if (ptr->node_operator == MULTIPLICATION)
        {
            // Display the operator
            s << "*";
        }
        else if (ptr->node_operator == DIVISION)
        {
            // Display the operator
            s << "/";
        }
        // Display the value at ptr->node_operand
        s << ptr->node_operand;

        // Display the equal to symbol
        s << "=";

        // Display the value at ptr->node_total
        s << ptr->node_total;

        // Move the stream pointer to next line
        s << std::endl;

        // Assign the ptr's next value to ptr
        ptr = ptr->nxt;

        // Decrement the value for back
        --back;
    }

    // Convert the stringtream object to string and assign to the to_string variable
    to_string = s.str();

    // Return the string value
    return to_string;
}