#include "Camel.h"


Camel::Camel(Color c, int num1, int num2)
{
	colour = c;
	symbol = 'C';
	row = num1;
	column = num2;
	occupied = 1;
	cout << row;
	cout << column;
}

Camel::Camel() {}

bool Camel::capture(Board& b1, Move& m1, Move& m2)
{
	if (m1.colour != m2.colour)
	{
		if (legalsquarestomove(b1, m1, m2))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Camel::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{
	if (rookmove(b1, m1, m2) || lshapemove(b1, m1, m2))
		return true;
	else
		return false;


}
bool Camel::lshapemove(Board& b1, Move& m1, Move& m2)
{

	if (m1.row + 1 == m2.row && m1.column - 2 == m2.column ||
		m1.row + 1 == m2.row && m1.column + 2 == m2.column ||
		m1.row - 1 == m2.row && m1.column - 2 == m2.column ||
		m1.row - 1 == m2.row && m1.column + 2 == m2.column ||
		m1.row + 2 == m2.row && m1.column - 1 == m2.column ||
		m1.row + 2 == m2.row && m1.column + 1 == m2.column ||
		m1.row - 2 == m2.row && m1.column - 1 == m2.column ||
		m1.row - 2 == m2.row && m1.column + 1 == m2.column)
		return true;
	else
		return false;

}
bool Camel::rookmove(Board& b1, Move& m1, Move& m2)
{
	bool chose;


	if (m1.row == m2.row || m1.column == m2.column)
	{
		chose = 1;
		if (m1.row == m2.row)
			chose = verticalfree(b1, m1, m2);
		else
			chose = horizontalfree(b1, m1, m2);

	}
	else
		chose = 0;

	return chose;

}

bool Camel::verticalfree(Board& b1, Move& m1, Move& m2)
{

	int greater, lesser;
	if (m1.row == m2.row)
	{
		if (m1.column > m2.column)
		{
			greater = m1.column;
			lesser = m2.column;
		}
		else
		{
			lesser = m1.column;
			greater = m2.column;

		}
		for (int i = lesser + 1; i < greater; i++)
		{
			if (b1.boardptr[m1.row][i] != nullptr)
				return false;
		}
		return true;
	}
}
bool Camel::horizontalfree(Board& b1, Move& m1, Move& m2)
{
	int greater, lesser;
	if (m1.column == m2.column)
	{
		if (m1.row > m2.row)
		{
			greater = m1.row;
			lesser = m2.row;
		}
		else
		{
			lesser = m1.row;
			greater = m2.row;

		}
		for (int i = lesser + 1; i < greater; i++)
		{

			if (b1.boardptr[i][m1.column] != nullptr)
				return false;
		}
		return true;
	}
}
