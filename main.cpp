/*
Project 4: Part 7 / 9
Video: Chapter 5 Part 4

Create a branch named Part7

Do not delete your previous main. you will be adding to it.

Templates and Containers

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
    it's very easy to mess this task up. 

0) comment out part6(), both the function and where it is called.

#1) if you're not using std::unique_ptr to own your heap-allocated type as a member variable, 
    replace your manual memory management techniques with a private std::unique_ptr member variable.

#2) replace your Heap-Allocated Numeric Type-owning classes with a single templated class called 'Numeric'.
        replace all instances of your previous classes (Numeric, etc) with this templated class.

#3) add a 'using Type = <your class template parameter>;' 
        treat this type declaration via 'using' as a static member variable
        use this Type alias as the argument everywhere you previously used the template argument.
        this will make it very easy to change the type if needed.
            i.e. if you have 'std::unique_ptr<NumericType> value;' before
                you'd replace NumericType in that variable declaration with 'Type'
        
#4) you'll need to pair it with decltype() to help the compiler figure out the type of the object 
    your class owns when you make your lambda and free function that takes your unique_ptr.  
    i.e. like this for determining the template parameter of the unique_ptr function argument to your class's apply() function
        std::unique_ptr< decltype( <instance of class> )::Type >
    
#5) template your free function for the apply() that takes a function pointer so it can be used with your Wrapper class's apply() function

#6) add an explicit template specialization for 'double' of your wrapper class
        this template specialization will have one apply() function instead of 2. 

#7) this apply() function will be templated, and expect a Callable object, not std::function<>. 
        the function should allow for chaining.  
        the callable object should return void, like the function pointer-based apply() function in the primary class template

#8) instantiate your explicit template specialization

#9) call the apply function twice, once with a lambda and once with the free function
        the free function is templated, so you might need to call it including the template arguments.
        
#10) in addition to using the lambda argument to modify the owned object:  (your previous task's lambdas did this same thing) 
        make the lambda use your explicit template instance (maybe via a std::cout), 

#11) now that your class is templated, you'll need to adjust your logic in your division function to handle if your input is a zero or not, based on your templated type.  
        Note: this instruction does not apply to the explicit template specialization
        - look up how to use std::is_same<>::value on cppreference to determine the type of your template parameter.
        
        - look up how to use std::numeric_limits<>::epsilon() to determine if you're dividing by a floating point 0
        
        - read about Knuth's algorithm here: https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/

        - in plain-english, you'll need to implement this logic:
        if your class template type is an int
                if your parameter's type is also an int
                        if your parameter's value is 0
                                don't do the division
                else if your parameter's value is less than epsilon
                        dont do the divison
        else if your parameter's value is less than epsilon
                warn about doing the division

        - to make these checks work during compilation, your if() statements will need to be 'constexpr':  if constexpr (expression)

        - pay attention to the 2nd line in the plain-english logic.
                most people don't get this part of the assignment correct.

12) move part7() to before main()
        call part7() in main(), after where you were calling part6()

If you need to view an example, see: https://bitbucket.org/MatkatMusic/pfmcpptasks/src/master/Projects/Project4/Part7Example.cpp
*/

/*
your program should generate the following output EXACTLY.
This includes the warnings. 
 The output should have zero warnings.


Numeric add result=4
Numeric subtract result=2
Numeric multiply result=4
Numeric divide result=0.25

Numeric add result=4
Numeric subtract result=2
Numeric multiply result=4
Numeric divide result=0.8

Numeric add result=4
Numeric subtract result=2
Numeric multiply result=4
Numeric divide result=1

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

The result of Numeric^4 divided by Numeric is: 26.9136
The result of Numeric times 3 plus Numeric is : 67.3
The result of Numeric divided by 3.14 multiplied by Numeric minus Numeric is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
can't divide integers by zero!
can't divide integers by zero!
505521
Numeric x Numeric  =  13143546
(Numeric + Numeric + Numeric) x 24 = 315447336
Power tests with Numeric 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with Numeric 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with Numeric 
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

Point tests with Numeric argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with Numeric argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with Numeric argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

Calling Numeric<float>::apply() using a lambda (adds 7.0f) and Numeric<float> as return type:
ft3 before: 3
ft3 after: 10
Calling Numeric<float>::apply() twice using a free function (adds 7.0f) and void as return type:
ft3 before: 10
ft3 after: 24
---------------------

Calling Numeric<double>::apply() using a lambda (adds 6.0) and Numeric<double> as return type:
dt3 before: 4
dt3 after: 10
Calling Numeric<double>::apply() twice using a free function (adds 7.0) and void as return type:
dt3 before: 10
dt3 after: 24
---------------------

Calling Numeric<int>::apply() using a lambda (adds 5) and Numeric<int> as return type:
it3 before: 5
it3 after: 10
Calling Numeric<int>::apply() twice using a free function (adds 7) and void as return type:
it3 before: 10
it3 after: 24
---------------------

good to go!


Use a service like https://www.diffchecker.com/diff to compare your output. 
*/


