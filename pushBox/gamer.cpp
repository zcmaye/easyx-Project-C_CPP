#include "gamer.h"

Gamer::Gamer(Map<>& map)
	:m_map(&map),m_row(-1),m_col(-1),m_dir(-1)
{

}

void Gamer::updatePos()
{
	for (int i = 0; i < m_map->row(); i++)
	{
		for (int k = 0; k < m_map->col(); k++)
		{
			if (m_map->getCurMap()[i][k] == PLAYER || m_map->getCurMap()[i][k] == PLAYER + DEST)
			{
				m_row = i;
				m_col = k;
				return;
			}
		}
	}
}

void Gamer::move(char key)
{
	m_dir = key;
	int (*map)[10] =  m_map->getCurMap();
	updatePos();
	switch (key)
	{
	case 72:
		//玩家的前面是空地
		if (map[m_row - 1][m_col] == SPACE || map[m_row - 1][m_col] == DEST)
		{
			map[m_row - 1][m_col] += PLAYER;
			map[m_row][m_col] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[m_row - 1][m_col] == BOX || map[m_row - 1][m_col] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[m_row - 2][m_col] == SPACE || map[m_row - 2][m_col] == DEST)
			{
				map[m_row - 2][m_col] += BOX;
				map[m_row - 1][m_col] += (-BOX + PLAYER);
				map[m_row][m_col] -= PLAYER;
			}
		}
		break;
	case 80:
		//玩家的前面是空地
		if (map[m_row + 1][m_col] == SPACE || map[m_row + 1][m_col] == DEST)
		{
			map[m_row + 1][m_col] += PLAYER;
			map[m_row][m_col] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[m_row + 1][m_col] == BOX || map[m_row + 1][m_col] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[m_row + 2][m_col] == SPACE || map[m_row + 2][m_col] == DEST)
			{
				map[m_row + 2][m_col] += BOX;
				map[m_row + 1][m_col] += (-BOX + PLAYER);
				map[m_row][m_col] -= PLAYER;
			}
		}
		break;
	case 75:
		//玩家的前面是空地
		if (map[m_row][m_col - 1] == SPACE || map[m_row][m_col - 1] == DEST)
		{
			map[m_row][m_col - 1] += PLAYER;
			map[m_row][m_col] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[m_row][m_col - 1] == BOX || map[m_row][m_col - 1] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[m_row][m_col - 2] == SPACE || map[m_row][m_col - 2] == DEST)
			{
				map[m_row][m_col - 2] += BOX;
				map[m_row][m_col - 1] += (-BOX + PLAYER);
				map[m_row][m_col] -= PLAYER;
			}
		}
		break;
	case 77:
		
		//玩家的前面是空地
		if (map[m_row][m_col + 1] == SPACE || map[m_row][m_col + 1] == DEST)
		{
			printf("right\n");
			map[m_row][m_col + 1] += PLAYER;
			map[m_row][m_col] -= PLAYER;
		}
		//玩家前面是箱子
		else if (map[m_row][m_col + 1] == BOX || map[m_row][m_col + 1] == BOX + DEST)
		{
			//箱子前面是空地
			if (map[m_row][m_col + 2] == SPACE || map[m_row][m_col + 2] == DEST)
			{
				map[m_row][m_col + 2] += BOX;
				map[m_row][m_col + 1] += (-BOX + PLAYER);
				map[m_row][m_col] -= PLAYER;
			}
		}
		break;
	}
}

int Gamer::row()const
{
	return m_row;
}

int Gamer::col()const
{
	return m_col;
}

char Gamer::dir() const
{
	return m_dir;
}
