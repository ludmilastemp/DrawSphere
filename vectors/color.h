#ifndef STL_Color
#define STL_Color

using color_t = double;

class Color
{
public:

    color_t r {}; 
    color_t g {};
    color_t b {};

    Color (color_t r = 0, color_t g = 0, color_t b = 0);

    Color operator+ (const Color& color2) const;
    Color operator- (const Color& color2) const;
    Color operator* (const Color& color2) const;
    Color operator* (const double mul) const;
    Color operator/ (const double mul) const;
    Color operator- () const;

    void clamp ();
};

#endif /* STL_Color */