#include "Header.h"

void randomstar(int* ptr, vector<int> x, vector<int> y);
void lon(vector<int>* x, vector<int>* y);

void printmap(int map[MAX_SIZE][MAX_SIZE], vector<int> x);

void setcursor(int map[MAX_SIZE][MAX_SIZE], vector<int>* x, vector<int>* y, bool Xp, bool Xm, bool Yp, bool Ym);

void movecursor(int* X, int* Y, bool Xm, bool Xp, bool Ym, bool Yp);

bool storevector(int X, int Y, vector<int>* x, vector<int>* y);

void lon(vector<int>* x, vector<int>* y);

void randomstar(int* ptr, vector<int> x, vector<int> y);

void initarry(int map[MAX_SIZE][MAX_SIZE]);

void mainpage();

int gameover(vector<int> x);

int clear(vector<int> x);

void endgame();

void initcursor();