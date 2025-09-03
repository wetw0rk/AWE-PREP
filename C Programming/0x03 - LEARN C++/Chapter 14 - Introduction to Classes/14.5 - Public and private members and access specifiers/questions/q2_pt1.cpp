#include <iostream>

class Point3d
{
private:

    int m_x = {};
    int m_y = {};
    int m_z = {};

public:

    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
    }

    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}
