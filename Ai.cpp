#include "Ai.h"

void Ai::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50, 100));
	shape.setPosition(750, 200);
}

Ai::Ai()
	:moveSpeed{ 4 }
{
	initShape();
	
}

Ai::~Ai()
{

}

const sf::RectangleShape Ai::getShape() const
{
	return shape;
}

int Ai::compareBalltoAi(int y)
{
	if (shape.getGlobalBounds().top > y) {
		return 0; // means ball is above ai
		
	}
	else if ((shape.getGlobalBounds().top + shape.getGlobalBounds().height) < y) {
		return 1; // means ball is above ai
		
	}
	return 1;
}

void Ai::logic(const sf::RenderTarget* target, int y)
{
	//COLLISION
	//top
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	if (playerBounds.top <= 0) {
		shape.move(0, moveSpeed);//move down
	}
	//bottom
	else if (playerBounds.top + playerBounds.height >= target->getSize().y) {
		shape.move(0, -moveSpeed);//move up
	}
	//check if ball is above or below, then move
	if (compareBalltoAi(y) == 0) {
		shape.move(0, -moveSpeed); // move up
	}
	else if (compareBalltoAi(y) == 1) {
		shape.move(0, moveSpeed); // move down
	}

}

void Ai::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
