//Copyright (C) XiyuWang 2017-2018 All rights reserved.
//Copyright (C) ѧ���ɼ�����ϵͳ 2017-2018 All rights reserved.
//Version: 16.9.18

//Compiler: XiyuWang
//Compiler E-mail Address: XiyuWang_Code@hotmail.com 

//System Language: zh-cn
//Description Language: zh-cn
//Code Language: C++
//Edition: Linux 

//Lines:1000+
//Length:26000+

/* ѧ���ɼ�����ϵͳ ������
��ϵͳʵ�ֵĹ���
1.¼��+����+ɾ�� ѧ����Ϣ
2.�ļ� ����+���
3.���� ��ѯ��ʽ
4.�ɸ��� �û���Ϣ
5.������ϵͳ  
���๦�ܣ������ڴ��� 
*/

//#include <bits/stdc++.h> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <time.h> 
#include <set> 
#include <stdlib.h>
//7 Files included
using namespace std;

unsigned long long int i,j,n,ti;
int menl,midl,mnl;//menl:max exam_name length	midl:max id length	mnl:max name length
string o;//o:order

time_t tt = time(NULL);
tm* t=localtime(&tt);

struct student{
	double S;//S:Score
	string name,id,exam_name;
};
student z;
struct cmp_student{
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
set<student,cmp_student> stu;
set<student,cmp_student>::iterator it;

struct student_info{
	string name,id;
};
student_info zz;
struct cmp_si/*si:student info*/{
	bool operator()(const student_info&x,const student_info&y)const{
		if(x.id<y.id) return 0;
		if(x.id>y.id) return 1;
		return 0;
	}
};
set<student_info,cmp_si> stuinfo;
set<student_info,cmp_si>::iterator siit;//student info iterator
//function list
void start();
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
int file_output(bool save);
int file_input(bool w);
int make_class();
int class_edition(); 
//int class_backup();
//int main();
//function list end

int main(){
	system("mkdir SAMS");
	ti=t->tm_min; 
	load(); start(); login(1); load(); file_input(1);
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
			mnl>=it->name.length()?mnl=mnl:mnl=it->name.length();
			menl>=it->exam_name.length()?menl=menl:menl=it->exam_name.length(); 
			midl>=it->id.length()?midl=midl:midl=it->id.length(); 
		}
		system("clear");
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
		cin>>o;
		if(o[0]=='E'){
			system("clear");	
			cout<<"��ȷ��Ҫ�˳��𣿣�Y/N��"<<endl;
			cin>>o;
			if(o[0]=='Y'||o[0]=='y') break;
		}
		if(o[0]=='H') system("HELP_zh-cn.chm");
		if(o[0]=='L'){load();start();login(1);}
		if(o[0]=='R'){
			o[0]=0; 
			system("clear");
			cout<<"��ȷ��Ҫ���������𣿣�Y/N��"<<endl;
			cout<<"�˲��������棡"<<endl; 
			cin>>o;
			if(o[0]=='Y'||o[0]=='y') stu.clear(); 
			o[0]=0; 
		}
		if(o[0]=='@'){
			o[0]=0; 
			system("clear");	
			cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Copyright (C) ѧ���ɼ�����ϵͳ 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Version:16.9.18"<<endl; 
			cout<<"�밴 Enter ������"<<endl;
			cin>>o; 
			o[0]=0; 
		}
		if(o[0]=='1'){
			o[0]=0; 
			system("clear");
			cout<<"ѧ���ɼ�����ϵͳ-ѧ����Ϣ����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.¼��ѧ����Ϣ"<<endl;
			cout<<"2.����ѧ����Ϣ"<<endl; 
			cout<<"3.ɾ��ѧ����Ϣ"<<endl; 
			cout<<"4.�༶ģʽ¼����Ϣ������¼�룩"<<endl; 
			cout<<"�������� ����"<<endl;
			cout<<"������������룺";
			cin>>o;
			if(o[0]=='1'&&stu.size()<10000){
				system("clear");
				cout<<"������ѧ��������";
				cin>>n;
				record_input(n);
			}
			if(o[0]=='1'&&stu.size()>=10000){
				system("clear");
				cout<<"���������󣬲��ɼ���¼����Ϣ��"<<endl;
				system("pause");
			}
			if(o[0]=='2'){
				system("clear");
				cout<<"��������ĸ�����";
				cin>>n;
				record_change(n);
			}
			if(o[0]=='3'){
				system("clear");
				cout<<"������ɾ��������";
				cin>>n;
				record_delete(n);
			}
			if(o[0]=='4'){
				system("clear");
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(!fin){
					cout<<"����δ�����༶���밴Enter����......"<<endl;
					cin>>o;
					make_class();
				}
				else class_edition();
			}
			o[0]=0; 
		} 
		if(o[0]=='2'){
			o[0]=0; 
			system("clear");
			cout<<"ѧ���ɼ�����ϵͳ-�ļ�����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.������Ϣ���ļ����Զ���"<<endl;
			cout<<"2.���ļ���ȡ��Ϣ "<<endl;
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			cin>>o;
			if(o[0]=='1') file_output(0);
			if(o[0]=='2') file_input(0);
			o[0]=0;
		}
		if(o[0]=='3'){
			o[0]=0; 
			system("clear");
			cout<<"ѧ���ɼ�����ϵͳ-��ѯ";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�鿴����ѧ��������"<<endl;
			cout<<"2.�鿴����ѧ����ϸ��Ϣ"<<endl; 
			cout<<"3.�鿴�ض�����ѧ��������"<<endl; 
			cout<<"4.�鿴�ض���������ѧ��������"<<endl; 
			//cout<<"���ݲ�֧�֣��鿴���п��Ե�ƽ����"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			cin>>o;
			if(o[0]=='1') record_output(); 
			if(o[0]=='2') record_find();
			if(o[0]=='3') record_find_examname(); 
			if(o[0]=='4') record_find_score();
			//if(o[0]=='5') exam_info_output();
			o[0]=0;
		}
		if(o[0]=='4'){
			o[0]=0;
			system("clear");
			cout<<"ѧ���ɼ�����ϵͳ-����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�����û���Ϣ"<<endl;
			cout<<"2.��ϵ����"<<endl; 
			cout<<"3.�鿴������"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			cin>>o;
			if(o[0]=='1'){
				while(1){
					system("clear");
					cout<<"����Ҫ���µ�½��Y������Nֹͣ���ģ�"<<endl;
					cin>>o;
					if(o[0]=='Y'||o[0]=='y') login(1); 
					else break;
					system("clear");	
					cout<<"��½�ɹ���Y������Nֹͣ���ģ�"<<endl;
					if(o[0]=='Y'||o[0]=='y') reg(); 
					else break;
					system("clear");	
					cout<<"��ɣ�"<<endl; 
					cout<<"�밴 Enter ������"<<endl;
					cin>>o; 
					break;
				}
			}
			if(o[0]=='2'){
				system("clear");
				cout<<"�뷢���ʼ�����XiyuWang_Code@hotmail.com"<<endl; 
			}
			if(o[0]=='3'){
				system("clear");
				cout<<"��ǰ��������"<<stu.size()<<endl; 
				cout<<"�밴 Enter ������"<<endl;
				cin>>o; 
			}
		}
		o[0]=0; 
	}
	if(stu.size()>0) file_output(1);
	system("clear");
	load();
	for(i=1;i<=100000;i++);
	return 0; 
}

