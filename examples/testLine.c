#include "../turtlec.h"
#include <math.h>
void fractalTree(Turtle *, float, int);
void fractalTree2(Turtle *, float, int);
void levy(Turtle *, float, int);
void retofinal13(Turtle *, float, int, int);

int main(void){
  TurtleApp *app = turtleAppCreate(500, 500, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 100.0f, 250.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  //fractalTree(t, 100, 7);
  //fractalTree2(t, 100, 7);
  //levy(t, 250, 10);
  //retofinal13(t, 100, 6, 6);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}


void fractalTree(Turtle *t, float length, int depth){
    if(depth == 0 || length < 5)
        return;

    turtleForward(t, length);
    turtleLeft(t, 35);
    fractalTree(t, length * 0.6, depth - 1);
    
    turtleRight(t, 70);
    fractalTree(t, length * 0.6, depth - 1);
 
    turtleLeft(t, 35);
    turtleBackward(t, length);
}

void fractalTree2(Turtle *t, float length, int depth){
    //cuando ejecutemos esta funcion es correcto comentar la linea q define el
    //color en el main ya que aqui lo estamos haciendo con un if
     if(depth == 0 || length < 5)
        return;

     if(depth > 5)
        turtleSetColor (t, 120, 70, 20);
     else
        turtleSetColor (t, 0 , 200 , 0);


    turtleForward(t, length);
    turtleLeft(t, 20);
    fractalTree2(t, length / sqrt(2), depth - 1);
    
    turtleRight(t, 40);
    fractalTree2(t, length / sqrt(2), depth - 1);
 
    turtleLeft(t, 20);

    turtlePenUp(t);
    turtleBackward(t, length);
    turtlePenDown(t);
}

void levy(Turtle *t, float length, int depth){
    if(depth == 0){
        turtleForward(t, length);
        return;
    }
    
    if(depth > 0){
        turtleLeft(t, 45);
    }

    levy(t, length * 0.6, depth - 1);

    turtleRight(t, 90);
    
    levy(t, length * 0.6, depth - 1);
    
    turtleLeft(t,45);
}
void retofinal13(Turtle *t, float length, int depth, int max_depth){
    //aqui tmb debemos comentar el color del main para poder apreciar
    //cada nivel de recursion con un color diferente
    if(depth == 0 || length < 5)
        return;

    float factor = (float)(max_depth - depth) / max_depth;
    int r = 139 + factor * (34 - 139);
    int g = 69 + factor * (139 - 69);
    int b = 19 + factor * (34 - 19);
    turtleSetColor(t, r, g, b);

    turtleForward(t, length);
    turtleLeft(t, 35);
    retofinal13(t, length * 0.8, depth - 1, max_depth);
    
    turtleRight(t, 35);
    retofinal13(t, length * 0.8, depth - 1, max_depth);

    turtleRight(t, 35);
    retofinal13(t, length * 0.8, depth - 1, max_depth);

    turtleLeft(t,35);

    turtleSetColor(t,r,g,b);
    turtleBackward(t, length);
}
