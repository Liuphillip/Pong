#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::RectangleShape shape;
	float moveSpeed;
	void initShape();

	//states
	bool upButton = false, downButton = false;
public:
	Player();
	~Player();

	//functions
	const sf::RectangleShape getShape() const;
	

	//game loop functions
	void input(sf::Event& ev, sf::RenderWindow* target);
	void logic(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

