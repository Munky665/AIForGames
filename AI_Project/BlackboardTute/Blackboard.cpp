#include "Blackboard.h"



BlackBoard::BlackBoard()
{
}


BlackBoard::~BlackBoard()
{
}
void BlackBoard::set(std::string s, int a)
{
	m_data[s].type = ItemTypes::type_int;
	m_data[s].int_val = a;

}

bool BlackBoard::get(std::string v, int& out)
{
	auto f = m_data.find(v);
	if (f != m_data.end() && f->second.type == ItemTypes::type_int)
	{
		out = m_data[v].int_val;
		return true;
	}
	return false;
}