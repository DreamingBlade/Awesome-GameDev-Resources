#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Hex {
  int x, y;
  bool blocked;
  bool rightShifted;
  bool weight;
  
  void setHex(int x, int y, bool blocked, bool shifted)
  {
	  this->x = x;
	  this->y = y;
	  this->blocked = blocked;
      this->rightShifted = shifted;
  }
  Hex(){ 
	  x = 0;
          y = 0;
          blocked = false;
          rightShifted = false;
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

		Hex catHex;

		//Figuring out how wide and tall the grid is with its negative to positive form.
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

		//Getting the positions into an easily understandable format.
		int dataPull = 0;
        bool shift = false;
		for (int i = minSide; i < maxSide; i++)
		{
				for (int j = minSide; j < maxSide; j++)
				{
                    Hex aHex;
					if (i % 2 != 0)
					{
						bool shift = true;
                    } 
					else
					{
						shift = false;
                    }
                    aHex.setHex(i, j, world.at(dataPull), shift);
                    
					if (i == catPos.first && j == catPos.second)
					{
                        aHex.weight = 1000;
						catHex = aHex;
                        grid.push_back(aHex);
                    }
					else
					{
                        grid.push_back(aHex);
                    }
                    dataPull++;
				}
		}
		
		Hex currentHex = catHex;
        currentHex.weight = 0;
		//Checking adjecent tiles.
		bool exitFound = false;
		while (!exitFound)
		{
			for (int i = 0; i < grid.size(); i++)
			{
				int tileX = grid.at(i).x;
				int tileY = grid.at(i).y;

				if (!currentHex.rightShifted)
				{
					if (currentHex.x - 1 == tileX && currentHex.y - 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x == tileX && currentHex.y - 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x - 1 == tileX && currentHex.y == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x + 1 == tileX && currentHex.y == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x - 1 == tileX && currentHex.y + 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x == tileX && currentHex.y + 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
				}
				else
				{
					if (currentHex.x == tileX && currentHex.y - 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x + 1 == tileX && currentHex.y - 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x - 1 == tileX && currentHex.y == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x + 1 == tileX && currentHex.y == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x == tileX && currentHex.y + 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
					if (currentHex.x + 1 == tileX && currentHex.y + 1 == tileY)
					{
						if (grid.at(i).weight == 0)
						{
							if (grid.at(i).blocked)
							{
								grid.at(i).weight = 1000;
							}
							else
							{
								grid.at(i).weight = currentHex.weight + 1;
							}
						}
					}
				}


			}
		}
		
		return {xMove,yMove}; // todo: change this
	}
};
#endif