void start(){
	system("clear");
	cout<<"������ OK ������"<<endl; 
	cin>>o;
	if((o[0]!='o'&&o[0]!='O')||(o[1]!='k'&&o[1]!='K')) start();
}

void load(){
	system("clear");
	cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Copyright (C) ѧ���ɼ�����ϵͳ 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Version:16.9.18"<<endl; 
	cout<<"������......"<<endl; 
	for(i=1;i<=10;i++){
		cout<<"��";
		for(i=1;i<=10000;i++);
	}
}

//user operation 
void reg(){
	system("clear");
	cout<<"����δע�ᣬ�������û�����";
	cin>>o;
	ofstream fout;
	fout.open("SAMS/Control.info");
	if(!fout){
		cout<<"ϵͳ����ȱ�ٹ���ԱȨ�ޣ������Գ���������ϵͳ��"<<endl; 
		while(1);
	}
	fout<<o<<endl;
	fout.close();
	cout<<"���������룺";
	cin>>o;
	//�����㷨��ASCII���123
	for(long long i=0;i<=o.size();i++)
		o[i]=o[i]+123;
	fout.open("SAMS/Control.passwd");
	if(!fout){
		cout<<"ϵͳ����ȱ�ٹ���ԱȨ�ޣ������Գ���������ϵͳ��"<<endl; 
		while(1);
	}
	fout<<o<<endl;
	fout.close();
	cout<<"ע��ɹ���"<<endl;
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
}
int wt;//wt:wrong_time
int login(int t){
	if(t>3){
		system("clear");
		cout<<"�������������࣬ϵͳ��������"<<endl;
		for(i=1;i<=500000;i++); 
		system("sudo reboot");
	}
	system("clear");
	string usr,passwd;
	ifstream fin;
	fin.open("SAMS/Control.info");
	if(!fin) reg();
	system("clear");
	cout<<"��½"<<endl; 
	cout<<"�������û�����";
	cin>>o;
	fin>>usr; 
	if(!fin){
		cout<<"ϵͳ����ȱ�ٹ���ԱȨ�ޣ������Գ���������ϵͳ��"<<endl; 
		while(1);		
	}
	if(o!=usr){
		cout<<"�û������ڣ�"<<endl; 
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		login(t);
	}
	fin.close();
	fin.open("SAMS/Control.passwd");
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
		cout<<"�������"<<endl; 
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		login(wt);
	}
	cout<<"������ȷ��"<<endl; 
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
	return 0;
}
//user operation end

