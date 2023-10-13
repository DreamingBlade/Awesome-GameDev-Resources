#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Hex {
  int x, y;
  bool blocked;
  
  void setHex(int x, int y, bool blocked)
  {
	  this->x = x;
	  this->y = y;
	  this->blocked = blocked;
  }
  Hex(){ 
	  x = 0;
          y = 0;
          blocked = false;
  };
};

struct Cat : public IAgent {
	
	std::pair<int,int> move(const std::vector<bool>& world, std::pair<int,int> catPos, int sideSize ) override
	{
		int xMove = 2;
		int yMove = 2;
		
		std::vector<Hex> grid;

		int minSide;
        int maxSide;

		if (sideSize % 2 == 0)
		{
          minSide = (-sideSize / 2) - 1;
                  maxSide = sideSize / 2;
		}
		else
		{
                  minSide = -sideSize / 2;
                  maxSide = sideSize / 2;
		}

		int dataPull = 0;
		for (int i = minSide; i < maxSide; i++)
		{
                
					for (int j = minSide; j < maxSide; j++)
					{
                    Hex aHex;
                    aHex.setHex(i, j, world.at(dataPull));
                    grid.push_back(aHex);
                    dataPull++;
					}
		}


		
		return {xMove,yMove}; // todo: change this
	}
};
#endif