//Copyright (C) XiyuWang 2017-2018 All rights reserved.
//Version: 16.9.18

//Compiler: XiyuWang
//Compiler E-mail Address: XiyuWang_Code@hotmail.com 

//System Language: zh-cn
//Description Language: zh-cn
//Code Language: C++
//Edition: Linux 

//Lines:1000+
//Length:26000+

/* 学生成绩管理系统 描述：
该系统实现的功能
1.录入+更改+删除 学生信息
2.文件 输入+输出
3.四种 查询方式
4.可更改 用户信息
5.可锁定系统  
最新推出：班级模式
更多功能，敬请期待！ 
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
		cout<<"学生成绩管理系统";
		cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
		cout<<" 时间："<<t->tm_hour<<":";
		if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
		else cout<<t->tm_min<<endl;
		cout<<"1.学生信息操作"<<endl; 
		cout<<"2.文件操作"<<endl; 
		cout<<"3.查询"<<endl;
		cout<<"4.设置"<<endl; 
		cout<<"H.帮助"<<endl; 
		cout<<"E.退出系统"<<endl; 
		cout<<"L.锁定系统"<<endl; 
		cout<<"R.重置数据"<<endl; 
		cout<<"@.关于"<<endl; 
		cout<<"请输入命令代码："; 
		cin>>o;
		if(o[0]=='E'){
			system("clear");	
			cout<<"您确定要退出吗？（Y/N）"<<endl;
			cin>>o;
			if(o[0]=='Y'||o[0]=='y') break;
		}
		if(o[0]=='H') system("HELP_zh-cn.chm");
		if(o[0]=='L'){load();start();login(1);}
		if(o[0]=='R'){
			o[0]=0; 
			system("clear");
			cout<<"您确定要重置数据吗？（Y/N）"<<endl;
			cout<<"此操作不可逆！"<<endl; 
			cin>>o;
			if(o[0]=='Y'||o[0]=='y') stu.clear(); 
			o[0]=0; 
		}
		if(o[0]=='@'){
			o[0]=0; 
			system("clear");	
			cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Copyright (C) 学生成绩管理系统 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
			cout<<"Version:16.9.18"<<endl; 
			cout<<"请按 Enter 继续！"<<endl;
			cin>>o; 
			o[0]=0; 
		}
		if(o[0]=='1'){
			o[0]=0; 
			system("clear");
			cout<<"学生成绩管理系统-学生信息操作";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.录入学生信息"<<endl;
			cout<<"2.更改学生信息"<<endl; 
			cout<<"3.删除学生信息"<<endl; 
			cout<<"4.班级模式录入信息（集体录入）"<<endl; 
			cout<<"按其他键 返回"<<endl;
			cout<<"请输入命令代码：";
			cin>>o;
			if(o[0]=='1'&&stu.size()<10000){
				system("clear");
				cout<<"请输入学生个数：";
				cin>>n;
				record_input(n);
			}
			if(o[0]=='1'&&stu.size()>=10000){
				system("clear");
				cout<<"数据量过大，不可继续录入信息！"<<endl;
				system("pause");
			}
			if(o[0]=='2'){
				system("clear");
				cout<<"请输入更改个数：";
				cin>>n;
				record_change(n);
			}
			if(o[0]=='3'){
				system("clear");
				cout<<"请输入删除个数：";
				cin>>n;
				record_delete(n);
			}
			if(o[0]=='4'){
				system("clear");
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(!fin){
					cout<<"您尚未创建班级！请按Enter继续......"<<endl;
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
			cout<<"学生成绩管理系统-文件操作";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.保存信息到文件（自动）"<<endl;
			cout<<"2.从文件读取信息 "<<endl;
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
			cin>>o;
			if(o[0]=='1') file_output(0);
			if(o[0]=='2') file_input(0);
			o[0]=0;
		}
		if(o[0]=='3'){
			o[0]=0; 
			system("clear");
			cout<<"学生成绩管理系统-查询";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.查看所有学生的排名"<<endl;
			cout<<"2.查看单个学生详细信息"<<endl; 
			cout<<"3.查看特定考试学生的排名"<<endl; 
			cout<<"4.查看特定分数段内学生的排名"<<endl; 
			//cout<<"（暂不支持）查看所有考试的平均分"<<endl; 
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
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
			cout<<"学生成绩管理系统-设置";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.更改用户信息"<<endl;
			cout<<"2.联系作者"<<endl; 
			cout<<"3.查看数据量"<<endl; 
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
			cin>>o;
			if(o[0]=='1'){
				while(1){
					system("clear");
					cout<<"您需要重新登陆！Y继续，N停止更改！"<<endl;
					cin>>o;
					if(o[0]=='Y'||o[0]=='y') login(1); 
					else break;
					system("clear");	
					cout<<"登陆成功！Y继续，N停止更改！"<<endl;
					if(o[0]=='Y'||o[0]=='y') reg(); 
					else break;
					system("clear");	
					cout<<"完成！"<<endl; 
					cout<<"请按 Enter 继续！"<<endl;
					cin>>o; 
					break;
				}
			}
			if(o[0]=='2'){
				system("clear");
				cout<<"请发送邮件至：XiyuWang_Code@hotmail.com"<<endl; 
			}
			if(o[0]=='3'){
				system("clear");
				cout<<"当前数据量："<<stu.size()<<endl; 
				cout<<"请按 Enter 继续！"<<endl;
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
	cout<<"请输入 OK 继续！"<<endl; 
	cin>>o;
	if((o[0]!='o'&&o[0]!='O')||(o[1]!='k'&&o[1]!='K')) start();
}

void load(){
	system("clear");
	cout<<"Copyright (C) XiyuWang 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Copyright (C) 学生成绩管理系统 2017-"<<t->tm_year+1900<<" All rights reserved."<<endl;
	cout<<"Version:16.9.18"<<endl; 
	cout<<"加载中......"<<endl; 
	for(i=1;i<=10;i++){
		cout<<"■";
		for(i=1;i<=10000;i++);
	}
}

//user operation 
void reg(){
	system("clear");
	cout<<"您尚未注册，请输入用户名：";
	cin>>o;
	ofstream fout;
	fout.open("SAMS/Control.info");
	if(!fout){
		cout<<"系统错误！缺少管理员权限！您可以尝试重启本系统！"<<endl; 
		while(1);
	}
	fout<<o<<endl;
	fout.close();
	cout<<"请输入密码：";
	cin>>o;
	//加密算法：ASCII码加123
	for(long long i=0;i<=o.size();i++)
		o[i]=o[i]+123;
	fout.open("SAMS/Control.passwd");
	if(!fout){
		cout<<"系统错误！缺少管理员权限！您可以尝试重启本系统！"<<endl; 
		while(1);
	}
	fout<<o<<endl;
	fout.close();
	cout<<"注册成功！"<<endl;
	cout<<"请按 Enter 继续！"<<endl;
	cin>>o; 
}
int wt;//wt:wrong_time
int login(int t){
	if(t>3){
		system("clear");
		cout<<"密码错误次数过多，系统已锁定！"<<endl;
		for(i=1;i<=500000;i++); 
		system("sudo reboot");
	}
	system("clear");
	string usr,passwd;
	ifstream fin;
	fin.open("SAMS/Control.info");
	if(!fin) reg();
	system("clear");
	cout<<"登陆"<<endl; 
	cout<<"请输入用户名：";
	cin>>o;
	fin>>usr; 
	if(!fin){
		cout<<"系统错误！缺少管理员权限！您可以尝试重启本系统！"<<endl; 
		while(1);		
	}
	if(o!=usr){
		cout<<"用户不存在！"<<endl; 
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		login(t);
	}
	fin.close();
	fin.open("SAMS/Control.passwd");
	fin>>passwd;
	fin.close();
	//解密算法：ASCII码减123 
	for(long long i=0;i<=passwd.size();i++)
		passwd[i]=passwd[i]-123;
	cout<<"请输入密码：";
	long long i=0;
	cin>>o;
	if(o!=passwd){
		wt++;
		cout<<"密码错误！"<<endl; 
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		login(wt);
	}
	cout<<"密码正确！"<<endl; 
	cout<<"请按 Enter 继续！"<<endl;
	cin>>o; 
	return 0;
}
//user operation end

//record operation (input,change,delete)
int record_input(unsigned long long int num){
	for(i=1;i<=num;i++){
		ri:
		system("clear");
		cout<<"正在输入第"<<i<<"个学生的信息，共"<<num<<"个......"<<endl; 
		cout<<"请输入学号：";
		cin>>z.id;
		midl>=z.id.length()?midl=midl:midl=z.id.length();
		cout<<"请输入姓名：";
		cin>>z.name;
		mnl>=z.name.length()?mnl=mnl:mnl=z.name.length();
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		menl>=z.exam_name.length()?menl=menl:menl=z.exam_name.length();
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				cout<<"该记录已存在！"<<endl; 
				cout<<"请按 Enter 继续！"<<endl;
				cin>>o; 
				return 1;
			}
		cout<<"请输入成绩：";
		cin>>z.S;
		stu.insert(z);
	}
}
int record_change(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("clear");
		string tmp;
		j=1;
		cout<<"正在更改第"<<i<<"个学生的信息，共"<<num<<"个......"<<endl; 
		cout<<"请输入学生学号或姓名：";
		cin>>tmp;
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&it->exam_name==z.exam_name){
				system("clear"); 
				cout<<"该学生原信息"<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"考试名称："<<it->exam_name<<endl; 
				cout<<"成绩："<<it->S<<endl;
				cout<<"确认更改？（Y/N）"<<endl;
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
				cout<<"未找到该学生的信息，请检查信息是否已经录入系统！"<<endl; 
				cout<<"请按 Enter 继续！"<<endl;
				cin>>o; 
				return 1;
			}
		}
		rc:
		cout<<"请输入新考试名称：";
		cin>>z.exam_name; 
		menl>=z.exam_name.length()?menl=menl:menl=z.exam_name.length();
		cout<<"请输入成绩：";
		cin>>z.S;
		stu.insert(z);
	}
}
int record_delete(unsigned long long int num){
	for(i=1;i<=num;i++){
		system("clear");
		string tmp;
		j=1;
		cout<<"正在删除第"<<i<<"个学生的信息，共"<<num<<"个......"<<endl; 
		cout<<"请输入学生学号或姓名：";
		cin>>tmp;
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&z.exam_name==it->exam_name){
				system("clear"); 
				cout<<"该学生原信息"<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"考试名称："<<it->exam_name<<endl; 
				cout<<"成绩："<<it->S<<endl;
				cout<<"确认删除？（Y/N）"<<endl; 
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
				cout<<"未找到该学生的信息，请检查信息是否已经录入系统！"<<endl;
				cout<<"请按 Enter 继续！"<<endl;
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
		cout<<"暂无记录！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	clock_t start = clock();
	z.exam_name=' ';
	cout<<"排名|学号 ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|姓名 ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|考试名称 ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|成绩"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"平均分："<<Average<<endl;
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
	cout<<"平均分："<<Average<<endl<<endl;
	clock_t end   = clock();
	cout << "使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
	cout<<"请按 Enter 继续！"<<endl;
	cin>>o; 
}
//output only one student's information
int record_find(){
	system("clear");
	if(stu.size()<1){
		cout<<"暂无记录！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	double Average,All;
	z.exam_name=' ';
	string tmp;
	bool f=false; 
	cout<<"请输入学生学号或姓名：";
	cin>>tmp;
	clock_t start = clock();
	cout<<"排名|学号 ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|姓名 ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|考试名称 ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|成绩"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"平均分："<<Average<<endl;
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
	cout<<"平均分："<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"暂无记录！"<<endl;
	cout<<"请按 Enter 继续！"<<endl;
	cin>>o; 
	return 1;
}
//output information in given examname
int record_find_examname(){
	system("clear");
	if(stu.size()<1){
		cout<<"暂无记录！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	double Average,All;
	bool f=false; 
	z.exam_name=' ';
	string tmp;
	cout<<"请输入考试名称：";
	cin>>tmp;
	clock_t start = clock();
	cout<<"排名|学号 ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|姓名 ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|考试名称 ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|成绩"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"平均分："<<Average<<endl;
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
	cout<<"平均分："<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"暂无记录！"<<endl;
	cout<<"请按 Enter 继续！"<<endl;
	cin>>o; 
	return 1;
}
//output information between given lowest score and given highest score
int record_find_score(){
	system("clear");
	if(stu.size()<1){
		cout<<"暂无记录！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	double Average,All;
	bool f=false; 
	z.exam_name=' ';
	int l,h;//l:lowest,h:highest
	cout<<"请输入最低分数：";
	cin>>l;
	cout<<"请输入最高分数：";
	cin>>h; 
	clock_t start = clock();
	cout<<"排名|学号 ";
	for(i=midl;i>4;i--) cout<<" ";
	cout<<"|姓名 ";
	for(i=mnl;i>4;i--) cout<<" ";
	cout<<"|考试名称 ";
	for(i=menl;i>8;i--) cout<<" ";
	cout<<"|成绩"<<endl;
	for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
		if(z.exam_name!=it->exam_name&&i!=1){
			Average=All/(i-1);
			All=0;
			i=1;
			cout<<"平均分："<<Average<<endl;
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
	cout<<"平均分："<<Average<<endl<<endl;
	if(f==true){
		clock_t end   = clock();
		cout << "使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"未找到该分数段中任何学生的信息，请检查信息是否已经录入系统！"<<endl;
	cout<<"请按 Enter 继续！"<<endl;
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
	fout.open("学生成绩信息.csv",ios::out|ios::trunc); 
	if(!fout){
		cout<<"无法保存文件！"<<endl; 
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	if(stu.size()==0) fout<<"暂无记录！"<<endl;
	else{
		fout<<"排名"<<","<<"学号"<<","<<"成绩"<<","<<"姓名"<<","<<"考试名称"<<endl;
		for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(i-1);
				All=0;
				i=1;
				fout<<"平均分："<<Average<<endl;
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
	fout<<"平均分："<<Average<<endl;
	}
	fout.close();
	fout.open("SAMS/StudentScore.dat"); 
	if(!fout){
		cout<<"无法保存文件！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
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
		cout<<"完成！请关闭预览窗口（Excel表格窗口）后继续！"<<endl;
		system("学生成绩信息.csv");
	}
}
int file_input(bool w){
	system("clear");
	unsigned long long int num;
	string version;
	ifstream fin;
	fin.open("SAMS/StudentScore.dat"); 
	if(!fin&&!w){
		cout<<"文件\"SAMS/StudentScore.dat\"不存在！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	if(!fin&&w) return 1; 
	fin>>version>>num;
	if(version!="16.9.18"&&!w){
		cout<<"文件版本与系统不符，无法录入信息！"<<endl;
		cout<<"文件版本："<<version<<endl; 
		cout<<"系统版本：16.9.18"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
		return 1;
	}
	if(version!="16.9.18"&&w) return 1;
	if((num+stu.size())>=10000&&!w){
		cout<<"文件数据量过大，无法录入系统！"<<endl;
		cout<<"文件数据量： "<<num<<endl;
		cout<<"系统当前数据量："<<stu.size()<<endl;
		cout<<"录入后数据量："<<num+stu.size()<<endl;
		cout<<"超过标准："<<num+stu.size()-10000<<endl;
		cout<<"请按 Enter 继续！"<<endl;
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
		cout<<"完成！"<<endl;
		cout<<"请按 Enter 继续！"<<endl;
		cin>>o; 
	}
}
//file operation end

//Class Edition
int make_class(){
	ofstream fout;
	fout.open("ClassEdition.dat");
	if(!fout){
		cout<<"系统错误！请尝试重启系统！"<<endl;
		cout<<"请按 Enter 继续..."<<endl;
		cin>>o; 
		return 1;
	}
	string classname,passwd;
	int n;
	system("clear");
	cout<<"请输入班级名称：";
	cin>>classname;
	//加密算法 
	for(i=0;i<classname.length();i++)
		classname[i]+=88;
	cout<<"请输入班级管理员密码：";
	cin>>passwd;
	//加密算法 
	for(i=0;i<passwd.length();i++)
		passwd[i]+=88;
	system("clear");
	cout<<"请输入班级人数：";
	cin>>n;
	if(n>=10000){
		cout<<"班级人数过多！"<<endl;
		cout<<"请按 Enter 继续..."<<endl;
		cin>>o; 
		return 1;
	}
	fout<<classname<<" "<<passwd<<" "<<n<<endl; 
	for(i=1;i<=n;i++){
		system("clear");
		cout<<"正在输入第"<<i<<"个学生的信息，共"<<n<<"项......"<<endl;
		cout<<"请输入学生学号："; 
		cin>>zz.id;
		cout<<"请输入学生姓名：";
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
	cout<<"班级创建完成！"<<endl;
	cout<<"请按 Enter 继续..."<<endl;
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
	cout<<"班级模式-登陆"<<endl; 
	cout<<"请输入班级名称：";
	cin>>classname;
	if(classname!=clssnm){
		system("clear");
		cout<<"班级不存在！"<<endl;
		cout<<"请按 Enter 继续..."<<endl;
		cin>>o; 
		return 1;
	}
	cout<<"请输入密码：";
	cin>>passwd;
	if(passwd!=pwd){
		system("clear");
		cout<<"密码错误！"<<endl; 
		cout<<"请按 Enter 继续..."<<endl;
		cin>>o; 
		return 1;
	}
	system("clear");
	cout<<"请输入考试名称：";
	cin>>z.exam_name; 
	for(i=1;i<=n;i++){
		fin>>zz.name>>zz.id;
		stuinfo.insert(zz);
	}
	for(siit=stuinfo.begin();siit!=stuinfo.end();siit++){
		system("clear");
		cout<<"正在输入 "<<clssnm<<" 中第"<<i<<"个学生的成绩，共"<<n<<"项......"<<endl; 
		zz.id=siit->id;
		zz.name=siit->name;
		for(j=0;j<zz.id.length();j++)
			zz.id[j]-=10;
		z.id=zz.id;
		for(j=0;j<zz.name.length();j++)
			zz.name[j]-=10;
		z.name=zz.name;
		cout<<"学号："<<z.id<<endl;
		cout<<"姓名："<<z.name<<endl;
		cout<<"考试名称："<<z.exam_name<<endl;
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				cout<<"该学生信息已存在！"<<endl;
				found=true;
				cout<<"请按 Enter 继续..."<<endl;
				cin>>o; 
				break; 
			}
		if(found){
			found=false;
			continue;
		}
		cout<<"请输入成绩：";
		cin>>z.S;
		stu.insert(z);
	}
	system("clear");
	cout<<"班级模式数据录入结束！"<<endl;
	cout<<"请按 Enter 继续..."<<endl;
	cin>>o; 
}
//Class Edition	
