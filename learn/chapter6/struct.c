#include <stdio.h>
#include <math.h>

#define defprint(x) printf(#x ": %d\n", x)

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

main()
{
	/* why need declar this? */
	double sqrt(double);
	struct point pt = {3, 4};
	struct rect screen = {{2, 5}, {6, 10}};

	defprint(pt.x);
	/* notice this type cast */
	defprint((int)sqrt((double)pt.x * pt.x + (double)pt.y * pt.y));

	defprint(screen.pt1.x);
	defprint(screen.pt1.y);
	defprint(screen.pt2.x);
	defprint(screen.pt2.y);
}
