#include<stdio.h>
#include<string.h>
#include<Windows.h>


/*
1. ȸ������
2. �α���
3. �α׾ƿ�
4. ������ ���
5. ����

1 - ȸ������ ��
���̵�, �н�����, ��ġ�� �Է¹ް� ���� �ڵ�����(4�ڸ�)

2 - �α��� ��
���̵�, �н����� �Է¹���

2 - �α��� ��
1. �Ա�
2. ���
3. ���� ��ü
4. �Ա� Ȯ��
5. ��� Ȯ��
6. ����

4 - �����ڸ�� ��
������ ���̵� �� ��й�ȣ �Է�

4 - �����ڸ�� ��
1. ȸ�� ��ü Ȯ��
2. ȸ�� �˻� Ȯ��
3. ȸ�� ����
4. ȸ�� ����
5. ���� ����(ȸ�� 1 : ���� N)
6. ���� ����

5 - ���� ��
ȸ�� ������ �����־����
*/

void firstmessage() {
	printf("���� ó�� �����ϴ� ������ �����ڰ����Դϴ�\n");
	printf("---------------------------------------------\n");
	printf("1.ȸ������\n");
	printf("2.�α���\n");
	printf("3.�����ڸ��\n");
}
int secondmessage(int a) {
	printf("***************************\n");
	printf("�ŷ����ɾ�:-2147483648 ~ 2147483647(int��)\n\n");
	printf("1.������ȸ\n");
	printf("2.�Ա�\n");
	printf("3.���\n");
	printf("4.������ü\n");
	printf("5.ȸ��Ż��\n");
	printf("0.����\n");
	scanf_s("%d", &a, sizeof(a));
	return a;
}
void Thirdmessage() {
	printf("�����ڸ��\n");
	printf("1.������� ��ȸ\n");
	printf("2.�����˻�\n");
	printf("3.��������\n");
	printf("0.����\n");
}
/*void mkAClist() {
	FILE *ac;
	ac = fopen("AClist1.txt", "w+");
	for (int i = 0; i < 10; i++) {
		printf("0%d",i);
		for (int j = 0; j < 10; j++) {
			printf("%d",j);
			for (int k = 0; k < 10; k++) {
				printf("%d\n", k);
			}
		}
	}
	fclose(ac);
}*/

