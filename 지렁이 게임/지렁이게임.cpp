#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 10
using namespace std;

void randomstar(int* ptr, vector<int> x, vector<int> y);
void lon(vector<int>* x, vector<int>* y);
void printmap(int map[MAX_SIZE][MAX_SIZE], vector<int> x)
{
    int score = x.size();
    system("cls");
    cout << endl << endl << endl << endl << endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << "             ";
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (map[i][j] == 0)
                cout << ". ";
            else if (map[i][j] == 1)
                cout << "* ";
            else if (map[i][j] == 2)
                cout << "@ ";

            else if (map[i][j] == 3)
                cout << "> ";
            else if (map[i][j] == 4)
                cout << "< ";
            else if (map[i][j] == 5)
                cout << "V ";
            else if (map[i][j] == 6)
                cout << "A ";

        }
        cout << endl;
    }
    cout << endl << "                       SCORE : " << score;
}

void setcursor(int map[MAX_SIZE][MAX_SIZE], vector<int>* x, vector<int>* y, bool Xp, bool Xm, bool Yp, bool Ym)
{
    vector<int> a = *x;
    vector<int> b = *y;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (map[i][j] == 1)
            {
                continue;
            }
            else
                map[i][j] = 0;
        }
    }

    randomstar(map[0], a, b);

    if (map[(*y).back() - 1][(*x).back() - 1] == 1)
        lon(x, y);

    (*x).erase((*x).begin());
    (*y).erase((*y).begin());
    int size = (*x).size();
    for (int k = 0; k < size; k++)
    {
        map[(*y)[k] - 1][(*x)[k] - 1] = 2;
    }

    if (Xp)
        map[(*y).back() - 1][(*x).back() - 1] = 3;
    else if (Xm)
        map[(*y).back() - 1][(*x).back() - 1] = 4;
    else if (Yp)
        map[(*y).back() - 1][(*x).back() - 1] = 5;
    else if (Ym)
        map[(*y).back() - 1][(*x).back() - 1] = 6;

}

void movecursor(int* X, int* Y, bool Xm, bool Xp, bool Ym, bool Yp)
{
    if (Xm)
        *X = *X - 1;
    else if (Xp)
        *X = *X + 1;
    else if (Ym)
        *Y = *Y - 1;
    else if (Yp)
        *Y = *Y + 1;
}

bool storevector(int X, int Y, vector<int>* x, vector<int>* y)
{
    int size = (*x).size();
    bool check = true;
    for (int i = 0; i < size; i++)
    {
        if ((*x)[i] == X && (*y)[i] == Y)
        {
            check = false;
            break;
        }
    }

    if (X > MAX_SIZE || X < 1 || Y>MAX_SIZE || Y < 1)
        return true;

    if (check)
    {
        (*x).push_back(X);
        (*y).push_back(Y);
        return false;
    }
    else
    {
        return true;
    }
}

void lon(vector<int>* x, vector<int>* y)
{
    (*x).insert((*x).begin(), -1);
    (*y).insert((*y).begin(), -1);
}

void randomstar(int* ptr, vector<int> x, vector<int> y)
{
    srand((unsigned int)time(NULL));
    int num = NULL;
    bool check = true;
    bool check2 = true;
    for (int i = 0; i < (MAX_SIZE * MAX_SIZE); i++)
    {
        if (*(ptr + i) == 1 || *(ptr + i) == 2)
        {
            check2 = false;
            break;
        }
    }

    while (check2)
    {
        check = true;
        num = rand() % (MAX_SIZE * MAX_SIZE);
        int size = x.size();
        for (int i = 0; i < size; i++)
        {
            int checknum = (x[i] - 1) * 5 + (y[i] - 1);
            if (checknum == num)
            {
                check = false;
                break;
            }

        }
        if (check)
            break;
        continue;
    }
    if (num != NULL)
        *(ptr + num) = 1;
}
void initarry(int map[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            map[i][j] = 0;
        }
    }
}