//record operation (input,change,delete)
int record_input(unsigned long long int num){
	for(i=1;i<=num;i++){
		ri:
		system("clear");
		cout<<"���������"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ�ţ�";
		cin>>z.id;
		midl>=z.id.length()?midl=midl:midl=z.id.length();
		cout<<"������������";
		cin>>z.name;
		mnl>=z.name.length()?mnl=mnl:mnl=z.name.length();
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		menl>=z.exam_name.length()?menl=menl:menl=z.exam_name.length();
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				cout<<"�ü�¼�Ѵ��ڣ�"<<endl; 
				cout<<"�밴 Enter ������"<<endl;
				cin>>o; 
				return 1;
			}
		cout<<"������ɼ���";
		cin>>z.S;
		stu.insert(z);
	}
}
int record_change(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("clear");
		string tmp;
		j=1;
		cout<<"���ڸ��ĵ�"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&it->exam_name==z.exam_name){
				system("clear"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<it->S<<endl;
				cout<<"ȷ�ϸ��ģ���Y/N��"<<endl;
				cin>>o; 
				if(o[0]=='Y'||o[0]=='y'){
					z.id=it->id;
					z.name=it->name;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("clear");
				cout<<"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��"<<endl; 
				cout<<"�밴 Enter ������"<<endl;
				cin>>o; 
				return 1;
			}
		}
		rc:
		cout<<"�������¿������ƣ�";
		cin>>z.exam_name; 
		menl>=z.exam_name.length()?menl=menl:menl=z.exam_name.length();
		cout<<"������ɼ���";
		cin>>z.S;
		stu.insert(z);
	}
}
int record_delete(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("clear");
		string tmp;
		j=1;
		cout<<"����ɾ����"<<i<<"��ѧ������Ϣ����"<<num<<"��......"<<endl; 
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&z.exam_name==it->exam_name){
				system("clear"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<it->S<<endl;
				cout<<"ȷ��ɾ������Y/N��"<<endl; 
				cin>>o; 
				if(o[0]=='Y'||o[0]=='y'){
					z.id=it->id;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("clear");
				cout<<"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��"<<endl;
				cout<<"�밴 Enter ������"<<endl;
				cin>>o; 
				return 1;
			}
		}
	}
}
//record operation end

