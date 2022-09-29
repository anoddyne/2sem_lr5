//Задача 5, вариант 13, Бесшапошников Владимир
//Имеется текстовый файл, требуется получить новый файл, в котором должен быть
//скопирован исходный текст с инвертированным порядком слов.
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stack>

using namespace std;

//создаем функцию, чтобы менять порядок слов на обратный
void invert(string s) {

    //создаем пустой стек со строками
    stack<string> file_string;

    //создаем буферную строку, чтобы хранить там временную информацию
    string buffer;

    //цикл для разбиения текста в файле на слова и добавление отдельных слов в стек
    for (int i = 0; i < s.length(); i++) {

        //если не найден пробел в тексте, то слова побуквенно добавляются в буферную строку
        if (s[i] != ' ') {
            buffer += s[i];
        }

        //если пробел найден, то добавляем полученное слово в стек и очищаем буфер для следующих слов
        else {
            file_string.push(buffer);
            buffer.clear();
        }
    }

    //добавляем последнее слово в тексте, так как в конце может не быть пробела
    file_string.push(buffer);

    //цикл для вывода текста в обратном порядке
    while (!file_string.empty()) {

        //переносим в буферную строку последний элемент стека
        buffer = file_string.top();

        //вывод
        cout << buffer << " ";

        //убираем последний элемент из стека
        file_string.pop();
    }
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");
    string file;
    ifstream input("test.txt");

    cout << "Исходный текст:" << endl;

    //цикл нужен для того, чтобы показать содержимое файла
    if (input.is_open()) {
        while (getline(input, file)) {
            cout << file << endl;
        }
    }

    input.close();
    cout << endl << "Вывод текста в обратном порядке:" << endl;
    //вызов функции
    invert(file);
    cout << endl;
    return 0;
}