void mainpage()
{
    int key;


    while (1)
    {

        Sleep(250);
        system("cls");
        cout << endl << endl << endl << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15);
        cout << "              Áö··ÀÌ °ÔÀÓ" << endl << endl << endl;
        cout << "              press X to start" << endl;

        Sleep(250);
        if (_kbhit())
        {
            key = _getch();
            if (key == 120)
                break;
        }
    }
}

int gameover(vector<int> x)
{
    int key;
    int score = x.size();
    while (1)
    {
        system("cls");
        cout << endl << endl << endl << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15);

        cout << "              Game Over!!!" << endl << endl << endl;
        cout << "              SCORE : " << score << endl << endl << endl;
        cout << "              press X to go mainpage" << endl << endl;
        cout << "              press SPACE BAR to exit" << endl;
        Sleep(250);
        if (_kbhit())
        {
            key = _getch();
            if (key == 120)
                break;
            else if (key == 32)
            {
                return 0;
            }
        }
    }
}
int clear(vector<int> x)
{
    int key;
    int score = x.size();
    while (1)
    {
        system("cls");
        cout << endl << endl << endl << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15);
        cout << "              Clear!!!" << endl << endl << endl;
        cout << "              SCORE : " << score << endl << endl << endl;
        cout << "              press X to go mainpage" << endl << endl;
        cout << "              press SPACE BAR to exit" << endl;

        Sleep(250);
        if (_kbhit())
        {
            key = _getch();
            if (key == 120)
                break;
            else if (key == 32)
            {
                return 0;
            }
        }
    }
}

void endgame()
{
    system("cls");
    cout << endl << endl << endl << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "              GAME END";
    cout << endl << endl << endl << endl << endl;
}
void initcursor()
{
    CONSOLE_CURSOR_INFO c = { 0 };
    c.dwSize = 1;
    c.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);

}
int main()
{
    initcursor();

    while (1)
    {
        int key;
        int map[MAX_SIZE][MAX_SIZE];
        vector<int> x;
        vector<int> y;
        int cnt = 1;
        int X = MAX_SIZE / 2 + 1;
        int Y = MAX_SIZE / 2 + 1;
        bool Xm = false;
        bool Xp = false;
        bool Ym = true;
        bool Yp = false;
        mainpage();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        initarry(map);
        storevector(X, Y, &x, &y);
        map[X - 1][Y - 1] = 2;
        printmap(map, x);

        while (1)
        {
            Sleep(250);

            if (_kbhit())
            {
                key = _getch();
                if (key == 224)
                {
                    key = _getch();
                    switch (key)
                    {
                    case 72:
                    {
                        //printf("up\n");
                        Xm = false;
                        Xp = false;
                        Ym = true;
                        Yp = false;
                        break;
                    }
                    case 75:
                    {
                        //printf("left\n");
                        Xm = true;
                        Xp = false;
                        Ym = false;
                        Yp = false;
                        break;
                    }
                    case 77:
                    {
                        //printf("right\n");
                        Xm = false;
                        Xp = true;
                        Ym = false;
                        Yp = false;
                        break;
                    }
                    case 80:
                        //printf("down\n");
                        Xm = false;
                        Xp = false;
                        Ym = false;
                        Yp = true;
                        break;
                    }
                }
            }

            movecursor(&X, &Y, Xm, Xp, Ym, Yp);
            if (storevector(X, Y, &x, &y))
            {
                if (!gameover(x))
                {
                    endgame();
                    return 0;
                }
                break;
            }
            if (x.size() == MAX_SIZE * MAX_SIZE / 2 - 1)
            {
                if (!clear(x))
                {
                    endgame();
                    return 0;
                }
                break;
            }
            setcursor(map, &x, &y, Xp, Xm, Yp, Ym);
            printmap(map, x);
        }
    }
}



//#include <stdio.h>
//
//int main()
//{
//	int map[5][5] = { {0,0,0,0,0}, {0,1,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
//
//	int* p = map[0];
//	printf("%d", *(p+6));
//}