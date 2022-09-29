//������ 5, ������� 13, ������������� ��������
//������� ��������� ����, ��������� �������� ����� ����, � ������� ������ ����
//���������� �������� ����� � ��������������� �������� ����.
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stack>

using namespace std;

//������� �������, ����� ������ ������� ���� �� ��������
void invert(string s) {

    //������� ������ ���� �� ��������
    stack<string> file_string;

    //������� �������� ������, ����� ������� ��� ��������� ����������
    string buffer;

    //���� ��� ��������� ������ � ����� �� ����� � ���������� ��������� ���� � ����
    for (int i = 0; i < s.length(); i++) {

        //���� �� ������ ������ � ������, �� ����� ���������� ����������� � �������� ������
        if (s[i] != ' ') {
            buffer += s[i];
        }

        //���� ������ ������, �� ��������� ���������� ����� � ���� � ������� ����� ��� ��������� ����
        else {
            file_string.push(buffer);
            buffer.clear();
        }
    }

    //��������� ��������� ����� � ������, ��� ��� � ����� ����� �� ���� �������
    file_string.push(buffer);

    //���� ��� ������ ������ � �������� �������
    while (!file_string.empty()) {

        //��������� � �������� ������ ��������� ������� �����
        buffer = file_string.top();

        //�����
        cout << buffer << " ";

        //������� ��������� ������� �� �����
        file_string.pop();
    }
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");
    string file;
    ifstream input("test.txt");

    cout << "�������� �����:" << endl;

    //���� ����� ��� ����, ����� �������� ���������� �����
    if (input.is_open()) {
        while (getline(input, file)) {
            cout << file << endl;
        }
    }

    input.close();
    cout << endl << "����� ������ � �������� �������:" << endl;
    //����� �������
    invert(file);
    cout << endl;
    return 0;
}
