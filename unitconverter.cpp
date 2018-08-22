#include <cstdlib>
#include <iostream>

using namespace std;



float c_to_f(float t)
{
    return 32 + (t * 9/5);
}

float f_to_c(float t) {
    return (t-32) * 5/9;
}

int main()
{
    // These variables are internal, do I have to declare variables externally for any reason?
    // Variable definition:
    float degrees; 
    float res;
    char temperature_type;
    string temperature_type_string;
    string converted_temperature_type;

    cout << "Temperature converter!" << endl;
    cout << "Please enter the temperature in degrees" << endl;
    cin >> degrees;

    cout << "Now enter c for celsius or f for fahrenheit" << endl;
    cin >> temperature_type;

    // so how do I lift this out and put it into it's own function?
    res = (temperature_type == 'c') ? c_to_f(degrees) : f_to_c(degrees);
    temperature_type_string = (temperature_type == 'c') ? "celsius" : "fahrenheit";
    converted_temperature_type = (temperature_type == 'c') ? "fahrenheit" : "celsius";

    cout << degrees << "° " << temperature_type_string << " is " << res << "° " << converted_temperature_type << endl;
    return 0;
}