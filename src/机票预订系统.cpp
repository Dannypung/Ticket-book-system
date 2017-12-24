#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#define N 100//�������� 
#define M 1000//�˿����� 
using namespace std;
class passenger{
private: 
	char ID[20];//���֤��
	char name[20];//����
	char sex[10];//�Ա�
	char phone[20];//�ֻ���
	char card[30];//���п���
	char code[30];//���� 
	int num[20];//���˺����
public:
	passenger(){}
	char* get_ID()                  {return ID;}
	char* get_name()                {return name;}
	char* get_sex()                 {return sex;}
	char* get_phone()               {return phone;}
	char* get_card()                {return card;}
	char* get_code()                {return code;}
	int* get_num()                  {return num;}
	void set_ID(char a[])           {strcpy(ID,a);}
	void set_name(char a[])         {strcpy(name,a);}
	void set_sex(char a[])          {strcpy(sex,a);}
	void set_phone(char a[])        {strcpy(phone,a);}
	void set_card(char a[])         {strcpy(card,a);}
	void set_code(char a[])         {strcpy(code,a);}
	void set_num(int a[])           {for(int k=0;k<20;k++)num[k]=a[k];}
	int login();//��½ 
	void enroll();//ע�� 
	void order();//��Ʊ
    void refund();//��Ʊ
    void check();//�鿴���� 
    ~passenger(){}
};//�˿���

class passenger_manage{
private:
	passenger p[M];//�˿Ͷ������� 
	int i;//�����±� 
public:
	passenger_manage();//�ļ���ȡ 
	int search_p(char a[]);//Ѱ�ҳ˿�,���������±� 
	~passenger_manage();//д���ļ� 
	friend class passenger;
};//�˿���Ϣ������ 

class air{
private:
    int num;//�����
    char start[20];//��ʼվ
    char end[20];//�յ�վ
    char time[30];//ʱ��
    int count;//�涨��Ʊ�� 
    int r_count;//�Ѷ���Ʊ��
public:
	air(){}
	int get_num()                   {return num;}
	char* get_start()               {return start;}
	char* get_end()                 {return end;}
	char* get_time()                {return time;}
	int get_count()                 {return count;}
	int get_r_count()               {return r_count;}
	void set_num(int a)             {num=a;}
	void set_start(char a[])        {strcpy(start,a);}
	void set_end(char a[])          {strcpy(end,a);}
	void set_time(char a[])         {strcpy(time,a);}
	void set_count(int a)           {count=a;}
    void set_r_count(int a)         {r_count=a;}
	void add();//��Ӻ�����Ϣ
	void delet();//ɾ��������Ϣ
    void search();//��ѯ������Ϣ
    void change();//�޸ĺ�����Ϣ 
	~air(){}
};//������ 

class air_manager{
private:
	air a[N];//����������� 
	int i;//�����±� 
public:
	air_manager();//�ļ���ȡ 
	int search_num();//�ú������������,���������±� 
	void delte1(int k);//��������ɾ����ʽ1 
	void delte2();//��������ɾ����ʽ2 
	~air_manager();//д���ļ� 
	friend class air;
	friend void passenger::order();
	friend void passenger::refund();
	friend void passenger::check();
};//������Ϣ������ 

//�������Ա���� 
void air::add(){
	air_manager Air;
	cout << "�����뺽��ţ�"; 	          cin >> num;         Air.a[Air.i].set_num(num);//���뺽��������� 
	cout << endl << "��������ʼվ��";     cin >> start;       Air.a[Air.i].set_start(start);
	cout << endl << "�������յ�վ��";     cin >> end;         Air.a[Air.i].set_end(end);
	cout << endl << "������ʱ�䣺";       cin >> time;        Air.a[Air.i].set_time(time);
	cout << endl << "������涨��Ʊ����"; cin >> count;       Air.a[Air.i].set_count(count);
	Air.a[Air.i].set_r_count(0);//�Ѷ���Ʊ����ʼ��Ϊ0 
	Air.i++;//���������±��һ 
	cout << endl << "�ú�������ӳɹ���"<< endl<< endl ;
}//��Ӻ�����Ϣ 

