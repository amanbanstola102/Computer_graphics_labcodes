//bresenham's line drawing algorithm
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int x = x1, y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x, y, WHITE);
        if (x == x2 && y == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 < dx)  { err += dx; y += sy; }
    }
}

int main() {
    int gd = DETECT, gm;
    char path[] = "";
    initgraph(&gd, &gm, path);

    bresenham(50, 50, 250, 200);

    getch();
    closegraph();
    return 0;
}
