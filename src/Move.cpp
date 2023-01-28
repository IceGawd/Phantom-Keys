#include "Move.hpp"

Move::Move(bool p, float d) : physical(p), damage(d), mana(0) {

}

Move::Move(bool p, float d, int m) : physical(p), damage(d), mana(m) {

}