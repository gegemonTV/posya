#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	m_Player.update(dtAsSeconds);                                   // Обновление позиции спрайта игрока
}