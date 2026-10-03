#include <string>
#include <iostream>

using namespace std;

enum class Box_Category
{
    None = 0,
    Bulky = (1 << 1),
    Heavy = (1 << 2),
    Neither = (1 << 3),
};

constexpr Box_Category operator| (const Box_Category& b1, const Box_Category& b2)
{
    return (Box_Category)((int)b1 | (int)b2);
}
constexpr Box_Category& operator|=(Box_Category& b1, const Box_Category& b2)
{
    b1 = (Box_Category)((int)b1 | (int)b2);
    return b1;
}

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {



        Box_Category ctg = Box_Category::None;

        string ret;
        if (length >= 1e4 || width >= 1e4 || height >= 1e4)
            ctg |= Box_Category::Bulky;
        else
        {
            long long vol = (long long)length * width * height;
            if (vol >= 1e9)
                ctg |= Box_Category::Bulky;
        }

        if (mass >= 100)
            ctg |= Box_Category::Heavy;

        const Box_Category both = Box_Category::Bulky | Box_Category::Heavy;
        const Box_Category Bulky = Box_Category::Bulky;
        const Box_Category Heavy = Box_Category::Heavy;
        const Box_Category Neither = Box_Category::None;

        switch (ctg)
        {
        case both: return "Both";
        case Bulky: return "Bulky";
        case Heavy: return "Heavy";
        case Neither: return "Neither";
        }

        return "";
    }
};