#include <iostream>
#include <cmath>
#include <functional>
#include <memory>

struct FloatTYpe;
struct DoubleType;
struct IntTYpe;
template<typename T>
struct Numeric;

struct Point
{
    Point(float x, float y);
    explicit Point(Numeric<float>& x);
    explicit Point(Numeric<double>& x);
    explicit Point(Numeric<int>& x);
    
    
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(Numeric<float>& m);
    Point& multiply(Numeric<double>& m);
    Point& multiply(Numeric<int>& m);
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

template<typename T>
struct Numeric
{
    using Type = T;

    Numeric(Type num) : value(std::make_unique<Type>(num)) {}
    ~Numeric() {}

    Numeric& operator+=(Type rhs) 
    {
        *value += rhs;
        return *this;
    }
    
    
    Numeric& operator-=(Type rhs)
    {       
        *value -= rhs;
        return *this;  
    }
    
    
    Numeric& operator*=(Type rhs)
    {
        *value *= rhs;
        return *this;
    }
    
    
    template<typename P>
    Numeric& operator/=(P rhs)
    {
        if constexpr(std::is_same<int, Type>::value)
        {
            if constexpr(std::is_same<int, P>::value)
            {
                if(rhs == 0)
                {
                    std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
                    return *this;
                }
            }
            else if (static_cast<float>(rhs) < std::numeric_limits<float>::epsilon())
            {
                std::cout << "can't divide integers by zero!" << std::endl;
                return *this;
            }
        }
        else if (rhs < std::numeric_limits<float>::epsilon())
        {
            std::cout << "warning: floating point division by zero!" << std::endl;
            *value /= rhs;
            return *this;
        }

        *value /= static_cast<T>(rhs);
        return *this;
    }


    Numeric& pow(const Numeric& exp)
    {
        return powInternal(value, exp);
    }

    Numeric& pow(Type exp)
    {
        return powInternal(value, exp);
    }


    Numeric& apply(std::function<Numeric&(std::unique_ptr<Type>&)> func)
    {
        if (func != nullptr)
        {
            return func(value);
        }
        return *this;
    }


    Numeric& apply(void(*func)(std::unique_ptr<Type>&))
    {
        if (func != nullptr)
        {
            func(value);
        }
        return *this;
    }

    operator Type() const
    {
        return *value;
    }
    

private:
    
    std::unique_ptr<Type> value;
    Numeric& powInternal(std::unique_ptr<Type>& lhs, Type rhs)
    {
        *lhs = static_cast<Type>(std::pow( *lhs, rhs ));
        return *this;
    }
};

template<>
struct Numeric<double>
{

    using Type = double;
    
    explicit Numeric(Type num) : value(std::make_unique<Type>(num)) {}
    ~Numeric() {}
    
    Numeric& operator+=(Type rhs)
    {
        *value += rhs;
        return *this;
    }


    Numeric& operator-=(Type rhs)
    {
        *value -= rhs;
        return *this;
    }


    Numeric& operator*=(Type rhs)
    {
        *value *= rhs;
        return *this;
    }
    
    
    Numeric& operator/=(Type rhs)
    {
        if(rhs == 0.0)
        {
            std::cout << "warning: floating point division by zero!" <<  std::endl;
        }
        *value /= rhs;
        return *this;
    }


