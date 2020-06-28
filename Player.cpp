#include "Player.h"

Player::Player()
{
	m_PlayerSpeed = 400;                                                       // Устанавливаем значение скорости игрока в 400 пикс./сек
	//---------------------------------------------------------------------------------------------------------------------------
	// Загружаем текстуры скинов игрока (ниже):
	m_PlayerSkinL.loadFromFile("Textures\\Player_Textures\\LeftSkin.png");       
	m_PlayerSkinLU.loadFromFile("Textures\\Player_Textures\\LeftUpSkin.png");
	m_PlayerSkinU.loadFromFile("Textures\\Player_Textures\\UpSkin.png");
	m_PlayerSkinRU.loadFromFile("Textures\\Player_Textures\\RightUpSkin.png");
	m_PlayerSkinR.loadFromFile("Textures\\Player_Textures\\RightSkin.png");
	m_PlayerSkinRD.loadFromFile("Textures\\Player_Textures\\RightDownSkin.png");
	m_PlayerSkinD.loadFromFile("Textures\\Player_Textures\\DownSkin.png");
	m_PlayerSkinLD.loadFromFile("Textures\\Player_Textures\\LeftDownSkin.png");

	m_PlayerSprite.setTexture(m_PlayerSkinL);

	m_PlayerDirection = 0;

	m_PlayerPosition.x = VideoMode::getDesktopMode().width / 2;
	m_PlayerPosition.y = VideoMode::getDesktopMode().height / 2;
}

/*
* Описание функций ниже в header-файле
*/

//-------------------------------------------------------------------------------------------------------------------------------
Sprite Player::getSprite()
{
	return m_PlayerSprite;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::moveLeft()
{
	m_LeftPressed = true;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::moveRight()
{
	m_RightPressed = true;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::moveUp()
{
	m_UpPressed = true;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::moveDown()
{
	m_DownPressed = true;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::stopLeft()
{
	m_LeftPressed = false;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::stopRight()
{
	m_RightPressed = false;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::stopUp()
{
	m_UpPressed = false;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::stopDown()
{
	m_DownPressed = false;
}
//-------------------------------------------------------------------------------------------------------------------------------

void Player::setDirection()
{
	if (m_LeftPressed)
	{
		m_PlayerDirection = 0;
		m_PlayerSprite.setTexture(m_PlayerSkinL);
	}

	else if (m_LeftPressed && m_UpPressed)
	{
		m_PlayerDirection = 1;
		m_PlayerSprite.setTexture(m_PlayerSkinLU);
	}

	else if (m_UpPressed)
	{
		m_PlayerDirection = 2;
		m_PlayerSprite.setTexture(m_PlayerSkinU);
	}

	else if (m_RightPressed && m_UpPressed)
	{
		m_PlayerDirection = 3;
		m_PlayerSprite.setTexture(m_PlayerSkinRU);
	}

	else if (m_RightPressed)
	{
		m_PlayerDirection = 4;
		m_PlayerSprite.setTexture(m_PlayerSkinR);
	}

	else if (m_RightPressed && m_DownPressed)
	{
		m_PlayerDirection = 5;
		m_PlayerSprite.setTexture(m_PlayerSkinRD);
	}

	else if (m_DownPressed)
	{
		m_PlayerDirection = 6;
		m_PlayerSprite.setTexture(m_PlayerSkinD);
	}

	else if (m_LeftPressed && m_DownPressed)
	{
		m_PlayerDirection = 7;
		m_PlayerSprite.setTexture(m_PlayerSkinLD);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
short Player::getDirection()
{
	return m_PlayerDirection;
}
//-------------------------------------------------------------------------------------------------------------------------------
void Player::update(float elapsedTime)
{
	if (m_LeftPressed)
	{
		m_PlayerPosition.x -= m_PlayerSpeed * elapsedTime;
	}
	
	if (m_RightPressed)
	{
		m_PlayerPosition.x += m_PlayerSpeed * elapsedTime;
	}

	if (m_UpPressed)
	{
		m_PlayerPosition.y -= m_PlayerSpeed * elapsedTime;
	}

	if (m_DownPressed)
	{
		m_PlayerPosition.y += m_PlayerSpeed * elapsedTime;
	}

	setDirection();

	m_PlayerSprite.setPosition(m_PlayerPosition);
}

// TODO: Добавить изменение скина и считывание коллизии.