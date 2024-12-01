#pragma once
#include "stdafx.h"
#include "Enemigos.h"
#include "Civiles.h"
#include "Instrucciones.h"
#include "GameOver.h"
#include "BucleJuego.h"

Enemigo::Enemigo() : eliminado(false), puntos(1) {
    textura1.loadFromFile("zom1.png");
    sprite.setTexture(textura1);
    ajustarTama�o(100.0f, 100.0f);
}

void Enemigo::aparecerAleatorio(const std::vector<sf::Vector2f>& posiciones) {
    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(static_cast<unsigned>(time(nullptr))); 
        semillaInicializada = true;
    }
    int indiceAleatorio = rand() % posiciones.size(); 
    sprite.setPosition(posiciones[indiceAleatorio]);  
    eliminado = false;
}


void Enemigo::ajustarTama�o(float ancho, float alto) {
    sf::Vector2u tama�oOriginal = sprite.getTexture()->getSize();
    sprite.setScale(
        ancho / tama�oOriginal.x,
        alto / tama�oOriginal.y
    );
}

sf::Sprite Enemigo::obtenerSprite() const {
    return sprite;
}

void Enemigo::eliminar() {
    eliminado = true;
}

bool Enemigo::estaEliminado() const {
    return eliminado;
}

int Enemigo::obtenerPuntos() const {
    return puntos;
}

Civil::Civil() : eliminado(false) {
    textura1.loadFromFile("civ1.png");
    sprite.setTexture(textura1);
    ajustarTama�o(100.0f, 100.0f);
}

void Civil::aparecerAleatorio(const std::vector<sf::Vector2f>& posiciones) {
    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(static_cast<unsigned>(time(nullptr))); 
        semillaInicializada = true;
    }

    int indiceAleatorio = rand() % posiciones.size(); 
    sprite.setPosition(posiciones[indiceAleatorio]);  
    eliminado = false;
}



void Civil::ajustarTama�o(float ancho, float alto) {
    sf::Vector2u tama�oOriginal = sprite.getTexture()->getSize();
    sprite.setScale(
        ancho / tama�oOriginal.x,
        alto / tama�oOriginal.y
    );
}

sf::Sprite Civil::obtenerSprite() const {
    return sprite;
}

void Civil::eliminar() {
    eliminado = true;
}

bool Civil::estaEliminado() const {
    return eliminado;
}

