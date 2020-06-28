#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "Player/Player.h"

using namespace sf;

class Engine
{
private:
	RenderWindow m_Window;                 // ���� ��� ��������� ��������
//-------------------------------------------------------------------------------------------------------------------------------
	Sprite m_BackgroundSprite;             // ������ ������� ����
	Texture m_BackgroundTexture;           // �������� ������� ����
//-------------------------------------------------------------------------------------------------------------------------------
	Player m_Player;                       // ������ ������
//-------------------------------------------------------------------------------------------------------------------------------
	void input();                          // ������� ��� ��������� �����
	void update(float dtAsSeconds);        // ������� ��� ���������� ������� ��������
	void draw();                           // ������� ��� ��������� ��������
//-------------------------------------------------------------------------------------------------------------------------------
public:
	Engine();                              // ����������� �������� ������
//-------------------------------------------------------------------------------------------------------------------------------
	void start();                          // �������, ������� ��������� ������ � main() �������
};

#endif // !ENGINE_H