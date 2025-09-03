struct Date
{
    int year;
    int month;
    int day;
};

int main()
{
    /* Here we see the use of the 'const' type. When we use this keyword, the object
       MUST be initialized at the time of creation. Just as with normal variables we
       want to make our class const or constexpr to ensure they are not edited after
       creation. */
    const Date today { 2020, 10, 14 };

    return 0;
}
