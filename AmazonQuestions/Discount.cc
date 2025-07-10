#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool validAmountToken(const string &input)
{
    if (input.empty() || input == "")
        return false;
    if (input.back() == '$' && isdigit(input.front()))
        return true;
    return false;
};

string calculateDiscount(const string &input, const double &discount)
{
    double amount = stod(input);
    double output = amount * (100 - discount) / 100.0;
    return to_string(output) + "$";
}

string getDiscountedPrice(const string &input, const double &discount)
{
    stringstream inputStream(input);
    string token, output = "";
    while (inputStream >> token)
    {
        if (validAmountToken(token))
        {
            token.pop_back();
            string discountedAmount = calculateDiscount(token, discount);
            output += discountedAmount + " ";
        }
        else
            output += token + " ";
    }
    return output;
}

int main()
{
    string input = "Amazon Echo costs 100$ now.";
    double discount = 20;
    string output = getDiscountedPrice(input, discount);
    cout << output << endl;
    return 0;
}