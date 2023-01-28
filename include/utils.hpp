#pragma once

#include <random>
#include <vector>

using namespace std;

float random();
float rand(float std, float m);
float invNorm(float x);
float RationalApproximation(float t);

template <typename T>
float weighted(vector<T> levels);

template <typename T>
float average(vector<T> levels);

float quadratic(float a, float b, float c);
float increase(float initial, float percent);

enum Tag {
	PIERCING, 
	BLUDGEONING, 
	SLASHING, 
	UPWARD, 
	FORWARD, 
};