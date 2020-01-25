#include <iostream>
#include <string>
#include <unordered_map>

enum ItemTypes {
	type_float,
	type_int,
	type_bool,
	type_char,
	type_ptr
};

struct ItemType
{
	ItemTypes type;
	union 
	{
		float float_val;
		int int_val;
		bool bool_val;
		char char_val;
		void* ptr_val;
	};
};

class BlackBoard {
public:
	
	std::unordered_map<std::string, ItemType> m_data;

	void set(std::string s, int a)
	{
		m_data[s].type = ItemTypes::type_int;
		m_data[s].int_val = a;

	}

	bool get(std::string v, int& out)
	{
		auto f = m_data.find(v);
		if (f != m_data.end() && f->second.type == ItemTypes::type_int)
		{
			out = m_data[v].int_val;
			return true;
		}
		return false;
	}
};

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