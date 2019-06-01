// Created by felix on 5/30/2019.
#include "BaseScene.h"

void BaseScene::update(float elapsed) {
    for(auto e: entities){
        e->update(elapsed);
    }

    // elimina actores
    for(auto d: to_delete){
        auto it = find(entities.begin(), entities.end(), d);
        if(it != entities.end()){
            entities.erase(it);
        }
    }
    to_delete.clear();
}

void BaseScene::draw(sf::RenderWindow &window) {
    for(auto e: entities){
        e->draw(window);
    }
}

void BaseScene::process_event(const sf::Event &evnt) {

}

void BaseScene::add(Entity *entity) {
    entities.push_back(entity);
}