void air::search(){
	int in,x; 
	air_manager Air;
      cout << "***** ��ѡ����ҷ�ʽ: *****" << endl << endl;
      cout << "***** 1  ������Ų��� *****" << endl;
      cout << "***** 2  �����߲���   *****" << endl;
      cout << "***** 0  ����         *****" << endl << endl;
      cout << "����0-3��ѡ��"; cin >> in;
    if(in==0) return;//���� 
    switch(in){
       case 1:
          x=Air.search_num();//�ҳ������±� 
          if(x==-1) return; //�޴˺��� 
          cout << "��ѯ������£�" << endl;
		  cout << "�����        ��ʼվ        �յ�վ        ʱ��        �Ѷ���Ʊ��" << endl;
		  cout <<"  "<<Air.a[x].num<<"            "<<Air.a[x].start<<"         "<<Air.a[x].end<<"         "
			   <<Air.a[x].time<<"         "<<Air.a[x].r_count<<"/"<<Air.a[x].count<<endl;
		  cout <<endl<<endl<<endl;
       break;
       case 2:
	      cout << endl << "��������ʼվ��"; cin >> start;
	      cout << endl << "�������յ�վ��"; cin >> end;
	      cout <<endl<<endl<< "��ѯ������£�" << endl;
	      cout << "�����        ��ʼվ        �յ�վ        ʱ��        �Ѷ���Ʊ��" << endl;
	      for(int j=0;j<Air.i;j++)
	         if(strcmp(Air.a[j].get_start(),start)==0 && strcmp(Air.a[j].get_end(),end)==0){
			 cout <<"  "<<Air.a[j].num<<"            "<<Air.a[j].start<<"         "<<Air.a[j].end<<"         "
			      <<Air.a[j].time<<"         "<<Air.a[j].r_count<<"/"<<Air.a[j].count<<endl;
	         }//�����յ���ͬ�����ӡ 
	      cout <<endl<<endl<<endl;
       break;
       default:
         cout << "�����������������" << endl << endl << endl;
    }
}//��ѯ������Ϣ 

void air::delet(){
	int in,x; 
	air_manager Air;
      cout << "***** ��ѡ��ɾ����ʽ: *****" << endl << endl;
      cout << "***** 1  �������ɾ�� *****" << endl;
      cout << "***** 2  ������ɾ��   *****" << endl;
      cout << "***** 0  ����         *****" << endl << endl;
      cout << "����0-3��ѡ��"; cin >> in;
    if(in==0) return ;//���� 
    switch(in){
       case 1:
          x=Air.search_num();//�ҳ������±� 
          if(x==-1)return;//�޴˺���
          Air.delte1(x);//�������ɾ�� 
       break;
       case 2:
		  Air.delte2();//������ɾ�� 
       break;
       default:
         cout << "�����������������" << endl << endl << endl;
    }
}//ɾ������ 

void  air::change(){
	int j,in,x;
	air_manager Air;
	j=Air.search_num();//�ҳ������±�
	do{ system("cls");//���� 
	cout << "***** ��ѡ���޸�����: *****" << endl << endl;
    cout << "*****   1  ��ʼվ     *****" << endl;
    cout << "*****   2  �յ�վ     *****" << endl;
    cout << "*****   3  ʱ���     *****" << endl;
    cout << "*****   0  ����       *****" << endl << endl;
	cout << "����0-3��ѡ��"; cin >> in;
	switch(in){
		case 1:{
			cout << "�������µ���ʼվ��"; cin >> start;
			cout <<endl<< "�Ƿ�ȷ���޸�:   1  ��     2  ��" <<endl;
			cin >> x;
			if(x==1) {
                Air.a[j].set_start(start); //����������������� 
				cout <<endl<<"�޸ĳɹ���";} 
			break;}
		case 2:{
			cout << "�������µ��յ�վ��"; cin >> end;
			cout <<endl<< "�Ƿ�ȷ���޸�:   1  ��     2  ��" <<endl;
			cin >> x;
			if(x==1) {
			    Air.a[j].set_end(end);//����������������� 
				cout <<endl<<"�޸ĳɹ���";} 
			break;}
		case 3:{
			cout << "�������µ�ʱ��Σ�"; cin >> time;
			cout <<endl<< "�Ƿ�ȷ���޸�:   1  ��     2  ��" <<endl;
			cin >> x;
			if(x==1) {
			    Air.a[j].set_time(time);//����������������� 
				cout <<endl<<"�޸ĳɹ���";} 
			break;}
		case 0:
			break;
		default:
    		cout << "�����������������" << endl << endl << endl;
	}
   }while(in!=0);
}//�޸ĺ�����Ϣ 

