#include "Move.hpp"

Move::Move(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, bool tet, int h) : ap(a), name(n), physical(p), damage(d), mana(m), selectEnemy(se), tags(t), targetEnemyTeam(tet), hits(h) {

}

void Move::dealDamage(Fightable attacker, Fightable defender) {

}