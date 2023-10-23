#include <ncurses.h>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <iostream>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
// ...

using namespace std;




struct Player {
    string name;
    unsigned int HP;
    unsigned int score;
    unsigned int gameLength;

    void enterName(){
        cout << "Введите имя: "; cin >> name;
    }
};

Player p;

struct Question {
    string text;
    string ans[4];
    unsigned char rightAns;
    unsigned char diffNum;


};

Question qu;

void drawQuestion(){
    cout << "Игрок: " << p.name << "  Осталось жизней: " << p.HP << endl;
    cout << "Сложность: " << qu.diffNum << endl << endl;
    cout << qu.text << endl << endl;
    cout << "[1] " << qu.ans[0] << endl;
    cout << "[2] " << qu.ans[1] << endl;
    cout << "[3] " << qu.ans[2] << endl;
    cout << "[4] " << qu.ans[3] << endl;
}

void drawMenu(){
    cout << "[*] Программистическая викторина!!!\n\n"
            "[1] Начать игру!\n"
            "[2] Правила\n"
            "[3] Настройки\n"
            "[4] Выход\n";
}

void drawSettings(){
    cout << "[*] Настройки\n\n"
            "[-] Текущие настройки:\n\n"
            "[=]    Имя игрока: " << p.name << endl <<
            "[=]    Длина игры: " << p.gameLength << endl <<
            "[=]    Тема: " << endl << endl <<
            "[1] Изменить имя\n"
            "[2] Изменить длину игры\n"
            "[3] Изменить тему\n"
            "[4] Назад";

}

void drawArrow(string &ch){
    cout << "-> "; cin >> ch;
}

map<int, char> difficulty {
        { 1, 'C' }, { 2, 'B' }, { 3, 'A' }
};



void startGame(){
    p.HP = 3;
    p.score = 0;
}

int main (){

    unsigned int nQuestions;

    p.name = "";
    p.HP = 0;
    p.score = 0;
    p.gameLength = 10;


    vector<Question> questions = {
            {"fffff",
             "123", "2345", "2346", "476",
             3, 1
            },
            {"fffff",
             "123", "2345", "2346", "476",
             0, 1
            },
            {"fffff",
             "123", "2345", "2346", "476",
             2, 1
            },
            {"fffff",
               "123", "2345", "2346", "476",
               1, 1
            }
    };
    nQuestions = questions.size();

    srand(time(nullptr));
    unsigned int random = rand() % nQuestions;

    while (true) {
        drawMenu();
        string choice;
        drawArrow(choice);

        switch (choice[0]) {
            case '1':
                if (p.name == "") {
                    p.enterName();
                    startGame();

                }
                cout << "Игра началась.\n";



                break;
            case '2':
                cout << "Rules";
                break;
            case '3':

            case '4':
                return 0;
        }
    }




}