//����������Ա���� 
air_manager::air_manager(){
	i=0;air A;	
	fstream file("air.txt",ios::in);
	while(1){
        file.read((char*)&A,sizeof(A));
        if(!file) break; 
          a[i]=A;i++; }//�ļ������а��ն����ȡ������ 
	file.close();
}//���캯������ȡ�ļ����ݣ�

int air_manager::search_num(){
	int n;
	cout << "�����뺽��ţ�"; 	cin >> n;
	cout << endl;
	int j;
	for(j=0;j<i;j++)
	   if(a[j].get_num()==n)
	      return j;//���������±� 
	if(j==i){
	   cout <<" �˺��಻���ڣ�"<< endl; return -1;
    }   
}//Ѱ���±�  

void air_manager::delte1(int k){
	 if(k==-1) return;
	 for(int j=k;j<i;j++)
	        a[j]=a[j+1];//�ҳ��±꣬������ǰ�ƶ�һλ 
	 i--; 
	 cout << "ɾ���ɹ���"<< endl<< endl;
}//ɾ����ʽ1

void air_manager::delte2(){
	 char start[20],end[20];
	 cout << endl << "��������ʼվ��"; cin >> start;
	 cout << endl << "�������յ�վ��"; cin >> end;
	 int j,n;
	 for(j=0;j<i;j++)
	    if(strcmp(a[j].get_start(),start)==0 && strcmp(a[j].get_end(),end)==0) break;//�����յ㶼��ͬ 
     if(j==i){
     	cout <<" �˺��಻���ڣ�"<< endl; return;  }
	 do{
	 for(int k=j;k<i;k++)
	        a[k]=a[k+1];//������ǰ�ƶ�һλ  
	 i--; 
	 for(n=0;n<i;n++)
	    if(strcmp(start,a[n].get_start())==0 && strcmp(end,a[n].get_end())==0)
	      { j=n;break;} //����Ѱ����ͬ���ߵĺ��� 
	 }while(n!=i);
	 cout << "ɾ���ɹ���"<< endl<< endl;
}//ɾ����ʽ2 

