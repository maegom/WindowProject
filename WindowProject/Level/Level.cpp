#include "Level.h"
#include "../Object/Bullet.h"
#include "../Object/GuidedBullet.h"
#include "../GameManager.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	// 레벨이 제거될때 레벨이 가지고 있는 모든 오브젝트를 제거한다.
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));
	}
}

CObject* CLevel::FindObject(const char* Name)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		// strcmp : 두 문자열을 비교하여 같을 경우 0을 반환한다.
		if (strcmp((*iter)->GetName(), Name) == 0)
		{
			return *iter;
		}
	}

	return nullptr;
}

void CLevel::Init()
{
}

void CLevel::Input(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Input(DeltaTime);
		++iter;
	}
}

void CLevel::Update(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Update(DeltaTime);
		++iter;
	}
}

void CLevel::Collision(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();
	--iterEnd;

	for (iter = mObjList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetActive())
		{
			// 메모리 주소를 이용해서 할당된 객체를 제거한다.
			delete* iter;

			// erase 함수는 지운 노드의 다음 노드를 반환한다.
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		Vector2D	Pos = (*iter)->GetPos();
		Vector2D	Size = (*iter)->GetSize();

		std::list<CObject*>::iterator	iter1 = iter;
		++iter1;
		std::list<CObject*>::iterator	iter1End = mObjList.end();

		for (; iter1 != iter1End; ++iter1)
		{
			Vector2D	Pos1 = (*iter1)->GetPos();
			Vector2D	Size1 = (*iter1)->GetSize();

			Resolution	RS = CGameManager::GetInst()->GetResolution();

			size_t	TypeID1 = (*iter)->GetTypeID();
			size_t	TypeID2 = (*iter1)->GetTypeID();

			// 서로 충돌이 일어났는지 판단한다.
			if (Pos.x <= Pos1.x + Size1.x && Pos.x + Size.x >= Pos1.x &&
				Pos.y <= Pos1.y + Size1.y && Pos.y + Size.y >= Pos1.y)
			{
				(*iter)->Collision((*iter1));
				(*iter1)->Collision((*iter));
			}
		}

		++iter;
	}

	//for (iter = mObjList.begin(); iter != iterEnd; )
	//{
	//	if (!(*iter)->GetActive())
	//	{
	//		// 메모리 주소를 이용해서 할당된 객체를 제거한다.
	//		delete* iter;

	//		// erase 함수는 지운 노드의 다음 노드를 반환한다.
	//		iter = mObjList.erase(iter);
	//		iterEnd = mObjList.end();

	//		continue;
	//	}

	//	(*iter)->Collision(DeltaTime);
	//	++iter;
	//}
}
void CLevel::Render(HDC hDC)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Render(hDC);
		++iter;
	}
}
