#include "../turtlec.h"

void splitLine(Turtle *, int, int);
void koch(Turtle *, int, int);
void copo(Turtle *, int, int);
void fractalTree( Turtle *, float, int);
int main(void){
  TurtleApp *app = turtleAppCreate(400, 300, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 150.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  //turtleForward(t, 300.0f);
//  splitLine(t, 300, 2);
  //koch(t, 100, 3);
  copo(t, 100, 1);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

void splitLine(Turtle *t, int length, int count) {
    if(count == 0){
        turtleForward(t, length);
        return;
    }
    splitLine(t, length / 2.0, count - 1);
    turtleLeft(t, 60.0);
    splitLine(t, length / 2.0, count - 1);
    turtleRight(t, 60.0);
}

void koch(Turtle *t, int length, int count){
    if(count == 0) {
        turtleForward(t,length);
        return;
    }
    koch(t, length / 3.0, count - 1);
    turtleLeft(t, 60.0);
    koch(t, length / 3.0, count - 1);
    turtleRight(t, 120.0);
    koch(t, length / 3.0, count - 1);
    turtleLeft(t, 60.0);
    koch(t, length / 3.0, count - 1);
}

void copo(Turtle *t, int length, int count){
    for(int i = 0; i < 3; i++){
        koch(t, length, count);
        turtleRight(t, 120.0);
    }
}

void fractalTree(Turtle *t, float length, int depth){
     
}
