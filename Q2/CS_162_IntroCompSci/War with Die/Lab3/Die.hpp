#ifndef DIE_HPP
#define DIE_HPP

class Die {
protected: 
	int numSides;
public: 
	Die(int);
	int roll(); 
};

class LoadedDie : public Die {
public:
	LoadedDie(int);
	int roll();
};

#endif