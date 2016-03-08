#include "Scene.h"
#include "GameConstants.h"
#include "InputHandler.h"
#include "PulsingText.h"
#include "UnitController.h"
#include <functional>
#include "Vector2D.h"
using namespace std;
enum { SNIPER_UNIT = 2, CQB_UNIT = 1, ASSAULT_UNIT = 0, BUNKER_REPAIR = 3 };

class MenuItem
{
public:
	MenuItem(Vector2D pos, Vector2D size);

	void setSelected(bool selected);
	bool getSelected();
	void update(float dt);
	void draw(sf::RenderWindow& window);

	void setCost(int cost);

	void setAnimKey(string animKey);

	void setTextField(string text);
	void setColor(sf::Color c);

private:
	Vector2D m_position;
	Vector2D m_size;
	string m_itemName;
	int m_cost;
	bool m_selected;
	Animation m_anim,m_button;
	PulsingText m_costText, m_descText;
	sf::Color m_Color;

};