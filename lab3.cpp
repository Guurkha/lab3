#include <iostream>
#include <vector>
#include <fstream>

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

};


int main()
{
    //wczytanie i wyswietlenie rowów i columnusów
    int row;
    int col;
    cout << "podaj liczbe wierszy" << endl;
    cin >> row;
    cout << "podaj liczbe kolumn" << endl;
    cin >> col;
    //tworzenie matrixa z konstruktorem jedoargumentowym
    labmatrix macierz(row);
    //wyswietlenie jego column, test funkcji
    cout << "a too" << macierz.col() << endl;
    //tworzenie dwuargumentowego 
    labmatrix macierz2(row, col);
    labmatrix macierz3(row, col);
    //sprawdzenie czy dziala.
    //proba wypisania
    //macierz2.print(); //dziala :)
    //proba set
    //macierz2.set(2, 2, 5);
    macierz2.print(); // dziala :)
    //proba get
    macierz2.set(1, 1, 3);
    macierz2.set(1, 0, 5);
    macierz2.set(0, 0, 2);
    cout << "-----macierz 2----" << endl;
    macierz2.print();
    macierz3.set(1, 1, 5);
    macierz3.set(1, 0, 3);
    macierz3.set(0, 0, 7);
    cout << "-----macierz 3----" << endl;
    macierz3.print();
    /*
    double a = macierz2.get(1, 1);
    cout << "proba get" << endl;
    cout << a << endl;
    cout << "-----------" << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        (macierz2)[i][j] = i+j;
    }
    cout << "-----macierz 3----" << endl;
    macierz3.print();

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
    */
    //matrix mnozenie
    cout << "---------" << endl;
    cout << "mnozenie" << endl;
    macierz2 = macierz2.multiply(macierz3);
    macierz2.print();
    macierz2.store("chujdupa.txt", "C:\\Users\\proco\\cppprojects\\lab3\\");
    //macierz2.store("\duupa.txt");    
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

