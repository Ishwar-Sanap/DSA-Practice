#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/*
std::stringstream in C++ is a part of the <sstream> library and is used for string manipulation, including parsing and formatting.
It allows you to treat strings like input/output streams (like cin and cout).

int num = 0;
cin >> num; // extraction operator (>>) Extract from keybord store into num //taking input from kebord and store it into num

cout << num ; //Insertion operator(<<):  display the num output in terminal


*/

vector<string> splitWords(string data, char del)
{
    stringstream ss(data);

    /*
    How getline(ss, token, delimiter) Works??

    getline() reads characters from the stream (ss) until it encounters the delimiter.
    Once it reaches the delimiter, it extracts the token before the delimiter and stores it in token.
    The stream's position moves forward, so the next call to getline() starts from where the last delimiter was found.
    This process repeats until the end of the string.
    */

    vector<string> tokens;
    string token = "";
    while (getline(ss, token, del))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{

    string data = "value is       10.45";
    stringstream ss(data);

    string str = "";

    ss >> str;
    cout << str << endl; // value
    ss >> str;
    cout << str << endl; // is
    ss >> str;
    cout << str << endl; // 10.45

    cout<<"\n------------------------------\n";
    /*
    How ss >> str Works in Stringstream
    When you use the extraction operator (>>) with stringstream, it automatically extracts the next word (token)
    separated by whitespace (spaces, tabs, or newlines).
    */

    data = "this,is,update,text";

    vector<string> tokens = splitWords(data, ',');
    for (string tk : tokens)
        cout << tk << endl;



    // Converting int / double to string
    int num = 42;
    double pi = 3.14159;
    stringstream ss2;

    ss2 << num << ":" << pi;  // storing int & double in stringstream

    string result = ss2.str();  // Get the formatted string
    cout << "Formatted String: " << result << endl; //42:3.14159


    // converting string to int/double
    string value = "3.14";
    stringstream ssObj(value);

    double dpi;
    ssObj >> dpi; // extract from the stringStream into pi
    cout<<dpi<<endl;

    return 0;
}