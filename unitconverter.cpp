#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// conversion functions
// should I be using classes?

// length: inches, centimeters, feet, meters, miles, kilometers

// how critical is it to only have one flow direction?
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
    // perhaps this should return a string
    // that would make it easier to denote errors
    // no number would be appropriate for errors
    // is there an NA value?
    // maybe if there is an error it should just
    // return the same value
    // or the error could be caught before this step
    // that would be better

    // variables
    // l is "length"
    // fl is "from length"
    // to is "to length"

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
            return l;
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
            return l;
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
            return l;
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
            return l;
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
            return l;
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
            return l;
        }

    // mistake
    default:
        return l;
    }
}

// This is the function that asks the user for
// the length input variables
string length_converter()
{
    // the variables
    float size;
    float res;
    char f;
    char t;
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
    cin >> size >> f >> t;

    // the error catcher could be here
    // if fl and tl are not c, m, k, i, f, or M reject
    // if size is not a number, reject

    // do the calculation
    res = length_switcher(size, f, t);

    // paste everything together
    oss << size << " " << f << " is " << res << " " << t << endl;
    s = oss.str();

    // return the string
    return s;
}

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

    // make the converted temperature type string
    converted_temperature_type = (temperature_type == 'c') ? 'f' : 'c';

    // paste everything together
    oss << degrees << "° " << temperature_type << " is " << res << "° " << converted_temperature_type << endl;
    s = oss.str();

    // return the string
    return s;
}

// Make a function that asks the user what they want
// it should return a char: t or l
char type_of_conversion()
{
    // variables
    char x;
    string text =
        "Will you be converting a temperature "
        "or length? Please answer t for "
        "temperature and l for length.";

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

    string def = "Please choose either t for temperature or l for length.";

    switch (oper)
    {
    case 't':
        return temperature_converter();
    case 'l':
        return length_converter();
    default:
        return def;
    }
}

int main()
{
    char oper;

    // There needs to be a function that decides whether to go down the
    // temperature, length, or volume pathway
    cout << case_switcher(type_of_conversion()) << endl;

    return 0;
}