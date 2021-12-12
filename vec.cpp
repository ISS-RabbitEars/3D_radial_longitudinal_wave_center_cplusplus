vec::vec()
{
    x=0.;
    y=0.;
    z=0.;
}

vec::~vec() {}

vec::vec(const double a, const double b, const double c)
{
    x=a;
    y=b;
    z=c;
}

vec::vec(const double a, const double b)
{
    x=a;
    y=b;
    z=0.;
}

vec::vec(const double a)
{
    x=a;
    y=0.;
    z=0.;
}

vec& vec::operator()(const double a, const double b, const double c)
{
    x=a;
    y=b;
    z=c;
    return (*this);
}

vec& vec::operator()(const double a, const double b)
{
    x=a;
    y=b;
    z=0;
    return (*this);
}

vec& vec::operator()(const double a)
{
    x=a;
    y=0.;
    z=0;
    return (*this);
}

vec& vec::operator()()
{
    x=0.;
    y=0.;
    z=0.;
    return (*this);
}

double vec::norm()
{
    return(sqrt(x*x+y*y+z*z));
}

vec vec::hat()
{
    vec a;
    a.x=x/norm();
    a.y=y/norm();
    a.z=z/norm();
    return(a);
}

vec vec::operator+(const vec &v)const
{
    return vec(this->x+v.x,this->y+v.y,this->z+v.z);
}

vec vec::operator-(const vec &v)const
{
    return vec(this->x-v.x,this->y-v.y,this->z-v.z);
}

vec vec::operator*(const double &a)const
{
    return vec(this->x*a,this->y*a,this->z*a);
}

vec operator*(const double &a, const vec &v)
{
    return v*a;
}

vec& vec::operator+=(const vec &a)
{
    return(*this=*this+a);
}

vec& vec::operator-=(const vec &a)
{
    return(*this=*this-a);
}

