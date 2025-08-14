#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x
      && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

int main()
{
  /*------ MAKEPOINT DEMO ------*/
  struct rect screen;                 /* declare a rect structure */
  struct point middle;                /* declare a point struct to be our middle */
  struct point makepoint(int, int);   /* make a random point */

  screen.pt1 = makepoint(0, 0); /* base point aka botton left corner */
  screen.pt2 = makepoint(4, 4); /* end point aka top right corner  */

  printf("screen.pt1.x = %d, screen.pt1.y = %d\n", screen.pt1.x, screen.pt1.y);
  printf("screen.pt2.x = %d, screen.pt2.y = %d\n", screen.pt2.x, screen.pt2.y);
  middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                     (screen.pt1.y + screen.pt2.y)/2);

  printf("middle is located at (%d, %d)\n\n", middle.x, middle.y);

  /*------ ADDPOINT DEMO ------*/
  struct point pt1 = {1, 1};  // declare the point struct
  struct point pt2 = {2, 2};  // ^
  struct point np;            // create point struct to hold returned addition

  printf("pt1.x: %d, pt1.y: %d\n", pt1.x, pt1.y);
  printf("pt2.x: %d, pt2.y: %d\n", pt2.x, pt2.y);
  np = addpoint(pt1, pt2);
  printf("(after calling addpoint) np.x: %d, np.y: %d\n\n", np.x, np.y);

  /*------ PTINRECT DEMO ------*/
  printf("Is (3, 3) within our screen?: %d\n", ptinrect((struct point) {3, 3}, screen));
  printf("Is (5, 5) within our screen?: %d\n\n", ptinrect((struct point) {5, 5}, screen));

  /*------ CANONRECT DEMO ------*/
  struct rect newRect;

  canonrect(newRect);

  printf("newRect.pt1.x = %d, newRect.pt1.y = %d\n", newRect.pt1.x, newRect.pt1.y);
  printf("newRect.pt2.x = %d, newRect.pt2.y = %d\n", newRect.pt2.x, newRect.pt2.y);
}








