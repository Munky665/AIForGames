#include <iostream>
#include "Blackboard.h"

int main()
{
	BlackBoard bb;
	
	bb.set("Pi", 3);

	int v; 
	if (bb.get("Pi", v))
	{
		std::cout << v << std::endl;
	}
	else
		std::cout << "Pi Not Found" << std::endl;

	//if (bb.m_data.find("Pi") != bb.m_data.end())
	//{
	//	switch (bb.m_data["Pi"].type)
	//	{
	//	case ItemTypes::type_float:
	//		std::cout << bb.m_data["Pi"].float_val << std::endl;
	//		break;
	//	case ItemTypes::type_char:
	//		std::cout << "Not float" << std::endl;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	return 0;
}