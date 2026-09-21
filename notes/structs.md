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

The declaration `struct point pt` defines a variable of the type `struct point`, with several members (x, y), to which you assign valuse using the operator `.`.

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

    if (abs(rect.pt1.x) > abs(rect.pt2.x))
        x = rect.pt1.x - rect.pt2.x;
    else
        
}
```

---

## Linked lists
```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}                   t_list;
```
Structs can also be *named*, by adding the aforementioned name after the closing brace, before the ";"

In this case, the structure contains a void pointer declaration `content` and a declaration of `next`, which is a pointer to the next node 

---

[1] Most of this note is based on *Chapter 6: Structures* of **The C Programming Language**, by Brian W. Kernighan and Dennis M. Ritchie.
