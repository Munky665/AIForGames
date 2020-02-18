#pragma once
#include <glm/glm.hpp>
#include <Renderer2D.h>
#include <vector>
#include "DNode.h"

class Rect;
class PatrolBehaviour;
class SearchBehaviour;
class SeekBehaviour;
class SearchBox;
class Player;

enum RoomId
{
	ROOMONE,
	ROOMTWO,
	ROOMTHREE,
	ROOMFOUR,
	ROOMFIVE,
	ROOMSIX,
	ROOMSEVEN
};

class Agent
{
public:
	Agent(RoomId id, MapLoader* map, Player* p);
	~Agent();
	void Update(float dT, MapLoader* map);
	void Draw(aie::Renderer2D* r);

	void colliderUpdate();

	//getters
	glm::vec2 GetPosition();
	float GetSpeed();
	int GetRoomNumber();
	DNode* GetNodeTree();
	Node* GetTarget();
	std::vector<SearchBox*> GetSearchBoxes();
	int GetSearchTime();
	bool GetPathEnd();
	//setters
	void SetPosition(glm::vec2 p);
	void SetSprite();
	void SetRotation(float r);
	void SetVelocity(glm::vec2 v);
	void setCurrentNode(std::list<const Node *>::iterator n);
	void AtPathEnd(bool p);
	

private:
	glm::vec2 m_position;
	glm::vec2 m_velocity;

	DNode* m_decisionTree;
	Condition* m_reachedNode;
	aie::Texture* m_sprite;

	Rect* m_collider;

	float m_speed;
	float m_maxSpeed;
	float m_rotation = 0;
	bool  m_triggeredCollider = false;

	bool m_pathEnd = false;

	int m_roomNumber = 0;
	float m_searchTimer;

	std::vector<SearchBox*> m_searchBoxes;

    Node* m_target;
	const Node* m_currentNode;
	PatrolBehaviour* m_patrol;
	SearchBehaviour* m_search;
};

