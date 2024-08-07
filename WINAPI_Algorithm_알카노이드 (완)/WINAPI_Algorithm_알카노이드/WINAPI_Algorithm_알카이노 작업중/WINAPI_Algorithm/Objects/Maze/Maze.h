#pragma once
#include "Block.h"

class Block;

#define MAXCOUNT_X 25
#define MAXCOUNT_Y 25

class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze(); // 미로 길 만들기 
	Block::BlockType GetBlockType(int x, int y);

	void SetPlayerPos(Vector2 pos);

private:
	vector<vector<shared_ptr<Block>>> _blocks;

};

