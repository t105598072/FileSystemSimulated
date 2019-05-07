class Rectangle: public Shape
{
public:
  Rectangle(double l, double w):_l(l), _w(w)
  {
  }

private:
  double _l;
  double _w;
};
