/*
 * 7_1.cpp
 *
 *  Created on: 2013-4-30
 *      Author: beet
 */

struct Card
{
	enum CardColor
	{
		// general
		SPADE, HEART, CLUB, DIAMOND,
		// special, for Jokers
		RED, BLACK
	};

	enum CardNumber
	{
		JOKER = 0,
		A, TWO, THREE, FORE, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K
	};

	CardColor color;
	CardNumber number;
};

const int CARDS_NUMBER = 54;

class CardGame
{
	Card cards[CARDS_NUMBER];

	void init();
	void shuffle();
	void play();
	//...
};
