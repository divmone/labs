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
    int index, currentNumber, carryOver;
    bool isFound;
    index = ONE;
    currentNumber = 2;
    carryOver = 0;
    isFound = false;

    while (index < arraySize && !isFound) {

        currentNumber = currentNumber * TWO + carryOver;
        carryOver = (currentNumber > NINE) ? ONE : ZERO;
        currentNumber = (currentNumber > NINE) ? (currentNumber - TEN) : currentNumber;
        numberArray[index] = currentNumber;
        isFound = (currentNumber == TWO) && (carryOver == ZERO);
        index++;
    }

    printNumber(numberArray, index);
}

void printProblemStatement()
{
    std::cout
        << "Данная программа находит самое маленькое натуральное число,"
        << "для которого верно следующее условие: " << std::endl
        << "Eсли последнюю цифру этого числа перенести и поставить перед первой цифрой, то получится число," << std::endl
        << "в два раза больше исходного числа"
        << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    printProblemStatement();
    findMinimumNumber();

    return 0;
}