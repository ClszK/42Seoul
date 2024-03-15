#include "Weapon.hpp"

Weapon::Weapon(std::string type) : mType(type) {}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const { return mType; }

void Weapon::setType(const std::string& type) { mType = type; }