int mkID(int a) {
	char ID[7],IDCF[7], PASSWD[5], PASSCF[5], ACCOUNT[7];
	int linecount=0;

	FILE *in;
	in = fopen("IDlist.txt", "r");
	while (!feof(in)) {						//line count
		fgets(IDCF, sizeof(IDCF), in);
		IDCF[sizeof(IDCF)-2] = '\0';
		linecount++;
	}
	fclose(in);

	printf("���̵�(����+���� 5�ڸ�):");
	scanf_s("%s", ID, sizeof(ID));
	while (getchar() != '\n');

	a = strcmp(ID, IDCF);
	if (a == 0) {
		printf("�̹� �����ϴ� �����Դϴ�\nó������ �������ּ���!\n\n");
		return 0;
	}

	printf("\n�н�����(4�ڸ�):");
	scanf_s("%s", PASSWD, sizeof(PASSWD));
	while (getchar() != '\n');
	printf("\n�н�����Ȯ��:");
	scanf_s("%s", PASSCF, sizeof(PASSCF));
	a = strcmp(PASSWD, PASSCF);


	if (a == 0) {
		FILE *in, *inp, *ac,*money;
		in = fopen("IDlist.txt", "a");
		inp = fopen("PWlist.txt", "a");
		ac = fopen("AClist.txt", "r");
		money = fopen("money.txt", "a");

		fprintf(in, "%s\n", ID);
		fprintf(inp, "%s\n", PASSWD);
		fprintf(money, "0\n");

		fclose(in);
		fclose(inp);
		fclose(money);
		printf("ID: %s�� ȸ������ �Ǿ����ϴ�\n", ID);
		
		a = 2;
		for (int i = 0; i < linecount; i++) {
			fgets(ACCOUNT, sizeof(ACCOUNT), ac);
			ACCOUNT[sizeof(ACCOUNT) - 2] = '\0';
		}
		
		printf("���¹�ȣ: %s\n", ACCOUNT);
		printf("���� �ܾ�: 0\n");
		fclose(ac);
		return a;
	}
	else {
		return 0;
	}
	return 0;
}
int login(int a) {
	char ID[6], ch;
	char FIND[7];
	int count = 1;
	printf("ID : ");
	scanf_s("%s", ID, sizeof(ID));
	getchar();
	FILE *in;
	
	in = fopen("IDlist.txt", "r");
	
	while (!feof(in)) {

		fgets(FIND, sizeof(FIND), in);
		FIND[sizeof(FIND) - 2] = '\0';
		a = strcmp(ID, FIND);   // �Էµ� ID ���ؼ� ȸ�����Ե� ��� ã��
		
		if (a == 0) {
			fclose(in);
			return count;
		}
		else if (a!=0) {		
			count++;			// line ���پ� conut
		}
		else {}
	}
	fclose(in);
	printf("\a���̵� ���� �ʽ��ϴ�\n");
	return 0;
	
}
int passwd(int a) {
	int pwdcf,b;
	char PASSWD[6], ch;
	char FIND[6];
	printf("PASSWORD : ");

	scanf_s("%s", PASSWD, sizeof(PASSWD));
	getchar();

	FILE *in;
	in = fopen("PWlist.txt", "r");

	while (!feof(in)) {
		for (int i = 0; i < a; i++) {
			fgets(FIND, sizeof(FIND), in);
			FIND[sizeof(FIND) - 2] = '\0';
		}
		a = strcmp(PASSWD, FIND);   // �Էµ� PASSWD ���ؼ� ��� ��� ã��
		if (a == 0) {
			fclose(in);
			a = 100;
			return a;
		}
		else if (a != 0) {
			a = 99;
			fclose(in);
			printf("\a �ߺ�!��й�ȣ ����!");
			return a;
		}
		else {}
	}
	fclose(in);
	return a;
}
int JoHoae(int a) {
	char ACCOUNT[7];
	FILE *ac;
	ac = fopen("AClist.txt", "r");
	for (int i = 0; i < a; i++) {
		fgets(ACCOUNT, sizeof(ACCOUNT), ac);
		ACCOUNT[sizeof(ACCOUNT) - 2] = '\0';
	}
	printf("���¹�ȣ: %s\n", ACCOUNT);
	fclose(ac);
	return a;
}
int Scancash() {
	int cash;
	scanf_s("%d", &cash,sizeof(cash));
	return cash;
}
int Cash(int a) {
	int cash;
	FILE *cs;
	cs = fopen("money.txt", "r");
	for (int i = 0; i < a; i++) {
		fscanf_s(cs, "%d", &cash, sizeof(cash));
	}
	printf("�ܾ� : %d\n", cash);
	fclose(cs);
	return a;

}
int turn(int a) {
	int money = 0, count = 0, b = 0;
	char j[7];
	FILE *cs, *cstemp, *usercount;
	usercount = fopen("IDlist.txt", "r+");
	cs = fopen("money.txt", "r+");
	cstemp = fopen("ACtemp.txt", "a");
	while (fscanf_s(usercount, "%s", j, sizeof(j)) != EOF) {
		count++;													//user �� ������� total count
		
	}
	
	for (int i = 0; i < a; i++) {
		fscanf_s(cs, "%d", &money, sizeof(money));
	}
	fprintf(cstemp, "\n");
	b = count - a;
	for (int i=0; i <b; i++) {										//�α����� user���� total count ���� 
		fscanf_s(cs, "%d", &money, sizeof(money));					//moneylist�� ���
		fprintf(cstemp, "%d\n", money);
	}
	fclose(cs);
	fclose(cstemp);
	fclose(usercount);
	return a;
}
int reAC(int a) {
	int cash = 0,count=0;
	char j[7];
	FILE *cs, *cstemp,*usercount;
	usercount = fopen("IDlist.txt", "r+");
	cs = fopen("money.txt", "w+");
	cstemp = fopen("ACtemp.txt", "r+");

	while (fscanf_s(usercount, "%s", j, sizeof(j)) != EOF) {
		count++;													//user �� ������� total count
	}
	for (int i = 0; i < count; i++) {
		fscanf_s(cstemp, "%d", &cash, sizeof(cash));
		fprintf(cs, "%d\n", cash);
	}
	fclose(usercount);
	fclose(cs);
	fclose(cstemp);


	return a;

}
int Incash(int a,int Oncash) {
	int cash = 0, maxuser = 0,b=0;
	FILE *cs, *cstemp;

	cs = fopen("money.txt", "r+");
	cstemp = fopen("ACtemp.txt", "w+");

	for (int i = 0; i < a - 1; i++) {					//a �������� line�� temp���Ͽ� ����
		fscanf_s(cs, "%d", &cash, sizeof(cash));
		fprintf(cstemp, "%d\n", cash);
	}
	fscanf_s(cs, "%d", &cash, sizeof(cash));

	b = cash + Oncash;
	getchar();
	fprintf(cstemp, "%d", b);					//a line�� �Է¹޾� money�� ����� temp ���Ͽ� �߰�.
	fclose(cs);
	
	fclose(cstemp);
	a = turn(a);				// a������ line�� temp���Ͽ� �߰�.
	a = reAC(a);				// temp ������ money.txt�� ���󺹱�
	
	return a;
}
int Outcash(int a,int Oncash) {
	
	int cash = 0, b = 0;
	FILE *cs, *cstemp;

	cs = fopen("money.txt", "r+");
	cstemp = fopen("ACtemp.txt", "w+");

	for (int i = 0; i < a - 1; i++) {					//a �������� line�� temp���Ͽ� ����
		fscanf_s(cs, "%d", &cash, sizeof(cash));
		fprintf(cstemp, "%d\n", cash);
	}
	fscanf_s(cs, "%d", &cash, sizeof(cash));
	b = cash - Oncash;
	fprintf(cstemp, "%d", b);					//a line�� �Է¹޾� money�� ����� temp ���Ͽ� �߰�.
	
	fclose(cs);

	fclose(cstemp);
	a = turn(a);				// a������ line�� temp���Ͽ� �߰�.
	a = reAC(a);				// temp ������ money.txt�� ���󺹱�

	return a;
}
int Move(int a) {
	int b,count=0;
	char move[5], movepoint[6];

	printf("�Աݰ���:");
	scanf_s("%s", move,sizeof(move));
	FILE *mv;
	mv = fopen("AClist.txt", "r+");
	while (fscanf_s(mv, "%s", movepoint, sizeof(movepoint)) != EOF) {
		movepoint[sizeof(movepoint) - 1] = '\0';
		b = strcmp(move, movepoint);
		count++;
		if (b == 0) {
			break;
		}
	}
	
	printf("���ð��� : ");
	for (int i = 0; i < 5; i++) {
		printf("%c", move[i]);
	}
	return count;
}
int userturn(int a) {
	int count = 0,b=0;
	char ID[6];
	char j[7];
	FILE *user, *usertemp,*pw;
	user= fopen("IDlist.txt", "r+");
	usertemp = fopen("IDtemp.txt", "a");
	pw = fopen("PWlist.txt", "r+");
	while (fscanf_s(pw, "%s", j, sizeof(j)) != EOF) {
		count++;													//user �� ������� total count
	}

	for (int i = 0; i < a; i++) {
		fscanf_s(user, "%s", ID, sizeof(ID));
	}
	fprintf(usertemp, "\n");
	b = count - a;
	for (int i = 0; i <b; i++) {										//�α����� user���� total count ���� 
		fscanf_s(user, "%s", ID, sizeof(ID));					//userlist�� ���
		fprintf(usertemp, "%s\n", ID);
	}
	fclose(user);
	fclose(usertemp);
	return a;
}
int userAC(int a) {
	int cash = 0, count = 0;
	char ID[6],j[7],point;
	FILE *user, *usertemp,*pw;
	user = fopen("IDlist.txt", "w+");
	usertemp = fopen("IDtemp.txt", "r");
	pw = fopen("PWlist.txt","r");
	while (fscanf_s(pw, "%s", ID, sizeof(ID)) != EOF) {
		count++;													//user �� ������� total count
	}
	
	for (int i = 0; i < count+1; i++) {
		if (i == (a - 1)) {
			fprintf(user, "delet\n");						
		}
		else if (i == a) {
			fprintf(user, "");
		}
		else {
			fscanf_s(usertemp, "%s", ID, sizeof(ID));
			fprintf(user, "%s\n", ID);
		}
	}
	fclose(user);
	fclose(usertemp);
	return a;
}
int Taltwoi(int a) {
	char choice;
	char ID[6];
	printf("���� Ż�� �Ͻðڽ��ϱ�?[1.��/2.�ƴϿ�]\n");
	scanf_s("%c", &choice,sizeof(choice));
	
	if (choice == '2') {
		return a;
	}
	else if (choice == '1') {
		FILE *user, *usertemp;

		user = fopen("IDlist.txt", "r+");
		usertemp = fopen("IDtemp.txt", "w");

		for (int i = 0; i < a - 1; i++) {					//a �������� line�� temp���Ͽ� ����
			fscanf_s(user, "%s", ID, sizeof(ID));
			fprintf(usertemp, "%s\n", ID);
		}
		fscanf_s(user, "%s", &ID, sizeof(ID));
		fclose(user);
		fclose(usertemp);
		a = userturn(a);				// a������ line�� IDtemp���Ͽ� �߰�.
		a = userAC(a);				// temp ������ IDlist.txt�� ���󺹱�
		a = 0;
		return a;
	}
	else {
		return a;
	}
}
int Search(int a) {
	char FIND[7], ID[6];
	int count = 0;

	printf("ID : ");
	scanf_s("%s", ID, sizeof(ID));
	getchar();

	FILE *in;
	in = fopen("IDlist.txt", "r");
	while (!feof(in)) {
		
		fgets(FIND, sizeof(FIND), in);
		FIND[sizeof(FIND) - 2] = '\0';
		a = strcmp(ID, FIND);   // �Էµ� ID ���ؼ� ȸ�����Ե� ��� ã��

		if (a == 0) {
			printf("%s", FIND);
			fclose(in);
			count++;
			return count;
		}
		else if (a != 0) {
			count++;			// line ���پ� conut
		}
		else {}
	}
	printf("ã�� ���̵� �����ϴ�\n");
}

