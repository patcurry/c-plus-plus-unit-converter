#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// conversion functions
// starting with imperial to metric

// length: inches, centimeters, feet, meters, miles, kilometers

// metric to metric
// up
float centimeters_to_meters(float l) { return l * 100; }
float meters_to_kilometers(float l) { return l * 1000; }

//down
float kilometers_to_meters(float l) { return l / 1000; }
float meters_to_centimeters(float l) { return l / 100; }

// imperial to imperial
// up
float inches_to_feet(float l) { return l * 12; }
float feet_to_miles(float l) { return l * 5280; }

// down
float miles_to_feet(float l) { return l / 12; }
float feet_to_inches(float l) { return l / 12; }

// metric to imperial
float cm_to_inches(float l) { return l * 0.3937; }
float meters_to_feet(float l) { return l * 3.2808; }
float kilometers_to_miles(float l) { return l * 0.621371; }

// imperial to metric
float inches_to_cm(float l) { return l / 0.3937; }
float feet_to_meters(float l) { return l / 3.2808; }
float miles_to_kilometers(float l) { return l / 0.621371; }

// volume: ounces and liters

// temperature: fahrenheit and celsius
float celsius_to_fahrenheit(float t) { return 32 + (t * 9 / 5); }
float fahrenheit_to_celsius(float t) { return (t - 32) * 5 / 9; }

// This is the function that asks the user for
// the temperature input variables
string temperature_converter()
{
    // the variables
    float degrees;
    float res;
    char temperature_type;
    string temperature_type_string;
    string converted_temperature_type;
    string s;
    ostringstream oss;

    // this could be a function, should it be?
    // get the temperature to be converted
    cout << "Temperature converter!" << endl;
    cout << "Please enter the temperature in degrees" << endl;
    cin >> degrees;
    cout << "Now enter c for celsius or f for fahrenheit" << endl;
    cin >> temperature_type;

    // do the math
    // should this be a switch case?
    // right now this works, but what about errors?
    res = (temperature_type == 'c') ? celsius_to_fahrenheit(degrees) : fahrenheit_to_celsius(degrees);

    // make the original temperature type string
    temperature_type_string = (temperature_type == 'c') ? "celsius" : "fahrenheit";

    // make the converted temperature type string
    converted_temperature_type = (temperature_type == 'c') ? "fahrenheit" : "celsius";

    // paste everything together
    oss << degrees << "° " << temperature_type_string << " is " << res << "° " << converted_temperature_type << endl;
    s = oss.str();

    // return the string
    return s;
}

// Make a function that asks the user what they want
// it should return a char: t, l, or v
char type_of_conversion()
{
    // variables
    char x;
    string text =
        "Will you be converting a temperature, "
        "length or volume? Please answer t for "
        "temperature, l for length and v for volume.";

    // ask user what they will be converting
    cout << text << endl;

    // get x
    cin >> x;
    return x;
}

string case_switcher(char oper)
{
    // this should probably be a function that takes oper
    // write switch case for temperature, length and volume

    string l = "You chose length conversion!";
    string v = "You chose volume conversion!";
    string def = "I did not understand";

    switch (oper)
    {
    case 't':
        return temperature_converter();
    case 'l':
        // return length_converter();
        return l;
    case 'v':
        return v;
    default:
        return def;
    }
}

int main()
{
    char oper;

    // There needs to be a function that decides whether to go down the
    // temperature, length, or volume pathway
    oper = type_of_conversion();

    cout << case_switcher(oper) << endl;

    return 0;
}