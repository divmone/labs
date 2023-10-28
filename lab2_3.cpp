#include <iostream>
#include <fstream>
#include <string>

const int MIN_SIZE = 2;
const int MAX_SIZE = 10;
const int MIN_VALUE = -1000;
const int MAX_VALUE = 1000;

void printProblemStatement() 
{
    std::cout << "Данная программа выполняет прямой ход в решении СЛАУ методом Гаусса." << std::endl
        << "Диапазон ввода значений количества уравнений в системе: " << MIN_SIZE << "..." << MAX_SIZE << "." << std::endl
        << "Диапазон ввода значений коэффициентов при переменных: " << MIN_VALUE << "..." << MAX_VALUE << "." << std::endl;
}

int selectInputMethod() 
{
    std::cout << "Выберите метод ввода (1 - через консоль, 2 - из файла): ";
    int choice;
    bool isIncorrect;
    
    do
    {
        isIncorrect = false;
        std::cin >> choice;

        if (std::cin.fail() ||  std::cin.get() != '\n')
        {
            isIncorrect = true;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Проверьте корректность ввода данных!" << std::endl;
            
        }

        if (isIncorrect || (choice != 1 && choice != 2))
        {
            isIncorrect = true;
            std::cout << "Введите 1(ввод из консоли) или 2(ввод из файла)!" << std::endl;
        }

    } while (isIncorrect);

    return choice;

}

int inputSizeFromConsole() {
    int sizeMatrix;
    bool isIncorrect;

    std::cout << "Введите количество уравнений в системе: ";

    do {
        isIncorrect = false;
        std::cin >> sizeMatrix;
        
        if (std::cin.fail() || std::cin.get() != '\n') {
            
            isIncorrect = true;
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Проверьте корректность ввода данных!" << std::endl;
          
        }

        if (isIncorrect && (sizeMatrix < MIN_SIZE || sizeMatrix > MAX_SIZE)) {
            isIncorrect = true;
            std::cout << "Введите число в диапазоне от " << MIN_SIZE << " до " << MAX_SIZE << std::endl;

        }

    } while (isIncorrect);

    return sizeMatrix;
}

int inputSizeFromFile(const std::string path) {
    int size;
    std::string sizeInp;
    bool isIncorrect = true;
    std::ifstream fin(path);

    fin >> sizeInp;

    try {
        size = atoi(sizeInp.c_str());
    }
    catch (...) {
        std::cout << "Ошибка при чтении системы! Введите систему с консоли! \n";
        isIncorrect = true;
        size = inputSizeFromConsole();
    }

    if (!isIncorrect && (size < MIN_SIZE || size > MAX_SIZE))
    {

        std::cout << "Ошибка при чтении системы! Введите систему с консоли! \n";
        isIncorrect = true;
        size = inputSizeFromConsole();

    }

    return size;

}

float** inputMatrixFromConsole(const int size) {
    float** matrix = new float* [size];
    bool isIncorrect;
    int finalPos = size + 1;
     
    for (int i = 0; i < size; i++) {
        matrix[i] = new float[size + 1];
    }
     
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            do {
                std::cout << "Введите " << j + 1 << "-ый коэффицент " << i + 1 << "-ого уравнения: ";
                isIncorrect = false;
                std::cin >> matrix[i][j];

                if(std::cin.fail() || std::cin.get() != '\n')
                {
                    isIncorrect = true;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Проверьте корректность ввода данных!" << std::endl;

                }

                if (isIncorrect && (matrix[i][j] < MIN_VALUE || matrix[i][j] > MAX_VALUE))
                {
                    isIncorrect = true;
                    std::cout << "Для выбора введите 1 или 2!" << std::endl;
                }

            } while (isIncorrect);
        }
    }

    return matrix;
}

std::string inputPathToFile() {
    std::string path;
    bool isIncorrect;

    std::cout << "Укажите путь к файлу: ";

    do
    {
        isIncorrect = false;
        std::cin >> path;
        std::ifstream file(path);
        if (path.substr(path.find_last_of(".") + 1) != "txt")
        {
            isIncorrect = true;
            std::cout << "Введён некорректный формат пути! Введите путь расширением .txt заново!" << std::endl;
        }
        file.open(path);
        if (!file.is_open())
        {
            std::cout << "По указанному пути файл не найден! Укажите правильный путь: ";
            isIncorrect = true;
        }
    } while (isIncorrect);

    return path;
}

float** inputMatrixFromFile(const int size, const std::string path) {
    
    int count = 0;
    int finalPos = size + 1;

    float** matrix = new float* [size];

    for (int i = 0; i < size; i++)
        matrix[i] = new float[size + 1];

    bool isIncorrect;
    std::string matrixInp;
    std::ifstream fin(path);

    fin >> matrixInp;

    while (!fin.eof())
    {
        std::string symbol;
        fin >> symbol;
        count++;
    }

    if (count > size * (size + 2))
    {
        std::cout << "Ошибка при чтении системы! Введите систему с консоли! \n";
        matrix = inputMatrixFromConsole(size);
    }
    else
    {
        fin.close();
        fin.open(path);
        fin >> matrixInp;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < finalPos; j++)
            {
                do
                {
                    isIncorrect = false;

                    try
                    {
                        fin >> matrix[i][j];
                    }
                    catch (...)
                    {
                        std::cout << "Ошибка при чтении системы! Введите систему с консоли! \n";
                        isIncorrect = true;
                        matrix = inputMatrixFromConsole(size);
                    }

                    if (!isIncorrect && (matrix[i][j] < MIN_VALUE || matrix[i][j] > MAX_VALUE))
                    {
                        std::cout << "Ошибка при чтении системы! Введите систему с консоли! \n";
                        isIncorrect = true;
                        matrix = inputMatrixFromConsole(size);
                    }
                } while (isIncorrect);
            }
        }
    }

    fin.close();

    return matrix;
}

