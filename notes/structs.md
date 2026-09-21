# Structures in C

While doing libft.h I have done a variety of memory manipulation functions, as well as general utility function for running calculations and handling basic types of data. I have worked with several types of variables and their respective pointers and arrays, but I have not yet touched structures. [^1]

## Basics of a structure:

A structure can be declared like this:
```c
struct point
{
    int x;
    int y;
    // any type of variable can be stored
    // a few other things can also be stored here haha stay tuned
};
```
This structure can then be implemented within a function like this:
```c
struct point   *fill_point(int a, int b)
{
    struct point pt;

    pt.x = a; //whatever int can be assigned
    pt.y = b; //oh my god what is wrong with me

    return (pt);
};
```
Fundamentally, structs are a *type*, in the same way `int`, or `char`, are.

The declaration `struct point pt` defines a variable of the type `struct point`, with several members (x, y), to which you assign values using the operator `.`.

Being a type of variable, which contains other variable, structs can be *nested*, meaning they can contain structs, within themselves.

```c
#include <stdlib.h> //for abs()
#include <math.h> //for sqrt

struct  line
{
    struct point pt1;
    struct point pt2;
};

double  calc_len(struct line rect)
{
    double      len;
    int x;

    if (abs(rect.pt1.x) > abs(rect.pt2.x))
        x = rect.pt1.x - rect.pt2.x;
    else
        x = rect.pt2.x - rect.pt1.x;
    if (abs(rect.pt1.y) > abs(rect.pt2.y))
        y = rect.pt1.y - rect.pt2.y;
    else
        y = rect.pt2.y - rect.pt1.y;
    return (sqrt(sqrt(x) + sqrt(y)));
}
```
This is an example of using a struct containing 2 structs to calculate the length of a line between two points.

## Arrays of structs and pointers to structs.

Structs, like other variable types, can be declared as arrays with defined sizes.

Say you have a `student` struct, containing information about students, such as age, time in the school, grades, etc; and you have a set number of students. An array of structs with a defined size could be used to contain information about all the students
```c
    struct s_student
    {
        int     age;
        char    *name;
        //etc
    };

    s_student pop[NSTUDENTS]; //assume NSTUDENTS is defined as a macro
```
you could implement this in a function as such:
```c
unsigned int    count_under_21(t_student pop[])
{
    unsigned int    i;
    unsigned int    count;
    
    i = 0;
    while (i < NSTUDENTS)
    {
        if ((base[i].age) < 21)
            count++;
        i++;
    }
    return (count);
}
```
---

Just as you would navigate diferent characters of a string using indexes, you can do the same with structs.

Structs can both contain pointers as variable types within them and be *pointed to*, just like any variable. You can use pointers to structures like this:
```c
int sum_points(struct point original)
{
    struct point    *pp;
    int             sum;

    pp = &original;
    sum = (*pp).x + (*pp).y;
    return (sum);
}
```
In this case pp is a pointer to `original`, a structure of type struct point, which is passed as a parameter.
A specific operator `->` exists as a shorthand way to reference the pointer to a specific member in a struct.
```c
    struct rect r;
    struct rect *rp;

    *rp = r;
```
Given the former, the following is true:
```c
    r.pt1.x == rp->pt1.x == (r.pt1).x == (rp->pt1).x;
// all four of these expressions are equivalent.
```
Using this operator requires being quite careful about the ordering of the operators you use, as structure operators(`.`,`->`), `()` and `[]` hold precedence over any other operators.

Given the structure:
```c
    typedef struct p
    {
        int     len;
        char    *str;
    }           t_p;
    t_p         *element;
    // Structs can also be named, by adding the aforementioned name after the closing brace, before the ";"
```
The expression:
```c
    ++element->len;
```
Increments len, not element, because the system evaluates it as
```c
    ++(element->len);
```
If you wanted to increment the pointer before the `->` operator, the proper notation is:
```c
    (++element)->len;
```

---

## Linked lists

Linked lists are collections of values stored in different memory areas, where each value also contains a link to the next value.

In the case of `c`, a structure which can be used to form a linked list could look like:
```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}                   t_list;
```

In this case, the structure contains a void pointer declaration `content` and a declaration of `next`, which is a pointer to the next node 

---

[1] Most of this note is based on *Chapter 6: Structures* of **The C Programming Language**, by Brian W. Kernighan and Dennis M. Ritchie.
