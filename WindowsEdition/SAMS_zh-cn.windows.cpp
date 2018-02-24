//Copyright (C) 2017-2018 XiyuWang All rights reserved.
//Version: 16.9.18

//Author: XiyuWang
//Author E-mail Address: XiyuWang_Code@hotmail.com 

//System Language: zh-cn
//Description Language: zh-cn
//Code Language: C++

//Lines:1100+
//Length:32000+ 

/* 学生成绩管理系统 描述：
该系统实现的功能
1.录入+更改+删除 学生信息 
2.文件 输入+输出
3.五种 查询方式
4.可更改 用户信息
5.可锁定系统  
最新推出：班级模式 
更多功能，敬请期待！ 
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
//9 Files included
using namespace std;

long long i,j,n,ti;
int menl,midl,mnl;//menl:max exam_name length	midl:max id length	mnl:max name length
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

int max(int a,int b){
	if(a>b) return a;
	return b;
}

void start(int len){
	srand(time(0));
	string key,ans;
	;
	system("cls");
	system("title 学生成绩管理系统");
	cout<<"验证码："; 
	for(i=0;i<len;i++){
		key[i]=char(65+rand()%(65-122+1));
		cout<<key[i];
	}	
	cout<<endl<<"请输入验证码：";
	cin>>ans;
	for(i=0;i<len;i++)
		if(ans[i]!=key[i]) start(len+1);
	cout<<"验证码正确！"<<endl; 
}

void load(){
	system("cls");
	system("title 学生成绩管理系统-加载中......");
	cout<<"Copyright (C) 2017-2018 XiyuWang All rights reserved."<<endl;
	cout<<"Version:16.9.18"<<endl; 
	cout<<"小提示：所有数据输入时不可添加空格，否则系统会出错！"<<endl; 
	cout<<"加载中......"<<endl; 
	for(i=1;i<=10;i++){
		cout<<"■";
		Sleep(188);
	}
}

namespace user{ 
	//user operation 
	void reg(){
		ifstream fin;
		fin.open("SignIn.dll"); 
		if(!fin){
			system("cls");
			cout<<"系统重要文件缺失，无法注册账户！"<<endl;
			system("pause");
			exit(0);
		}
		system("SignIn.dll");
		system("del SignIn.dll /f /q"); 
	}
	int wt;//wt:wrong_time
	bool login(int t){
	signin:
		wt=t;
		;
		if(t>3){
			system("cls");
			cout<<"密码错误次数过多，系统已锁定！"<<endl;
			Sleep(5000);
			system("shutdown -p");
			exit(0);
		}
		system("cmd.exe /c attrib C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.info +h");
		system("cmd.exe /c attrib C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd +h");
		system("cls");
		system("title 学生成绩管理系统-登陆");
		string usr,passwd;
		ifstream fin;
		fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr");
		if(!fin) user::reg();
		system("cls");
		cout<<"登陆"<<endl; 
		cout<<"请输入用户名：";
		cin>>o;
		if(o=="Student"||o=="学生"){
			system("cls");
			cout<<"请输入学生姓名：";
			cin>>o;
			int ii=0;
			string stuName[100000];
			ifstream fin;
			fin.open("StudentLogin.txt");
			while(getline(fin,stuName[ii])) ii++;
			fin.close();
			ofstream fout;
			fout.open("StudentLogin.txt");
			for(int i=0;i<ii;i++) fout<<stuName[i]<<endl;
			fout<<"第"<<ii<<"次     "<<o<<endl;
			fout.close();
			system("cls"); 
			cout<<"学生免密进入系统！"<<endl;
			system("pause");
			return 0;
		}
		fin>>usr; 
		if(!fin){
			MessageBox(NULL,"系统错误！\r\n请以管理员身份重新运行程序！","学生成绩管理系统",MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			exit(0);
		}
		if(o!=usr){
			MessageBox(NULL,"用户不存在！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			login(t);
		}
		fin.close();
		fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd");
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
			MessageBox(NULL,"密码错误！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			t=wt;
			goto signin;
		}
		MessageBox(NULL,"密码正确！","学生成绩管理系统",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//user operation end
}

namespace record_input{ 
	//record operation (input,change,delete)
	int rinput(){
		ris: 
		o[0]=0; 
		bool found=false;
		ri:
		system("cls");
		cout<<"请输入学号：";
		cin>>z.id;
		midl=max(midl,z.id.length());
		cout<<"请输入姓名：";
		cin>>z.name;
		mnl=max(mnl,z.name.length());
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		string tmp; 
		inputScore:
		cout<<"请输入成绩：";
		cin>>tmp;
		for(int iii=0;iii<tmp.size();iii++)
			if((tmp[iii]<'0'||tmp[iii]>'9')&&tmp[iii]!='.'){
				system("cls");
				cout<<endl<<"成绩不合法！请重新输入！"<<endl; 
				system("pause");
				system("cls");
				goto inputScore;
			}
		z.S=atof(tmp.c_str());
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				system("cls");
				cout<<"错误：该记录已存在！"<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"考试名称："<<it->exam_name<<endl;
				cout<<"本地成绩："<<it->S<<endl;
				cout<<"输入成绩："<<z.S<<endl;
				cout<<"===================="<<endl;
				cout<<"是否替换？(Y/N)"; 
				cin>>o;
				o[0]=='Y'||o[0]=='y'?found=false:found=true;
				break;
			}
		stu.insert(z);
		system("cls");
		cout<<"输入完成！是否继续输入？(Y/N)"<<endl;
		cin>>o;
		if(o[0]=='y'||o[0]=='Y') goto ris;
		else return 0;
	}
	int rchange(){
		rcs:
		o[0]=0;
		system("cls");
		string tmp;
		j=1;
		cout<<"请输入学生学号或姓名：";
		cin>>tmp;
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&it->exam_name==z.exam_name){
				system("cls"); 
				cout<<"该学生原信息"<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"考试名称："<<it->exam_name<<endl; 
				cout<<"成绩："<<it->S<<endl;
				if(MessageBox(NULL,"您确定要更改该学生的信息吗？","学生成绩管理系统",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					z.name=it->name;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"未找到该学生的信息，请检查信息是否已经录入系统！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
				return 1;
			}
		}
		rc:
		cout<<"请输入新考试名称：";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		string ttmp;
		inputScore:
		cout<<"请输入成绩：";
		cin>>ttmp;
		for(int iii=0;iii<ttmp.size();iii++)
			if((ttmp[iii]<'0'||ttmp[iii]>'9')&&ttmp[iii]!='.'){
				system("cls");
				cout<<endl<<"成绩不合法！请重新输入！"<<endl; 
				system("pause");
				system("cls");
				goto inputScore;
			}
		z.S=atof(ttmp.c_str());
		stu.insert(z);
		system("cls");
		cout<<"更改完成！是否继续更改？(Y/N)"<<endl;
		cin>>o;
		if(o[0]=='Y'||o[0]=='y') goto rcs;
		else return 0; 
	}
	int rdelete(){
		rds:
		system("cls");
		string tmp;
		j=1;
		cout<<"请输入学生学号或姓名：";
		cin>>tmp;
		cout<<"请输入考试名称：";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&z.exam_name==it->exam_name){
				system("cls"); 
				cout<<"该学生原信息"<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"考试名称："<<it->exam_name<<endl; 
				cout<<"成绩："<<it->S<<endl;
				if(MessageBox(NULL,"您确定要删除该学生的信息吗？","学生成绩管理系统",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"未找到该学生的信息，请检查信息是否已经录入系统！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				return 1;
			}
		}
		system("cls");
		cout<<"删除完成！是否继续删除？(Y/N)"<<endl;
		cin>>o;
		if(o[0]=='Y'||o[0]=='y') goto rds;
		else return 0; 
	}
	//record operation end
}
namespace record_output{
	//record output (five ways)
	//output all information
	int output(){
		double All,Average;
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"暂无记录！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
		system("pause");
	}
	//output only one student's information
	int find(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"暂无记录！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"未找到该学生的信息，请检查信息是否已经录入系统！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information in given examname
	int find_examname(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"暂无记录！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"未找到该考试中任何学生的信息，请检查信息是否已经录入系统！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information between given lowest score and given highest score
	int find_score(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"暂无记录！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"未找到该分数段中任何学生的信息，请检查信息是否已经录入系统！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information in given classname 
	int find_clssnm(){
		string clssnm,pwd;
		int n;
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"暂无记录！","学生成绩管理系统",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
		cout<<"平均分："<<Average<<endl<<endl;
		clock_t end   = clock();
		cout << "使用时间：" << (double)(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
		system("pause");
		return 1;
	}
	//record output end
}

namespace file{
	//file operation
	int output(bool save){
		double Average,All;
		ofstream fout;
		system("cls");
		z.exam_name=' ';
		fout.open("D:\\学生成绩信息.csv",ios::out|ios::trunc); 
		if(!fout){
			MessageBox(NULL,"错误：\r\n无法保存文件！","学生成绩管理系统",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
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
		fout.open("StudentScore.dat"); 
		if(!fout){
			MessageBox(NULL,"错误：\r\n无法保存文件！","学生成绩管理系统",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
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
			system("D:\\学生成绩信息.csv");
			system("pause");
		}
	}
	int input(bool w){
		bool found;
		system("cls");
		unsigned long long int num;
		string version;
		ifstream fin;
		fin.open("StudentScore.dat"); 
		if(!fin&&!w){
			MessageBox(NULL,"文件\"StudentScore.dat\"不存在！","学生成绩管理系统",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		if(!fin&&w) return 1; 
		fin>>version>>num;
		if(version!="16.9.18"&&!w){
			cout<<"文件版本与系统不符，无法录入信息！"<<endl;
			cout<<"文件版本："<<version<<endl; 
			cout<<"系统版本：16.9.18"<<endl;
			system("pause");
			return 1;
		}
		if(version!="16.9.18"&&w) return 1;
		if((num+stu.size())>=10000&&!w){
			cout<<"文件数据量过大，无法录入系统！"<<endl;
			cout<<"文件数据量： "<<num<<endl;
			cout<<"系统当前数据量："<<stu.size()<<endl;
			cout<<"录入后数据量："<<num+stu.size()<<endl;
			cout<<"超过标准："<<num+stu.size()-10000<<endl;
			system("pause");
			return 1;
		}
		if((num+stu.size())>=10000&&w) return 1;
		for(int iiii=1;iiii<=num;iiii++){
			fin>>z.exam_name>>z.id>>z.name>>z.S; 
			for(i=0;i<=z.exam_name.size();i++)
				z.exam_name[i]=z.exam_name[i]-1;
			menl=max(menl,z.exam_name.length());
			for(i=0;i<=z.name.size();i++)
				z.name[i]=z.name[i]-2;
			mnl=max(mnl,z.name.length());
			for(i=0;i<=z.id.size();i++)
				z.id[i]=z.id[i]-3;
			midl=max(midl,z.id.length());
			z.S=z.S-12397;
			for(it=stu.begin();it!=stu.end();it++){
				if(it->exam_name==z.exam_name&&it->name==z.name&&it->id==z.id){
					fileInputError:
					system("cls");
					cout<<"文件";
					if(w) cout<<"自动";
					cout<<"引入时出错：检测到相同学生信息！"<<endl;
					cout<<"学号："<<it->id<<endl; 
					cout<<"姓名："<<it->name<<endl;
					cout<<"考试名称："<<it->exam_name<<endl;
					cout<<"本地成绩："<<it->S<<endl;
					cout<<"文件成绩："<<z.S<<endl; 
					cout<<"===================================="<<endl;
					cout<<"1.本地                        2.文件"<<endl; 
					cout<<"请选择要保留的信息（序号）："; 
					cin>>o;
					o[0]=='1'?found=true:found=false;
					if(o[0]!='1'&&o[0]!='2') goto fileInputError;
				}
			}
			if(found){
				continue;
				found=false;
			}
			if(!found) stu.insert(z);
		}
		if(!w) MessageBox(NULL,"完成！","学生成绩管理系统",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND);
	}
	//file operation end
}

namespace ClassEdition{
	//Class Edition
	int reg(){
		string classname,passwd,name,id;
		int n;
		ifstream fin;
		fin.open("ClassEdition.dat");
		fin>>classname>>passwd>>n;
		ofstream fout;
		fout.open("ClassEdition.dat");
		if(!fout){
			cout<<"系统错误！请尝试重启系统！"<<endl;
			system("pause");
			return 1;
		}
		system("cls");
		cout<<"请输入新班级名称：";
		cin>>classname;
		//加密算法 
		for(i=0;i<classname.length();i++)
			classname[i]+=18;
		cout<<"请输入新班级管理员密码：";
		cin>>passwd;
		//加密算法 
		for(i=0;i<passwd.length();i++)
			passwd[i]+=18;
		fout<<classname<<" "<<passwd<<" "<<n<<endl;
		for(i=1;i<=n;i++){
			fin>>name>>id;
			fout<<name<<" "<<id<<endl;
		}
		system("cls");
	} 
	int make(){
		ofstream fout;
		fout.open("ClassEdition.dat");
		if(!fout){
			cout<<"系统错误！请尝试重启系统！"<<endl;
			system("pause");
			return 1;
		}
		string classname,passwd;
		int n;
		system("cls");
		cout<<"请输入班级名称：";
		cin>>classname;
		//加密算法 
		for(i=0;i<classname.length();i++)
			classname[i]+=18;
		cout<<"请输入班级管理员密码：";
		cin>>passwd;
		//加密算法 
		for(i=0;i<passwd.length();i++)
			passwd[i]+=18;
		system("cls");
		cout<<"请输入班级人数：";
		cin>>n;
		if(n+stu.size()>=10000){
			cout<<"班级人数过多！"<<endl;
			system("pause");
			return 1;
		}
		fout<<classname<<" "<<passwd<<" "<<n<<endl; 
		for(i=1;i<=n;i++){
			system("cls");
			cout<<"正在输入第"<<i<<"个学生的信息，共"<<n<<"项......"<<endl;
			cout<<"请输入学生学号："; 
			cin>>zz.id;
			cout<<"请输入学生姓名：";
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
		cout<<"班级创建完成！"<<endl;
		system("pause");
	}
	int main(){
		system("cls");
		string clssnm,pwd,classname,passwd;
		int n=0;
		ifstream fin;
		fin.open("ClassEdition.dat");
		fin>>clssnm>>pwd>>n;
		for(i=0;i<clssnm.length();i++)
			clssnm[i]-=18;
		for(i=0;i<pwd.length();i++)
			pwd[i]-=18;
		cout<<"班级模式-登陆"<<endl; 
		cout<<"班级名称："<<clssnm<<endl;
		cout<<"密码：";
		cin>>passwd;
		if(passwd!=pwd){
			system("cls");
			cout<<"密码错误！"<<endl; 
			system("pause");
			return 1;
		}
		system("cls");
		cout<<"请输入考试名称：";
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
			cout<<"正在输入 "<<clssnm<<" 中第"<<i<<"个学生的成绩，共"<<n<<"项......"<<endl; 
			z.id=siit->id;
			z.name=siit->name;
			cout<<"学号："<<z.id<<endl;
			cout<<"姓名："<<z.name<<endl;
			cout<<"考试名称："<<z.exam_name<<endl;
			string tmp; 
			inputScore:
			cout<<"请输入成绩：";
			cin>>tmp;
			for(int iii=0;iii<tmp.size();iii++)
				if((tmp[iii]<'0'||tmp[iii]>'9')&&tmp[iii]!='.'){
					system("cls");
					cout<<endl<<"成绩不合法！请重新输入！"<<endl; 
					system("pause");
					system("cls");
					goto inputScore;
				}
			for(it=stu.begin();it!=stu.end();it++)
				if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
					ef:
					system("cls");
					cout<<"学号："<<it->id<<endl;
					cout<<"姓名："<<it->name<<endl;
					cout<<"考试名称："<<it->exam_name<<endl; 
					cout<<"本地成绩："<<it->S<<endl; 
					cout<<"输入成绩："<<z.S<<endl; 
					cout<<"错误：该学生信息已存在！"<<endl;
					cout<<"================================="<<endl;
					cout<<"1.保存本地信息     2.保存输入信息"<<endl; 
					cin>>o;
					if(o[0]=='1') z.S=it->S;
					if(o[0]!='1'&&o[0]!='2') goto ef;
					break;  
				}
			stu.insert(z);
		}
		system("cls");
		cout<<"班级模式数据录入结束！"<<endl;
		system("pause"); 
	}
	//Class Edition
}

int main(){
	string clssnm,pwd;
	int n,lockh,lockm;
	system("color f0");
	;
	ti=t->tm_min; 
	bool usr;
	load(); start(4); usr=user::login(1); load(); file::input(1);
	while(o[0]!='E'){
		cin.clear();
		cin.sync(); 
		time_t tt = time(NULL);	
		tm* t=localtime(&tt);
		if(t->tm_min!=ti&&stu.size()>0){
			file::output(1);
			ti=t->tm_min;
		}
		mnl=menl=midl=0;
		for(it=stu.begin();it!=stu.end();it++){
			mnl=max(mnl,it->name.length());
			menl=max(menl,it->exam_name.length());
			midl=max(midl,it->id.length());
		}
		system("cls");
		if(usr) system("title 学生成绩管理系统");
		if(!usr) system("title 学生成绩查询系统"); 
		;
		if(usr) cout<<"学生成绩管理系统";
		if(!usr) cout<<"学生成绩查询系统"; 
		cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
		cout<<" 时间："<<t->tm_hour<<":";
		if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
		else cout<<t->tm_min<<endl;
		cout<<"1.学生信息操作";
		if(!usr) cout<<"-需要管理员权限"<<endl; 
		else cout<<endl;
		cout<<"2.文件操作"; 
		if(!usr) cout<<"-需要管理员权限"<<endl; 
		else cout<<endl;
		cout<<"3.查询"<<endl;
		cout<<"4.设置"; 
		if(!usr) cout<<"-需要管理员权限"<<endl; 
		else cout<<endl;
		cout<<"H.帮助"<<endl; 
		cout<<"E.退出系统"<<endl; 
		cout<<"L.锁定系统"<<endl; 
		cout<<"R.重置数据";
		if(!usr) cout<<"-需要管理员权限"<<endl; 
		else cout<<endl; 
		cout<<"@.关于"<<endl; 
		cout<<"请输入命令代码："; 
		o[0]=getch();
		if(t->tm_min>=lockm&&t->tm_hour>=lockh){
			system("cls");
			cout<<"挂机超过5分钟，自动登出！"<<endl;
			Sleep(5000); 
			start(4);
			usr=user::login(1);
		}
		t->tm_min+5<60?lockm+=5:lockh++,lockm-=55;
		if(o[0]=='E') if(MessageBox(NULL,"您确定要退出吗？","学生成绩管理系统",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) break;
		if(o[0]=='H') system("HELP_zh-cn.chm");
		if(o[0]=='L'){load();start(4);usr=user::login(1);}
		if(o[0]=='R'&&usr){
			o[0]=0; 
			system("cls");
			if(MessageBox(NULL,"您确定要重置数据吗？\r\n此操作不可逆！","学生成绩管理系统",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) stu.clear();
			o[0]=0; 
		}
		if(o[0]=='@'){
			o[0]=0; 
			system("cls");	
			cout<<"Copyright (C) 2017-2018 XiyuWang All rights reserved."<<endl;
			cout<<"Version:16.9.18"<<endl; 
			system("pause");
			o[0]=0; 
		}
		if(o[0]=='1'&&usr){
			;
			o[0]=0; 
			string clssnm="请创建班级"; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			if(fin){
				fin>>clssnm;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			cout<<"学生成绩管理系统-学生信息操作";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.录入学生信息"<<endl;
			cout<<"2.更改学生信息"<<endl; 
			cout<<"3.删除学生信息"<<endl; 
			cout<<"4.班级模式录入信息（当前班级："<<clssnm<<"）"<<endl; 
			cout<<"按其他键 返回"<<endl;
			cout<<"请输入命令代码：";
			o[0]=getch(); 
			if(o[0]=='1'&&stu.size()<10000) record_input::rinput();
			if(o[0]=='1'&&stu.size()>=10000){
				system("cls");
				cout<<"数据量过大，不可继续录入信息！"<<endl;
				system("pause");
			}
			if(o[0]=='2') record_input::rchange();
			if(o[0]=='3') record_input::rdelete();
			if(o[0]=='4'){
				system("cls");
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(!fin){
					cout<<"您尚未创建班级！请按任意键继续......"<<endl;
					getch();
					ClassEdition::make();
				}
				else ClassEdition::main();
			}
			o[0]=0; 
		} 
		if(o[0]=='2'&&usr){
			;
			o[0]=0; 
			system("cls");
			cout<<"学生成绩管理系统-文件操作";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.保存信息到文件（自动）"<<endl;
			cout<<"2.从文件读取信息 "<<endl;
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
			o[0]=getch(); 
			if(o[0]=='1') file::output(0);
			if(o[0]=='2') file::input(0);
			o[0]=0;
		}
		if(o[0]=='3'){
			;
			o[0]=0; 
			string clssnm="（请创建班级）"; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			if(fin){
				fin>>clssnm;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			if(usr) cout<<"学生成绩管理系统-查询";
			if(!usr) cout<<"学生信息查询系统-查询"; 
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.查看所有学生的排名"<<endl;
			cout<<"2.查看单个学生详细信息"<<endl; 
			cout<<"3.查看特定考试学生的排名"<<endl; 
			cout<<"4.查看特定分数段内学生的排名"<<endl; 
			cout<<"5.查看班级 "<<clssnm<<" 内学生的排名"<<endl; 
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
			o[0]=getch(); 
			if(o[0]=='1') record_output::output(); 
			if(o[0]=='2') record_output::find();
			if(o[0]=='3') record_output::find_examname(); 
			if(o[0]=='4') record_output::find_score();
			if(o[0]=='5'&&fin) record_output::find_clssnm();
			if(o[0]=='5'&&!fin) MessageBox(NULL,"您尚未创建班级！\r\n请前往 主页=>学生信息操作=>4.班级模式录入信息 创建班级！","学生成绩管理系统",MB_OK|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			o[0]=0;
		}
		if(o[0]=='4'&&usr){
			;
			o[0]=0;
			system("cls");
			cout<<"学生成绩管理系统-设置";
			cout<<" 日期："<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" 时间："<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.更改用户信息"<<endl;
			cout<<"2.更改班级信息"<<endl; 
			cout<<"3.联系作者"<<endl; 
			cout<<"4.查看数据量"<<endl; 
			cout<<"按其他键 返回"<<endl; 
			cout<<"请输入命令代码：";
			o[0]=getch();
			if(o[0]=='1'){
				while(1){
					system("cls");
					start(4);
					if(MessageBox(NULL,"您需要重新登录！\r\n按是继续，按否停止更改！","学生成绩管理系统",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) user::login(1);
					else break;
					if(MessageBox(NULL,"登陆成功！\r\n按是继续，按否停止更改！","学生成绩管理系统",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) user::reg();
					else break;
					MessageBox(NULL,"完成！","学生成绩管理系统",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					break;
				}
			}
			if(o[0]=='2') ClassEdition::reg();
			if(o[0]=='3'){
				system("cls");
				MessageBox(NULL,"请发送邮件至：\r\nXiyuWang_Code@hotmail.com","学生成绩管理系统",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
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
				cout<<"当前数据量："<<stu.size()<<endl; 
				if(fin) cout<<"班级 "<<clssnm<<" 中的学生量："<<stuinfo.size()<<endl; 
				system("pause");
			}
		}
		o[0]=0; 
	}
	if(stu.size()>0) file::output(1);
	system("cls");
	system("title 学生成绩管理系统-正在退出"); 
	load();
	system("title 学生成绩管理系统-正在退出"); 
	Sleep(1000);
	return 0; 
}
