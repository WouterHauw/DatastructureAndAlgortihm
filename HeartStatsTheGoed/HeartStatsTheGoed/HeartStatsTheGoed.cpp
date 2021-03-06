#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

class CopNPCFiniteStateMachine;
using namespace std;

enum string_code
{
	getRich,
	spotCop,
	bankAlarm,
	getBroke,
	getTired,
	feelSafe
};

class NPCFiniteStateMachine
{
	class NPCState *current;
public:
	NPCFiniteStateMachine();
	void setCurrent(NPCState *s)
	{
		current = s;
	}
	int wealth, distanceCop, strength,alarm;
	

	void update(CopNPCFiniteStateMachine* c);
	void getRich();
	void spotCop();
	void bankAlarm();
	void getBroke();
	void getTired();
	void feelSafe();
};
class CopNPCFiniteStateMachine
{
	class CopState *current;
public:
	CopNPCFiniteStateMachine();
	void setCurrent(CopState *s)
	{
		current = s;
	}
	CopState* getCurrent(CopState *s)
	{
		return current;
	}
	int dutyTime;

	void update(NPCFiniteStateMachine *m);
	void getToWork();
	void getOffDuty();
	void getChasing();
	void catchNPC();
};

class NPCState
{
public:
	virtual ~NPCState() = default;
	virtual void update(NPCFiniteStateMachine *m, CopNPCFiniteStateMachine* c)
	{
		
	}
	virtual void getRich(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
	virtual void spotCop(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
	virtual void bankAlarm(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
	virtual void getBroke(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
	virtual void getTired(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
	virtual void feelSafe(NPCFiniteStateMachine *m)
	{
		cout << "cant do\n";
	}
};
class CopState
{
public:
	virtual ~CopState() = default;
	virtual void update(CopNPCFiniteStateMachine *c,NPCFiniteStateMachine *m)
	{

	}

	virtual void getToWork(CopNPCFiniteStateMachine *c)
	{
		cout << "cant do GET TO WORK\n";
	}
	virtual void getOffDuty(CopNPCFiniteStateMachine *c)
	{
		cout << "cant do GET OFF DUTY\n";
	}
	virtual void getChasing(CopNPCFiniteStateMachine *c)
	{
		cout << "cant do GET CHASING\n";
	}
	virtual void cathedNPC(CopNPCFiniteStateMachine *c)
	{
		cout << "cant do CATCHED NPC\n";
	}
};

void NPCFiniteStateMachine::update(CopNPCFiniteStateMachine* c)
{
	current->update(this,c);
}

void NPCFiniteStateMachine::getRich()
{
	current->getRich(this);
}

void NPCFiniteStateMachine::spotCop()
{
	current->spotCop(this);
}

void NPCFiniteStateMachine::bankAlarm()
{
	current->bankAlarm(this);
}

void NPCFiniteStateMachine::getBroke()
{
	current->getBroke(this);
}

void NPCFiniteStateMachine::getTired()
{
	current->getTired(this);
}

void NPCFiniteStateMachine::feelSafe()
{
	current->feelSafe(this);
}

void CopNPCFiniteStateMachine::update(NPCFiniteStateMachine *m)
{
	current->update(this, m);
}

void CopNPCFiniteStateMachine::getToWork()
{
	current->getToWork(this);
}

void CopNPCFiniteStateMachine::getOffDuty()
{
	current->getOffDuty(this);
}

void CopNPCFiniteStateMachine::getChasing()
{
	current->getChasing(this);
}

void CopNPCFiniteStateMachine::catchNPC()
{
	current->cathedNPC(this);
}


class RobbingBank : public NPCState
{
public:
	RobbingBank()
	{
		cout << "i am robbing a bank! pew pew!\n";
	};
	void getRich(NPCFiniteStateMachine *m) override;
	void spotCop(NPCFiniteStateMachine *m) override;
	void bankAlarm(NPCFiniteStateMachine *m) override;
	void update(NPCFiniteStateMachine *m, CopNPCFiniteStateMachine* c) override;
};

class HavingGoodTime : public NPCState
{
public:
	HavingGoodTime()
	{
		cout << "Having good time spending a lot of money\n ";
	};
	void getBroke(NPCFiniteStateMachine *m) override;
	void getTired(NPCFiniteStateMachine *m) override;
	void spotCop(NPCFiniteStateMachine *m) override;
	void update(NPCFiniteStateMachine *m, CopNPCFiniteStateMachine* c) override;
};

class LayingLow : public NPCState
{
public:
	LayingLow()
	{
		cout << "Laying low for while\n ";
	};
	void feelSafe(NPCFiniteStateMachine *m) override;
	void update(NPCFiniteStateMachine *m, CopNPCFiniteStateMachine* c) override;
};

class Fleeing : public NPCState
{
public:
	Fleeing()
	{
		cout << "Fleeing for the cops\n ";
	};
	void feelSafe(NPCFiniteStateMachine *m) override;
	void getTired(NPCFiniteStateMachine *m) override;
	void update(NPCFiniteStateMachine *m, CopNPCFiniteStateMachine* c) override;
};

class OffDuty : public CopState
{
public:
	OffDuty()
	{
		cout << "Cop is offduty\n ";
	}
	void update(CopNPCFiniteStateMachine *c, NPCFiniteStateMachine *m) override;
	void getToWork(CopNPCFiniteStateMachine *c) override;
};
class OnStakeOut : public CopState
{
public:
	OnStakeOut()
	{
		cout << "Cop is on stake out\n ";
	}
	void update(CopNPCFiniteStateMachine *c, NPCFiniteStateMachine *m) override;
	void getOffDuty(CopNPCFiniteStateMachine *c) override;
	void getChasing(CopNPCFiniteStateMachine *c) override;
};
class Chasing: public CopState
{
public:
	Chasing()
	{
		cout << "Cop is on chasing\n ";	
	}
	void update(CopNPCFiniteStateMachine *c, NPCFiniteStateMachine *m) override;
	void getOffDuty(CopNPCFiniteStateMachine *c) override;
	void cathedNPC(CopNPCFiniteStateMachine *c) override;
	void getToWork(CopNPCFiniteStateMachine *c) override;
};
class CaughtNPC: public CopState
{
public:
	CaughtNPC()
	{
		exit(0);
	}
};

//transitions robbing bank
void RobbingBank::getRich(NPCFiniteStateMachine *m)
{
	cout << "Im rich enough to have a good time \n";
	m->setCurrent(new HavingGoodTime());
	delete this;
}

void RobbingBank::spotCop(NPCFiniteStateMachine* m)
{
	cout << "Shit, I see a cop!\n";
	m->setCurrent(new Fleeing());
	delete this;
}

void RobbingBank::bankAlarm(NPCFiniteStateMachine* m)
{
	cout << "tuuuuuuuuuuuuuuuuuuuuuuuuuuuhhhhhh, shit bank alarm!\n";
	m->setCurrent(new Fleeing());
	delete this;
}

void RobbingBank::update(NPCFiniteStateMachine* m, CopNPCFiniteStateMachine* c)
{
	//setting values
	m->wealth++;
	if(m->strength >= 0)
	{
		m->strength--;
	}

	if(m->wealth >= 6)
	{
		m->getRich();
		m->alarm = 1;
		return;
	}
	if(m->distanceCop <= 2)
	{
		m->spotCop();
		m->alarm = 1;
		return;
	}
	if (m->alarm == 0)
	{
		m->bankAlarm();
		m->alarm = 1;
	}

	/*cout << " wealth: " << m->wealth << endl;
	cout << " strength: " << m->strength << endl;
	cout << " distance: " << m->distanceCop << endl;
	cout << " alarm: " << m->alarm << endl;
	cout << endl;*/
}

//transitions having a good time
void HavingGoodTime::getBroke(NPCFiniteStateMachine *m)
{
	cout << "Im have no more money!\n";
	m->setCurrent(new RobbingBank());
	delete this;
}

void HavingGoodTime::getTired(NPCFiniteStateMachine* m)
{
	cout << "pfffff, i am tired!\n";
	m->setCurrent(new LayingLow());
	delete this;
}

void HavingGoodTime::spotCop(NPCFiniteStateMachine* m)
{
	cout << "Shit, I see a cop!\n";
	m->setCurrent(new Fleeing());
	delete this;
}

void HavingGoodTime::update(NPCFiniteStateMachine* m, CopNPCFiniteStateMachine* c)
{
	
		m->wealth--;
	
	
		m->strength--;
	

	/*cout << " wealth: " << m->wealth << endl;
	cout << " strength: " << m->strength << endl;
	cout << " distance: " << m->distanceCop << endl;
	cout << " alarm: " << m->alarm << endl;
	cout << endl;*/

	//checking value
	if (m->wealth <= 2)
	{
		m->getBroke();
		return;
	}
	if(m->strength <=2)
	{
		m->getTired();
		return;
	}
	if (m->distanceCop <= 2)
	{
		m->spotCop();
	}
	
}

//transitions laying low
void LayingLow::feelSafe(NPCFiniteStateMachine* m)
{
	cout << "Finally safe, lets rob a bank!\n";
	m->setCurrent(new RobbingBank());
	delete this;
}

void LayingLow::update(NPCFiniteStateMachine* m, CopNPCFiniteStateMachine* c)
{
	m->strength++;

	/*cout << " wealth: " << m->wealth << endl;
	cout << " strength: " << m->strength << endl;
	cout << " distance: " << m->distanceCop << endl;
	cout << " alarm: " << m->alarm << endl;
	cout << endl;*/

	//checking value
	if (m->distanceCop >= 1 && m->strength >= 5)
	{
		m->feelSafe();
	}
	
}

//transitions fleeing 
void Fleeing::feelSafe(NPCFiniteStateMachine* m)
{
	cout << "Run out the cops, get back to robbing!\n";
	m->setCurrent(new RobbingBank());
	delete this;
}

void Fleeing::getTired(NPCFiniteStateMachine* m)
{
	cout << "pfffff, i got tired from fleeing\n";
	m->setCurrent(new LayingLow());
	delete this;
}

void Fleeing::update(NPCFiniteStateMachine* m, CopNPCFiniteStateMachine* c)
{
	if (m->wealth > 0)
	{
		m->wealth--;
	}
	m->strength--;

	/*cout << " wealth: " << m->wealth << endl;
	cout << " strength: " << m->strength << endl;
	cout << " distance: " << m->distanceCop << endl;
	cout << " alarm: " << m->alarm << endl;
	cout << endl;*/

	//checking value
	if (m->strength <= 2)
	{
		m->getTired();
		return;
	}
	if (m->distanceCop > 2 )
	{
		m->feelSafe();
	}
	
}

void OffDuty::update(CopNPCFiniteStateMachine* c, NPCFiniteStateMachine* m)
{
	if(c->dutyTime > 0)
	{
		c->dutyTime--;
	}
	/*cout << "DutyTime:" << c->dutyTime << endl;*/
	if(c-> dutyTime == 0)
	{
		c->getToWork();
	}
}

void OffDuty::getToWork(CopNPCFiniteStateMachine* c)
{
	cout << "Lets get to work! \n";
	c->setCurrent(new OnStakeOut);
	delete this;
}

void OnStakeOut::update(CopNPCFiniteStateMachine* c, NPCFiniteStateMachine* m)
{
	c->dutyTime++;
	auto dist = rand() % 6;
	m->distanceCop = dist;
	auto num = rand() % 6;
	m->alarm = num;
	/*cout << "DutyTime:" << c->dutyTime << endl;
	cout << "DistanceToCop:" << m->distanceCop << endl;*/
	if(c->dutyTime>8)
	{
		c->getOffDuty();
		return;
	}
	if (m->alarm == 0)
	{
		m->distanceCop = 2;
		c->getChasing();
		return;
	}
	if(m->distanceCop <= 2)
	{
		c->getChasing();
	}
}

void OnStakeOut::getOffDuty(CopNPCFiniteStateMachine* c)
{
	cout << "Lets go to my sofa, to see the walking dead! \n";
	c->setCurrent(new OffDuty);
	delete this;
}

void OnStakeOut::getChasing(CopNPCFiniteStateMachine* c)
{
	cout << "Hold it right there buddy! \n";
	c->setCurrent(new Chasing);
	delete this;
}

void Chasing::update(CopNPCFiniteStateMachine* c, NPCFiniteStateMachine* m)
{
	c->dutyTime++;
	m->distanceCop = m->distanceCop - 1;
	int num = rand()%3;
	m->distanceCop = m->distanceCop + num;
	if (c->dutyTime>8)
	{
		c->getOffDuty();
		m->distanceCop = 0;
		return;
	}
	if(m->distanceCop > 2 ||m->strength <= 2)
	{
		c->getToWork();
	}
	if(m->distanceCop == 0)
	{
		c->catchNPC();
	}
}

void Chasing::getOffDuty(CopNPCFiniteStateMachine* c)
{
	cout << "Tired off chasing, lets find my sofa! \n";
	c->setCurrent(new OffDuty);
	delete this;
}

void Chasing::cathedNPC(CopNPCFiniteStateMachine *c)
{
	cout << "I got you bad guy, this is your last day robbing! \n";
	c->setCurrent(new CaughtNPC);
	delete this;
}

void Chasing::getToWork(CopNPCFiniteStateMachine* c)
{
	cout << "We lost him, lets go back to work! \n";
	c->setCurrent(new OnStakeOut);
	delete this;
}


NPCFiniteStateMachine::NPCFiniteStateMachine()
{
	current = new RobbingBank();
	wealth = 2;
	strength = 10;
	distanceCop = 3;
	alarm = 2;
	cout << '\n';
}
CopNPCFiniteStateMachine::CopNPCFiniteStateMachine()
{
	current = new OffDuty();
	dutyTime = 0;

	cout << '\n';
}
string_code hashit(std::string const& inputString)
{
	if (inputString == "getrich") return getRich;
	if (inputString == "spotcop") return spotCop;
	if (inputString == "bankalarm") return bankAlarm;
	if (inputString == "getbroke") return getBroke;
	if (inputString == "gettired") return getTired;
	if (inputString == "feelsafe") return feelSafe;
}

int main()
{
	NPCFiniteStateMachine fsm;
	CopNPCFiniteStateMachine copfsm;
	string num;
	std::chrono::seconds interval(10);
	while (1)
	{
		copfsm.update(&fsm);
		fsm.update(&copfsm);
		std::this_thread::sleep_for(interval);
	}
	
	/*while (1)
	{
		cout << "Enter action, possible command getrich, spotcop, bankalarm, getbroke,gettired, feelsafe: ";
		getline(cin, num);
		switch (hashit(num))
		{
		case getRich: fsm.getRich();
			break;
		case spotCop: fsm.spotCop();
			break;
		case bankAlarm: fsm.bankAlarm();
			break;
		case getBroke: fsm.getBroke();
			break;
		case getTired: fsm.getTired();
			break;
		case feelSafe: fsm.feelSafe();
			break;
		}

	}*/
}
