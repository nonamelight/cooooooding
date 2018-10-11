#include<stdio.h>
#include<string.h>
#include<Windows.h>


/*
1. 회원가입
2. 로그인
3. 로그아웃
4. 관리자 모드
5. 종료

1 - 회원가입 시
아이디, 패스워드, 예치금 입력받고 계좌 자동생성(4자리)

2 - 로그인 시
아이디, 패스워드 입력받음

2 - 로그인 후
1. 입금
2. 출금
3. 계좌 이체
4. 입금 확인
5. 출금 확인
6. 종료

4 - 관리자모드 시
관리자 아이디 및 비밀번호 입력

4 - 관리자모드 후
1. 회원 전체 확인
2. 회원 검색 확인
3. 회원 생성
4. 회원 삭제
5. 계좌 생성(회원 1 : 계좌 N)
6. 계좌 삭제

5 - 종료 후
회원 데이터 남아있어야함
*/

void firstmessage() {
	printf("제일 처음 가입하는 계정이 관리자계정입니다\n");
	printf("---------------------------------------------\n");
	printf("1.회원가입\n");
	printf("2.로그인\n");
	printf("3.관리자모드\n");
}
int secondmessage(int a) {
	printf("***************************\n");
	printf("거래가능액:-2147483648 ~ 2147483647(int형)\n\n");
	printf("1.계좌조회\n");
	printf("2.입금\n");
	printf("3.출금\n");
	printf("4.계좌이체\n");
	printf("5.회원탈퇴\n");
	printf("0.종료\n");
	scanf_s("%d", &a, sizeof(a));
	return a;
}
void Thirdmessage() {
	printf("관리자모드\n");
	printf("1.모든유저 조회\n");
	printf("2.유저검색\n");
	printf("3.유저삭제\n");
	printf("0.종료\n");
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

	printf("아이디(영문+숫자 5자리):");
	scanf_s("%s", ID, sizeof(ID));
	while (getchar() != '\n');

	a = strcmp(ID, IDCF);
	if (a == 0) {
		printf("이미 존재하는 계정입니다\n처음부터 진행해주세요!\n\n");
		return 0;
	}

	printf("\n패스워드(4자리):");
	scanf_s("%s", PASSWD, sizeof(PASSWD));
	while (getchar() != '\n');
	printf("\n패스워드확인:");
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
		printf("ID: %s로 회원가입 되었습니다\n", ID);
		
		a = 2;
		for (int i = 0; i < linecount; i++) {
			fgets(ACCOUNT, sizeof(ACCOUNT), ac);
			ACCOUNT[sizeof(ACCOUNT) - 2] = '\0';
		}
		
		printf("계좌번호: %s\n", ACCOUNT);
		printf("계좌 잔액: 0\n");
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
		a = strcmp(ID, FIND);   // 입력된 ID 비교해서 회원가입된 목록 찾기
		
		if (a == 0) {
			fclose(in);
			return count;
		}
		else if (a!=0) {		
			count++;			// line 한줄씩 conut
		}
		else {}
	}
	fclose(in);
	printf("\a아이디가 맞지 않습니다\n");
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
		a = strcmp(PASSWD, FIND);   // 입력된 PASSWD 비교해서 비번 목록 찾기
		if (a == 0) {
			fclose(in);
			a = 100;
			return a;
		}
		else if (a != 0) {
			a = 99;
			fclose(in);
			printf("\a 삐빅!비밀번호 오류!");
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
	printf("계좌번호: %s\n", ACCOUNT);
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
	printf("잔액 : %d\n", cash);
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
		count++;													//user 총 몇명인지 total count
		
	}
	
	for (int i = 0; i < a; i++) {
		fscanf_s(cs, "%d", &money, sizeof(money));
	}
	fprintf(cstemp, "\n");
	b = count - a;
	for (int i=0; i <b; i++) {										//로그인한 user부터 total count 까지 
		fscanf_s(cs, "%d", &money, sizeof(money));					//moneylist를 출력
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
		count++;													//user 총 몇명인지 total count
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

	for (int i = 0; i < a - 1; i++) {					//a 전까지의 line을 temp파일에 복사
		fscanf_s(cs, "%d", &cash, sizeof(cash));
		fprintf(cstemp, "%d\n", cash);
	}
	fscanf_s(cs, "%d", &cash, sizeof(cash));

	b = cash + Oncash;
	getchar();
	fprintf(cstemp, "%d", b);					//a line을 입력받아 money와 계산후 temp 파일에 추가.
	fclose(cs);
	
	fclose(cstemp);
	a = turn(a);				// a이후의 line을 temp파일에 추가.
	a = reAC(a);				// temp 파일을 money.txt에 원상복구
	
	return a;
}
int Outcash(int a,int Oncash) {
	
	int cash = 0, b = 0;
	FILE *cs, *cstemp;

	cs = fopen("money.txt", "r+");
	cstemp = fopen("ACtemp.txt", "w+");

	for (int i = 0; i < a - 1; i++) {					//a 전까지의 line을 temp파일에 복사
		fscanf_s(cs, "%d", &cash, sizeof(cash));
		fprintf(cstemp, "%d\n", cash);
	}
	fscanf_s(cs, "%d", &cash, sizeof(cash));
	b = cash - Oncash;
	fprintf(cstemp, "%d", b);					//a line을 입력받아 money와 계산후 temp 파일에 추가.
	
	fclose(cs);

	fclose(cstemp);
	a = turn(a);				// a이후의 line을 temp파일에 추가.
	a = reAC(a);				// temp 파일을 money.txt에 원상복구

	return a;
}
int Move(int a) {
	int b,count=0;
	char move[5], movepoint[6];

	printf("입금계좌:");
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
	
	printf("선택계좌 : ");
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
		count++;													//user 총 몇명인지 total count
	}

	for (int i = 0; i < a; i++) {
		fscanf_s(user, "%s", ID, sizeof(ID));
	}
	fprintf(usertemp, "\n");
	b = count - a;
	for (int i = 0; i <b; i++) {										//로그인한 user부터 total count 까지 
		fscanf_s(user, "%s", ID, sizeof(ID));					//userlist를 출력
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
		count++;													//user 총 몇명인지 total count
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
	printf("정말 탈퇴 하시겠습니까?[1.예/2.아니오]\n");
	scanf_s("%c", &choice,sizeof(choice));
	
	if (choice == '2') {
		return a;
	}
	else if (choice == '1') {
		FILE *user, *usertemp;

		user = fopen("IDlist.txt", "r+");
		usertemp = fopen("IDtemp.txt", "w");

		for (int i = 0; i < a - 1; i++) {					//a 전까지의 line을 temp파일에 복사
			fscanf_s(user, "%s", ID, sizeof(ID));
			fprintf(usertemp, "%s\n", ID);
		}
		fscanf_s(user, "%s", &ID, sizeof(ID));
		fclose(user);
		fclose(usertemp);
		a = userturn(a);				// a이후의 line을 IDtemp파일에 추가.
		a = userAC(a);				// temp 파일을 IDlist.txt에 원상복구
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
		a = strcmp(ID, FIND);   // 입력된 ID 비교해서 회원가입된 목록 찾기

		if (a == 0) {
			printf("%s", FIND);
			fclose(in);
			count++;
			return count;
		}
		else if (a != 0) {
			count++;			// line 한줄씩 conut
		}
		else {}
	}
	printf("찾는 아이디가 없습니다\n");
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
	firstmessage();						//회원가입 , 로그인
	scanf_s("%d", &a, sizeof(a));
	getchar();
	if (a == 1) {
		system("cls");
		a = mkID(a);						//회원가입 진입. IDlist.txt와 PWlist.txt에다가 아이디비번 저장.
	}
	if (a == 2) {					//로그인 진입
		a = login(a); // 아이디 비교 및 검색. a는 line번호.
		b = passwd(a);//line 번호에 있는 password를 읽어서 입력된 값과 대조.b는 다음단계
	}
	else if (a == 3) {						//관리자모드
		a = login(a);
		b = passwd(a);
		if (a != 1) {
			printf("관리자가 아닙니다\n");
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
					printf("\n검색유저 : %d line\n", a);
					b = 100;
					a = 1;
				}
				if (b == 3) {
					printf("삭제할 유저:");
					a = Search(a);
					printf("라인값:%d\n", a);
					a= Taltwoi(a);
					b = 100;
					a = 1;
				}
			}
		}
			return 0;
		
	}
	else {}

	if (b == 100) {						//로그인 성공. 
		while (b != 0) {			//종료시 0번

			b = secondmessage(a); //1조회, 2입금, 3출금, 4이체, 5회원탈퇴

			if (b == 1) {
				system("cls");
				JoHoae(a);
				Cash(a);
			}
			else if (b == 2) {
				system("cls");
				printf("입금금액:");
				cash = Scancash();
				Incash(a, cash);
				printf("\n입금되었습니다\n");
				Cash(a);
			}
			else if (b == 3) {
				system("cls");
				printf("출금금액:");
				cash = Scancash();
				Outcash(a, cash);
				printf("\n출금되었습니다\n");
				Cash(a);
			}
			else if (b == 4) {
				system("cls");
				c = Move(a);
				printf("\n이체금액");
				cash = Scancash();
				Incash(c, cash);
				Outcash(a, cash);
				printf("\n이체되었습니다\n");
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
