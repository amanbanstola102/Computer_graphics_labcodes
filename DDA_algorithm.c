//DDA algorithm in C
#include <graphics.h>
#include <conio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}

int main() {
    int gd = DETECT, gm;
    char path[] = "";
    initgraph(&gd, &gm, path);

    DDA(50, 50, 250, 200);

    getch();
    closegraph();
    return 0;
}
