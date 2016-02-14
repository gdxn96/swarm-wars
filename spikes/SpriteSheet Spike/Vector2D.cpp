#include "stdafx.h"
#include "Vector2D.h"
#include <cmath>
#define M_PI 3.141592654
Vector2D::Vector2D()
{
	x = 0.0;
	y = 0.0;
}Vector2D::~Vector2D()
{}
Vector2D::Vector2D(float sourceX, float sourceY)
{
	x = sourceX;
	y = sourceY;
}
sf::Vector2f Vector2D::toSFMLVector()
{
	return sf::Vector2f(x,y);
}
Vector2D Vector2D::operator+(const Vector2D &v) const
{
	return Vector2D(x+v.x, y+v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v) const
{
	return Vector2D(x-v.x, y-v.y);
}

Vector2D Vector2D::operator*(const Vector2D &v) const
{
	return Vector2D(x*v.x, y*v.y);
}
Vector2D Vector2D::operator=(const sf::Vector2f & sfv)
{
	x = sfv.x;
	y = sfv.y;

	return *this;
}
Vector2D Vector2D::operator += (const Vector2D& rhs) 
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}
Vector2D Vector2D::operator/(const Vector2D &v) const
{
	return Vector2D(x/v.x, y/v.y);
}

bool Vector2D::operator==(const Vector2D &v) const
{
	return ((x == v.x) && (y == v.y));
}

bool Vector2D::operator>(const Vector2D &v) const
{
	return (x*x + y*y) > (v.x*v.x + v.y*v.y);
}

bool Vector2D::operator<(const Vector2D &v) const
{
	return (x*x + y*y) < (v.x*v.x + v.y*v.y);
}

bool Vector2D::operator>=(const Vector2D &v) const
{
	return (x*x + y*y) > (v.x*v.x + v.y*v.y) ||
		(x*x + y*y) == (v.x*v.x + v.y*v.y);
}

bool Vector2D::operator<=(const Vector2D &v) const
{
	return (x*x + y*y) < (v.x*v.x + v.y*v.y) ||
		(x*x + y*y) == (v.x*v.x + v.y*v.y);
}
Vector2D Vector2D::operator-() const
{
	return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(const float& scalar) const
{
	return Vector2D(x*scalar, y*scalar);
}

Vector2D Vector2D::operator/(const float& scalar) const
{
	return Vector2D(x/scalar, y/scalar);
}

float Vector2D::DotProduct(const Vector2D &a, const Vector2D &b)
{
	return ((a.x * b.x) + (a.y * b.y));
}
float Vector2D::DotProduct(const Vector2D &b)
{
	return ((x * b.x) + (y * b.y));
}
float Vector2D::CrossProduct(const Vector2D &a, const Vector2D &b)
{
	return ((a.x * b.y) - (a.y * b.x));
}

float Vector2D::Magnitude(const Vector2D &v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}

float Vector2D::Magnitude()
{
	return sqrt((x * x) + (y * y));
}
Vector2D Vector2D::Normalize()
{
	Vector2D nVec;
	if (x*x + y*y == 0)
	{
		nVec.x = 0;
		nVec.y = 0;
	}
	if (x*x + y*y != 0)
	{
		nVec.x = x / sqrt(x*x + y*y);
		nVec.y = y / sqrt(x*x + y*y);
	}
	return nVec;
}
Vector2D Vector2D::Normalize(Vector2D t)
{
	Vector2D nVec;
	if (t.x*t.x + t.y*t.y == 0)
	{
		nVec.x = 0;
		nVec.y = 0;
	}
	if (t.x*t.x + t.y*t.y != 0)
	{
		nVec.x = t.x / sqrt(t.x*t.x + t.y*t.y);
		nVec.y = t.y / sqrt(t.x*t.x + t.y*t.y);
	}
	return nVec;
}
Vector2D Vector2D::Normal(const Vector2D &v)
{
	float magnitude = Magnitude(v);
	return Vector2D(v.x / magnitude, v.y / magnitude);
}

Vector2D Vector2D::Perpendicular(const Vector2D &v)
{
	return Vector2D(v.y, -v.x);
}
Vector2D Vector2D::DirectionVectorBetweenTwoPoints(const Vector2D &v1, const Vector2D & v2)
{
	Vector2D vec = Vector2D(v2.x-v1.x,v2.y-v1.y);
	return vec.Normalize();
}
bool Vector2D::Intersect(const Vector2D &aa, const Vector2D &ab, const Vector2D &ba, const Vector2D &bb)
{
	Vector2D p = aa;
	Vector2D r = ab - aa;
	Vector2D q = ba;
	Vector2D s = bb - ba;

	float t = CrossProduct((q - p), s) / CrossProduct(r, s);
	float u = CrossProduct((q - p), r) / CrossProduct(r, s);

	return (0.0 <= t && t <= 1.0) &&
		(0.0 <= u && u <= 1.0);
}

Vector2D Vector2D::GetIntersect(const Vector2D &aa, const Vector2D &ab, const Vector2D &ba, const Vector2D &bb)
{
	float pX = (aa.x*ab.y - aa.y*ab.x)*(ba.x - bb.x) -
		(ba.x*bb.y - ba.y*bb.x)*(aa.x - ab.x);
	float pY = (aa.x*ab.y - aa.y*ab.x)*(ba.y - bb.y) -
		(ba.x*bb.y - ba.y*bb.x)*(aa.y - ab.y);
	float denominator = (aa.x - ab.x)*(ba.y - bb.y) -
		(aa.y - ab.y)*(ba.x - bb.x);

	return Vector2D(pX / denominator, pY / denominator);
}

float Vector2D::Distance(Vector2D & one,Vector2D & two)
{
	return sqrt((two.x -one.x)*(two.x - one.x) + (two.y - one.y)*(two.y - one.y));
}

float Vector2D::AngleRad(Vector2D & one, Vector2D & two)
{
	return atan2(one.y - two.y, one.x - two.x);
}

float Vector2D::AngleDeg(Vector2D & one, Vector2D & two)
{
	return (atan2(one.y - two.y, one.x - two.x)) * 180 / M_PI;
}