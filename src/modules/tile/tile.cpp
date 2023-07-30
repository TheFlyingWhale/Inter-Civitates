#include "tile.hpp"

#include <string>

using namespace std;

string biomeTypes[] = {
	"Forest",
	"Desert",
	"Jungle",
	"Tundra",
	"Savanna",
	"Taiga",
	"Grassland",
	"Wetland",
	"Mountain",
	"Volcano",
	"Swamp",
	"Ocean",
	"Coral Reef",
	"Beach",
	"Cavern",
	"Glacier",
	"Caves",
	"Canyon",
	"Oasis",
	"Lava Fields",
	"Archipelago",
	"Plateau",
	"Marsh",
	"Dunes",
	"Rainforest",
	"Ruins",
	"Abandoned City",
	"Crystal Caves",
	"Underground River",
	"Ancient Temple",
	"Frozen Lake",
	"Crystal Forest",
	"Underground Catacombs",
	"Floating Islands",
	"Mystic Grove",
	"Subterranean City",
	"Underwater Caves",
	"Mushroom Forest",
	"Underwater Volcano",
	"Underwater Ruins",
	"Floating City",
	"Floating Gardens",
	"Skyland",
	"Ancient Library",
	"Underground Mines",
	"Forgotten Graveyard",
	"Sand Dunes",
	"Steppes",
	"Underwater Canyon",
	"Crystal Lake"};

string getRandomBiome()
{
	int index = randomInt(sizeof(biomeTypes) / sizeof(string));
	return biomeTypes[index];
};