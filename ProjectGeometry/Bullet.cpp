#include "Bullet.h"

Bullet::Bullet(int damage, sf::Vector2f direction)
{
	sf::Color color;
	std::size_t count = 0;
	if (Player::player->typeB == Player::TYPEBULLET::TRIANGLE)
	{
		count = 3;
		color = sf::Color::Red;
		Player::player->shootTimerValue = 0.5f;
		Player::player->shootTimerShipValue = 0.5f;
	}
	else if (Player::player->typeB == Player::TYPEBULLET::SQUARE)
	{

		Player::player->shootTimerValue = 1.0f;
		Player::player->shootTimerShipValue = 0.5f;
		color = sf::Color::Magenta;
		count = 4;
	}
	/*else if (Player::player->typeB == Player::TYPEBULLET::PENTAGONE)
	{
		count = 5;
	}*/
	else if (Player::player->typeB == Player::TYPEBULLET::HEXAGONE)
	{

		Player::player->shootTimerValue = 0.2f;
		Player::player->shootTimerShipValue = 0.5f;
		color = sf::Color::Yellow;
		scaleB = 0.8f;
		count = 6;
	}
	damageB = damage;
	trajectoire = direction;
	shapeB.setPointCount(count);
	shapeB.setFillColor(color);
	shapeB.setRadius(radiusB);
	shapeB.setScale(scaleB, 1.0f);
	float aimingAngle = atan2f(direction.y, direction.x);
	shapeB.setRotation(ConvertRadToDeg(aimingAngle + IIM_PI / 2.0f));
}
void Bullet::Update(sf::RenderWindow *window, float deltaTime)
{
	MoveBullet(speedB * deltaTime);
	window->draw(shapeB);
}

void Bullet::MoveBullet(float speed)
{
	shapeB.setPosition(shapeB.getPosition() + trajectoire * speed);
}