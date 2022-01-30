/* 30 Jan 2022 Week 05
    Difference between struct and class in c++
    https://www.geeksforgeeks.org/structure-vs-class-in-cpp/

    There are two answers to this question

    Struct and class are pretty much the same, except that the members of a struct are public by default, 
    while the members of a class are private by default. So you’d pick whichever one made the coding task easy.
    You should only use a struct for a simple data record with no associated functions, and no constructor, 
    destructor, or assign ops. 
    Class is what you want for serious use, and you want to make its contents available through accessor functions so you could change the implementation later if you wanted.

These answers are quite different. The first one is pragmatic. The second one is object oriented. Either answer is good advice for an experienced programmer who knows what they’re doing. Answer 2 is probably better for a student. It teaches fewer bad habits.
*/

#include <iostream>

struct Point
{
    Point(float x = 0.f, float y = 0.f) : _x{x}, _y{y} {  std::cout << "Point()\n"; }
    ~Point() { }
    // float getX() const { return _x;}
    // float getY() const { return _y;}
    // virtual void printPt()
    // {
    //    std::cout << "x, y : " << getX() << ", " << getY() << std::endl; 
    // }
private:
    float _x, _y;
};

// inheritance no problem checked
// run time polymorphism no problem checked

/*
Only diff is everything in struct is public by default
*/

struct ThreeDPoint : private Point
{
    ThreeDPoint() { }
    ~ThreeDPoint() { }
    // ThreeDPoint(float x = 0.f, float y = 0.f, float z = 0.f) : _x{x}, _y{y}, _z{z} {}
    // ThreeDPoint(float x = 0.f, float y = 0.f, float z = 0.f) : Point(x, y) , _z{z} { std::cout << "ThreeDPoint()\n"; }
    // float getZ() const { return _z;}
    // void printPt()
    // {
    //     std::cout << "x, y, z : " << getX() << ", " << getY() << ", " << getZ() << std::endl;
    // }
private:
    //float _x, _y;
    float _z;
};


struct Test
{
private:
    // wild pointer 
    //int *arr; // if not initialized it will give segmentation fault during freeing the memory because no memory could be allocated at the first place
    // it will hold garbage value
    int *arr{nullptr};
public:
    Test( ) 
    {
        if(!arr)
        {
            std::cout << "ctor\n";
            arr = new int[10];
        }
    }
    ~Test()
    {
        std::cout << "dtor\n";
        if(arr)
            delete [] arr;
    }
};
/*
[thapa@gns101 OOPs]$ g++ -std=c++11 structVsClass.cpp -o structVsClass
[thapa@gns101 OOPs]$ valgrind --tool=memcheck ./structVsClass
==13545== Memcheck, a memory error detector
==13545== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==13545== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==13545== Command: ./structVsClass
==13545== 
Point()
Point()
==13545== Conditional jump or move depends on uninitialised value(s)
==13545==    at 0x400A00: Test::Test() (in /applgns/my_new_data/OOPs/structVsClass)
==13545==    by 0x4008B9: main (in /applgns/my_new_data/OOPs/structVsClass)
==13545== 
dtor
==13545== Conditional jump or move depends on uninitialised value(s)
==13545==    at 0x400A4F: Test::~Test() (in /applgns/my_new_data/OOPs/structVsClass)
==13545==    by 0x4008CA: main (in /applgns/my_new_data/OOPs/structVsClass)
==13545== 
==13545== Conditional jump or move depends on uninitialised value(s)
==13545==    at 0x400A5B: Test::~Test() (in /applgns/my_new_data/OOPs/structVsClass)
==13545==    by 0x4008CA: main (in /applgns/my_new_data/OOPs/structVsClass)
==13545== 
==13545== Conditional jump or move depends on uninitialised value(s)
==13545==    at 0x4C2BA72: operator delete[](void*) (vg_replace_malloc.c:651)
==13545==    by 0x400A6B: Test::~Test() (in /applgns/my_new_data/OOPs/structVsClass)
==13545==    by 0x4008CA: main (in /applgns/my_new_data/OOPs/structVsClass)
==13545== 
==13545== Invalid free() / delete / delete[] / realloc()
==13545==    at 0x4C2BABF: operator delete[](void*) (vg_replace_malloc.c:651)
==13545==    by 0x400A6B: Test::~Test() (in /applgns/my_new_data/OOPs/structVsClass)
==13545==    by 0x4008CA: main (in /applgns/my_new_data/OOPs/structVsClass)
==13545==  Address 0x2 is not stack'd, malloc'd or (recently) free'd
==13545== 
==13545== 
==13545== HEAP SUMMARY:
==13545==     in use at exit: 0 bytes in 0 blocks
==13545==   total heap usage: 0 allocs, 1 frees, 0 bytes allocated
==13545== 
==13545== All heap blocks were freed -- no leaks are possible
==13545== 
==13545== For counts of detected and suppressed errors, rerun with: -v
==13545== Use --track-origins=yes to see where uninitialised values come from
==13545== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 0 from 0)

*/

int main()
{
    Point pt1{0.2, 0.3};
    ThreeDPoint pt3;
    //ThreeDPoint pt_3d{0.2f , 0.3f , 0.6f};
    //pt_3d.printPt();

    // Point *pt = new ThreeDPoint(0.1f, 0.2f, 0.3f);
    // pt->printPt();

    Test t;

    return 0;
}