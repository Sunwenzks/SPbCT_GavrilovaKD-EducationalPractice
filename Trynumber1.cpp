#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <locale> 
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "Trap.h" 
#include <thread>
using namespace std;
vector<string> v1(10);
void mas() // сортировка по убыванию 
{
    sort(v1.begin(), v1.end(), greater<>());
    cout << endl;
    cout << "Векторы после сортировки: " << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << v1[i] << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "ФИО: Гаврилова Ксения Дмитриевна" << "\nГруппа: 503" << endl;
    string buffer = "";
    RealDateTime();
    string path = "info.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        cout << "Файл открыт" << endl;
        cout << "Векторы файла: " << endl;
        v1.clear();
        getline(fs, buffer);
        for (int i = 0; i < 100; i++)
        {
            v1.push_back(buffer.substr(i+1, 1)); // создание векторов
        }
    }
    cout << "Векторы: " << endl;
    for (int i = 0; i < 100; i++) 
    {
        cout << v1[i] << endl;
    }
    thread blj(mas);
    blj.join();
}