//record output (four ways)
//output all information
int record_output(){
	double All,Average;
	system("clear");
	if(stu.size()<1){
		cout<<"���޼�¼��"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
}
//output only one student's information
int record_find(){
	system("clear");
	if(stu.size()<1){
		cout<<"���޼�¼��"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"���޼�¼��"<<endl;
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
	return 1;
}
//output information in given examname
int record_find_examname(){
	system("clear");
	if(stu.size()<1){
		cout<<"���޼�¼��"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"���޼�¼��"<<endl;
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
	return 1;
}
//output information between given lowest score and given highest score
int record_find_score(){
	system("clear");
	if(stu.size()<1){
		cout<<"���޼�¼��"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"δ�ҵ��÷��������κ�ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��"<<endl;
	cout<<"�밴 Enter ������"<<endl;
	cin>>o; 
	return 1;
}
//record output end

//file operation
int file_output(bool save){
	double Average,All;
	ofstream fout;
	system("clear");
	z.exam_name=' ';
	fout.open("ѧ���ɼ���Ϣ.csv",ios::out|ios::trunc); 
	if(!fout){
		cout<<"�޷������ļ���"<<endl; 
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
	fout.open("SAMS/StudentScore.dat"); 
	if(!fout){
		cout<<"�޷������ļ���"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
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
		system("ѧ���ɼ���Ϣ.csv");
	}
}
int file_input(bool w){
	system("clear");
	unsigned long long int num;
	string version;
	ifstream fin;
	fin.open("SAMS/StudentScore.dat"); 
	if(!fin&&!w){
		cout<<"�ļ�\"SAMS/StudentScore.dat\"�����ڣ�"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	if(!fin&&w) return 1; 
	fin>>version>>num;
	if(version!="16.9.18"&&!w){
		cout<<"�ļ��汾��ϵͳ�������޷�¼����Ϣ��"<<endl;
		cout<<"�ļ��汾��"<<version<<endl; 
		cout<<"ϵͳ�汾��16.9.18"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	if(version!="16.9.18"&&w) return 1;
	if((num+stu.size())>=10000&&!w){
		cout<<"�ļ������������޷�¼��ϵͳ��"<<endl;
		cout<<"�ļ��������� "<<num<<endl;
		cout<<"ϵͳ��ǰ��������"<<stu.size()<<endl;
		cout<<"¼�����������"<<num+stu.size()<<endl;
		cout<<"������׼��"<<num+stu.size()-10000<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
		return 1;
	}
	if((num+stu.size())>=10000&w) return 1;
	for(i=1;i<=num;i++){
		fin>>z.exam_name>>z.id>>z.name>>z.S; 
		for(int i=0;i<=z.exam_name.size();i++)
			z.exam_name[i]=z.exam_name[i]-1;
		menl>=z.exam_name.length()?menl=menl:menl=z.exam_name.length();
		for(int i=0;i<=z.name.size();i++)
			z.name[i]=z.name[i]-2;
		mnl>=z.name.length()?mnl=mnl:mnl=z.name.length();
		for(int i=0;i<=z.id.size();i++)
			z.id[i]=z.id[i]-3;
		midl>=z.id.length()?midl=midl:midl=z.id.length();
		z.S=z.S-12397;
		stu.insert(z);
	}
	if(!w){
		cout<<"��ɣ�"<<endl;
		cout<<"�밴 Enter ������"<<endl;
		cin>>o; 
	}
}
//file operation end

//Class Edition
int make_class(){
	ofstream fout;
	fout.open("ClassEdition.dat");
	if(!fout){
		cout<<"ϵͳ�����볢������ϵͳ��"<<endl;
		cout<<"�밴 Enter ����..."<<endl;
		cin>>o; 
		return 1;
	}
	string classname,passwd;
	int n;
	system("clear");
	cout<<"������༶���ƣ�";
	cin>>classname;
	//�����㷨 
	for(i=0;i<classname.length();i++)
		classname[i]+=88;
	cout<<"������༶����Ա���룺";
	cin>>passwd;
	//�����㷨 
	for(i=0;i<passwd.length();i++)
		passwd[i]+=88;
	system("clear");
	cout<<"������༶������";
	cin>>n;
	if(n>=10000){
		cout<<"�༶�������࣡"<<endl;
		cout<<"�밴 Enter ����..."<<endl;
		cin>>o; 
		return 1;
	}
	fout<<classname<<" "<<passwd<<" "<<n<<endl; 
	for(i=1;i<=n;i++){
		system("clear");
		cout<<"���������"<<i<<"��ѧ������Ϣ����"<<n<<"��......"<<endl;
		cout<<"������ѧ��ѧ�ţ�"; 
		cin>>zz.id;
		cout<<"������ѧ��������";
		cin>>zz.name;
		stuinfo.insert(zz);
	}
	for(siit=stuinfo.begin();siit!=stuinfo.end();siit++){
		zz.id=it->id;
		zz.name=it->name;		
		for(j=0;j<zz.id.length();j++)
			zz.id[j]+=10;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]+=10;
		fout<<zz.name<<" "<<zz.id<<endl;
	}
	fout.close();
	system("clear");
	cout<<"�༶������ɣ�"<<endl;
	cout<<"�밴 Enter ����..."<<endl;
	cin>>o; 
}
int class_edition(){
	system("clear");
	string clssnm,pwd,classname,passwd;
	int n;
	bool found=false;
	ifstream fin;
	fin.open("ClassEdition.dat");
	fin>>clssnm>>pwd>>n;
	for(i=0;i<clssnm.length();i++)
		clssnm[i]-=88;
	for(i=0;i<pwd.length();i++)
		pwd[i]-=88;
	cout<<"�༶ģʽ-��½"<<endl; 
	cout<<"������༶���ƣ�";
	cin>>classname;
	if(classname!=clssnm){
		system("clear");
		cout<<"�༶�����ڣ�"<<endl;
		cout<<"�밴 Enter ����..."<<endl;
		cin>>o; 
		return 1;
	}
	cout<<"���������룺";
	cin>>passwd;
	if(passwd!=pwd){
		system("clear");
		cout<<"�������"<<endl; 
		cout<<"�밴 Enter ����..."<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"�����뿼�����ƣ�";
	cin>>z.exam_name; 
	for(i=1;i<=n;i++){
		fin>>zz.name>>zz.id;
		stuinfo.insert(zz);
	}
	for(siit=stuinfo.begin();siit!=stuinfo.end();siit++){
		system("clear");
		cout<<"�������� "<<clssnm<<" �е�"<<i<<"��ѧ���ĳɼ�����"<<n<<"��......"<<endl; 
		zz.id=siit->id;
		zz.name=siit->name;
		for(j=0;j<zz.id.length();j++)
			zz.id[j]-=10;
		z.id=zz.id;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]-=10;
		z.name=zz.name;
		cout<<"ѧ�ţ�"<<z.id<<endl;
		cout<<"������"<<z.name<<endl;
		cout<<"�������ƣ�"<<z.exam_name<<endl;
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				cout<<"��ѧ����Ϣ�Ѵ��ڣ�"<<endl;
				found=true;
				cout<<"�밴 Enter ����..."<<endl;
				cin>>o; 
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
	system("clear");
	cout<<"�༶ģʽ����¼�������"<<endl;
	cout<<"�밴 Enter ����..."<<endl;
	cin>>o; 
}
int class_backup(){
	string classname,passwd;
	int n;
	ifstream fin;
	ofstream fout;
	fin.open("ClassEdition.dat");
	fout.open("ClassEdition.dat.bak");
	fin>>classname>>passwd>>n;
	fout<<classname<<" "<<passwd<<" "<<n<<endl;
	for(i=0;i<n;i++){
		fin>>z.name>>z.id;
		for(j=0;j<z.name.length();j++)
			z.name[j]-=10;
		for(j=0;j<z.id.length();j++)
			z.id[j]-=10;
		//�˴����Լ��ϸ��Ĵ�����Ϣ����� 
		cout<<z.name<<" "<<z.id<<endl;
		fout<<z.name<<" "<<z.id<<endl;
	}
	fin.close();
	fout.close();
	fout.open("ClassEdition.dat");
	fin.open("ClassEdition.dat.bak");
	fin>>classname>>passwd>>n;
	fout<<classname<<" "<<passwd<<" "<<n<<endl;
	for(i=0;i<n;i++){
		fin>>z.name>>z.id;
		for(j=0;j<z.name.length();j++)
			z.name[j]+=10;
		for(j=0;j<z.id.length();j++)
			z.id[j]+=10;
		fout<<z.name<<" "<<z.id<<endl;
	}
	cout<<"Finished!"<<endl;
	return 0;
}
//Class Edition	