float** inputMatrix(const int size, std::string path, const int choice) {
    float** matrix = new float* [size];

    for (int i = 0; i < size; i++)
        matrix[i] = new float[size + 1];

    if (choice == 1)
        matrix = inputMatrixFromConsole(size);
    if (choice == 2)
        matrix = inputMatrixFromFile(size, path);

    return matrix;
}

int inputSize(const int choice, std::string path) {
    int size;
    size = 0;
    if (choice == 1)
        size = inputSizeFromConsole();
    if (choice == 2)
        size = inputSizeFromFile(path);

    return size;
}

void outputEnteredMatrix(const int choice, std::string path, float** &matrix, const int size) {
    bool isIncorrect;
    std::ofstream fout;

    if (choice == 1)
    {
        std::cout << "Начальная система уравнений: \n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "|";
            for (int j = 0; j < size; j++)
                std::cout << " " << matrix[i][j] << " \t";
            std::cout << "|" << matrix[i][size] << "\n";
        }

        std::cout << "\n";
    }

    if (choice == 2)
    {
        std::cout << "Вывод начальной системы уравнений в файл... \n";

        fout.open(path, std::ios::app);
        fout << "\n";

        do
        {
            isIncorrect = false;

            try
            {
                std::cout << "Вывод начальной системы уравнений: \n";
                for (int i = 0; i < size; i++)
                {
                    fout << "|";
                    for (int j = 0; j < size; j++)
                        fout << " " << matrix[i][j] << " \t";
                    fout << "|  " << matrix[i][size] << "; \n";
                }
                 
                fout << "\n";
            }
            catch (...)
            {
                std::cout << "Ошибка! Измените параметры файла или укажите новую ссылку! \n";
                isIncorrect = true;
                path = inputPathToFile();
            }
        } while (isIncorrect);

        fout.close();
        std::cout << "Данные успешно записаны в файл! \n";
    }
}

float** triangulateMatrix(float** matrix, const int size) {
 
    for (int i = 0; i < size; i++)
    {
 
        for (int j = i + 1; j < size; j++)
        {
            float K = matrix[j][i] / matrix[i][i];

            for (int k = i; k < size; k++)
                matrix[j][k] = matrix[j][k] - K * matrix[i][k];

            matrix[j][size] = matrix[j][size] - K * matrix[i][size];
        }
    }
    return matrix;
}

void outputTriangulatedMatrix(const int choice,std::string path, float** matrix , const int size) {
    bool isIncorrect;
    std::ofstream fout;

    if (choice == 1)
    {
        std::cout << "Преобразованная система уравнений по методу Гаусса: \n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "|";
            for (int j = 0; j < size; j++)
                std::cout << " " << matrix[i][j] << "  ";
            std::cout << "|" << matrix[i][size] << "\n";
        }

        std::cout << "\n";
    }

    if (choice == 2)
    {
        std::cout << "Вывод преобразованной системы уравнений в файл... \n";

        fout.open(path, std::ios::app);
        fout << "\n";

        do
        {
            isIncorrect = false;

            try
            {
                std::cout << "Вывод преаброзованной системы уравнений: \n";
                for (int i = 0; i < size; i++)
                {
                    fout << "|";
                    for (int j = 0; j < size; j++)
                        fout << " " << matrix[i][j] << " \t";
                    fout << "|  " << matrix[i][size] << "; \n";
                }

                fout << "\n";
            }
            catch (...)
            {
                std::cout << "Ошибка! Измените параметры файла или укажите новую ссылку! \n";
                isIncorrect = true;
                path = inputPathToFile();
            }
        } while (isIncorrect);

        fout.close();
        std::cout << "Данные успешно записаны в файл! \n";
    }

}

void processInputSelection(int &choice, std::string path,  int &size) {
    

    printProblemStatement();

    choice = selectInputMethod();
    if (choice == 2)
        path = inputPathToFile();
    size = inputSize(choice, path);

}

void processOutputSelection(int choice,float** matrix, std::string path, int size) {

    outputEnteredMatrix(choice, path, matrix, size);

    matrix = triangulateMatrix(matrix, size);

    outputTriangulatedMatrix(choice, path, matrix, size);
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice, size;
    std::string path;

    processInputSelection(choice, path, size);

    float** matrix = new float* [size];

    for (int i = 0; i < size; i++)
        matrix[i] = new float[size];

    matrix = inputMatrix(size, path, choice);

    processOutputSelection(choice, matrix, path, size);

    for (int i = 0; i < size; ++i)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
