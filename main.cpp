#include <iostream>
#include <locale>
#include "header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    baggage info[numPerson];
    string action_s;
    int action_i;


    //Программа будет продолжаться
    //пока того желает пользователь
    do
    {
        cout
            << "Выберите действие:\n"
            << "\t1 - Изменить информацию о багаже;\n"
            << "\t2 - Вывести список багажа;\n"
            << "\t3 - Вывести пассажиров, багаж которых состоит "
            << "из одного предмета весом не меньше 30 кг;\n"
            << "\t0 - Выход.\n";

        //поиск исключения
        try{
            cin
                >> action_s;
            action_i = stoi(action_s);
        }
        //обработка исключени
        //если был введен символ
        catch(...)
        {
            cout
                << endl << endl
                << setw(40) << setfill('-')
                << '-'
                << setfill(' ')
                << endl << endl;
            cout
                << "\tПроизошла ошибка!\n"
                << "\tВы ввели не числовое значение!\n\n";
            cout
                << setw(40) << setfill('-')
                << '-'
                << setfill(' ')
                << endl << endl;
            action_i = 1;
            continue;
        }
        cout
            << endl << endl;


        switch(action_i)//выбор действия
        {
            case 0:
                    break;
            case 1:
                    inputInfo(info); break;
            case 2:
                    outputInfo(info); break;
            case 3:
                    specialPerson(info); break;
            default:
            {
                    cout
                        << setw(40) << setfill('-')
                        << '-'
                        << setfill(' ')
                        << endl << endl;
                    cout
                        << "Нет действия с номером который вы ввели!\n"
                        << "Выберите номер действия из списка.\n\n";
                    cout
                        << setw(40) << setfill('-')
                        << '-'
                        << setfill(' ')
                        << endl << endl;
            }
        }
    }while(action_i != 0);


    return 0;
}
