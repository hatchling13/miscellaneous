#include <stdio.h>
#include <stdlib.h>

typedef struct Customer
{
	int o_arr[3]; // Order Array, 각 음료 별로 잔 수를 저장하는 변수
	int o_cnt; // Order Count, 음료의 총 잔 수를 저장하는 변수

	struct Customer *pNext;
} CUSTOMER;

typedef struct CList
{
	int iSize;

	CUSTOMER *pHead;
} CLIST;

void InitList(CLIST *);
int MakeNode(CLIST *);
void DeleteNode(CLIST *);
CUSTOMER *GetNode(CLIST *, int);
CUSTOMER *LastNode(CLIST *); // 마지막 노드를 반환하는 함수

int main()
{
	int td_flag; // To Do Flag, 종업원의 할 일을 저장하는 변수
	int m_flag; // Menu Flag, 커피 메뉴를 저장하는 변수
	int c_bev = 0; // Count Beverage, 음료 총 개수를 저장하는 변수
	int c_num = 0; // Customer Number, 고객 번호를 저장하는 변수
	int n_temp = 0; // (Customer) Number Temporary Variable, 임시 고객 번호를 저장하는 변수
	int p_sum = 0; // Price Sum, 가격의 합을 저장하는 변수
	int i, flag = 0;
	
	CLIST myList = {0, NULL};
	CUSTOMER *Temp;

	InitList(&myList);

	printf("~ 슽아벅스 종업원의 하루 ~\n");
	
	while(!flag)
	{
		printf("***********************\n");
		printf("1. 주문 받기\n");
		printf("2. 내어 주기\n");
		printf("0. 가게 닫기\n");
		printf("***********************\n");
		printf("할 일을 선택하시오 : ");

		scanf("%d", &td_flag);

		switch (td_flag)
		{
		case 1:
			if (!MakeNode(&myList)) printf("손님 안 받아욧!\n");

			else
			{
				printf("***********************\n");
				printf("1. 아메리카노 : 3,000 원\n");
				printf("2. 카페라떼  : 3,500 원\n");
				printf("3. 카푸치노  : 3,500 원\n");
				printf("0. 주문 그만 받기\n");
				printf("***********************\n");
				printf("주문 받을 커피를 선택하시오 : ");

				Temp = LastNode(&myList);
				
				for (i = 0; i < 3; i++)
				{
					Temp->o_arr[i] = 0;
				}

				Temp->o_cnt = 0;
				m_flag = 1;

				while(m_flag)
				{
					scanf("%d", &m_flag);

					switch (m_flag)
					{
					case 1:
						Temp->o_arr[0]++;
						p_sum += 3000;
						printf("아메리카노 한 잔 추가요~\n");
						break;
					case 2:
						Temp->o_arr[1]++;
						p_sum += 3500;
						printf("카페라떼 한 잔 추가요~\n");
						break;
					case 3:
						Temp->o_arr[2]++;
						p_sum += 3500;
						printf("카푸치노 한 잔 추가요~\n");
						break;
					case 0:
						printf("주문 끝났어요~\n");
						break;
					default:
						printf("그런 메뉴 없어양!");
						break;
					}

					if (0 < m_flag && m_flag < 4)
					{
							Temp->o_cnt++;
							printf("계속 골라주세요~ : ");
					}
				}

				printf("고갱님 주문 내역 확인하겠습니다~\n");

				for (i = 0; i < 3; i++)
				{
					if (Temp->o_arr[i] != 0)
					{
						if (i == 0)
							printf("아메리카노 %d 잔\n", Temp->o_arr[i]);
						else if (i == 1)
							printf("카페라떼 %d 잔\n", Temp->o_arr[i]);
						else if (i == 2)
							printf("카푸치노 %d 잔\n", Temp->o_arr[i]);
					}				
				}

				printf("이며, 결제금액은 %d 원 입니당~\n", p_sum);
			
				c_num++;
			}
			break;

		case 2:
			for (i = 1; i <= c_num; i++)
			{
				c_bev = GetNode(&myList, i)->o_cnt;

				printf("%d 번 고갱님~ 주문하신 음료 %d 잔 나왔습니다~\n", i, c_bev);
			}
			break;

		case 0:
			printf("가게 셔터 내립니다 !!!!!!\n");
			flag = !flag;
			break;
		}

		p_sum = 0;
	}
	return 0;
}

void InitList(CLIST *list)
{
	list->iSize = 0;
	list->pHead = NULL;
}

int MakeNode(CLIST *list)
{
	CUSTOMER *Temp;
	int result = 0;

	if (list->iSize == 0)
	{
		list->pHead = (CUSTOMER *)malloc((unsigned int)sizeof(CUSTOMER));
		list->pHead->pNext = NULL;

		Temp = list->pHead;
	}
	else
	{
		Temp = LastNode(list);
		Temp->pNext = (CUSTOMER *)malloc((unsigned int)sizeof(CUSTOMER));
		list->iSize++;
	}

	if (!Temp->pNext)
	{
		printf("Node made\n");
		result = !result;
	}
	else printf("Node not made\n");

	return result;
}

void DeleteNode(CLIST *list)
{
	CUSTOMER *Temp;

	while (list->iSize != 0)
	{
		Temp = LastNode(list);
		free(Temp);
		Temp = NULL;

		printf("Node deleted\n");
	}
}

CUSTOMER *GetNode(CLIST *list, int index)
{
	CUSTOMER *Temp = list->pHead;
	int i = 1;

	if (list->iSize == 1) return Temp;
	else
	{
		while (i < index)
		{
			Temp = Temp->pNext;
			i++;
		}

		return Temp;
	}
}

CUSTOMER *LastNode(CLIST *list)
{
	CUSTOMER *Temp = list->pHead;

	if (list->iSize == 1) return Temp;
	else
	{
		while(Temp->pNext != NULL) Temp = Temp->pNext;
		return Temp;
	}
}