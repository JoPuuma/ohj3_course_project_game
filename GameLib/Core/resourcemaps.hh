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

// building cottage
const Course::ResourceMap COTTAGE_BUILD_COST = {

};
const Course::ResourceMap COTTAGE_PRODUCTION = {

};

// building fishinghut
const Course::ResourceMap FISHINGHUT_BUILD_COST = {

};
const Course::ResourceMap FISHINGHUT_PRODUCTION = {

};

// building mine
const Course::ResourceMap MINE_BUILD_COST = {

};
const Course::ResourceMap MINE_PRODUCTION = {

};

// Worker - Miner
const Course::ResourceMapDouble MINER_WORKER_EFFICIENCY = {

};

const Course::ResourceMap MINER_RECRUITMENT_COST = {

};

// Worker - Fisher
const Course::ResourceMapDouble FISHER_WORKER_EFFICIENCY = {

};

const Course::ResourceMap FISHER_RECRUITMENT_COST = {

};

// Worker - Timberjack
const Course::ResourceMapDouble TIMBERJACK_WORKER_EFFICIENCY = {

};

const Course::ResourceMap TIMBERJACK_RECRUITMENT_COST = {

};

}
}



#endif // RESOURCEMAPS_HH
