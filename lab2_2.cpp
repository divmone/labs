#include <iostream>

const int ONE = 1;
const int TWO = 2;
const int ZERO = 0;
const int NINE = 9;
const int TEN = 10;

void printNumber(int numberArray[], int length)
{
    int lastIndex = length - 1;
    std::cout << "Ваше число ---->  ";
    for (int i = lastIndex; i > ZERO; i--) {
        std::cout << numberArray[i];
    }
    std::cout << std::endl;
}

void findMinimumNumber()
{
    const int arraySize = 50;
    int numberArray[arraySize];
    int i, currentNumber, carryOver;
    bool isFound;
    i = ONE;
    currentNumber = 2;
    carryOver = 0;
    isFound = false;

    while (i < arraySize && !isFound) {

        currentNumber = currentNumber * TWO + carryOver;
        carryOver = (currentNumber > NINE) ? ONE : ZERO;

        currentNumber = (currentNumber > NINE) ? (currentNumber - TEN) : currentNumber;
        numberArray[i] = currentNumber;
        isFound = (currentNumber == TWO) && (carryOver == ZERO);
        i++;
    }

    printNumber(numberArray, i);
}

void printProblemStatement()
{
    std::cout
        << "Если последнюю цифру некоторого натурального числа n перенести "
        << "и поставить перед первой цифрой этого числа," << std::endl
        << "то получится число, в два раза больше n. Найти самое маленькое из "
        "таких чисел."
        << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    printProblemStatement();
    findMinimumNumber();

    return 0;
}