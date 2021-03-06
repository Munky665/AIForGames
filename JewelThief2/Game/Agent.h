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

class Agent
{
public:
	Agent(int room, MapLoader* map, Player* p);
	~Agent();
	void Update(float dT, MapLoader* map, Player* p);
	void Draw(aie::Renderer2D* r);

	void colliderUpdate();

	//getters
	glm::vec2 GetPosition();
	float GetSpeed();
	int GetRoomNumber();
	Node* GetTarget();
	std::vector<SearchBox*>& GetSearchBoxes();
	float GetSearchTime();
	bool GetPathEnd();
	bool GetChase();
	const Node* GetCurrentNode();
	bool GetCaptured();

	//setters
	void SetPosition(glm::vec2 p);
	void SetSprite();
	void SetVelocity(glm::vec2 v);
	void setCurrentNode(std::list<const Node *>::iterator n);
	void AtPathEnd(bool p);
	void SetChase(bool c);

private:
	glm::vec2 m_position;
	glm::vec2 m_velocity;

	Condition* m_reachedNode;
	aie::Texture* m_sprite;

	Rect* m_collider;

	float m_speed;
	float m_maxSpeed;
	bool  m_triggeredCollider = false;

	bool m_pathEnd = false;
	bool m_chase = false;
	bool m_captured = false;

	int m_roomNumber;
	float m_searchTimer;
	int m_currentRoom;
	std::vector<SearchBox*> m_searchBoxes;

    Node* m_target;
	const Node* m_currentNode;

	PatrolBehaviour* m_patrol;
	SearchBehaviour* m_search;
	SeekBehaviour* m_seek;
};

