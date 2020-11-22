#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class labmatrix
{
    private:
    vector< vector<double> > matrix;

    public:
    labmatrix(int size);
    labmatrix(int row, int col);
    void print();
    ~labmatrix();
    int row();
    int col();
    void set(int n, int m, double val);
    double get(int n, int m);
    labmatrix add(labmatrix m2);
    labmatrix substract(labmatrix m2);
    labmatrix multiply(labmatrix m2);
    bool store(string filename, string path);
    labmatrix(string filename);

};


int main()
{
    srand((unsigned) time(0));
    //wczytanie i wyswietlenie rowów i columnusów
    int row;
    int col;

    cout << "podaj liczbe wierszy" << endl;
    cin >> row;
    cout << "podaj liczbe kolumn" << endl;
    cin >> col;
    //---------------proba konstruktorow----------------//

    //tworzenie matrixa z konstruktorem jedoargumentowym
    labmatrix macierz(row);
    //tworzenie matrixa z drugim konstruktorem
    labmatrix macierz2(row, col);
    labmatrix macierz3(row, col);
    //z pliku
    labmatrix macierz4("C:\\Users\\proco\\cppprojects\\lab3\\plik.txt");
    
    //-----proba funkcji cols i rows-----------//
    cout << "kolumny to" << macierz2.col() << endl;
    cout << "wiersze to" << macierz2.row() << endl;

    //-------proba funkcji set i get---------//
    macierz2.set(1, 1, 3);
    macierz2.set(1, 0, 5);
    macierz2.set(0, 0, 2);
    macierz3.set(1, 1, 5);
    macierz3.set(1, 0, 3);
    macierz3.set(0, 0, 7);
    int get = macierz2.get(1, 1);
    cout << "test funkcji get: " << get << endl;

    //--------proba funkcji print----------//
    cout << "macierz 1:" << endl;
    macierz.print();
    cout << "macierz 2:" << endl;
    macierz2.print(); 
    cout << "macierz 3:" << endl;
    macierz3.print(); 
    cout << "wypisz macierz 4 (z pliku)" << endl;
    macierz4.print();

    //------add, subtract, multiply-------//
        //matrix dodawanie
    cout << "---------" << endl;
    cout << "dodawanie" << endl;
    macierz2 = macierz2.add(macierz3);
    macierz2.print();
        //matrix odejmowanie
    cout << "---------" << endl;
    cout << "odejmowanie" << endl;
    macierz2 = macierz2.substract(macierz3);
    macierz2.print();
        //matrix mnozenie
    cout << "---------" << endl;
    cout << "mnozenie" << endl;
    macierz2 = macierz2.multiply(macierz3);
    macierz2.print();
    
    //--------test  funkcji store-------//

    macierz2.store("plik.txt", "C:\\Users\\proco\\cppprojects\\lab3\\");
    
    return 0;
}

labmatrix::labmatrix(int size)
{
        vector<double>row;
        for(int j = 0; j < size; j++)
        {
            row.push_back(0);
        }
        for(int i = 0; i < size; i++)
        {
        matrix.push_back(row);
        }
}


labmatrix::labmatrix(int a, int b)
{
        vector<double>row;
        for(int j = 0; j < a; j++)
        {
            for(int i = 0; i < b; i++)
            {
                row.push_back(0);    
            }
            matrix.push_back(row);
        }
        
}

int labmatrix::col()
{
    return matrix[0].size();
}

int labmatrix::row()
{
    return matrix.size();
}

labmatrix::~labmatrix()
{

}

void labmatrix::print()
{
    cout << "-----wypisanie----" << endl;
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

labmatrix labmatrix::add(labmatrix m2)
{
    int a = row();
    int b = col();
    if( ! (a == m2.col() ) && (b == m2.col() ) )
    {
        cout << "nie mozna dodac" << endl;
        exit(1);
    }
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
        }
    }
    return matrix3;
}

void labmatrix::set(int n, int m, double val)
{
    matrix.at(n).at(m) = val;
}

double labmatrix::get(int n, int m)
{
    return matrix.at(n).at(m);
}

labmatrix labmatrix::substract(labmatrix m2)
{
    int a = row();
    int b = col();
    if( ! (a == m2.col() ) && (b == m2.col() ) )
    {
        cout << "nie mozna odjac" << endl;
        exit(1);
    }
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];
        }
    }
    return matrix3;    
}

labmatrix labmatrix::multiply(labmatrix m2)
{
    int a = row();
    int b = col();
    if(!(a == m2.row()))
    {
        cout << "nie mozna mnozyc" << endl;
        exit(1);
    }
    double value = 0;
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            value = 0;
            for(int k = 0; k < row(); k++)
            {
               value = value + matrix[i][k] * (m2.matrix)[k][j];
            }
            (matrix3.matrix)[i][j] = value;
        }
    }
    return matrix3;
}

bool labmatrix::store(string filename, string path)
{
    fstream mojplik;

    int a = row();
    int b = col();
    string full_file_name = path + filename;
    cout << full_file_name;
    mojplik.open(full_file_name, ios::out);
    
    if(mojplik.is_open())
    {
        mojplik << a << " " << b;
        mojplik << endl;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                mojplik << matrix[i][j];
                mojplik << " ";
            }
            mojplik << endl;
        }
    }
    else
    {
        cout << "plik otwarty nieprawidłowo" << endl;
    }
    
    return true;

}

labmatrix::labmatrix(string filename)
{
    fstream mojplik;
    int a;
    int b;
    double val;
    vector<double>row;

    mojplik.open(filename, ios::in);

    if(mojplik.is_open())
    {
        mojplik >> a;
        mojplik >> b;
        for(int j = 0; j < a; j++)
        {
            for(int i = 0; i < b; i++)
            {
                mojplik >> val;
                row.push_back(val);
            }
            matrix.push_back(row);
            row.clear();
        }

    }

    cout << "a to " << a << endl;
    cout << "b to " << b << endl;
    

}

