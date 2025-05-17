//midpoint ellipse drawing 
#include <graphics.h>
#include <conio.h>
#include <math.h>
void drawEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}
void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2, x = 0, y = ry;
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        drawEllipsePoints(xc, yc, x, y);
        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++; y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }

    d2 = (ry * ry) * ((x + 0.5) * (x + 0.5)) +
         (rx * rx) * ((y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    while (y >= 0) {
        drawEllipsePoints(xc, yc, x, y);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--; x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}
int main() {
    int gd = DETECT, gm;
    char path[] = "";
    initgraph(&gd, &gm, path);

    midpointEllipse(300, 200, 150, 100);

    getch();
    closegraph();
    return 0;
}
