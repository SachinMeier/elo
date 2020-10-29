#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <random>
#include <iostream>

class Player {
  public:
	Player();
	Player(int, double);

	void setElo(int);
	void setK(double);

	int getElo()const;
	double getK() const;
	void print() const;

	bool versus(Player&);
	bool playMatch(Player&);

  private:
	int elo;
	double k;
	double expectedScore(int);
	void updateElo(int, int);
};

using namespace std;

#endif