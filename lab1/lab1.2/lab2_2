#include <iostream>

const int TEN = 10;
const int TWO = 2;

void printNumber(const int array[], int iterationCount) {

    std::cout << "Минимальное число --->  ";
    for (int i = iterationCount; i > 0; i--) {
        std::cout << array[i];
    }
    std::cout << std::endl;
}

void findMinimumNumber() {
    const int arraySize = 50;
    int numberArray[arraySize], i, currentNumber, curryOver;
    bool isFound;
    i = 1;
    currentNumber = TWO;
    curryOver = 0;
    isFound = false;

    
    while (i < arraySize && !isFound) {
        
        currentNumber = currentNumber * TWO;

        currentNumber = currentNumber + curryOver;

        curryOver = (currentNumber >= TEN) ? 1 : 0;

        currentNumber = (currentNumber >= TEN) ? (currentNumber - TEN) : currentNumber;

        numberArray[i] = currentNumber;

        isFound = currentNumber == TWO && curryOver == 0;
    
        i++;
        
    }
    printNumber(numberArray, i - 1);

}
 
void printProblemStatement() {
    std::cout << "Если последнюю цифру некоторого натурального числа n перенести "
              << "и поставить перед первой цифрой этого числа," << std::endl
              << "то получится число, в два раза больше n. Найти самое маленькое из таких чисел." << std::endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    printProblemStatement();
    findMinimumNumber();

    return 0;
}
