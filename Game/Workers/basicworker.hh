#ifndef BASICWORKER_HH
#define BASICWORKER_HH

#include "workers/basicworker.h"
#include "Core/resourcemaps.hh"
#include "tiles/tilebase.h"

namespace Game {

/**
 * @brief The BasicWorker class represents a "normal worker" in the game.
 *
 * Worker has following production-efficiency: \n
 * * Money - 1.00 \n
 * * Food - 0.75 \n
 * * Wood - 0.50 \n
 * * Stone - 0.25 \n
 * * Ore - 0.25 \n
 *
 * BasicWorkers consume Food and money. \n
 * * 1 Food - Or BasicWorker refuses to work. \n
 * * 1 Money - Or BasicWorker works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the worker is refusing work.
 */

class basicWorker : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    basicWorker() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    basicWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    ConstResourceMap::BW_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    ConstResourceMap::BW_WORKER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~basicWorker() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the worker can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the worker.
     * @param target is the Tile that worker is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for worker.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived worker.
     * @post Exception guarantee: Basic
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @brief Performs the Worker's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns Worker's efficiency at resource production.
     * Worker consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on WORKER_EFFICIENCY.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;


}; // class basicWorker

} // namespace Game


#endif // BASICWORKER_HH
