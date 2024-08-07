#include "pch.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
{
	_maze = maze;
}

Player::~Player()
{
	_maze = nullptr;
}

void Player::BeginPlay()
{
	_maze->SetPlayerPos(_pos); 
	RightHand();
}

void Player::RightHand()
{
	// 실습 ? 
	// 우수법을 이용해서 미로를 끝점까지 가면 된다,
	// 찾은 길은 _path에다 넣는다
	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,

		DIR_COUNT = 4
	};

	Vector2 pos = _pos;
	_path.push_back(pos);
	Vector2 endPos = Vector2(23, 23);

	Direction dir = Direction::BOTTOM;

	Vector2 frontpos[4] =
	{
		Vector2{0,-1}, // UP
		Vector2{-1,0},//  LEFT
		Vector2{0,1}, // BOTTOM
		Vector2{1,0}, // RIGHT

	};

	while (true)
	{
		if (pos == endPos)
			break;

		// % 알고리즘에서 순환구조에서 많이 쓰인다.
		int newDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontpos[dir];
		Vector2 newDirVector2 = frontpos[newDir];

		Vector2 newPos = pos + newDirVector2; // 내 오른쪽 방향 
		Vector2 oldPos = pos + oldDirVector2; // 내 앞방향

		// 오른쪽으로 갈 수 있으면 방향을 바꾸고 오른쪽으로 진행
		if (cango(newPos._y,newPos._x)) // 오른쪽 가다 오른쪽 비어있음 회전하는 코드 
		{
			dir = static_cast<Direction>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// 오른쪽이 막혀있고 옆쪽으로 갈 수 있으면 방향 그대로 앞으로 진행
		else if (cango(oldPos._y, oldPos._x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}
		// 오른쪽, 앞 둘다 막혀있을 떄 왼쪽으로 회전
		else
		{
			dir = static_cast<Direction>((dir + 1 + DIR_COUNT) % DIR_COUNT);
		}
		
	}


}

bool Player::cango(int x, int y)
{
	Block::BlockType blockType = _maze->GetBlockType(y, x);
	if (blockType == Block::BlockType::ABLE)
	{
		return true;
	}

	return false;
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_path.clear();
		
		return;
	}

	_time += 0.1f; // 움직이는 속도 
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			// 발자취
			_maze->SetPlayerPos(_pos);

		}

		_pathIndex++;

	}
}