air_manager::~air_manager(){
    ofstream file("air.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&a[j],sizeof(a[j])); }//���������ڽ���ʱ����д���ļ� 
	file.close();	
}//�������� (д���ļ�)

//�˿����Ա���� 
int passenger::login(){
	cout <<endl<<"�������ֻ���:";cin>>phone;
	cout <<endl<<"����������:";cin>>code;
	int j;
	passenger_manage pas;
	for(j=0;j<pas.i;j++){
       if(strcmp(pas.p[j].get_phone(),phone)==0 && strcmp(pas.p[j].get_code(),code)==0){ //�˺ź����붼��ͬ 
	     return 0;} 
	}
	if(j==pas.i){
	 cout<<endl<<"��������"<<endl; return -1;  }
}//��½ 

void passenger::enroll(){
	 passenger_manage pas;  
	 cout <<endl<< "������������";     cin >> name;     pas.p[pas.i].set_name(name);//����������� 
	 cout <<endl<< "�������Ա�";     cin >> sex;      pas.p[pas.i].set_sex(sex);
	 cout <<endl<< "���������֤�ţ�"; cin >> ID;       pas.p[pas.i].set_ID(ID);
	 cout <<endl<< "�������ֻ��ţ�";   cin >> phone;    pas.p[pas.i].set_phone(phone);
	 cout <<endl<< "���������п��ţ�"; cin >> card;     pas.p[pas.i].set_card(card);
	 cout <<endl<< "���趨���룺";     cin >> code;     pas.p[pas.i].set_code(code);
	 int n[20];
	 for(int k=0;k<20;k++)
	     n[k]=0;//�˿����к���ų�ʼ��Ϊ�� 
     pas.p[pas.i].set_num(n);
	 pas.i++;
	 cout <<endl<< "ע��ɹ���"<<endl;
}//ע�� 
	
void passenger::order(){
	 int in;
     air_manager Air;
     int k=Air.search_num();//�ҳ������±� 
     if(k==-1) return;
     if(Air.a[k].get_count()==Air.a[k].get_r_count()){
        cout << "�˺���Ʊ�����꣡"; 
		return; }
     cout <<endl<< "�����������ֻ��ţ�";cin >> phone;
     passenger_manage pas;
     int j=pas.search_p(phone);//�����ֻ���Ѱ�ҳ˿� 
     if(j==-1) return;
     for(int l=0;l<20;l++)
	    if(pas.p[j].num[l]==Air.a[k].get_num()){ // һ������ֻ�ܶ�һ��Ʊ 
	    cout<<endl<< "�˺����Ѷ���Ʊ"<<endl;
		return;} 
	 int y;//��֤�� 
	 cout <<endl<< "������"<<phone<<"���յ�����֤�룺";cin >> y;
     cout <<endl <<endl<< "�Ƿ��ύ������ 1  ��     2  ��"<<endl;
	 cout <<endl<< "������1��2ѡ��"; cin >> in;
	 if(in==1){
	 	for(int l=0;l<20;l++)
		    if(pas.p[j].num[l]==0){
		      pas.p[j].num[l]=Air.a[k].get_num();//����ŷ���˿���Ϣ 
			  break;} 
	 	Air.a[k].set_r_count(Air.a[k].get_r_count()+1);//�Ѷ�Ʊ����һ 
	 	cout << endl << "��Ʊ�ɹ���" << endl; 
	 }
	 else return;
}//��Ʊ 

void passenger::refund(){ 
     air_manager Air;
     int k=Air.search_num();//�ҳ������±� 
     if(k==-1)return;
     int in;
	 cout <<endl<< "�����������ֻ��ţ�";cin >> phone;
	 int z;//��֤�� 
	 cout <<endl<<endl<< "������"<<phone<<"���յ�����֤�룺";cin >> z;
	 cout <<endl <<endl<< "�Ƿ�ȷ�ϴ˲����� 1  ��     2  ��"<<endl;
	 cout <<endl<< "������1��2ѡ��";cin >> in;
	 if(in==1){
	   passenger_manage pas;
 	   int j=pas.search_p(phone);
 	   if(j==-1) return;
 	   int l;
       for(l=0;l<20;l++){
	      if(pas.p[j].num[l]==Air.a[k].get_num()){
            Air.a[k].set_r_count(Air.a[k].get_r_count()-1);//�Ѷ�Ʊ����һ 
            pas.p[j].num[l]=0; break;} }//ȥ�������
       if(l!=20) cout <<endl<< "��Ʊ�ɹ���" <<endl;     
       else cout <<endl<<"���û�δ���˺����Ʊ��"<<endl;  
	 }
     else return;
}//��Ʊ 

void passenger::check(){
	 int r=1;//������ 
	 air_manager Air;
	 cout <<endl<< "�����������ֻ��ţ�";cin >> phone;
	 int y;//��֤�� 
	 cout <<endl<< "������"<<phone<<"���յ�����֤�룺" ;cin >> y;
	 cout <<endl<< "�ҵĶ�����Ϣ���£�"<<endl;
	 passenger_manage pas;
	 int j=pas.search_p(phone);
	 if(j==-1) return;
     for(int l=0;l<20;l++){
	     if(pas.p[j].num[l]!=0){
	        for(int k=0;k<Air.i;k++)
               if(Air.a[k].get_num()==pas.p[j].num[l]){//����� 
                 cout <<endl<<endl<< "���� "<<r<<endl; r++;
	             cout <<"������  "<<pas.p[j].name;
	             cout <<endl<< "�ֻ��ţ�"<<pas.p[j].phone;
	             cout <<endl<< "����ţ�"<<Air.a[k].get_num(); 
	             cout <<endl<< "��ʼվ��"<<Air.a[k].get_start();
	             cout <<endl<< "�յ�վ��"<<Air.a[k].get_end();
	             cout <<endl<< "ʱ�䣺  "<<Air.a[k].get_time()<<endl<<endl; 
				 }
         }
      }
     if(r==1) cout <<endl<<"�޶�����"<<endl; 
}//�鿴���� 

//�˿͹������Ա���� 
passenger_manage::passenger_manage(){
	i=0;passenger a;	
	fstream file("passengers.txt",ios::in);
	while(1){
        file.read((char*)&a,sizeof(a));
        if(!file) break; 
          p[i]=a;i++; }//�ļ������а��ն����ȡ������ 
	file.close();
}//���캯������ȡ�ļ����ݣ� 

int passenger_manage::search_p(char a[]){
	 int j;
	 for(j=0;j<i;j++)
	 	if(strcmp(p[j].get_phone(),a)==0)//���ֻ��� 
        return j;//���������±� 
     if(j==i) { cout<<"�޴��û���"<<endl;
	 return -1;} 
}//���� 

passenger_manage::~passenger_manage(){
    ofstream file("passengers.txt",ios::out);
    for(int j=0;j<i;j++){
	   file.write((char*)&p[j],sizeof(p[j])); }//���·Ż����� 
	file.close();	
}//�������� (д���ļ�)

//������ 
int main()
{
 char n[30],m[4]="123";//����Ա�˺� 
 int in,x,y,z; //switch�ṹ������ 
 do{
 cout << "************  ��ӭ����ɻ�Ʊ����ϵͳ!  ************" << endl << endl;
 cout << "********          ��ѡ���½���:          ********" << endl;
 cout << "********          1    ����Ա              ********" << endl;
 cout << "********          2    �û�                ********" << endl;
 cout << "********          0    �˳�                ********" << endl;
 cout << "��ѡ��:";
 cin >> in;
 system("cls");
 switch(in){
  case 1:{ 
    cout << "���������Ա�˺�(Ԥ��Ϊ123)��"; cin >>n;
    if(strcmp(n,m)==0){
       do{
       	 cout << "********       1    ��Ӻ�����Ϣ           ********" << endl;
         cout << "********       2    ��ѯ������Ϣ           ********" << endl;
         cout << "********       3    ɾ��������Ϣ           ********" << endl;
         cout << "********       4    �޸ĺ�����Ϣ           ********" << endl;
         cout << "********       0    ����                   ********" << endl << endl;
         cout<<"��ѡ��"; 
         cin >>x;
         system("cls");
         switch(x){
         	case 1:{ air Air;Air.add();
         		break;}
         	case 2:{ air Air;Air.search();
         		break;}
         	case 3:{ air Air;Air.delet();
         		break;}
         	case 4:{ air Air;Air.change();
         		break; } 
         	case 0:
         		break;
            default:
             cout << "�����������������" << endl << endl << endl; 
         }
       }while(x!=0);
    }
    else cout << "����"<<endl; 
    break;} 
  case 2:{ 
   do{
    cout << "********       1    ��½           ********" << endl;
    cout << "********       2    ע��           ********" << endl;
    cout << "********       0    ����           ********" << endl << endl;
    cout<<"��ѡ��";
    cin >> y;
    system("cls");
    switch(y){
    	case 1:{ 
    	      passenger p;
			  int s=p.login();//��¼ 
			  if(s==-1) break;//��½ʧ���򷵻���һ���� 
		      do{
    	      cout << "********       1    ��Ʊ           ********" << endl;
              cout << "********       2    ��Ʊ           ********" << endl;
              cout << "********       3    �鿴����       ********" << endl;
              cout << "********       4    ��ѯ������Ϣ   ********" << endl;
              cout << "********       0    ����           ********" << endl <<endl;
              cout<<"��ѡ��";
              cin >>z;
              system("cls");
              switch(z){
              	case 1:{ passenger p;p.order();
              		break;}
              	case 2:{ passenger p;p.refund();
              		break;}
              	case 3:{ passenger p;p.check();
              		break;}
              	case 4:{ air Air;Air.search();
              		break;}
              	case 0:
              		break;
              	default:
              		cout << "�����������������" << endl << endl << endl;
              }
              }while(z!=0);
    		break;}
    	case 2:{
		    passenger p;
			p.enroll();//ע�� 
    		break;}
    	case 0:
    		break;
    	default:
    		cout << "�����������������" << endl << endl << endl;
    }
   }while(y!=0);
    break;}
  case 0:
    break;
  default:
   cout << "�����������������" << endl << endl << endl; 
  }
 }while(in!=0);
}
