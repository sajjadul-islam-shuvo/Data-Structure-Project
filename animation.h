#include <bits/stdc++.h>
#include <windows.h>

#ifndef animation
#define animation

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void loadingBar()
{
    //loading border top-bottom
    for (int x = 25; x < 65; x++)
    {
        gotoxy(x, 17);
        printf("%c", 205);
        gotoxy(x, 19);
        printf("%c", 205);
    }
    //loading border left-right
    gotoxy(25, 18);
    printf("%c", 186);
    gotoxy(65, 18);
    printf("%c", 186);

    // top left corner
    gotoxy(25, 17);
    printf("%c", 201);
    // top right corner
    gotoxy(65, 17);
    printf("%c", 187);
    // bottom left corner
    gotoxy(25, 19);
    printf("%c", 200);
    // bottom right corner
    gotoxy(65, 19);
    printf("%c", 188);

    for (int i = 26; i < 65; i++)                   //fill the box with light-shade
    {
        gotoxy(i, 18);
        printf("%c", 176);
    }

    for (int percent = 0; percent <= 100; percent++)
    {
        int loadStart = 25 + 1;                     //start filling form here
        int length = (65 - 25) - 1;                 //length of empty area in the loading border

        int barLength = ((length) * percent) / 100; // Calculate the number of characters to fill based on the percentage
        for (int i = 0; i < barLength; i++)         //fill the box with box
        {
            gotoxy(loadStart + i, 18);
            printf("%c", 219);
        }
        gotoxy(35, 20);
        cout << "Loading . . . " << percent << " %";
        Sleep(20);
    }
}

#endif