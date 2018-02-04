//Copyright (C) XiyuWang 2017-2018 All rights reserved.
//Copyright (C) ѧ���ɼ�����ϵͳ 2017-2018 All rights reserved.
//Version: 16.9.18

//Compiler: XiyuWang
//Compiler E-mail Address: XiyuWang_Code@hotmail.com 

//System Language: zh-cn
//Description Language: zh-cn
//Code Language: C++

//Lines:1100+
//Length:31000+ 

/* ѧ���ɼ�����ϵͳ ������
��ϵͳʵ�ֵĹ���
1.¼��+����+ɾ�� ѧ����Ϣ 
2.�ļ� ����+���
3.���� ��ѯ��ʽ
4.�ɸ��� �û���Ϣ
5.������ϵͳ  
�����Ƴ����༶ģʽ 
���๦�ܣ������ڴ��� 
*/

//#include <bits/stdc++.h> 
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <time.h> 
#include <set> 
//8 Files included
using namespace std;

unsigned long long int i,j,n,ti,menl,midl,mnl;//menl:max exam_name length	midl:max id length	mnl:max name length
string o;//o:order

time_t tt = time(NULL);
tm* t=localtime(&tt);

struct student{
	double S;//S:Score
	string name,id,exam_name;
};
student z;
struct cmp_ss/*ss:student score*/{
	bool operator()(const student&x,const student&y)const{
		if(x.exam_name<y.exam_name) return 1;
		if(x.exam_name>y.exam_name) return 0;
		if(x.S>y.S) return 1;
		if(x.S<y.S) return 0;
		if(x.id<y.id) return 1;
		if(x.id>y.id) return 0;
		return 0;
	}
};
set<student,cmp_ss> stu;
set<student,cmp_ss>::iterator it;

struct student_info{
	string name,id;
};
student_info zz;
struct cmp_si/*si:student info*/{
	bool operator()(const student_info&x,const student_info&y)const{
		if(x.id>y.id) return 0;
		if(x.id<y.id) return 1;
		return 0;
	}
};
set<student_info,cmp_si> stuinfo;
set<student_info,cmp_si>::iterator siit;//student info iterator

//function list
void start(int len);
void load();
void reg();
int login(int t);
int record_input(unsigned long long int num);
int record_change(unsigned long long int num);
int record_delete(unsigned long long int num);
int record_output();
int record_find();
int record_find_examname();
int record_find_score();
int record_find_clssnm();
int file_output(bool save);
int file_input(bool w);
int make_class();
int class_edition(); 
int class_remake();
int class_reg();
//int main();
//function list end

