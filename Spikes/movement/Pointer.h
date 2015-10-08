#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 



class Pointer
{
private:
	sf::Vector2f m_pos;
	float m_radius;
	float m_angle;
	float m_speed;
	sf::Color m_color;
	sf::CircleShape m_shape; 

public:
	Pointer(float, float, sf::Color);
	void update();
	void draw(sf::RenderWindow&);
};