#ifndef RESOURCEMAPS_HH
#define RESOURCEMAPS_HH

#include "core/basicresources.h"


namespace Game {

namespace ConstResourceMap {


const Course::ResourceMap EMPTY = {};

const Course::ResourceMap FOREST_BP = {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 3},
    {Course::BasicResource::WOOD, 10},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0},
};

const Course::ResourceMap ROCK_BP = {
    {Course::BasicResource::MONEY, 10},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 10},
    {Course::BasicResource::ORE, 5},
};

const Course::ResourceMap WATER_BP = {
    {Course::BasicResource::MONEY, 3},
    {Course::BasicResource::FOOD, 8},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0},
};

const Course::ResourceMap SAND_BP = {
    {Course::BasicResource::MONEY, 2},
    {Course::BasicResource::FOOD, 1},
    {Course::BasicResource::WOOD, 1},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0},
};

}
}


#endif // RESOURCEMAPS_HH
