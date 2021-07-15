#include "Ball.h"

void Ball::initVelocity()
{
	int a;
	srand(static_cast<unsigned>(time(0)));
	a = rand() % 4;
	switch (a) {
	case 0:
		xVelocity = -5;
		yVelocity = -5;
	case 1:
		xVelocity = 5;
		yVelocity = 5;
	case 2:
		xVelocity = -5;
		yVelocity = 5;
	case 3:
		xVelocity = 5;
		yVelocity = -5;
	}
}

void Ball::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setRadius(radius);
}

Ball::Ball()
	:radius{ 10 }
{
	initVelocity();
	initShape();
	shape.setPosition(400, 290);
}

Ball::~Ball()
{

}

void Ball::updateMovement(int i)
{
	switch (i) {
	case 1:
		if (yVelocity >= 0) {
			yVelocity = -5;
			std::cout << "case 1: ball yvelocity " << yVelocity << std::endl;
		}
		break;
	case 2:
		yVelocity = 0;
		std::cout << "case 2: ball yvelocity " << yVelocity << std::endl;
		break;
	case 3:
		if (yVelocity <= 0) {
			yVelocity = 5;
			std::cout << "case 3:ball yvelocity " << yVelocity << std::endl;
		}
		break;
	}

	if (xVelocity > 0) {
		xVelocity = -xVelocity;
	}
	else if (xVelocity < 0) {
		xVelocity = -xVelocity;
	}
}

const sf::CircleShape Ball::getShape() const
{
	return shape;
}

int Ball::getBallmiddle()
{
	return shape.getGlobalBounds().top - radius;
}

void Ball::logic(const sf::RenderTarget* target)
{
	shape.move(xVelocity, yVelocity);
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	//if player hits top of screen reverse y speed
	if (playerBounds.top <= 0) {
		yVelocity = -yVelocity;
		shape.move(0, yVelocity);
	}
	//if player hits bottom of screen reverse y speed
	else if (playerBounds.top + playerBounds.height >= target->getSize().y) {
		yVelocity = -yVelocity;
		shape.move(0, yVelocity);
	}
	//check left side collisions
	if (playerBounds.left > target->getSize().x - 50) {
		shape.setPosition(400, 290);
		initVelocity();
	}
	//check right side collisions
	if ((playerBounds.left + playerBounds.width) < 50 ) {
		shape.setPosition(400, 290);
		initVelocity();
	}
}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
