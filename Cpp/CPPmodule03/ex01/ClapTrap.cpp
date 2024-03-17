#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("default"), health_(10), energy_(10), damage_(0) {
  std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), health_(10), energy_(10), damage_(0) {
  std::cout << "ClapTrap Constructor called with " << name << "." << std::endl;
  std::cout << "Health : " << health_ << std::endl
            << "Energy : " << energy_ << std::endl
            << "Damage : " << damage_ << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, unsigned int health,
                   unsigned int energy, unsigned int damage)
    : name_(name), health_(health), energy_(energy), damage_(damage) {
  std::cout << "ClapTrap Constructor called with " << name << ". " << std::endl;
  std::cout << "Health : " << health_ << std::endl
            << "Energy : " << energy_ << std::endl
            << "Damage : " << damage_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  std::cout << "ClapTrap Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap Copy assignment operator called" << std::endl;

  if (this != &other) {
    name_ = other.name_;
    health_ = other.health_;
    energy_ = other.energy_;
    damage_ = other.damage_;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << " call destructor" << std::endl;
}

const std::string& ClapTrap::getName(void) const { return name_; }

unsigned int ClapTrap::getHealth(void) const { return health_; }

unsigned int ClapTrap::getEnergy(void) const { return energy_; }

unsigned int ClapTrap::getDamage(void) const { return damage_; }

void ClapTrap::attack(const std::string& target) {
  if (energy_ > 0 && health_ > 0) {
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
              << damage_ << " points of damage!" << std::endl;
    --energy_;
  } else
    std::cout << "ClapTrap " << name_ << " don't have energy or health."
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (health_ == 0) {
    std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
    return;
  }

  (health_ < amount) ? health_ = 0 : health_ -= amount;

  std::cout << "ClapTrap " << name_ << " take a damage of " << amount << ". ";
  if (health_ == 0)
    std::cout << name_ << " is dead." << std::endl;
  else
    std::cout << "Health left " << health_ << "." << std::endl;
}

void ClapTrap::beReparied(unsigned int amount) {
  if (health_ == 0) {
    std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
    return;
  }

  if (energy_ > 0) {
    health_ += amount;
    std::cout << "ClapTrap " << name_ << " repair " << amount << ". " << health_
              << " points of health!" << std::endl;
    --energy_;
  } else
    std::cout << "ClapTrap " << name_ << " don't have energy." << std::endl;
}