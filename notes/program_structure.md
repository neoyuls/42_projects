# Program Structure in C

## Functions

    Functions are designed to break down a program into specific tasks which, together, achieve the program's goal. This means that functions are, in a way, optional, yet are applied to mantain code suscint, readable, and modular. 

    Every function will have the form:
```c
/*
return-type name(arguments)
{
    declarations & statements;
}
*/
// For example:

char    find_char(char *string); // See function prototyping later

void    example_function(char c); // void return type means it does not return a value

int     main(int ac, char **av)
{
    if (condition)
        return (1);
    //etc...
    return (0);
}

// or:

char    find_char(char *string)
{
    //etc...
    return(some_char);
}
```

### Return values and arguments

    Most functions written in C will return some value, with a type defined in the first part of the function declaration. In addition to this, functions may (and in most cases, will) recieve arguments, in the form of values or variables defined in the last part of the function declaration.
    
