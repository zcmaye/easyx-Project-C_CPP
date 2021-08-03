#include "rollback.h"

Rollback::Rollback(Map<>& map,Gamer&gamer)
	:map(map),gamer(gamer)
{
}
void Rollback::rollBack()
{
	if (s.empty())
		return;
	State temp = s.top();
	for (int i = 0; i < 3; i++)
	{
		map.getCurMap()[temp.pos[i].r][temp.pos[i].c] = temp.pos[i].data;
	}
	s.pop();
}

void Rollback::saveState(char key)
{
	int r = gamer.row();
	int c = gamer.col();
	State a;
	switch (key)
	{
	case 72:
		for (int i = 0, k = 0; i < 3; i++)
		{
			a.pos[i].r = r - k;
			a.pos[i].c = c;
			a.pos[i].data = map.getCurMap()[a.pos[i].r][a.pos[i].c];
			k++;
		}
		s.push(a);
		break;
	case 80:
		for (int i = 0, k = 0; i < 3; i++)
		{
			a.pos[i].r = r + k;
			a.pos[i].c = c;
			a.pos[i].data = map.getCurMap()[a.pos[i].r][a.pos[i].c];
			k++;
		}
		s.push(a);
		break;
	case 75:
		for (int i = 0, k = 0; i < 3; i++)
		{
			a.pos[i].r = r;
			a.pos[i].c = c - k;
			a.pos[i].data = map.getCurMap()[a.pos[i].r][a.pos[i].c];
			k++;
		}
		s.push(a);
		break;
	case 77:
		for (int i = 0, k = 0; i < 3; i++)
		{
			a.pos[i].r = r;
			a.pos[i].c = c + k;
			a.pos[i].data = map.getCurMap()[a.pos[i].r][a.pos[i].c];
			k++;
		}
		s.push(a);
		break;
	}
}

void Rollback::clear()
{
	while (!s.empty())
	{
		s.pop();
	}
}
