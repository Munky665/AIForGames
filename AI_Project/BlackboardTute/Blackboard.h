#pragma once
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
	BlackBoard();
	~BlackBoard();

	std::unordered_map<std::string, ItemType> m_data;

	void set(std::string s, int a);
	bool get(std::string v, int& out);
	
	bool hasEntry(std::string id);
	
	bool contains(std::string v);
	bool getType(std::string v);


};