    Numeric& pow(const Numeric& rhs)
    {
        return powInternal(value, rhs);
    }


    Numeric& pow(Type rhs)
    {
        return powInternal(value, rhs);
    }

    
    template<typename Callable>
    Numeric& apply(Callable&& f)
    {
        f(value);
        return *this;
        
    }
    
    operator Type () const
    {
        return *value;
    }
 
private:
    
    std::unique_ptr<Type> value;
    Numeric& powInternal(std::unique_ptr<Type>& base, Type exp)
    {
        *value = std::pow( *base, exp );
        return *this;
    }
};


// Point Implimentations 

Point::Point(float x_, float y_) : x(x_), y(y_) {}
Point::Point(Numeric<float>& x_) : Point(static_cast<float>(x_), static_cast<float>(x_)) {}
Point::Point(Numeric<double>& x_) : Point(static_cast<float>(x_), static_cast<float>(x_)) {}
Point::Point(Numeric<int>& x_) : Point(static_cast<float>(x_), static_cast<float>(x_)) {}


Point& Point::multiply(Numeric<double>& d)
{
    return multiply(static_cast<float>(d));
}

Point& Point::multiply(Numeric<int>& d)
{
    return multiply(static_cast<float>(d));
}

Point& Point::multiply(Numeric<float>& d)
{
    return multiply(static_cast<float>(d));
}

void Point::toString()
{
    std::cout << "Point { x: " << x << ", y: " << y << " }" << std::endl;  
}


// Free Function 

template <typename T>
void myNumericFreeFunct(std::unique_ptr<T>& val)
{
    T& i = *val;
    i = i + 7;
}



void part3()
{
    Numeric<float> ft( 5.5f );
    Numeric<double> dt( 11.1 );
    Numeric<int> it ( 34 );
    Numeric<double> pi( 3.14 );

    ft *= ft;
    ft *= ft;
    ft /= static_cast<float>(it);
    std::cout << "The result of Numeric^4 divided by Numeric is: " << ft << std::endl;

    dt *= 3.0;
    dt += it;
    std::cout << "The result of Numeric times 3 plus Numeric is : " << dt << std::endl;

    it /= static_cast<int>(pi);
    it *= static_cast<int>(dt);
    it -= static_cast<int>(ft);
    std::cout << "The result of Numeric divided by 3.14 multiplied by Numeric minus Numeric is: " << it << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    it *= it;
    it /= 0;
    it /= 0.f;
    it /= 0.0;
    std::cout << it << std::endl;
    
    it *= static_cast<int>(ft);
    std::cout << "Numeric x Numeric  =  " << it << std::endl;

    it += static_cast<int>(dt);
    it += static_cast<int>(ft);
    it *= 24;
    std::cout << "(Numeric + Numeric + Numeric) x 24 = " << it << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    Numeric<float> ft1(2);
    Numeric<double> dt1(2);
    Numeric<int> it1(2);
    float floatExp = 2.0f;
    double doubleExp = 2.0;
    int intExp = 2;
    Numeric<int> itExp(2);
    Numeric<float> ftExp(2.0f);
    Numeric<double> dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with Numeric" << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(static_cast<float>(dtExp))  << std::endl;
    std::cout << "---------------------\n" << std::endl;

    // Power tests with DoubleType
    std::cout << "Power tests with Numeric" << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(static_cast<double>(ftExp))  << std::endl;
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;
    std::cout << "---------------------\n" << std::endl;

    // Power tests with IntType
    std::cout << "Power tests with Numeric" << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(static_cast<int>(ftExp))  << std::endl;
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(static_cast<int>(dtExp))  << std::endl;
    std::cout << "===============================\n" << std::endl;

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    Numeric ft2(3.0f);
    Numeric dt2(4.0);
    Numeric it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with Numeric
    std::cout << "Point tests with Numeric argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with Numeric
    std::cout << "Point tests with Numeric argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with Numeric
    std::cout << "Point tests with Numeric argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}

/*
void part6()
{
    Numeric ft3(3.0f);
    Numeric dt3(4.0);
    Numeric it3(5);
    
    std::cout << "Calling Numeric::apply() using a lambda (adds 7.0f) and Numeric as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply( [&](float& v) -> Numeric& 
    { 
        v += 7.0f;
        return ft3;
    } );
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "Calling Numeric::apply() using a free function (adds 7.0f) and void as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply(myFloatFreeFunct);
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric::apply() using a lambda (adds 6.0) and Numeric as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply( [&](double& v) -> Numeric&
    {
        v += 6.0;
        return  dt3;
    } );
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "Calling Numeric::apply() using a free function (adds 6.0) and void as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply(myDoubleFreeFunct);
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric::apply() using a lambda (adds 5) and Numeric as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply( [&](int& v) -> Numeric&
    {
        v += 5;
        return it3;
    } );
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "Calling Numeric::apply() using a free function (adds 5) and void as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply(myIntFreeFunct);
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "---------------------\n" << std::endl;    
}
*/

void part7()
{
    Numeric ft3(3.0f);
    Numeric dt3(4.0);
    Numeric it3(5);
    
    std::cout << "Calling Numeric<float>::apply() using a lambda (adds 7.0f) and Numeric<float> as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;

    {
        using Type = decltype(ft3)::Type;
        using ReturnType = decltype(ft3);
        ft3.apply( [&ft3](std::unique_ptr<Type>& value) -> ReturnType&
        {
            *value += 7.0f;
            return ft3;
        } );
    }

    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "Calling Numeric<float>::apply() twice using a free function (adds 7.0f) and void as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply(myNumericFreeFunct).apply(myNumericFreeFunct);
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric<double>::apply() using a lambda (adds 6.0) and Numeric<double> as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;

    {
        using primType = decltype(dt3)::Type;
        dt3.apply( [&](std::unique_ptr<primType>& value) 
        {
            *value += 6.0;
        } );
    }
    
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "Calling Numeric<double>::apply() twice using a free function (adds 7.0) and void as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply(myNumericFreeFunct<double>).apply(myNumericFreeFunct<double>); // This calls the templated apply fcn
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric<int>::apply() using a lambda (adds 5) and Numeric<int> as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;

    {
        using primType = decltype(it3)::Type;
        using ReturnType = decltype(it3);
        it3.apply( [&it3](std::unique_ptr<primType>& value) -> ReturnType&
        {
            *value += 5;
            return it3;
        } );
    }

    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "Calling Numeric<int>::apply() twice using a free function (adds 7) and void as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply(myNumericFreeFunct).apply(myNumericFreeFunct);
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "---------------------\n" << std::endl;    
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    Numeric<float> ft ( 2.0f );
    Numeric<double> dt ( 2 );
    Numeric<int> it ( 2 ) ;

    ft += 2.0f;
    std::cout << "Numeric add result=" << ft << std::endl;
    ft -= 2.0f;
    std::cout << "Numeric subtract result=" << ft << std::endl;
    ft *= 2.0f;
    std::cout << "Numeric multiply result=" << ft << std::endl;
    ft /= 16.0f;
    std::cout << "Numeric divide result=" << ft << std::endl << std::endl;

    dt += 2.0;
    std::cout << "Numeric add result=" << dt << std::endl;
    dt -= 2.0;
    std::cout << "Numeric subtract result=" << dt << std::endl;
    dt *= 2.0;
    std::cout << "Numeric multiply result=" << dt << std::endl;
    dt /= static_cast<double>(5.f);
    std::cout << "Numeric divide result=" << dt << std::endl << std::endl;

    it += 2;
    std::cout << "Numeric add result=" << it << std::endl;
    it -= 2;
    std::cout << "Numeric subtract result=" << it << std::endl;
    it *= 2;
    std::cout << "Numeric multiply result=" << it << std::endl;
    it /= 3;
    std::cout << "Numeric divide result=" << it << std::endl << std::endl;
    it *= 1000;
    it /= 2;
    it -= 10;
    it += 100;
    std::cout << "Chain calculation = " << it << std::endl;

        // Numeric object instanciation and method tests
    // --------
    ft += 3.0f;
    ft *= 1.5f;
    ft /= 5.0f;
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // Numeric/Numeric object instanciation and method tests
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
    // part6();
    part7();
    std::cout << "good to go!\n";

    return 0;
}
