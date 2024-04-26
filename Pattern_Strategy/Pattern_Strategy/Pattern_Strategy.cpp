
#include <iostream>
#include <vector>
using namespace std;

/*
//базовая абстрактная структур
struct PrintStrategy {
    virtual ~PrintStrategy() { }  //виртуальный деструктор
    virtual void print ( int *arr) const = 0;
};

// Конкретная стратегия для печати по n элементов в строке через пробел
class PrintElements : PrintStrategy {
    PrintElements (int n, int* arr) : n_(n), arr_(arr) {};

    void print(arr_) {
        for (size_t i = 0; i < arr_.size(); ++i) {
            cout << arr_[i] << " ";
            if ((i + 1) % n_ == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

private:
    int n_;
    int* arr_;
};

// Конкретная стратегия для печати по одному элементу в строке
class PrintOneElementStrategy : PrintStrategy {
public:
    void print(const std::vector<int>& arr) override {
        for (int num : arr) {
            std::cout << num << std::endl;
        }
    }
};

// Контекст, использующий стратегию печати
class ArrayPrinter {
public:
    void setPrintStrategy(PrintStrategy* strategy) {
        this->strategy = strategy;
    }

    void printArray(const std::vector<int>& arr) {
        strategy->print(arr);
    }

private:
    PrintStrategy* strategy;
};

int main() {
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    ArrayPrinter printer;

    PrintNElementsStrategy nElementsStrategy;
    nElementsStrategy.setN(3);

    PrintOneElementStrategy oneElementStrategy;

    printer.setPrintStrategy(&nElementsStrategy);
    std::cout << "Printing array with n elements in a row:" << std::endl;
    printer.printArray(arr);

    printer.setPrintStrategy(&oneElementStrategy);
    std::cout << "Printing array with one element in a row:" << std::endl;
    printer.printArray(arr);

    return 0;
}*/


#include <iostream>

using namespace std;

class PrintStrategy {    //класс, выполняющий роль интерфейса
public:
    virtual void operation(int*& arr, const int size) const = 0;   //Для того, чтобы работать не с копией указателя, параметр ссылка на указатель
    virtual ~PrintStrategy() {};
};

/*СТРАТЕГИИ*/
class PrintElementsN : public PrintStrategy {
public:
    PrintElementsN(int n) : n(n) {};
    void operation(int*& arr, const int size) const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
            if ((i + 1) % n == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    private:
        int n;
};

class PrintElements : public PrintStrategy {
public:
    void operation(int*& arr, const int size) const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
    }
};


// Контекст хранит все необходимые алгоритму данные и указатель на объект класса Strategy
class ArrayPrinter {        
    
public:

    ArrayPrinter(PrintStrategy* strategy) : strategy(strategy) {}

    void setStrategy(PrintStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void printArray(int*& arr, const int size) const {
        strategy->operation(arr, size);
    }

private:
    PrintStrategy* strategy;

};

int main()
{
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Создаем объекты стратегий 
    PrintElementsN printN(3);
    PrintElements printOne;

    // Создаем объекты контекста с разными стратегиями 
    ArrayPrinter arrayPrinter1(&printN);
    ArrayPrinter arrayPrinter2(&printOne);

    // Печать массива с разными стратегиями 
    cout << "Printing array 1:" << endl;
    arrayPrinter1.printArray(arr, size);

    cout << "\nPrinting array 2:" << endl;
    arrayPrinter2.printArray(arr, size);

   // PrintStrategy* str1 = new PrintElementsN(3);
   // PrintStrategy* str2 = new PrintElements();


    delete arr;
}

