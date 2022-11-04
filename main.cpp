/*
Project 4: Part 5 / 9
 video: Chapter 5 Part 2
 Operator Overloading.

Do not delete your previous main. 

 Create a branch named Part5

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) replace the add/subtract/multiply/etc functions in your UDTs with overloaded math operators 
        e.g. add() would become operator+=() because it modifies the internal heap-allocated object.
        The easiest way to do this is to just rename your member functions.  
        Do not: delete your member functions and add new ones.  Simply rename them
        You do not need to change the Point class's multiply() functions.
 
 2) Your overloaded operators should only take primitives, passed by value.
    since they are passed by value, they do not need to be const.
 
 3) don't delete your conversion functions.
 
 4) your main() function should be the same as Project 4 part 4, 
    excluding the changes made due to 1)
     
 5) delete the example below after it makes sense how your code will change due to 1).
 */

 /*
 6) compile/link/run to make sure you don't have any errors or warnings.

 7) your program should produce the exact same output as Project 4 part 4, listed below.
    use https://www.diffchecker.com/diff to make sure it is the same.
 */

/*
your program should generate the following output EXACTLY.
This includes any warnings included below.  

The output should have zero warnings.


FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with DoubleType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

good to go!

Use a service like https://www.diffchecker.com/diff to compare your output. 
*/


#include <iostream>
#include <cmath>

struct IntType;
struct DoubleType;
struct FloatType; 


struct Point
{
    Point(float x, float y);
    explicit Point(FloatType& x, FloatType& y);
    explicit Point(DoubleType& x, DoubleType& y);
    explicit Point(IntType& x, IntType& y);
    
    
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(FloatType& m);
    Point& multiply(DoubleType& m);
    Point& multiply(IntType& m);
    void toString();

private:
    float x{0}, y{0};
};



struct A {};
struct HeapA
{ 
    HeapA() : a(new A) {}
    ~HeapA()
    {
        delete a;
    }
    A* a = nullptr;
};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


struct FloatType
{
    explicit FloatType(float f) : value(new float(f)) {}
    ~FloatType()
    {
        delete value;
    } 

    FloatType& operator+=(float lhs);
    FloatType& operator-=(float lhs);
    FloatType& operator*=(float lhs);
    FloatType& operator/=(float lhs);

    FloatType& pow(FloatType&);
    FloatType& pow(DoubleType&);
    FloatType& pow(IntType&);
    FloatType& pow(float);

    operator float() const
    {
        return *value;
    }

private:
    float* value;
    FloatType& powInternal(const float);
};

struct DoubleType
{
    explicit DoubleType(double d) : value(new double(d)) {}
    ~DoubleType()
    {
        delete value;
    } 

    DoubleType& operator+=(double lhs);
    DoubleType& operator-=(double lhs);
    DoubleType& operator*=(double lhs);
    DoubleType& operator/=(double lhs);


    DoubleType& pow(FloatType&);
    DoubleType& pow(DoubleType&);
    DoubleType& pow(IntType&);
    DoubleType& pow(double);

    operator double() const
    {
        return *value;
    }

private:
    double* value;
    DoubleType& powInternal(const double);
};

struct IntType
{
    explicit IntType(int i) : value(new int(i)) {}
    ~IntType()
    {
        delete value;
    } 

    IntType& operator+=(int lhs);
    IntType& operator-=(int lhs);
    IntType& operator*=(int lhs);
    IntType& operator/=(int lhs);

    IntType& pow(FloatType&);
    IntType& pow(DoubleType&);
    IntType& pow(IntType&);
    IntType& pow(int);

    operator int() const
    {
        return *value;
    }

private:
    int* value;
    IntType& powInternal(const int);
};

// Point Implimentations 

Point::Point(float x_, float y_) : x(x_), y(y_) {}
Point::Point(FloatType& x_, FloatType& y_) : Point(static_cast<float>(x_), static_cast<float>(y_)) {}
Point::Point(DoubleType& x_, DoubleType& y_) : Point(static_cast<float>(x_), static_cast<float>(y_)) {}
Point::Point(IntType& x_, IntType& y_) : Point(static_cast<float>(x_), static_cast<float>(y_)) {}


Point& Point::multiply(FloatType& value)
{
    return multiply(static_cast<float>(value));
}

Point& Point::multiply(DoubleType& value)
{
    return multiply(static_cast<float>(value));
}

Point& Point::multiply(IntType& value)
{
    return multiply(static_cast<float>(value));
}

void Point::toString()
{
    std::cout << "Point { x: " << x << ", y: " << y << " }" << std::endl;  
}

// FloatType Implimentations 

FloatType& FloatType::operator+=(float lhs) 
{
    *value += lhs;
    return *this;
}

FloatType& FloatType::operator-=(float lhs)
{       
    *value -= lhs;
    return *this;  
}

FloatType& FloatType::operator*=(float lhs)
{
    *value *= lhs;
    return *this;
}

FloatType& FloatType::operator/=(float lhs)
{
    if( lhs == 0.f )  
    { 
        std::cout << "warning: floating point division by zero!\n";
    }
    *value /= lhs;
    return *this;
}

FloatType& FloatType::powInternal(float exp)
{
    *value = std::pow( *value, exp ); 
    return *this;
}

