#pragma once
#include "stdafx.h"
#include <random>

class Civil {
public:
    Civil();

    
    void aparecerAleatorio(const std::vector<sf::Vector2f>& posiciones);
    void ajustarTamaño(float ancho, float alto);
    sf::Sprite obtenerSprite() const;
    void eliminar();
    bool estaEliminado() const;

private:
    sf::Texture textura1;
    sf::Sprite sprite;
    bool eliminado;
};