int main(){
	string clssnm,pwd;
	int n;
	system("del C:\\Users\\SAMS.TRUST");
	system("color f0");
	system("mode con cols=120 lines=30000");
	ti=t->tm_min; 
	load(); start(4); login(1); load(); file_input(1);
	while(o[0]!='E'){
		cin.clear();
		cin.sync(); 
		time_t tt = time(NULL);	
		tm* t=localtime(&tt);
		if(t->tm_min!=ti&&stu.size()>0){
			file_output(1);
			ti=t->tm_min;
		}
		mnl=menl=midl=0;
		for(it=stu.begin();it!=stu.end();it++){
			mnl=max(mnl,it->name.length());
			menl=max(menl,it->exam_name.length());
			midl=max(midl,it->id.length());
		}
		system("cls");
		system("title ѧ���ɼ�����ϵͳ");
		system("mode con cols=120 lines=30000");
		cout<<"ѧ���ɼ�����ϵͳ";
		cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
		cout<<" ʱ�䣺"<<t->tm_hour<<":";
		if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
		else cout<<t->tm_min<<endl;
		cout<<"1.ѧ����Ϣ����"<<endl; 
		cout<<"2.�ļ�����"<<endl; 
		cout<<"3.��ѯ"<<endl;
		cout<<"4.����"<<endl; 
		cout<<"H.����"<<endl; 
		cout<<"E.�˳�ϵͳ"<<endl; 
		cout<<"L.����ϵͳ"<<endl; 
		cout<<"R.��������"<<endl; 
		cout<<"@.����"<<endl; 
		cout<<"������������룺"; 
		o[0]=getch();
		if(!t->tm_min%10){
			cout<<"����ÿ10���Ӱ�ȫ����ģʽ��"<<endl;
			Sleep(5000); 
			start(4);
			login(1);
		}
		if(o[0]=='E') if(MessageBox(NULL,"��ȷ��Ҫ�˳���","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) break;
		if(o[0]=='H') system("HELP_zh-cn.chm");
		if(o[0]=='L'){load();start(4);login(1);}
		if(o[0]=='R'){
			o[0]=0; 
			system("cls");
			if(MessageBox(NULL,"��ȷ��Ҫ����������\r\n�˲��������棡","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) stu.clear();
			o[0]=0; 
		}
		if(o[0]=='@'){
			o[0]=0; 
			system("cls");	
			cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Copyright (C) ѧ���ɼ�����ϵͳ 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Version:16.9.18"<<endl; 
			system("pause");
			o[0]=0; 
		}
		if(o[0]=='1'){
			system("mode con cols=120 lines=30000");
			o[0]=0; 
			string clssnm="�봴���༶"; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			if(fin){
				fin>>clssnm;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-ѧ����Ϣ����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.¼��ѧ����Ϣ"<<endl;
			cout<<"2.����ѧ����Ϣ"<<endl; 
			cout<<"3.ɾ��ѧ����Ϣ"<<endl; 
			cout<<"4.�༶ģʽ¼����Ϣ����ǰ�༶��"<<clssnm<<"��"<<endl; 
			cout<<"�������� ����"<<endl;
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1'&&stu.size()<10000){
				system("cls");
				cout<<"������ѧ��������";
				cin>>n;
				record_input(n);
			}
			if(o[0]=='1'&&stu.size()>=10000){
				system("cls");
				cout<<"���������󣬲��ɼ���¼����Ϣ��"<<endl;
				system("pause");
			}
			if(o[0]=='2'){
				system("cls");
				cout<<"��������ĸ�����";
				cin>>n;
				record_change(n);
			}
			if(o[0]=='3'){
				system("cls");
				cout<<"������ɾ��������";
				cin>>n;
				record_delete(n);
			}
			if(o[0]=='4'){
				system("cls");
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(!fin){
					cout<<"����δ�����༶���밴���������......"<<endl;
					getch();
					make_class();
				}
				else class_edition();
			}
			o[0]=0; 
		} 
		if(o[0]=='2'){
			system("mode con cols=120 lines=30000");
			o[0]=0; 
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-�ļ�����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.������Ϣ���ļ����Զ���"<<endl;
			cout<<"2.���ļ���ȡ��Ϣ "<<endl;
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1') file_output(0);
			if(o[0]=='2') file_input(0);
			o[0]=0;
		}
		if(o[0]=='3'){
			system("mode con cols=120 lines=30000");
			o[0]=0; 
			string clssnm="���봴���༶��"; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			if(fin){
				fin>>clssnm;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-��ѯ";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�鿴����ѧ��������"<<endl;
			cout<<"2.�鿴����ѧ����ϸ��Ϣ"<<endl; 
			cout<<"3.�鿴�ض�����ѧ��������"<<endl; 
			cout<<"4.�鿴�ض���������ѧ��������"<<endl; 
			cout<<"5.�鿴�༶ "<<clssnm<<" ��ѧ��������"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1') record_output(); 
			if(o[0]=='2') record_find();
			if(o[0]=='3') record_find_examname(); 
			if(o[0]=='4') record_find_score();
			if(o[0]=='5'&&fin) record_find_clssnm();
			if(o[0]=='5'&&!fin) MessageBox(NULL,"����δ�����༶��\r\n��ǰ�� ��ҳ=>ѧ����Ϣ����=>4.�༶ģʽ¼����Ϣ �����༶��","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			o[0]=0;
		}
		if(o[0]=='4'){
			system("mode con cols=120 lines=30000");
			o[0]=0;
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�����û���Ϣ"<<endl;
			cout<<"2.���İ༶��Ϣ"<<endl; 
			cout<<"3.��ϵ����"<<endl; 
			cout<<"4.�鿴������"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			o[0]=getch();
			if(o[0]=='1'){
				while(1){
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ���µ�¼��\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES)login(1);
					else break;
					if(MessageBox(NULL,"��½�ɹ���\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) reg();
					else break;
					MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					break;
				}
			}
			if(o[0]=='2') class_reg();
			if(o[0]=='3'){
				system("cls");
				MessageBox(NULL,"�뷢���ʼ�����\r\nXiyuWang_Code@hotmail.com","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			}
			if(o[0]=='4'){
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(fin){
					fin>>clssnm;
					for(i=0;i<clssnm.length();i++)
						clssnm[i]-=18;
				}
				system("cls");
				cout<<"��ǰ��������"<<stu.size()<<endl; 
				if(fin) cout<<"�༶ "<<clssnm<<" �е�ѧ������"<<stuinfo.size()<<endl; 
				system("pause");
			}
		}
		o[0]=0; 
	}
	if(stu.size()>0) file_output(1);
	system("cls");
	system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
	load();
	system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
	Sleep(1000);
	return 0; 
}

void start(int len){
	srand(time(0));
	string key,ans;
	system("mode con cols=120 lines=30000");
	system("cls");
	system("title ѧ���ɼ�����ϵͳ");
	cout<<"��֤�룺"; 
	for(i=0;i<len;i++){
		key[i]=char(65+rand()%(65-122+1));
		cout<<key[i];
	}	
	cout<<endl<<"��������֤�룺";
	cin>>ans;
	for(i=0;i<len;i++)
		if(ans[i]!=key[i]) start(len+1);
	cout<<"��֤����ȷ��"<<endl; 
}

void load(){
	system("cls");
	system("title ѧ���ɼ�����ϵͳ-������......");
	cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Copyright (C) ѧ���ɼ�����ϵͳ 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Version:16.9.18"<<endl; 
	cout<<"С��ʾ��������������ʱ������ӿո񣬷���ϵͳ�����"<<endl; 
	cout<<"������......"<<endl; 
	for(i=1;i<=10;i++){
		cout<<"��";
		Sleep(188);
	}
}

//user operation 
void reg(){
	system("mode con cols=120 lines=30000");
	system("title ѧ���ɼ�����ϵͳ");
	system("cls");
	cout<<"����δע�ᣬ�������û�����";
	cin>>o;
	ofstream fout;
	fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\Control.info");
	if(!fout){
		MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		exit(0);
	}
	fout<<o<<endl;
	fout.close();
	cout<<"���������룺";
	cin>>o;
	//�����㷨��ASCII���123
	for(long long i=0;i<=o.size();i++)
		o[i]=o[i]+123;
	fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\Control.passwd");
	if(!fout){
		MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		exit(0);
	}
	fout<<o<<endl;
	fout.close();
	MessageBox(NULL,"ע��ɹ���","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
}
int wt;//wt:wrong_time
int login(int t){
	system("mode con cols=120 lines=30000");
	if(t>3){
		system("cls");
		cout<<"�������������࣬ϵͳ��������"<<endl;
		Sleep(5000);
		system("shutdown -p");
		exit(0);
	}
	system("mkdir C:\\ProgramData\\StudentAchievementManagementSystem");
	system("cls");
	system("title ѧ���ɼ�����ϵͳ-��½");
	string usr,passwd;
	ifstream fin;
	fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\Control.info");
	if(!fin) reg();
	system("cls");
	cout<<"��½"<<endl; 
	cout<<"�������û�����";
	cin>>o;
	fin>>usr; 
	if(!fin){
		MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		exit(0);
	}
	if(o!=usr){
		MessageBox(NULL,"�û������ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		login(t);
	}
	fin.close();
	fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\Control.passwd");
	fin>>passwd;
	fin.close();
	//�����㷨��ASCII���123 
	for(long long i=0;i<=passwd.size();i++)
		passwd[i]=passwd[i]-123;
	cout<<"���������룺";
	long long i=0;
	cin>>o;
	if(o!=passwd){
		wt++;
		MessageBox(NULL,"�������","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		login(wt);
	}
	MessageBox(NULL,"������ȷ��","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
	return 0;
}
//user operation end

//record operation (input,change,delete)
int record_input(unsigned long long int num){
	bool found=false;
	for(i=1;i<=num;i++){
		ri:
		system("cls");
		cout<<"���������"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ�ţ�";
		cin>>z.id;
		midl=max(midl,z.id.length());
		cout<<"������������";
		cin>>z.name;
		mnl=max(mnl,z.name.length());
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				MessageBox(NULL,"�ü�¼�Ѵ��ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				found=true;
				break;
			}
		if(found){
			found=false;
			continue;
		}
		cout<<"������ɼ���";
		cin>>z.S;
		stu.insert(z);
	}
	system("cls");
	cout<<"����ɶ�"<<num<<"��ѧ��������¼�룡"<<endl;
	system("pause"); 
}
int record_change(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("cls");
		string tmp;
		j=1;
		cout<<"���ڸ��ĵ�"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&it->exam_name==z.exam_name){
				system("cls"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<it->S<<endl;
				if(MessageBox(NULL,"��ȷ��Ҫ���ĸ�ѧ������Ϣ��","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					z.name=it->name;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
				return 1;
			}
		}
		rc:
		cout<<"�������¿������ƣ�";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		cout<<"������ɼ���";
		cin>>z.S;
		stu.insert(z);
	}
	system("cls");
	cout<<"����ɶ�"<<num<<"��ѧ�������ݸ��ģ�"<<endl;
	system("pause"); 
}
int record_delete(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("cls");
		string tmp;
		j=1;
		cout<<"����ɾ����"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&z.exam_name==it->exam_name){
				system("cls"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<it->S<<endl;
				if(MessageBox(NULL,"��ȷ��Ҫɾ����ѧ������Ϣ��","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				return 1;
			}
		}
	}
	system("cls");
	cout<<"����ɶ�"<<num<<"��ѧ��������ɾ����"<<endl;
	system("pause"); 
}
//record operation end

//record output (four ways)
//output all information
int record_output(){
	double All,Average;
	system("cls");
	if(stu.size()<1){
		MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	clock_t start = clock();
	z.exam_name=' ';
	cout<<"����|ѧ�� ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|���� ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|�������� ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|�ɼ�"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"ƽ���֣�"<<Average<<endl;
			cout<<endl;
		}
		if(i<10) cout<<i<<"   |";
		if(i>=10&&i<100) cout<<i<<"  |";
		if(i>=100&&i<1000) cout<<i<<" |";
		if(i>=1000&&i<10000) cout<<i<<"|";
		cout<<it->id;
		for(j=midl;j>=it->id.length();j--) cout<<" ";
		cout<<"|"<<it->name;
		for(j=mnl;j>=it->name.length();j--) cout<<" ";
		cout<<"|"<<it->exam_name;
		for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
		cout<<"|"<<setprecision(2)<<fixed<<it->S;
		cout<<endl;
		All+=it->S;
		z.exam_name=it->exam_name;
	}
	Average=All/(i-1);
	cout<<"ƽ���֣�"<<Average<<endl<<endl;
	clock_t end   = clock();
	cout << "ʹ��ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
	system("pause");
}
//output only one student's information
int record_find(){
	system("cls");
	if(stu.size()<1){
		MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	double Average,All;
	z.exam_name=' ';
	string tmp;
	bool f=false; 
	cout<<"������ѧ��ѧ�Ż�������";
	cin>>tmp;
	clock_t start = clock();
	cout<<"����|ѧ�� ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|���� ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|�������� ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|�ɼ�"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"ƽ���֣�"<<Average<<endl;
			cout<<endl;
		}
		if(it->id==tmp||it->name==tmp){
			if(i<10) cout<<i<<"   |";
			if(i>=10&&i<100) cout<<i<<"  |";
			if(i>=100&&i<1000) cout<<i<<" |";
			if(i>=1000&&i<10000) cout<<i<<"|";
			cout<<it->id;
			for(j=midl;j>=it->id.length();j--) cout<<" ";
			cout<<"|"<<it->name;
			for(j=mnl;j>=it->name.length();j--) cout<<" ";
			cout<<"|"<<it->exam_name;
			for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
			cout<<"|"<<setprecision(2)<<fixed<<it->S;
			cout<<endl;
			f=true;
		}
		All+=it->S; 
		z.exam_name=it->exam_name;
	}
	Average=All/(i-1);
	cout<<"ƽ���֣�"<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "ʹ��ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
		system("pause");
		return 1;
	}
	system("cls");
	MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
	return 1;
}
//output information in given examname
int record_find_examname(){
	system("cls");
	if(stu.size()<1){
		MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	double Average,All;
	bool f=false; 
	z.exam_name=' ';
	string tmp;
	cout<<"�����뿼�����ƣ�";
	cin>>tmp;
	clock_t start = clock();
	cout<<"����|ѧ�� ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|���� ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|�������� ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|�ɼ�"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"ƽ���֣�"<<Average<<endl;
			cout<<endl;
		}
		if(it->exam_name==tmp){
			if(i<10) cout<<i<<"   |";
			if(i>=10&&i<100) cout<<i<<"  |";
			if(i>=100&&i<1000) cout<<i<<" |";
			if(i>=1000&&i<10000) cout<<i<<"|";
			cout<<it->id;
			for(j=midl;j>=it->id.length();j--) cout<<" ";
			cout<<"|"<<it->name;
			for(j=mnl;j>=it->name.length();j--) cout<<" ";
			cout<<"|"<<it->exam_name;
			for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
			cout<<"|"<<setprecision(2)<<fixed<<it->S;
			cout<<endl;
			f=true;
		}
		All+=it->S; 
		z.exam_name=it->exam_name;
	}
	Average=All/(i-1);
	cout<<"ƽ���֣�"<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "ʹ��ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
		system("pause");
		return 1;
	}
	system("cls");
	MessageBox(NULL,"δ�ҵ��ÿ������κ�ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
	return 1;
}
//output information between given lowest score and given highest score
int record_find_score(){
	system("cls");
	if(stu.size()<1){
		MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	double Average,All;
	bool f=false; 
	z.exam_name=' ';
	int l,h;//l:lowest,h:highest
	cout<<"��������ͷ�����";
	cin>>l;
	cout<<"��������߷�����";
	cin>>h; 
	clock_t start = clock();
	cout<<"����|ѧ�� ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|���� ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|�������� ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|�ɼ�"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"ƽ���֣�"<<Average<<endl;
			cout<<endl;
		}
		if(it->S>=l&&it->S<=h){
			if(i<10) cout<<i<<"   |";
			if(i>=10&&i<100) cout<<i<<"  |";
			if(i>=100&&i<1000) cout<<i<<" |";
			if(i>=1000&&i<10000) cout<<i<<"|";
			cout<<it->id;
			for(j=midl;j>=it->id.length();j--) cout<<" ";
			cout<<"|"<<it->name;
			for(j=mnl;j>=it->name.length();j--) cout<<" ";
			cout<<"|"<<it->exam_name;
			for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
			cout<<"|"<<setprecision(2)<<fixed<<it->S;
			cout<<endl;
			f=true;
		}
		All+=it->S; 
		z.exam_name=it->exam_name;
	}
	Average=All/(i-1);
	cout<<"ƽ���֣�"<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "ʹ��ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
		system("pause");
		return 1;
	}
	system("cls");
	MessageBox(NULL,"δ�ҵ��÷��������κ�ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
	return 1;
}
//output information in given classname 
int record_find_clssnm(){
	string clssnm,pwd;
	int n;
	system("cls");
	if(stu.size()<1){
		MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	ifstream fin;	
	fin.open("ClassEdition.dat");
	fin>>clssnm>>pwd>>n;
	for(i=1;i<=n;i++){
		fin>>zz.name>>zz.id;
		for(j=0;j<zz.id.length();j++)
			zz.id[j]-=10;
		z.id=zz.id;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]-=10;
		stuinfo.insert(zz);
	}
	double Average,All;
	bool f=false; 
	z.exam_name=' ';
	clock_t start = clock();
	cout<<"����|ѧ�� ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|���� ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|�������� ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|�ɼ�"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"ƽ���֣�"<<Average<<endl;
			cout<<endl;
		}
		for(siit=stuinfo.begin();siit!=stuinfo.end();siit++){
			if(siit->name==it->name&&siit->id==it->id){
				if(i<10) cout<<i<<"   |";
				if(i>=10&&i<100) cout<<i<<"  |";
				if(i>=100&&i<1000) cout<<i<<" |";
				if(i>=1000&&i<10000) cout<<i<<"|";
				cout<<it->id;
				for(j=midl;j>=it->id.length();j--) cout<<" ";
				cout<<"|"<<it->name;
				for(j=mnl;j>=it->name.length();j--) cout<<" ";
				cout<<"|"<<it->exam_name;
				for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
				cout<<"|"<<setprecision(2)<<fixed<<it->S;
				cout<<endl;
				break;
			}
		}
		All+=it->S; 
		z.exam_name=it->exam_name;
	}
	Average=All/(i-1);
	cout<<"ƽ���֣�"<<Average<<endl<<endl;
	clock_t end   = clock();
	cout << "ʹ��ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
	system("pause");
	return 1;
}
//record output end

//file operation
int file_output(bool save){
	double Average,All;
	ofstream fout;
	system("cls");
	z.exam_name=' ';
	fout.open("D:\\ѧ���ɼ���Ϣ.csv",ios::out|ios::trunc); 
	if(!fout){
		MessageBox(NULL,"����\r\n�޷������ļ���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	if(stu.size()==0) fout<<"���޼�¼��"<<endl;
	else{
		fout<<"����"<<","<<"ѧ��"<<","<<"�ɼ�"<<","<<"����"<<","<<"��������"<<endl;
		for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(i-1);
				All=0;
				i=1;
				fout<<"ƽ���֣�"<<Average<<endl;
				fout<<endl;
			}
			if(i<10) fout<<i<<"   "<<","<<"";
			if(i>=10&&i<100) fout<<i<<"  "<<","<<"";
			if(i>=100&&i<1000) fout<<i<<" "<<","<<"";
			if(i>=1000&&i<10000) fout<<i<<""<<","<<"";
			if((it->id).length()==1) fout<<it->id<<"   "<<","<<" ";
			if((it->id).length()==2) fout<<it->id<<"  "<<","<<" ";
			if((it->id).length()==3) fout<<it->id<<" "<<","<<" ";
			if((it->id).length()==4) fout<<it->id<<""<<","<<" ";
			fout<<setprecision(2)<<fixed<<it->S;
			fout<<" "<<","<<" "<<it->name<<" "<<","<<" "<<it->exam_name<<endl;
			z.exam_name=it->exam_name;
			All+=it->S; 
		}
	Average=All/(i-1);
	fout<<"ƽ���֣�"<<Average<<endl;
	}
	fout.close();
	fout.open("StudentScore.dat"); 
	if(!fout){
		MessageBox(NULL,"����\r\n�޷������ļ���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	fout<<"16.9.18"<<endl;
	fout<<stu.size()<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		z.exam_name=it->exam_name;
		for(int i=0;i<=z.exam_name.size()-1;i++)
			z.exam_name[i]=z.exam_name[i]+1;
		z.name=it->name;
		for(int i=0;i<=z.name.size()-1;i++)
			z.name[i]=z.name[i]+2;
		z.id=it->id;
		for(int i=0;i<=z.id.size()-1;i++)
			z.id[i]=z.id[i]+3;
		z.S=it->S;
		z.S=z.S+12397;
		fout<<z.exam_name<<" "<<z.id<<" "<<z.name<<" "<<z.S<<" ";
	}
	fout.close();
	if(!save){
		cout<<"��ɣ���ر�Ԥ�����ڣ�Excel��񴰿ڣ��������"<<endl;
		system("D:\\ѧ���ɼ���Ϣ.csv");
		system("pause");
	}
}
int file_input(bool w){
	system("cls");
	unsigned long long int num;
	string version;
	ifstream fin;
	fin.open("StudentScore.dat"); 
	if(!fin&&!w){
		MessageBox(NULL,"�ļ�\"StudentScore.dat\"�����ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	if(!fin&&w) return 1; 
	fin>>version>>num;
	if(version!="16.9.18"&&!w){
		cout<<"�ļ��汾��ϵͳ�������޷�¼����Ϣ��"<<endl;
		cout<<"�ļ��汾��"<<version<<endl; 
		cout<<"ϵͳ�汾��16.9.18"<<endl;
		system("pause");
		return 1;
	}
	if(version!="16.9.18"&&w) return 1;
	if((num+stu.size())>=10000&&!w){
		cout<<"�ļ������������޷�¼��ϵͳ��"<<endl;
		cout<<"�ļ��������� "<<num<<endl;
		cout<<"ϵͳ��ǰ��������"<<stu.size()<<endl;
		cout<<"¼�����������"<<num+stu.size()<<endl;
		cout<<"������׼��"<<num+stu.size()-10000<<endl;
		system("pause");
		return 1;
	}
	if((num+stu.size())>=10000&w) return 1;
	for(i=1;i<=num;i++){
		fin>>z.exam_name>>z.id>>z.name>>z.S; 
		for(int i=0;i<=z.exam_name.size();i++)
			z.exam_name[i]=z.exam_name[i]-1;
		menl=max(menl,z.exam_name.length());
		for(int i=0;i<=z.name.size();i++)
			z.name[i]=z.name[i]-2;
		mnl=max(mnl,z.name.length());
		for(int i=0;i<=z.id.size();i++)
			z.id[i]=z.id[i]-3;
		midl=max(midl,z.id.length());
		z.S=z.S-12397;
		stu.insert(z);
	}
	if(!w) MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND);
}
//file operation end

//Class Edition
int class_reg(){
	string classname,passwd,name,id;
	int n;
	ifstream fin;
	fin.open("ClassEdition.dat");
	fin>>classname>>passwd>>n;
	ofstream fout;
	fout.open("ClassEdition.dat");
	if(!fout){
		cout<<"ϵͳ�����볢������ϵͳ��"<<endl;
		system("pause");
		return 1;
	}
	system("cls");
	cout<<"�������°༶���ƣ�";
	cin>>classname;
	//�����㷨 
	for(i=0;i<classname.length();i++)
		classname[i]+=18;
	cout<<"�������°༶����Ա���룺";
	cin>>passwd;
	//�����㷨 
	for(i=0;i<passwd.length();i++)
		passwd[i]+=18;
	fout<<classname<<" "<<passwd<<" "<<n<<endl;
	for(i=1;i<=n;i++){
		fin>>name>>id;
		fout<<name<<" "<<id<<endl;
	}
	system("cls");
} 
int make_class(){
	ofstream fout;
	fout.open("ClassEdition.dat");
	if(!fout){
		cout<<"ϵͳ�����볢������ϵͳ��"<<endl;
		system("pause");
		return 1;
	}
	string classname,passwd;
	int n;
	system("cls");
	cout<<"������༶���ƣ�";
	cin>>classname;
	//�����㷨 
	for(i=0;i<classname.length();i++)
		classname[i]+=18;
	cout<<"������༶����Ա���룺";
	cin>>passwd;
	//�����㷨 
	for(i=0;i<passwd.length();i++)
		passwd[i]+=18;
	system("cls");
	cout<<"������༶������";
	cin>>n;
	if(n+stu.size()>=10000){
		cout<<"�༶�������࣡"<<endl;
		system("pause");
		return 1;
	}
	fout<<classname<<" "<<passwd<<" "<<n<<endl; 
	for(i=1;i<=n;i++){
		system("cls");
		cout<<"���������"<<i<<"��ѧ������Ϣ����"<<n<<"��......"<<endl;
		cout<<"������ѧ��ѧ�ţ�"; 
		cin>>zz.id;
		cout<<"������ѧ��������";
		cin>>zz.name;
		stuinfo.insert(zz);
		for(j=0;j<zz.id.length();j++)
			zz.id[j]+=10;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]+=10;
		fout<<zz.name<<" "<<zz.id<<endl;
	}
	fout.close();
	system("cls");
	cout<<"�༶������ɣ�"<<endl;
	system("pause");
}
int class_edition(){
	system("cls");
	string clssnm,pwd,classname,passwd;
	int n=0;
	bool found=false;
	ifstream fin;
	fin.open("ClassEdition.dat");
	fin>>clssnm>>pwd>>n;
	for(i=0;i<clssnm.length();i++)
		clssnm[i]-=18;
	for(i=0;i<pwd.length();i++)
		pwd[i]-=18;
	cout<<"�༶ģʽ-��½"<<endl; 
	cout<<"�༶���ƣ�"<<clssnm<<endl;
	cout<<"���룺";
	cin>>passwd;
	if(passwd!=pwd){
		system("cls");
		cout<<"�������"<<endl; 
		system("pause");
		return 1;
	}
	system("cls");
	cout<<"�����뿼�����ƣ�";
	cin>>z.exam_name; 
	for(i=1;i<=n;i++){
		fin>>zz.name>>zz.id;
		for(j=0;j<zz.id.length();j++)
			zz.id[j]-=10;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]-=10;
		stuinfo.insert(zz);
	}
	for(siit=stuinfo.begin(),i=1;siit!=stuinfo.end();siit++,i++){
		system("cls");
		cout<<"�������� "<<clssnm<<" �е�"<<i<<"��ѧ���ĳɼ�����"<<n<<"��......"<<endl; 
		z.id=siit->id;
		z.name=siit->name;
		cout<<"ѧ�ţ�"<<z.id<<endl;
		cout<<"������"<<z.name<<endl;
		cout<<"�������ƣ�"<<z.exam_name<<endl;
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				cout<<"��ѧ����Ϣ�Ѵ��ڣ�"<<endl;
				found=true;
				system("pause");
				break; 
			}
		if(found){
			found=false;
			continue;
		}
		cout<<"������ɼ���";
		cin>>z.S;
		stu.insert(z);
	}
	system("cls");
	cout<<"�༶ģʽ����¼�������"<<endl;
	system("pause"); 
}
//Class Edition
