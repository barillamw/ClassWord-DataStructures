/* Lecture 7
 * 19 September 2018
 *
 * Notes:
 * Class Inheritance, Polymorphism, and Virtual Functions
 *
 * C++ tries to make code easy to re-use code, but splitting code to objects
 *  makes it more difficult to share code.
 */
 /*class Square {
   int w; //width
   int l; //length
 Public:
  Sqaure(int);
  int are(){
    return w*l;
  }
};
//vs
class Rectangle{
  int w; //width
  int l; //length
Public:
 Sqaure(int);
 int are(){
   return w*l;
 }
};*/

/* we could make area a global funciton, but it then wouldn't have access to
 *  the private member funcitons within the objects.
 *
 * INHERITANCE: Make relationships between classes explicit and allows for
 *  code re-use. This allows us to define derrived class in terms of a base
 *  Rectangle is the base, Square is the derrived from Rectangle.
 * Derrived classes inherit a copy of all member variables and member functions.
 */

//Example of INHERITANCE
 #include <stdio.h>

 class Rectangle{
 private:
   int width;
   int length;
 public:
   //colon based initialtion list cleans up code and is common in cpp programs
   //not a function call. It acts as an initialization.
   Rectangle(int w,int l):width(w), length(l){}
   int area(){return width*length;}
   void print(){printf("Rectangle\n")}
 };

 class Square : public Rectangle{
 public:
   //the colon here calls the constructor of rectangle.
   Square(int s):Rectangle(s,s){}
   void print(){printf("Square\n")}
 };

/*
 Rectangle::Rectangle(int w, int l)
 {
   width = w;
   length = l;
 }
 */
 /*
 Square::Square(int side)
 :Rectangle(side,side)
 {
 }
 */

 /* A Few Important Details about INHERITANCE:
  * 1. Only public members of the base class can be modified by member functions
  *    within the derived class
  * 2. Private memers of the base remain private to the other objects, even to
  *    the derived class
  * 3. We can add new public and private members to derived classes, so we need
  *    to add constructors to initialize them.
  * 4. When constructing a derrived class, we MUST initalize the base class first
  *    so that private members can get initialized.
  * 5. If a function with the same name exists in both the base and the derived
  *    class, the function in the derived class overrides the function in the
  *    base class.
  */
 /* ---------protected keyword-----------
  * protected members are visible to derived classes but are treated like Private
  *   members outside the base or the derived class.
  *
  * Why is there the public keyword with the inheritance call?
  *   It is possible to have public, private and protected inheritance
  *   Public inheritance lets other code know that Square IS A Rectangle
  *
  * Limitations of Inheritance:
  * - when using the pointer to the base type, we can only use public members
  *   of the base class, even if we are pointing to a drived type.
  *
  * Polymorphic Classes: The desire to make each kind of Object work differnetly,
  *   even though they are all derived from Object. Having many forms.
  *   -to achieve this we use inheritance and virtural Functions
  *
  * Virtual Functions are called in the base function and each function within
  *   the derived functions with the same name will be ran instead.
  */


 int main()
 {
   Square s(5);
   Rectangle r(4.6);
   print("area of s = %d\n",s.area());
   print("area of r = %d\n", r.area());

   Rectangle& r2 = s; //s is a rectangle
   printf("the area of r2 is %d", r.area());

   return 0;
 }
