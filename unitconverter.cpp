#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// conversion functions
// should I be using classes or something?

// length: inches, centimeters, feet, meters, miles, kilometers

// how critical is it to only have one flow direction?
// for instance when converting from inches to kilometers
// we could go from inches to centimeters, then from centimeters
// to meters, then meters to kilometers
// or
// from inches to feet, then from feet to miles, then from
// miles to kilometers
// or something else all together.
// maybe there should be metric to metric, metric to
// imperial and imperial to metric but no imperial to
// imperial
//
// for example, in the first picture below there are
// many ways for one unit to get to another, but
// in the second picture below there is only
// one way to get from one unit to another
//
//  c----i       c----i
//  |    |       |
//  m----f  vs.  m----f
//  |    |       |
//  k----M       k----M

// metric to metric
// up
float centimeters_to_meters(float l) { return l / 100; }
float meters_to_kilometers(float l) { return l / 1000; }

//down
float kilometers_to_meters(float l) { return l * 1000; }
float meters_to_centimeters(float l) { return l * 100; }

// metric to imperial
float centimeters_to_inches(float l) { return l * 0.3937; }
float meters_to_feet(float l) { return l * 3.2808; }
float kilometers_to_miles(float l) { return l * 0.621371; }

// imperial to metric
float inches_to_centimeters(float l) { return l / 0.3937; }
float feet_to_meters(float l) { return l / 3.2808; }
float miles_to_kilometers(float l) { return l / 0.621371; }

float length_switcher(float l, char fl, char tl)
{
    // it should be nested switch cases.

    switch (fl)
    {
    // centimeters
    case 'c':
        switch (tl)
        {
        case 'm':
            return centimeters_to_meters(l);
        case 'k':
            return meters_to_kilometers(centimeters_to_meters(l));
        case 'i':
            return centimeters_to_inches(l);
        case 'f':
            return meters_to_feet(centimeters_to_meters(l));
        case 'M':
            return kilometers_to_miles(meters_to_kilometers(centimeters_to_meters(l)));
        default:
            return 0;
        }

    // meters
    case 'm':
        switch (tl)
        {
        case 'c':
            return meters_to_centimeters(l);
        case 'k':
            return meters_to_kilometers(l);
        case 'i':
            return centimeters_to_inches(meters_to_centimeters(l));
        case 'f':
            return meters_to_feet(l);
        case 'M':
            return kilometers_to_miles(meters_to_kilometers(l));
        default:
            return 0;
        }

    // kilometers
    case 'k':
        switch (tl)
        {
        case 'c':
            return meters_to_centimeters(kilometers_to_meters(l));
        case 'm':
            return kilometers_to_meters(l);
        case 'i':
            return centimeters_to_inches(meters_to_centimeters(kilometers_to_meters(l)));
        case 'f':
            return meters_to_feet(kilometers_to_meters(l));
        case 'M':
            return kilometers_to_miles(l);
        default:
            return 0;
        }

    // inches
    case 'i':
        switch (tl)
        {
        case 'c':
            return inches_to_centimeters(l);
        case 'm':
            return centimeters_to_meters(inches_to_centimeters(l));
        case 'k':
            return meters_to_kilometers(centimeters_to_meters(inches_to_centimeters(l)));
        case 'f':
            return meters_to_feet(centimeters_to_meters(inches_to_centimeters(l)));
        case 'M':
            return kilometers_to_miles(meters_to_kilometers(centimeters_to_meters(inches_to_centimeters(l))));
        default:
            return 0;
        }

    // feet
    case 'f':
        switch (tl)
        {
        case 'c':
            return meters_to_centimeters(feet_to_meters(l));
        case 'm':
            return feet_to_meters(l);
        case 'k':
            return meters_to_kilometers(feet_to_meters(l));
        case 'i':
            return centimeters_to_inches(meters_to_centimeters(feet_to_meters(l)));
        case 'M':
            return kilometers_to_miles(meters_to_kilometers(feet_to_meters(l)));
        default:
            return 0;
        }

    // miles
    case 'M':
        switch (tl)
        {
        case 'c':
            return miles_to_kilometers(kilometers_to_meters(meters_to_centimeters(l)));
        case 'm':
            return miles_to_kilometers(kilometers_to_meters(l));
        case 'k':
            return miles_to_kilometers(l);
        case 'i':
            return miles_to_kilometers(kilometers_to_meters(meters_to_centimeters(centimeters_to_inches(l))));
        case 'f':
            return miles_to_kilometers(kilometers_to_meters(meters_to_feet(l)));
        default:
            return 0;
        }

    // mistake
    default:
        return 0;
    }
}

// This is the function that asks the user for
// the length input variables
string length_converter()
{
    // the variables
    float size;
    float res;
    char fl;
    char tl;
    // string length_type_string;
    // string converted_length_type;
    string s;
    ostringstream oss;

    string directions =
        "First enter the length size followed by the units, "
        "then enter the units you want the length convered to: "
        "c for centimeters, m for meters, k for kiometers, "
        "i for inches, f for feet and M for miles.";

    // this could be a function, should it be?
    // get the temperature to be converted
    cout << "Length converter!" << endl;
    cout << directions << endl;
    cin >> size >> fl >> tl;

    // do the calculation
    res = length_switcher(size, fl, tl);

    // deal with this later. it looks like a nother switch case
    // make the original temperature type string
    // temperature_type_string = (temperature_type == 'c') ? "celsius" : "fahrenheit";
    // make the converted temperature type string
    // converted_temperature_type = (temperature_type == 'c') ? "fahrenheit" : "celsius";

    // paste everything together
    oss << size << " " << fl << " is " << res << " " << tl << endl;
    s = oss.str();

    // return the string
    return s;
}

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
        return length_converter();
        // return l;
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