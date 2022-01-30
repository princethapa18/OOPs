/* 29 Jan 2022 
   Asked Capgemini interview today
   https://stackoverflow.com/questions/19808667/c-abstract-class-constructor-yes-or-no

   We can't instantiate (or create an object) of an Abstract Class . [But we can create a pointer]
   AbstractClass a; //error
   AbstractCalss *p; // no error

*/
#include <string>
#include <iostream>

class Vehicle
{
public:
    Vehicle();
    virtual void printVehicle() = 0;
    void nonVirtualFun() { std::cout << "This is non virtual function\n"; }
    void fun1();
private:
    int vehicleType{};
    std::string brandName;
};

/*
// this is okay
// Can define a constructor for an abstract class
// Why ? Abstract class ka object nhi bana sakte to constructor kis baat ka ????
Vehicle::Vehicle()
{

}
*/

Vehicle::Vehicle()
{
    vehicleType = 1;      // okay
    brandName = "HONDA";  // okay
    nonVirtualFun();   // okay

    // Can't call pure virtual function in the constructor
    //printVehicle(); // pure virtual ‘virtual void Vehicle::printVehicle()’ called from constructor [enabled by default]

    //In function `Vehicle::Vehicle()':
    //abstract_class.cpp:(.text+0x5b): undefined reference to `Vehicle::printVehicle()'
}

void Vehicle::fun1()
{
    printVehicle(); // this is okay
}

class SubVehicle : public Vehicle
{
    public:
        void printVehicle()
        {
            std::cout << "This is SubVehicle ";
        }
};


class NonAbstractClass
{
    public:
    NonAbstractClass( int x = 0);
    virtual void vfun1() { std::cout << "vfun1 -- NonAbstractClass\n"; }
    private:
        int someFun{};
};

//NonAbstractClass::NonAbstractClass(int x = 0) : someFun{x}  // error: after previous specification in ‘NonAbstractClass::NonAbstractClass(int)’ [-fpermissive]
//  do bari default value dene ki jaroorat nahi hai
NonAbstractClass::NonAbstractClass(int x) : someFun{x} 
{
    vfun1(); // No error
}

class SubClass : public NonAbstractClass
{
    public:
    SubClass();
    void vfun1() {std::cout << "vfun1 -- SubClass\n";}
};

SubClass::SubClass() : NonAbstractClass(0) 
{
    vfun1(); // No error
}

int main()
{
    SubClass sb1;
    sb1.vfun1();
    
    SubVehicle obj;
    obj.printVehicle();
    //Vehicle vobj; // error: cannot declare variable ‘vobj’ to be of abstract type ‘Vehicle’
    Vehicle *ptr_to_abstract_class = &obj; // ok no problem
    // dereferenced the ptr
    //SubVehicle obj1 = *ptr_to_abstract_class; // error: conversion from ‘Vehicle’ to non-scalar type ‘SubVehicle’ requested
    //Vehicle *pv = new Vehicle(); // error: cannot allocate an object of abstract type ‘Vehicle’
     
    int x = 5;
    int *p = &x;
    int y = *p;  // this is okay

    return 0;
}