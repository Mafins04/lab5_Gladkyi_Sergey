#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

//структура, которая сожержит инфу
//про багаж пассажира
struct baggage
{
    string surname = "-";
    int number_things = 0;
    float total_weight = 0.0;
};

//кол-во пассажиров
const int numPerson = 10;

//объявление функций
void inputInfo(baggage* info);
void outputInfo(baggage* info);
void specialPerson(baggage* info);

#endif // HEADER_H_INCLUDED
