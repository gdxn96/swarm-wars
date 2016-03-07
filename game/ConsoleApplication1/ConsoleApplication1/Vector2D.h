#pragma once

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
 
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <cfloat>
#include <climits>


/*The Vector2d class is an object consisting of simply an x and
  y value. Certain operators are overloaded to make it for
  easier vector math to be performed.*/

class Vector2D {
public:
    /*The x and y values are public to give easier access for
      outside funtions. Accessors and mutators are not really
      necessary*/
    float x, &width, &w;
    float y, &height, &h;
    ~Vector2D(void);
    //Constructor assigns the inputs to x and y.
    Vector2D();

	//creates a unit vector based on a radian angle
	Vector2D::Vector2D(float angle);
    Vector2D(float, float);
	sf::Vector2f toSFMLVector();
    /*The following operators simply return Vector2ds that
      have operations performed on the relative (x, y) values*/
    Vector2D operator+(const Vector2D&) const;
    Vector2D operator-(const Vector2D&) const;
    Vector2D operator*(const Vector2D&) const;
    Vector2D operator/(const Vector2D&) const;
	Vector2D operator+=(const Vector2D&) ;
	Vector2D operator=(const Vector2D & v);
	// nromalise its self
	Vector2D Normalize() ;
	//normalise a value
	static Vector2D Normalize(Vector2D t) ;
    //Check if the Vectors have the same values.
    bool operator==(const Vector2D&) const;

    /*Check which Vectors are closer or further from the
      origin.*/
    bool operator>(const Vector2D&) const;
    bool operator<(const Vector2D&) const;
    bool operator>=(const Vector2D&) const;
    bool operator<=(const Vector2D&) const;

    //Negate both the x and y values.
    Vector2D operator-() const;

	Vector2D operator=(const sf::Vector2f &);
    //Apply scalar operations.
    Vector2D operator*(const float&) const;
    Vector2D operator/(const float&) const;

	static Vector2D DirectionVectorBetweenTwoPoints(const Vector2D&, const Vector2D&);
    //Product functions
    static float DotProduct(const Vector2D&, const Vector2D&);
    float DotProduct(const Vector2D&);
    static float CrossProduct(const Vector2D&, const Vector2D&);

    //Returns the length of the vector from the origin.
    static float Magnitude(const Vector2D&);
	//gets the length/mag of its self
	float Magnitude();
    //Return the unit vector of the input
    static Vector2D Normal(const Vector2D&);

    //Return a vector perpendicular to the left.
    static Vector2D Perpendicular(const Vector2D&);

    //Return true if two line segments intersect.
    static bool Intersect(const Vector2D&, const Vector2D&, const Vector2D&, const Vector2D&);

    //Return the point where two lines intersect.
    static Vector2D GetIntersect(const Vector2D&, const Vector2D&, const Vector2D&, const Vector2D&);
	//get the distance between 2 points retuns as float
	static float Distance(Vector2D & one ,Vector2D &two);

	static float DistanceSq(Vector2D & one, Vector2D & two);

	//get the angle between 2 points returns as float in degrees
	static float AngleDeg(Vector2D & one, Vector2D & two);
	//get the angle between 2 points returns as float in radians
	static float AngleRad(Vector2D & one, Vector2D & two);
};
