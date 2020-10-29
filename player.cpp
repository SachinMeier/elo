#include "player.h"

Player::Player(){
	this->elo = 1500;
	this->k = 32.0;
}
Player::Player(int newElo, double newK){
	this->elo = newElo;
	this->k = newK;
}
void Player::setElo(int newElo){
	this->elo = newElo;
}
void Player::setK(double newK){
	this->k = newK;
}
int Player::getElo()const{
	return this->elo;
}
double Player::getK() const{
	return this->k;
}
void Player::print() const{
	cout << "Player:\n";
	cout << "ELO: " << elo << endl;
	//cout << "K: " << k << endl;
}

double Player::expectedScore(int otherElo){
	return 1.0 / ( 1.0 + pow(10, double(otherElo - this->elo)/400));
}

void Player::updateElo(double score, int otherElo){
	int delta = this->k * (score - this->expectedScore(otherElo));
	this->elo += delta;
}

bool Player::versus(Player& opponent, double outcome){
	this->updateElo(outcome, opponent.elo);
	opponent.updateElo(abs(1-outcome), this->elo);
	return outcome;
}

bool Player::playMatch(Player& opponent){
	double odds = this->expectedScore(opponent.elo);
	random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(odds);
	int * scores = new int[2];
	scores[0] = d(gen) ? 1 : 0;
	scores[1] = scores[0] ? 0 : 1;
	this->updateElo(scores[0], opponent.elo);
	opponent.updateElo(scores[1], this->elo);
	bool victory = scores[0];
	delete scores;
}