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
    {Course::BasicResource::MONEY, -100},
    {Course::BasicResource::FOOD, -50},
    {Course::BasicResource::WOOD, -75},
};
const Course::ResourceMap COTTAGE_PRODUCTION = {
    {Course::BasicResource::MONEY, 20},
    {Course::BasicResource::FOOD, 15},
};

// building fishinghut
const Course::ResourceMap FISHINGHUT_BUILD_COST = {
    {Course::BasicResource::MONEY, -75},
    {Course::BasicResource::FOOD, -30},
    {Course::BasicResource::WOOD, -25},
    {Course::BasicResource::STONE, -15},
    {Course::BasicResource::ORE, -10},
};
const Course::ResourceMap FISHINGHUT_PRODUCTION = {
    {Course::BasicResource::MONEY, 10},
    {Course::BasicResource::FOOD, 20},
    {Course::BasicResource::STONE, 5},
};

// building mine
const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::MONEY, -100},
    {Course::BasicResource::FOOD, -30},
    {Course::BasicResource::WOOD, -10},
    {Course::BasicResource::STONE, -10},

};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, 20},
    {Course::BasicResource::STONE, 45},
    {Course::BasicResource::ORE, 25},
};

// Worker - basicWorker
const Course::ResourceMapDouble BW_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 1.00},
    {Course::BasicResource::FOOD, 0.75},
    {Course::BasicResource::WOOD, 0.50},
    {Course::BasicResource::STONE, 0.25},
    {Course::BasicResource::ORE, 0.00},
};

const Course::ResourceMap BW_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -25},
    {Course::BasicResource::FOOD, -15},
};


// Worker - Miner
const Course::ResourceMapDouble MINER_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 0.50},
    {Course::BasicResource::FOOD, 0.25},
    {Course::BasicResource::WOOD, 0.50},
    {Course::BasicResource::STONE, 2.50},
    {Course::BasicResource::ORE, 1.50},
};

const Course::ResourceMap MINER_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -25},
    {Course::BasicResource::FOOD, -15},
};

// Worker - Fisher
const Course::ResourceMapDouble FISHER_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 1.00},
    {Course::BasicResource::FOOD, 3.00},
    {Course::BasicResource::WOOD, 0.75},
    {Course::BasicResource::STONE, 0.25},
    {Course::BasicResource::ORE, 0.25},
};

const Course::ResourceMap FISHER_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -30},
    {Course::BasicResource::FOOD, -10},
};

// Worker - Timberjack
const Course::ResourceMapDouble TIMBERJACK_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 0.50},
    {Course::BasicResource::FOOD, 1.00},
    {Course::BasicResource::WOOD, 2.50},
    {Course::BasicResource::STONE, 0.75},
    {Course::BasicResource::ORE, 0.50},
};

const Course::ResourceMap TIMBERJACK_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -20},
    {Course::BasicResource::FOOD, -15},
};

} // namespace ConstResourceMap
} // namespace Game



#endif // RESOURCEMAPS_HH
