#include <stdio.h>

struct Point {
    int x, y;
};

struct Point add_point(struct Point p1, struct Point p2) {
    struct Point result = {p1.x + p2.x, p1.y + p2.y};
    return result;
}

int main() {
    struct Point p1 = {1, 2};
    struct Point p2 = {3, 4};
    struct Point p3 = add_point(p1, p2);
    printf("(%d, %d)\n", p3.x, p3.y);
    return 0;
}