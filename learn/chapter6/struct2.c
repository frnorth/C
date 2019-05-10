#include <stdio.h>
#include <math.h>

#define defprint(type, x) printf(#x ": %" #type"\n", x)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define XMAX 200
#define YMAX 100

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
	struct point middle;
	struct point pointadd;
	struct rect screen;
	struct point makepoint(int, int);
	struct point addpoint(struct point, struct point);
	struct rect canonrect(struct rect);
	void printrect(struct rect r);

	screen.pt1 = makepoint(XMAX, 0);
	screen.pt2 = makepoint(0, YMAX);
	printrect(screen);
	screen = canonrect(screen);
	printrect(screen);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);
	pointadd = addpoint(screen.pt1, screen.pt2);

	/* notice this type cast */
	defprint(g, sqrt((double)middle.x * middle.x + (double)middle.y * middle.y));

	defprint(d, middle.x);
	defprint(d, middle.y);
	defprint(d, pointadd.x);
	defprint(d, pointadd.y);

	defprint(d, ptinrect(middle, screen));
	defprint(d, ptinrect(pointadd, screen));

}

struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect screen)
{
	return p.x >= screen.pt1.x && p.x < screen.pt2.x && p.y >= screen.pt1.y && p.y < screen.pt2.y;
}

struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
};

void printrect(struct rect r)
{
	defprint(d, r.pt1.x);
	defprint(d, r.pt1.y);
	defprint(d, r.pt2.x);
	defprint(d, r.pt2.y);
}
