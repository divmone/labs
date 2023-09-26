#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    const int DIVISOR_TWO = 2;
    const int STEP = 2;
    int i;
    const int MIN = 1;
    const int MAX = 50;
    unsigned long long number;
    unsigned long long nFactFact = 1;
    unsigned long long nMax;
    bool isInCorrect;
    

    std::cout << "\tДанная программа принимает n, и считает 1*3*...*n для нечетного n и 2* 4*...*n для четного n.\n"
              <<   "Введите n (n - натуральное число)\n"
              <<   "Диапазон значений n : "
              <<    MIN << "..." << MAX << " \n";
     
    do
    {
        isInCorrect = false;

        std::cin >> number;

        if (std::cin.get() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(20000, '\n');
            isInCorrect = true;
        }

        if (isInCorrect || number < MIN || number > MAX )
        {
            isInCorrect = true;
            std::cout << "Проверьте корректность ввода данных!\n"
                      << "Диапазон значений n (n - натуральное число ) : "
                      <<  MIN << "..." << MAX << " \n";
        }
    } while (isInCorrect);
    
    nMax = number + 1;

    if (number % DIVISOR_TWO == 1) 
    {
        for (i = 1; i < nMax; i += STEP) 
        {
            nFactFact *= i;
        }
    } 
    else 
    {
        for (i = 2; i < nMax; i += STEP) 
        {
            nFactFact *= i;
        }
    }

    std::cout << "n!! = " << nFactFact;

    return 0;
}