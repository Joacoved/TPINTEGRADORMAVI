#pragma once
#include "stdafx.h"
#include <random>

class Enemigo {
public:
    Enemigo();
    void aparecerAleatorio(const std::vector<sf::Vector2f>& posiciones);
    Sprite obtenerSprite() const;
    void eliminar();
    void ajustarTamaño(float ancho, float alto);
    bool estaEliminado() const;
    int obtenerPuntos() const;

private:
    Texture textura1;
    Sprite sprite;
    bool eliminado;
    int puntos;
};