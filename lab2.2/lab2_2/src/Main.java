public class Main {

    public static final int TEN = 10;
    public static final int TWO = 2;
    public static final int ONE = 1;
    public static final int ZERO = 0;

    public static final int NINE = 9;

    public static void printNumber(int[] array, int iterationCount) {
        int lastIndex;
        lastIndex = iterationCount - ONE;
        System.out.print("Минимальное число --->  ");
        for (int i = lastIndex; i > ZERO; i--) {
            System.out.print(array[i]);
        }
        System.out.println();
    }

    public static void findMinimumNumber() {
        final int arraySize = 50;
        int[] numberArray = new int[arraySize];
        int index, currentNumber, carryOver;
        boolean isFound;
        index = ONE;
        currentNumber = TWO;
        carryOver = ZERO;
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

    public static void printProblemStatement() {
        System.out.println("Данная программа находит самое маленькое натуральное число," +
                           "для которого верно следующее условие:\n" +
                           "Eсли последнюю цифру этого числа перенести и поставить перед первой цифрой, то получится число," +
                           "в два раза больше исходного числа");
    }

    public static void main(String[] args) {
        printProblemStatement();
        findMinimumNumber();
    }
}