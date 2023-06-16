#ifndef WORLDDATA_HPP
#define WORLDDATA_HPP

class Player;
class WorldController;

class Database
{
    public:
        explicit Database(
                Player* m_pPlayer,
                WorldController* m_pWorldController
        );
        ~Database();
        void LoadBlocks();
        void InsertBlock();
        void LoadWorld(Database &world);
        void SaveWorld(Database &world);

    private:

        Player* m_pPlayer;
        WorldController* m_pWorldController;

};



#endif //WORLDDATA_HPP
