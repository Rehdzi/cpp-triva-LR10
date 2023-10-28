#include <ncurses.h>
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <iostream>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
// ...

#define YEL "\x1b[33m"

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

//map<int, char> difficulty {
//        { 1, 'C' },
//        { 2, 'B' },
//        { 3, 'A' }
//};

struct Question {
    string text;
    string ans[4];
    unsigned char rightAns;
    unsigned int diffNum;

    void drawQuestion(){
        cout << "Игрок: " << p.name << "  Осталось жизней: " << p.HP << endl;
        cout << "Счёт: " << p.score << endl;
        cout << "Сложность: " << diffNum << endl << endl;
        cout << text << endl << endl;
        cout << "[1] " << ans[0] << endl;
        cout << "[2] " << ans[1] << endl;
        cout << "[3] " << ans[2] << endl;
        cout << "[4] " << ans[3] << endl;
    }

    bool checkPAns(string answer) {
        if (answer[0] == rightAns){
            cout << "Правильно! вы получаете " << diffNum*10 << " очков\n";
            p.score = p.score + diffNum*10;
            return true;
        } else {
            cout << "Неправильно! вы теряете одну жизнь!\n\n";
            p.HP--;
            return false;
        }
    }

};

Question qu {"fffff",
             "123", "2345", "2346", "476",
             '3', 2
};



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





void startGame(){
    p.HP = 3;
    p.score = 0;
    cout << "Игра началась.\n";
}

int main (){

    unsigned int nQuestions;

    p.name = "";
    p.HP = 0;
    p.score = 0;
    p.gameLength = 10;


    vector<Question> ques = {
            {"fffff",
             "123", "2345", "2346", "476",
             '3', 1
            },
            {"fffff",
             "123", "2345", "2346", "476",
             '0', 1
            },
            {"fffff",
             "123", "2345", "2346", "476",
             '2', 1
            },
            {"fffff",
               "123", "2345", "2346", "476",
               '1', 1
            }
    };
    nQuestions = ques.size();

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


                while (true){

                    if(p.HP == 0){
                        cout << "Вы проиграли!\n\n";
                        return false;
                    }

                    qu.drawQuestion();
                    string pAns;
                    drawArrow(pAns);

                    qu.checkPAns(pAns);

                }



                break;
            case '2':
                cout << "Rules";
                break;
            case '3':
                drawSettings();
                break;
            case '4':
                return 0;
        }
    }




}