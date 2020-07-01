#include "Header.h"
#include "myfunction.h"


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