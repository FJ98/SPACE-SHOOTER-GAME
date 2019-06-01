// Created by felix on 5/30/2019.
#ifndef PROJPOO2_BASESCENE_H
#define PROJPOO2_BASESCENE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>

class BaseScene {
public:
    BaseScene() = default;

    // funcion que sera invocada para actualizar la escena
    virtual void update(float elapsed);

    // funcion que sera invocada para dibujar la escena
    virtual void draw(sf::RenderWindow &window);

    // funcion que sera invocada para notificar a la escena de un evento
    virtual void process_event(const sf::Event &evnt);

    // agrega un nuevo actor a la escena
    void add(Entity *entity);

    // eliminar un actor de la escena
    void remove(Entity *entity);

private:
    std::vector<Entity *> entities;
    std::vector<Entity *> to_delete;
};


#endif //PROJPOO2_BASESCENE_H
