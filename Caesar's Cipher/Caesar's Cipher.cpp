#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;


class CipherCaser {
protected:
    int num;
    string alphabet;
    string alphabetUp;

    void setChiper() {
        ifstream text;
        ofstream ciper;
        char syb;
        text.open("text.txt");
        ciper.open("ciper.txt");
        if (!text.is_open()) {
            cout << "не удалось считать файл text.txt" << endl;
        }
        else {
            cout << "Открываем файл:  text.txt" << endl << "Текст из файла: "<< endl << endl;
            while (text.get(syb)) {
                cout << syb;
                int alphanum = chekAlpha(syb);
                int count = num + alphanum - 1;
                if (alphanum) {
                    while(count >= alphabet.size()) {
                        count = count - alphabet.size();
                    }
                    ciper << alphabet[count];
                }
                else {
                    ciper << syb;
                }   
            }
        }
        text.close();
        ciper.close();
        ifstream ciperRead;
        ciperRead.open("ciper.txt");
        if (!ciperRead.is_open()) {
            cout << "не удалось считать файл ciper.txt" << endl;
        }
        else {
            cout << "Открываем файл:  ciper.txt" << endl << "Зашифрованный текст из файла c шагом "<< num <<": " << endl << endl;
            while (ciperRead.get(syb)) {
                cout << syb;
            }
        }
        ciperRead.close();
        cout << "Текст записан в корне программы под названием <<ciper.txt>>" << endl;
    }
    void toUP(){ // Создаём копию алфавита в верхнем регистре
        alphabetUp = alphabet;
        for (int i = 0; i < this->alphabet.size(); i++) {
            alphabetUp[i] = toupper(alphabet[i]);
        }
    }
public:
    CipherCaser(int num, string alphabet) {
        this->alphabet = alphabet;
        this->num = num;
        toUP();
        setChiper();
    }
    int chekAlpha(char ch) { // проверяем симовл на наличие в заданном алфавите 
        for (int i = 0; i < this -> alphabet.size(); i++) {
            if (ch == alphabet[i] || ch == alphabetUp[i]) {
                return i + 1;
            }
        }
        return false;
    }
    void getAlphabet() { // Посмотреть 
        cout << alphabet;
    }
};


class CipherWidginero{
private:
    string codword, alphabet, alphabetUp;
    bool ChekCodword() {
        for (int i = 0; i < this->codword.size(); i++) {
            if (!(chekAlpha(codword[i]))) {
                return false;
            }
            else {
                return true;
            }
        }
    }

    void toUP() { // Создаём копию алфавита в верхнем регистре
        alphabetUp = alphabet;
        for (int i = 0; i < this->alphabet.size(); i++) {
            alphabetUp[i] = toupper(alphabet[i]);
        }
    }
    void setChiper() {    
        if (!ChekCodword()) {
            cout << "Кодовое слово не соответствует выбрану алфавиту!!!" << endl;
        }
        else {
            ifstream text;
            ofstream ciper;
            char syb;
            text.open("text.txt");
            ciper.open("ciper.txt");
            if (!text.is_open()) {
                cout << "не удалось считать файл text.txt" << endl;
            }
            else {
                cout << "Открываем файл:  text.txt" << endl << "Текст из файла: " << endl << endl;
                int num = 0;
                while (text.get(syb)) {
                    cout << syb;
                    int alphanum = chekAlpha(syb);
                    
                    if (alphanum) {
                        if (num > codword.size()-1) {
                            num = 0;
                        }
                        while (alphanum + num - 1 > alphabet.size()) {
                            alphanum -= alphabet.size();
                        }
                        ciper << alphabet[alphanum + num - 1];
                        num++;
                    }
                    else {
                        ciper << syb;
                    }
                }
            }
            text.close();
            ciper.close();
            ifstream ciperRead;
            ciperRead.open("ciper.txt");
            if (!ciperRead.is_open()) {
                cout << "не удалось считать файл ciper.txt" << endl;
            }
            else {
                cout << "Открываем файл:  ciper.txt" << endl << "Зашифрованный текст из файла со словом " << codword << ": " << endl << endl;
                while (ciperRead.get(syb)) {
                    cout << syb;
                }
            }
            ciperRead.close();
            cout << "Текст записан в корне программы под названием <<ciper.txt>>" << endl;
        }    
    }
public:
    
    CipherWidginero(string codword, string alphabet){
        this->alphabet = alphabet;
        this->codword = codword;

        toUP();
        setChiper();
    }

    int chekAlpha(char ch) { // проверяем симовл на наличие в заданном алфавите 
        for (int i = 0; i < this->alphabet.size(); i++) {
            if (ch == alphabet[i] || ch == alphabetUp[i]) {
                return i + 1;
            }
        }
        return false;
    }
    
    

    void getAlphabet() { // Посмотреть 
        cout << alphabet;
    }
};

int chekInt() { // Функция "пока не будет введено число"
    int step;
    cout << "Введите число: ";
    cin >> step;
    while (cin.fail()) { //Проверка на ввод числа
        cin.clear();
        cin.ignore();
        cout << "Введите число: ";
        cin >> step;
    }
    return step;
 }


int main(){    
    int num = 0;
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string alphabetRUS = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    do{
        system("cls");
        cout << "Выберите метод шифровки:" << endl
            << "0) Закрыть программу || EXIT" << endl
            << "1) Шифр Цезаря" << endl
            << "2) Шрифт Виженера" << endl; 

        num = chekInt();

        if(num == 1){
            system("cls");
            cout << "Задайте шаг на шифровку" << endl;
            int step = chekInt();
            CipherCaser A(step, alphabetRUS);
            system("pause");
        }
        if (num == 2) {
            system("cls");
            cout << "Напишите кодовое слово для шифрования: ";
            string codWord;           
            cin >> codWord;
            CipherWidginero B(codWord, alphabetRUS);          
            system("pause");
        }
    }while(num > 0);

    return 0;
}


