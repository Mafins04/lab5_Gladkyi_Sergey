#include "header.h"


//Ввод информации о багажах
void inputInfo(baggage* info)
{
    char proceed;
    string numBaggage_s;
    int numBaggage_i;
    string check;


    //Ввод новой информации о багаже
    //будет продолжаться пока того желает пользователь
    do
    {
        cout
            << setw(67) << setfill('-')
            << '-'
            << setfill(' ')
            << endl;
        cout
            << "Введите номер багажа "
            << "информацию которого желаете изменить(1-10): ";

        //поиск исключения
        try
        {
            cin
                >> numBaggage_s;
            numBaggage_i = stoi(numBaggage_s);
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
            cout
                << "\n\nЖелаете ещё внести изменения?(y/n)\n";
            cin
                >> proceed;
            cout
                << endl << endl;
            continue;
        }

        //Уменьшаем значение вводимое пользователем
        //для работы с массивом
        numBaggage_i--;

        cout
            << endl << endl;

        //Проверка числа, которое ввёл пользователь
        //на вхождение в диапазон от 0 до 9
        if(numBaggage_i >= 0 && numBaggage_i < numPerson)
        {
            cout
                << setw(25) << setfill('-')
                << '-'
                << setfill(' ')
                << endl;
            cout
                << "Фамилия пассажира: ";
            cin
                >> info[numBaggage_i].surname;

            //поиск исключения
            try{
                cout
                    << "Кол-во вещей в багаже: ";
                cin
                    >> check;
                if(stoi(check) < 0) throw -1;
                info[numBaggage_i].number_things = stoi(check);

                if(info[numBaggage_i].number_things != 0)
                {
                    cout
                        << "Общий вес багажа(кг): ";

                    cin
                        >> check;
                    if(stoi(check) < 0) throw -1;
                    info[numBaggage_i].total_weight = stof(check);
                }
                cout
                    << setw(25) << setfill('-')
                    << '-'
                    << setfill(' ')
                    << endl;
            }
            //обработка исключени
            //если было введено число меньше 0
            catch(int)
            {
                cout
                    << endl << endl
                    << setw(40) << setfill('-')
                    << '-'
                    << setfill(' ')
                    << endl << endl;
                cout
                    << "\tПроизошла ошибка!\n"
                    << "\tЗначение не может быть отрицательным.\n\n";
                cout
                    << setw(40) << setfill('-')
                    << '-'
                    << setfill(' ')
                    << endl << endl;

                info[numBaggage_i].surname = "-";
                info[numBaggage_i].number_things = 0;
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
                info[numBaggage_i].surname = "-";
                info[numBaggage_i].number_things = 0;
            }
        }
        else
        {
            cout
                << setw(40) << setfill('-')
                << '-'
                << setfill(' ')
                << endl << endl;
            cout
                << "Вы ввели номер не существующего багажа!\n\n";
            cout
                << setw(40) << setfill('-')
                << '-'
                << setfill(' ')
                << endl << endl;
        }


        cout
            << "\n\nЖелаете ещё внести изменения?(y/n)\n";
        cin
            >> proceed;
        cout
            << endl << endl;

    }while(proceed == 'y');

    cout
        << setw(25) << setfill('-')
        << '-'
        << setfill(' ')
        << endl;
    cout
        << endl << endl;
}

//Вывод информации о багажах
void outputInfo(baggage* info)
{
    for(int i = 0; i < numPerson; i++)
    {
        cout
            << setw(25) << setfill('-')
            << '-'
            << setfill(' ')
            << endl;
        cout
            << "Пассажир №" << i + 1
            << ":\n\n";
        cout
            << "Фамилия: "
            << info[i].surname
            << endl;
        cout
            << "Кол-во вещей: "
            << info[i].number_things
            << endl;
        cout
            << "Общий вес багажа(кг): "
            << info[i].total_weight
            << endl << endl;
        cout
            << setw(25) << setfill('-')
            << '-'
            << setfill(' ')
            << endl;
    }
    cout
        << endl << endl << endl;
}


//Функция, определяющая есть ли
//пассажир, багаж которого состоит
//из одного предмета весом не меньше 30 кг
void specialPerson(baggage* info)
{
    int counter = 0;
    cout
            << setw(75) << setfill('-')
            << '-'
            << setfill(' ')
            << endl;
    cout
        << "Пассажиры, багаж которых состоит "
        << "из одного предмета весом не меньше 30 кг:\n\n";

    for(int i = 0; i < numPerson; i++)
    {
        if(info[i].number_things == 1 && info[i].total_weight >= 30)
        {
            cout
                << "\tПассажир " << info[i].surname
                << " с номером в списке " << i + 1
                << endl
                << "\tВес багажа: " << info[i].total_weight
                << endl << endl;
            counter++;
        }
    }

    if(counter == 0)
        cout
            << "\tНет пассажиров с таким багажом.\n\n\n";
    cout
            << setw(75) << setfill('-')
            << '-'
            << setfill(' ')
            << endl << endl << endl;
}