void Alluser() {
	system("cls");
	char read;
	FILE *all;
	all = fopen("IDlist.txt", "r+");
	while (fscanf_s(all, "%c", &read, sizeof(read)) != EOF) {
		printf("%c", read);
	}
	fclose(all);
}


int main() {
	int a=0, b=0, c=0, cash = 0;
	//mkAClist();
	firstmessage();						//ȸ������ , �α���
	scanf_s("%d", &a, sizeof(a));
	getchar();
	if (a == 1) {
		system("cls");
		a = mkID(a);						//ȸ������ ����. IDlist.txt�� PWlist.txt���ٰ� ���̵��� ����.
	}
	if (a == 2) {					//�α��� ����
		a = login(a); // ���̵� �� �� �˻�. a�� line��ȣ.
		b = passwd(a);//line ��ȣ�� �ִ� password�� �о �Էµ� ���� ����.b�� �����ܰ�
	}
	else if (a == 3) {						//�����ڸ��
		a = login(a);
		b = passwd(a);
		if (a != 1) {
			printf("�����ڰ� �ƴմϴ�\n");
			return 0;
		}
		while (b != 0) {
			if (b == 100 && a == 1) {
				Thirdmessage();
				scanf_s("%d", &b, sizeof(b));
				if (b == 1) {
					Alluser();
					b = 100;
				}
				if (b == 2) {
					system("cls");
					a=Search(a);
					printf("\n�˻����� : %d line\n", a);
					b = 100;
					a = 1;
				}
				if (b == 3) {
					printf("������ ����:");
					a = Search(a);
					printf("���ΰ�:%d\n", a);
					a= Taltwoi(a);
					b = 100;
					a = 1;
				}
			}
		}
			return 0;
		
	}
	else {}

	if (b == 100) {						//�α��� ����. 
		while (b != 0) {			//����� 0��

			b = secondmessage(a); //1��ȸ, 2�Ա�, 3���, 4��ü, 5ȸ��Ż��

			if (b == 1) {
				system("cls");
				JoHoae(a);
				Cash(a);
			}
			else if (b == 2) {
				system("cls");
				printf("�Աݱݾ�:");
				cash = Scancash();
				Incash(a, cash);
				printf("\n�ԱݵǾ����ϴ�\n");
				Cash(a);
			}
			else if (b == 3) {
				system("cls");
				printf("��ݱݾ�:");
				cash = Scancash();
				Outcash(a, cash);
				printf("\n��ݵǾ����ϴ�\n");
				Cash(a);
			}
			else if (b == 4) {
				system("cls");
				c = Move(a);
				printf("\n��ü�ݾ�");
				cash = Scancash();
				Incash(c, cash);
				Outcash(a, cash);
				printf("\n��ü�Ǿ����ϴ�\n");
				Cash(a);
			}
			else if (b == 5) {
				c = passwd(a);
				a = Taltwoi(a);
				b = 0;
			}
			
			else { return 0; }
		}
		
		

	}
	else {}

	return 0;

}
