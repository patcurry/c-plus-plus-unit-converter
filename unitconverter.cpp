#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// conversion functions
// starting with imperial to metric

// length: feet and meters
// obviously there are many more choices here, but we're starting simple

// volume: ounces and liters

// temperature: fahrenheit and celsius
float c_to_f(float t)
{
    return 32 + (t * 9 / 5);
}

float f_to_c(float t)
{
    return (t - 32) * 5 / 9;
}

// now make the function that asks the user for the temperature
// input variables
string temperature_converter()
{
    // variables
    float degrees;
    float res;
    char temperature_type;
    string temperature_type_string;
    string converted_temperature_type;
    string s;
    ostringstream oss;

    // start the process of getting the temperature
    cout << "Temperature converter!" << endl;
    cout << "Please enter the temperature in degrees" << endl;
    cin >> degrees;
    cout << "Now enter c for celsius or f for fahrenheit" << endl;
    cin >> temperature_type;

    // so how do I lift this out and put it into it's own function?
    res = (temperature_type == 'c') ? c_to_f(degrees) : f_to_c(degrees);
    temperature_type_string = (temperature_type == 'c') ? "celsius" : "fahrenheit";
    converted_temperature_type = (temperature_type == 'c') ? "fahrenheit" : "celsius";

    // make the variable
    oss << degrees << "° " << temperature_type_string << " is " << res << "° " << converted_temperature_type << endl;
    s = oss.str();

    return s;
}

// Make a function that asks the user what they want
// to convert. As in "Are you converting a temperature, length or volume?
// please answer t for temperature, l for length and v for volume."
/*
int type_of_conversion(char t) {
    const char *text =
        "Will you be converting a temperature, "
        "length or volume? Please answer t for "
        "temperature, l for length and v for volume.";
    cout << *text << endl;
    cout << "Temperature converter!" << endl;

    return 0;
}
*/

int main() {

    // There needs to be a function that decides whether to go down the
    // temperature, length, or volume pathway

    // this is set up for only the temperature pathway right now
    cout << temperature_converter() << endl;

    return 0;
}