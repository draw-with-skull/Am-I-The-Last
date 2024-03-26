#pragma once
#include "Building.h"
class BuildingSingleInterior :
    public Building
{
public:
    BuildingSingleInterior(const std::string textur_name, sf::RenderWindow* target);
public:
    // Inherited via Building
    virtual void update(const float& dt,sf::Vector2f position) override;
    virtual void render(const sf::RenderTarget* target) override;
};

