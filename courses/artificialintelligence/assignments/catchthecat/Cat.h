#ifndef CAT_h
#define CAT_h
#include "IAgent.h"

struct Hex {
  int x, y;
  bool blocked;
  bool rightShifted;
  int weight;
  
  void setHex(int x, int y, bool blocked, bool shifted)
  {
	  this->x = x;
	  this->y = y;
	  this->blocked = blocked;
      this->rightShifted = shifted;
	  if (blocked)
	  {
		  this->weight = 9;
	  }
  }
  Hex(){ 
	  x = 0;
          y = 0;
          blocked = false;
          rightShifted = false;
		  weight = 0;
  }
};

struct Cat : public IAgent {
	
	std::pair<int, int> move(const std::vector<bool>& world, std::pair<int, int> catPos, int sideSize) override
	{
		int xMove = 0;
		int yMove = 0;

		std::vector<Hex> grid;

		int minSide;
		int maxSide;

		Hex catHex;

		//Figuring out how wide and tall the grid is with its negative to positive form.
		if (sideSize % 2 == 0)
		{
			minSide = -((sideSize / 2) + 1);
			maxSide = sideSize / 2;
		}
		else
		{
			minSide = -((sideSize / 2));
			maxSide = sideSize / 2;
		}
		//Getting the positions into an easily understandable format.
		int dataPull = 0;
		bool shift = false;
		for (int i = minSide; i <= maxSide; i++)
		{
			for (int j = minSide; j <= maxSide; j++)
			{
				Hex aHex;
				if (i % 2 == 1)
				{
					bool shift = true;
				}
				else
				{
					shift = false;
				}
				aHex.setHex(j, i, world.at(dataPull), shift);

				grid.push_back(aHex);

				dataPull++;
			}
		}
		Hex currentHex = catHex;
		//Checking adjacent tiles.
		bool exitFound = false;
		Hex exit;
		std::vector<Hex> queuedHexes;
		queuedHexes.push_back(currentHex);
		int hexesChecked = 0;
		bool upLeftFound = false;
		bool upRightFound = false;
		bool leftFound = false;
		bool rightFound = false;
		bool downRightFound = false;
		bool downLeftFound = false;
		//Finding the end target for the cat.
		while (queuedHexes.size() > hexesChecked && exitFound == false)
		{
			currentHex = queuedHexes.at(hexesChecked);
			upLeftFound = false;
			upRightFound = false;
			leftFound = false;
			rightFound = false;
			downRightFound = false;
			downLeftFound = false;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						upLeftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						upRightFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						leftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						rightFound = true;
					}
					//Check down left
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						downLeftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						downRightFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						upLeftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						upRightFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						leftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						rightFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						downLeftFound = true;
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
								queuedHexes.push_back(grid.at(i));
							}
						}
						downRightFound = true;
					}
				}
			}
			//Checking if the cat found an escape route
			if (upLeftFound == false)
			{
				exitFound = true;
			}
			else if (upRightFound == false)
			{
				exitFound = true;
			}
			else if (rightFound == false)
			{
				exitFound = true;
			}
			else if (leftFound == false)
			{
				exitFound = true;
			}
			else if (downLeftFound == false)
			{
				exitFound = true;
			}
			else if (downRightFound == false)
			{
				exitFound = true;
			}

			if (exitFound == true)
			{
				exit = currentHex;
			}
			hexesChecked++;
		}

		if (exitFound == false)
		{
			return { catPos.first, catPos.second };
		}

		for (int i = 0; i < queuedHexes.size(); i++)
		{
			if (queuedHexes.at(i).weight == 1 && queuedHexes.at(i).blocked == false)
			{
				return{ queuedHexes.at(i).x, queuedHexes.at(i).y};
			}
		}

		//Sending where the cat should move to.
		return {currentHex.x, currentHex.y}; 
	}
};
#endif