#include "AssetImporter.h"

sf::Texture* AssetImporter::get_texture(ASSET_TYPE type, std::string name)
{
    std::string path = get_asset_path(type);
    path.append(name);
    path.append(".png");

    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile(path);

    return texture;
}

std::string AssetImporter::get_asset_path(ASSET_TYPE type)
{
    std::string path = "Textures/";

    switch (type) {
    case CITY_MAP: {path.append("Maps/"); }break;
        case BUTTON: {path.append("Buttons/");}break;
        case ENTITY: {path.append("Entity/"); }break;
        case SPLASH_ART:{path.append("Splash_Art/"); }break;
        default: {
        }
    }
    return path;
}