FloatType& FloatType::pow(FloatType& exp)
{
    return powInternal(exp);
}

FloatType& FloatType::pow(DoubleType& exp)
{
    return powInternal(static_cast<float>(exp));
}

FloatType& FloatType::pow(IntType& exp)
{
    return powInternal(static_cast<float>(exp));
}

FloatType& FloatType::pow(float exp)
{
    return powInternal(exp);
}

// DoubleType Implimentations 

DoubleType& DoubleType::operator+=(double lhs) 
{
    *value += lhs;
    return *this; 
}

DoubleType& DoubleType::operator-=(double lhs)
{
    *value -= lhs;
    return *this;    
}

DoubleType& DoubleType::operator*=(double lhs)
{
    *value *= lhs;
    return *this; 
}

DoubleType& DoubleType::operator/=(double lhs)
{
    if( lhs == 0.0)  
    { 
        std::cout << "warning: floating point division by zero!\n";
    }
    *value /= lhs;
    return *this; 
}

DoubleType& DoubleType::powInternal(double exp)
{
    *value = std::pow( *value, exp ); 
    return *this;
}

DoubleType& DoubleType::pow(DoubleType& exp)
{
    return powInternal(exp);
}

DoubleType& DoubleType::pow(FloatType& exp)
{
    return powInternal(static_cast<double>(exp));
}

DoubleType& DoubleType::pow(IntType& exp)
{
    return powInternal(static_cast<double>(exp));
}

DoubleType& DoubleType::pow(double exp)
{
    return powInternal(exp);
}

// IntType Implimentations 

IntType& IntType::operator+=(int lhs) 
{
    *value += lhs;
    return *this; 
}

IntType& IntType::operator-=(int lhs)
{
    *value -= lhs;
    return *this;  
}

IntType& IntType::operator*=(int lhs)
{
    *value *= lhs;
    return *this;
}

IntType& IntType::operator/=(int lhs)
{
    if( lhs == 0)  
    { 
        std::cout << "error: integer division by zero is an error and will crash the program!\n";
    }
    else
    {
        *value /= lhs;
    }    
    return *this;
}

IntType& IntType::powInternal(int exp)
{
    *value = static_cast<int>(std::pow( *value, exp )); 
    return *this;
}

IntType& IntType::pow(IntType& exp)
{
    return powInternal(exp);
}

IntType& IntType::pow(DoubleType& exp)
{
    return powInternal(static_cast<int>(exp));
}

IntType& IntType::pow(FloatType& exp)
{
    return powInternal(static_cast<int>(exp));
}

IntType& IntType::pow(int exp)
{
    return powInternal(exp);
}


void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    ft *= ft;
    ft *= ft;
    ft /= static_cast<float>(it);
    std::cout << "The result of FloatType^4 divided by IntType is: " << ft << std::endl;

    dt *= 3.0;
    dt += it;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt << std::endl;

    it /= static_cast<int>(pi);
    it *= static_cast<int>(dt);
    it -= static_cast<int>(ft);
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    it *= it;
    it /= 0;
    it /= 0;
    it /= 0;
    std::cout << it << std::endl;
    
    it *= static_cast<int>(ft);
    std::cout << "FloatType x IntType  =  " << it << std::endl;

    it += static_cast<int>(dt);
    it += static_cast<int>(ft);
    it *= 24;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    float floatExp = 2.0f;
    double doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with FloatType" << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType" << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType" << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with DoubleType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    ft += 2.0f;
    std::cout << "FloatType add result=" << ft << std::endl;
    ft -= 2.0f;
    std::cout << "FloatType subtract result=" << ft << std::endl;
    ft *= 2.0f;
    std::cout << "FloatType multiply result=" << ft << std::endl;
    ft /= 16.0f;
    std::cout << "FloatType divide result=" << ft << std::endl << std::endl;

    dt += 2.0;
    std::cout << "DoubleType add result=" << dt << std::endl;
    dt -= 2.0;
    std::cout << "DoubleType subtract result=" << dt << std::endl;
    dt *= 2.0;
    std::cout << "DoubleType multiply result=" << dt << std::endl;
    dt /= static_cast<double>(5.f);
    std::cout << "DoubleType divide result=" << dt << std::endl << std::endl;

    it += 2;
    std::cout << "IntType add result=" << it << std::endl;
    it -= 2;
    std::cout << "IntType subtract result=" << it << std::endl;
    it *= 2;
    std::cout << "IntType multiply result=" << it << std::endl;
    it /= 3;
    std::cout << "IntType divide result=" << it << std::endl << std::endl;
    it *= 1000;
    it /= 2;
    it -= 10;
    it += 100;
    std::cout << "Chain calculation = " << it << std::endl;

        // FloatType object instanciation and method tests
    // --------
    ft += 3.0f;
    ft *= 1.5f;
    ft /= 5.0f;
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    dt *= static_cast<double>(it);
    dt /= static_cast<double>(5.0f);
    dt += static_cast<double>(ft);
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = ";
    it /= 0;
    std::cout << it << std::endl;
    std::cout << "New value of ft = ft / 0 = ";
    ft /= 0;
    std::cout << ft << std::endl;
    std::cout << "New value of dt = dt / 0 = ";
    dt /= 0;
    std::cout << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();
    part4();
    std::cout << "good to go!\n";

    return 0;
}
