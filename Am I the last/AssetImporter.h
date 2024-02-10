#pragma once
#include <SFML/Graphics/Texture.hpp>
class AssetImporter
{
public:
	enum ASSET_TYPE
	{
		CITY_MAP,
		BUTTON,
		ENTITY,
		SPLASH_ART
	};
private:
	static std::string get_asset_path(ASSET_TYPE type);
public:
	static sf::Texture* get_texture(ASSET_TYPE type,std::string name);
};

