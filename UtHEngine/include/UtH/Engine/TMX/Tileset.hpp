#pragma once
#ifndef TILESET_TMX_UTH_H
#define TILESET_TMX_UTH_H

#include <UtH/Math/Rectangle.hpp>
#include <UtH/Resources/ResourceManager.h>
#include <UtH/Engine/TMX/Tile.hpp>
// For some "reason" you can't include this here
//#include <tinyxml2.h>
#include <string>

// Stupid hack to fix visual studio bugs
namespace tinyxml2
{
	class XMLElement;
}

namespace uth
{
	namespace TMX
	{
		class Map;

		class Tileset
		{
		public:
			Tileset(tinyxml2::XMLElement* tilesetElement, const std::string& mapFolder);
			 ~Tileset();

			Texture* GetTexture() const;

			unsigned int GetFirstGID() const;

			unsigned int GetTileWidth() const;
			unsigned int GetTileHeight() const;

			const umath::rectangle GetTile(unsigned int localId) const;
		private:
			void parseTileset(tinyxml2::XMLElement* tilesetElement, const std::string& mapFolder);

			unsigned int m_firstgid;

			unsigned int m_spacing, m_margin;

			unsigned int m_tileWidth, m_tileHeight;

			Texture* m_texture;
		};
	}
}

#endif