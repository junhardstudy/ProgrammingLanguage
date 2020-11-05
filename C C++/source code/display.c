#include "dataset.h"


void drawTable(int startpoint_y, int endpoint) {
	/*
		�� �Լ��� Ķ���� �������� cmd�� ǥ�����ִ� �Լ��Դϴ�.
		startpoint_y�� Ķ������ ���۵� ��ġ �Դϴ�.
	*/
	int line, column;
	
	drawMenu();

	
	gotoxy(0, startpoint_y);
	for (line = startpoint_y; line < 46 + startpoint_y; line++) {
		printf("|");
		if ((line - startpoint_y) == 0 || (line-startpoint_y) % 9  == 0) {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf("|");
				printf("-");

			}
		}
		else {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf("|");
				printf(" ");

			}

		}
		printf("|\n");
	}
	
}

void drawSquare(int startpoint_y, int endpoint) {
	/*�ӽ÷� §��.... �ڵ� �����ϰ� �� �� �����Ƿ� ���� ���*/
	int line, column;

	drawMenu();


	gotoxy(0, startpoint_y);
	for (line = startpoint_y; line < 10 + startpoint_y; line++) {
		printf("|");
		if ((line - startpoint_y) == 0 || (line - startpoint_y) % 9 == 0) {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf("|");
				printf("-");

			}
		}
		else {
			for (column = 0; column < 139; column++) {
				gotoxy(column + 1, line);
				if ((column + 1) % 20 == 0)printf(" ");
				printf(" ");

			}

		}
		printf("|\n");
	}
}

void drawMenu() {
	//������ ũ��� ����ϵ��� �س�����. ��ġ�� �Űܾ� �Ѵٸ� �ƿ� ���� ¥���ҵ�

	int a;
	gotoxy(0, 0);
	printf("|");

	for (a = 0; a < 39; a++) printf("-");

	printf("|");

	for(a = 0; a<5; a++) printf("-------------------|");

	gotoxy(0, 1);
	printf("|");
	for (a = 0; a < 39; a++) printf(" ");
	printf("|");
	for (a = 0; a < 5; a++) printf("                   |");

	gotoxy(41, 1);
	printf("F1. ���� �Ĵ� ¥��");

	gotoxy(61, 1);
	printf("F2. ��Į�θ� �Ĵ�");

	gotoxy(81, 1);
	printf("F3. ���� �߰�/����");

	gotoxy(101, 1);
	printf("F4. ����/�ҷ�����");

	gotoxy(121, 1);
	printf("F5. �����ϱ�");


}

void drawSubMenu() {
	//������ ũ��� ����ϵ��� �س�����. ��ġ�� �Űܾ� �Ѵٸ� �ƿ� ���� ¥���ҵ�

	int a;
	gotoxy(0, 0);
	printf("|");

	for (a = 0; a < 39; a++) printf("-");

	printf("|");

	for (a = 0; a < 5; a++) printf("-------------------|");

	gotoxy(0, 1);
	printf("|");
	for (a = 0; a < 39; a++) printf(" ");
	printf("|");
	for (a = 0; a < 5; a++) printf("                   |");

	gotoxy(41, 1);
	printf("F1. ���� �Ĵ� ¥��");

	gotoxy(61, 1);
	printf("F2. ���� �˻��ϱ�");

	gotoxy(81, 1);
	printf("F3. ���� �߰�/����");

	gotoxy(101, 1);
	printf("F4. ����/�ҷ�����");

	gotoxy(121, 1);
	printf("F5. �����ϱ�");


}

void drawData(struct meal *p, int *index_right, int *index_left) {
	/*
		This function is purpose for input data which is data, food menu, or otherthings....
		by manipulate each blank as elements in array.

		���� �μ��� ����ü �迭 �����ͷ� �޴°� ���� �� ����ȿ������

	*/
	
	int i, j, k, tmp, end;

	//�̰� �� �׸񺰷� ������ �����Ͱ� �� ���ۺκ���
	//�ٹٲ��Ϸ��� Y��ǥ�� ���� �ٲ������.
	//�μ��� �޴� ����ü ����Ʈ �迭 ������ �ش���� ���� ������ �ɰ� ���⿡ �ݺ����� ���� �ɾ�θ� �ɰŰ���
	//�����Ŵ� main���� ó���ؾ��ҰŰ���
	//gotoxy(2, 45);
	//printf(" index = %d",  *index_right);
	

	*index_left = *index_right;
	
	switch ((p + *index_right)->meal_calendary.month) {
	case 2: {
		if (((p->meal_calendary.year) % 4 == 0) && ((p->meal_calendary.year) % 100 == 0))
			end = 29;
		else if (((p->meal_calendary.year) % 400 == 0))
			end = 29;
		else
			end = 28;
	}
			break;

	case 1: case 3: case 5: case 7: case 8:case 10: case 12: end = 31;
			break;

	default: end = 30;
	}
	
	
	gotoxy(2, 1);
	printf("%d�� �Ĵ�ǥ", (p + *index_right)->meal_calendary.year);
	

	for (i = (p + *index_right)->meal_calendary.day ; i <= end; i++) {
		gotoxy((p + *index_right)->x, (p + *index_right)->y);
		printf("%d�� %d�� ", (p + *index_right)->meal_calendary.month, (p + *index_right)->meal_calendary.day);
		
		for (j = 0; j < (p + *index_right)->meal_num; j++) {
			gotoxy((p + *index_right)->x, (p + *index_right)->y + j + 2);
			printf("%s", (p + *index_right)->meal_menu[j]);
		}
		if ((p + *index_right)->total_calories != 0) {
			gotoxy((p + *index_right)->x, (p + *index_right)->y + j + 3);
			printf("%d(kcal)", (p + *index_right)->total_calories);
		}
		
		(*index_right)++; 
		if (*index_right >= 365) {
			*index_right = 0;
			break;
		}
	}

	gotoxy(1, 49);
	printf("��-----���� �Ĵ� ����");

	gotoxy(121, 49);
	printf("���� �Ĵ� ����-----��");
	
}

void drawData_left(struct meal *p, int *index_right, int *index_left) {
	int i, j;

	if (*index_left == 0) {
		*index_right = 0;
		*index_left = 364;
	}
	else {
		*index_right = *index_left;
		(*index_left)--;
	}

	gotoxy(2, 1);
	printf("%d��", (p + *index_left)->meal_calendary.year);

	
	for (i = (p + *index_left)->meal_calendary.day; ;) {
		gotoxy((p + *index_left)->x, (p + *index_left)->y);
		printf("%d�� %d�� ", (p + *index_left)->meal_calendary.month, (p + *index_left)->meal_calendary.day);
		
		for (j = 0; j < (p + *index_left)->meal_num; j++) {
			gotoxy((p + *index_left)->x, (p + *index_left)->y + j + 2);
			printf("%s", (p + *index_left)->meal_menu[j]);
		}

		if ((p + *index_left)->meal_calendary.day == 1 || *index_left==0) {
			break;
		}

		
		(*index_left)--;
		
		
	}

	gotoxy(1, 49);
	printf("��-----���� �Ĵ� ����");

	gotoxy(121, 49);
	printf("���� �Ĵ� ����-----��");

}








void gotoxy(int x, int y)

{

	COORD Pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}