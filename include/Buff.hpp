#pragma once

#include <math.h>
#include <iostream>

#include "BuffType.hpp"

using namespace std;

struct Buff {
	int level = 0;
	double actuallevel = 0;
	int max_level = 0;
	double actualmaxlevel = 0;
	int turns = 0;
	double actualturns = 0;

	BuffType bufftype;
	const static int MAXLEVEL = 4;
	const static int MAXTURNS = 5;

	Buff(int l, int t, BuffType b);
	Buff(const Buff &t);
	void infoUpdate();
	void changeBuff(Buff b, double (*op)(double, double));
	void merge(Buff b);
	void remove(Buff b);
	void effect(Fightable character);
	void turnOver(Fightable f);
};

double Add(double a, double b);
double Subtract(double a, double b);
