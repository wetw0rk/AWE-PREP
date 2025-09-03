#include <iostream>

class Foo
{
private:
    int m_x = {};
    int m_y = {};

public:
    // This is the constructor function
    Foo(int x, int y)
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo obj{ 7, 7 };

    obj.print();

    return 0;
}
