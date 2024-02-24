#include "defs.h"
#include <iostream>

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Rasteriser.h"
#include "Matrix44.h"
#include "GenericMath.h"

int main(void){
	initscr();
	raw();
	noecho();
    
    Razterizer razterizer(WW, WH);

    float angle = 0;

    while (angle < 360) {
        Matrix44 transformation;
        transformation.scale(Vector3(4, 2, 1));
        transformation.rotate(Vector3(1, 1, 1), GenericMath::toRadians(angle));

        Vector4 v1(10, 10, 1, 1);
        Vector4 v2(20, 10, 1, 1);
        Vector4 v3(15, 20, 1, 1);

        v1 = transformation * v1;
        v2 = transformation * v2;
        v3 = transformation * v3;

        razterizer.clearFrame();
        razterizer.razterizeTriangle(Vector2(v1.x, v1.y), Vector2(v2.x, v2.y), Vector2(v3.x, v3.y));
        razterizer.presentFrame(0, 0);

        getch();
        angle += 10;
        clear();
    }

    endwin();

    return 0;
}