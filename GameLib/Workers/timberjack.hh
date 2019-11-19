#ifndef TIMBERJACK_HH
#define TIMBERJACK_HH

#include "workers/workerbase.h"
#include "Core/resourcemaps.hh"


namespace Game {

/**
 * @brief The Timberjack class represents a timberjack in the game.
 *
 * timberjack has following production-efficiency: \n
 * * Money - 0 \n
 * * Food - 0 \n
 * * Wood - 0 \n
 * * Stone - 0 \n
 * * Ore - 0 \n
 *
 * Timberjack consume Food and money. \n
 * * 1 Food - Or Timberjack refuses to work. \n
 * * 1 Money - Or Timberjack works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the timberjack is refusing work.
 */
class Timberjack : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Timberjack() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    Timberjack(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
          const std::shared_ptr<Course::iObjectManager>& objectmanager,
          const std::shared_ptr<Course::PlayerBase>& owner,
          const int& tilespaces = 1,
          const Course::ResourceMap& cost =
             ConstResourceMap::TIMBERJACK_RECRUITMENT_COST,
          const Course::ResourceMapDouble& efficiency =
              ConstResourceMap::TIMBERJACK_WORKER_EFFICIENCY
          );

    /**
     * @brief Default destructor.
     */
    virtual ~Timberjack() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the timberjack can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the timberjack.
     * @param target is the Tile that timberjack is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for timberjack.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived timberjack.
     * @post Exception guarantee: Basic
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @brief Performs the miner's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns timberjack's efficiency at resource production.
     * Timberjack consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on TIMBERJACK_EFFICIENCY.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:

}; // class Timberjack

} // namespace Game


#endif // TIMBERJACK_HH
